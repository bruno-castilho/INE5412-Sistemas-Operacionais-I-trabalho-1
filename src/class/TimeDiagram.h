#ifndef TimeDiagram_H
#define TimeDiagram_H

#include <iostream>
#include <vector>
#include <string>
#include "Process.h"

using namespace std;

// Diagrama de Tempo de Execução.
class TimeDiagram {
    private:
        vector<vector<string> > progress; // Matriz de marcação de progresso dos processos.
        int n_process; // Número total de processos que serão executados (lidos).

    public:
        // Construtor.
        TimeDiagram(int col);
        ~TimeDiagram();

        // Adiciona o progresso atual dos processos na matriz.
        void addProgress(Process* running_process, vector<Process *> ready_processes);

        // Imprime Diagrama de Tempo de Execução.
        void print();
};

#endif