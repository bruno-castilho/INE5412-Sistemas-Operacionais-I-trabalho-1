#include "Scheduling.h"

Scheduling::Scheduling(vector<Process *> processes_read){
    mt19937_64 generator(rd());
    this->INE5412 = new CPU();
    this->time_diagram = new TimeDiagram(processes_read.size());
    this->current_time = 0;
    this->pid_cout = 1;

    // Cria uma cópia dos processos e adiciona em {this->processes_read}.
    for (Process *p : processes_read) {
        Process *p_copy = new Process(*p);
        this->processes_read.push_back(p_copy);
}
}


Scheduling::~Scheduling(){
    delete this->INE5412;
    delete this->time_diagram;
    this->processes_read.clear();
    this->process_table.ready_processes.clear();
    this->process_table.finished_processes.clear();
}

void Scheduling::selection(){
    // Coloca o próximo processo da fila de processos prontos em execução.
    this->process_table.running_process = this->process_table.ready_processes[0];
    this->process_table.running_process->setState(2);
    if(this->process_table.running_process->getStartTime()) this->process_table.running_process->setStartTime(current_time);
    this->process_table.ready_processes.erase(this->process_table.ready_processes.begin());

    // Troca o contexto do processor para o novo processo.
    this->INE5412->setRegisters(this->process_table.running_process->getRegisters());
    this->context_switches++ ;

    // Descomente o trecho abaixo para visualizar os valores dos registradores.
    // cout << "Seleção P" <<  this->process_table.running_process->getPid() << endl;
    // this->process_table.running_process->showRegisters();
    // cout << "INE5412" << endl;
    // this->INE5412->showRegisters();
}

void Scheduling::preemption(){
    // Salva contexto atual do processo na cpu.
    this->process_table.running_process->setRegisters(this->INE5412->getRegisters());

    // Descomente o trecho abaixo para visualizar os valores dos registradores.
    // cout << "Preempção P" <<  this->process_table.running_process->getPid() << endl;
    // this->process_table.running_process->showRegisters();
    // cout << "INE5412" << endl;
    // this->INE5412->showRegisters();

    // Zera o current_time_exec do processo.
    this->process_table.running_process->setCurrentTimeExec(0);
    
    // Coloca processo em execução no fim da fila de prontos.
    this->process_table.running_process->setState(1);
    this->process_table.ready_processes.push_back(this->process_table.running_process);

    this->process_table.running_process = nullptr;
}

void Scheduling::end(){
    // Marca tempo em que o processo foi finalizado.
    this->process_table.running_process->setEndTime(current_time); 

    // Zera o current_time_exec do processo.
    this->process_table.running_process->setCurrentTimeExec(0);
    
    // Finaliza o processo.
    this->process_table.running_process->setState(3);
    this->process_table.finished_processes.push_back(this->process_table.running_process);
    this->process_table.running_process = nullptr;
}

void Scheduling::passTime(){
    if (this->process_table.running_process){
        // Incrementa o tempo de execução do processo em execução.
        int time_exec = this->process_table.running_process->getTimeExec();
        time_exec = time_exec + 1;
        this->process_table.running_process->setTimeExec(time_exec);

        // Incrementa o tempo atual de execução do processo atual.
        int current_time_exec = this->process_table.running_process->getCurrentTimeExec();
        current_time_exec = current_time_exec + 1;
        this->process_table.running_process->setCurrentTimeExec(current_time_exec);
    } 

    // Incrementa o tempo.
    this->current_time += 1;

    // Adiciona o progresso dos processos na tabela.
    this->time_diagram->addProgress(this->process_table.running_process, this->process_table.ready_processes);

    // Troca os valores dos registradores da CPU.
    this->INE5412->changeRegisters(&this->generator);
}

void Scheduling::showResults(){
    // Imprime diagrama de tempo.
    this->time_diagram->print();

    // Imprime cálculos.
    int sum_TurnaroundTime = 0; 
    int n_finished_processes = this->process_table.finished_processes.size();

    for (int i = 0; i < n_finished_processes; i++) {
        Process *p = this->process_table.finished_processes[i];
        int TurnaroundTime = p->calculateTurnaroundTime();
        int AverageWaitingTime = p->calculateAverageWaitingTime();
        sum_TurnaroundTime = sum_TurnaroundTime + TurnaroundTime;
        cout << "P" << p->getPid();
        cout << " "  << "Tempo de retorno: "  << TurnaroundTime;
        cout << "\t"  << "Tempo médio de espera: " << AverageWaitingTime;
        cout << endl;

    }

    cout << "Tempo médio de retorno: " << static_cast<float>(sum_TurnaroundTime)/n_finished_processes  << endl;
    cout << "Total de trocas de contexto: " << this->context_switches << endl;
}

