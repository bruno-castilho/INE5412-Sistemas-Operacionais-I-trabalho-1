#ifndef FCFS_H
#define FCFS_H

#include "Scheduling.h"

// Classe que simula um escalonador do tipo FCFS (First Come, First Served).
class FCFS : public Scheduling{    
    private:
        // Busca processo com $submit_time igual a $current_time e o coloca no fim da fila de prontos.
        void findNewProcesses();   

    public:
        FCFS(vector<Process *> processes_read);

        // Executa.
        void run();
};

#endif