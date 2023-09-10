#ifndef SJF_H
#define SJF_H

#include "Scheduling.h"

// Classe que simula um escalonador do tipo Shortest Job First.
class SJF : public Scheduling{    
    private:
        
        /* Busca processo com $submit_time igual a $current_time e o coloca na fila
        de prontos na posição de sua prioridade (Menor tempo de execução).*/
        void findNewProcesses(); 
        
    public:
        SJF(vector<Process *> processes_read);

        // Executa.
        void run();
};

#endif