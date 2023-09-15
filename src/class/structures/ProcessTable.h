#ifndef ProcessTable_H
#define ProcessTable_H

#include <iostream>
#include <vector>
#include "../Process.h"

using namespace std;

class ProcessTable {
    public:
        vector<Process *> ready_processes; // Fila de processos prontos.
        vector<Process *> finished_processes; // Lista de processos finalizados.
        Process* running_process = NULL; // Processo em execução.
};

#endif