#include "SJF.h"

SJF::SJF(vector<Process *> processes_read) : Scheduling(processes_read){}

void SJF::findNewProcesses(){

    /*Enquanto o ${submit_time} do primeiro processo da fila de processos 
    lidos for igual ao ${current_time} do escalonador.*/ 
    while (this->processes_read[0]->getSubmitTime() == this->current_time)
    {   
         // Cria o processo no contexto do SO.
        Process *process = this->processes_read[0];
        process->setPid(this->pid_cout);
        process->setState(1); // Inicia já como pronto.
        process->generateRandomValuesForRegisters(&this->generator); // Gera valores aleatórios para os registradores.

        // Coloca na fila de prontos na posição da sua prioridade(Menor tempo de execução).
        for (vector<Process*>::size_type i = 0; i <= this->process_table.ready_processes.size(); i++) {
            if (i == this->process_table.ready_processes.size()){
                this->process_table.ready_processes.push_back(process);
                break;
            }

            Process *p = this->process_table.ready_processes[i];
            if (p->getNecessaryTime() > process->getNecessaryTime()){
                this->process_table.ready_processes.insert(this->process_table.ready_processes.begin() + i, process);
                break;
            }
        }


        // Remove o primeiro processo da fila de processos lidos.
        processes_read.erase(processes_read.begin());

        // Acrescenta +1 no contador de processos.
        this->pid_cout += 1;

        // Importante para evitar erros de segmentação.
        if (this->processes_read.size() == 0) break;
            
    }
}

void SJF::run(){
    // Enquanto houver processos na fila de processos lidos, prontos ou executando.
    while (this->processes_read.size() != 0 || this->process_table.ready_processes.size() != 0 || this->process_table.running_process)
    {       
        // Busca novos processos na fila de processos lidos.
        if (this->processes_read.size() != 0 ) this->findNewProcesses();

        // Se não houver processo em execução mas existir processos prontos.
        if(!this->process_table.running_process && this->process_table.ready_processes.size() != 0){
            // Seleciona o próximo processo a ser executado.
            this->selection();
        }

        // Avança o tempo.
        this->passTime();

        // Se o processo em execução chegou ao fim.
        if (this->process_table.running_process && this->process_table.running_process->getTimeExec() == this->process_table.running_process->getNecessaryTime()){
            // Encerra o processo em execução.
            this->end();
        }
    }
}