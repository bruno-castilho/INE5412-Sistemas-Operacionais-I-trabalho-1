#include "FCFS.h"


FCFS::FCFS(vector<Process *> processes_read) : Scheduling(processes_read){}

void FCFS::findNewProcesses(){

    /*Enquanto o ${submit_time} do primeiro processo da fila de processos 
    lidos for igual ao ${current_time} do escalonador.*/ 
    while (this->processes_read[0]->getSubmitTime() == this->current_time)
    {   
        // Cria o processo no contexto do SO.
        Process *p = this->processes_read[0];
        p->setPid(this->pid_cout);
        p->setState(1); // Inicia já como pronto.
        p->generateRandomValuesForRegisters(&this->generator); // Gera valores aleatórios para os registradores.

        // Coloca processo no fim da fila de prontos.
        this->process_table.ready_processes.push_back(p);

        // Remove o primeiro processo da fila de processos lidos.
        processes_read.erase(processes_read.begin());

        // Acrescenta +1 no contador de processos.
        this->pid_cout += 1;

        // Importante para evitar erros de segmentação.
        if (this->processes_read.size() == 0) break;

    }
}


void FCFS::run(){
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