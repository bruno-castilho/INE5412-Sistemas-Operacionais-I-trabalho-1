#ifndef ByPriority_H
#define ByPriority_H

#include "Scheduling.h"

// Classe que simula um escalonador do tipo por prioridade.
class ByPriority : public Scheduling{    
    private:
        // Busca processo com $submit_time igual a $current_time e o coloca na fila de prontos na posição de sua prioridade.
        void findNewProcesses(); 

        // Faz preempção do processo em execução.
        void preemption();
        
    public:
        ByPriority(vector<Process *> processes_read);

        // Executa sem preempção.
        void runNoPreemptive();

        // Executa com preempção.
        void runPreemptive();
};

#endif