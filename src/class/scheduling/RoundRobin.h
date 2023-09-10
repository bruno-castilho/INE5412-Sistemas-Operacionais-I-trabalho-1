#ifndef RoundRobin_H
#define RoundRobin_H

#include "Scheduling.h"

// Classe que simula um escalonador do tipo por Round-Robin.
class RoundRobin : public Scheduling{    
    private:
        int quantum; // Limite de tempo de execução por processo.
    
        // Busca processo com $submit_time igual a $current_time e o coloca no fim da fila de prontos.
        void findNewProcesses(); 
        
    public:
        RoundRobin(vector<Process *> processes_read);
        
        // Executa
        void run();
};

#endif