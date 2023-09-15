#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <iostream>
#include <vector>
#include <random>

#include "../structures/ProcessTable.h"
#include "../Process.h"
#include "../TimeDiagram.h"
#include "../CPU.h"

using namespace std;

class Scheduling{
    private:
        CPU* INE5412; // CPU
        TimeDiagram* time_diagram; // Diagrama de tempo de execução.
        int context_switches = 0; // Contagem de troca de contexto feitas no processador.

    protected:
        // Gerador de números aleatórios.
        random_device rd; 
        mt19937_64 generator; 
        int current_time; // Tempo de execução.
        int pid_cout; // Contador de processos.
        vector<Process *> processes_read; // Fila de processos lidos.
        ProcessTable process_table; // Tabela de processos.

        // Faz a seleção de um processo pronto.
        void selection();
        
        // Faz preempção do processo em execução.
        void preemption();

        // Encerra o processo em execução.
        void end();

        // Avança o tempo.
        void passTime();

    public:
        // Construtor
        Scheduling(vector<Process *> processes_read);

        // Destrutor
        ~Scheduling();

        // Apresenta os resultados.
        void showResults();   
};

#endif