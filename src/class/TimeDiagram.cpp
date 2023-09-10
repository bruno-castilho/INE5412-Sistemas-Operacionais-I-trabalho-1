#include "TimeDiagram.h"

TimeDiagram::TimeDiagram(int n_process){
    this->n_process = n_process;
}

TimeDiagram::~TimeDiagram(){
    this->progress.clear();
}

void TimeDiagram::addProgress(Process* running_process, vector<Process *> ready_processes){
    // Gera um vetor com uma string (" ") por posição para cada processo existente (n_process).
    vector<string> new_row;

    for(int i = 0; i < this->n_process; i++){
        new_row.push_back(" ");
    }

    // Se houver processo em execução, adiciona na posição (pid - 1) da nova linha a string ('#').
    if(running_process) new_row[running_process->getPid() -1] = "#";
    
    // Para cada processo na fila de prontos.
    for(vector<Process*>::size_type i = 0; i < ready_processes.size(); i++){
        // Adiciona a string ("-") na posição (pid - 1) da nova linha.
        Process *p = ready_processes[i];
        new_row[p->getPid() -1] = "-";
    }

    // Adiciona a nova linha na matriz de progresso dos processos.
    this->progress.push_back(new_row);
}


void TimeDiagram::print(){
    // Imprime cabeçalho.
    cout << "tempo";
    for(int i = 0; i < this->n_process; i++){
        cout << "\t" << "P" << i + 1;
    }

    cout << endl;
    
    // Imprime resultados.
    for(vector<vector<string> >::size_type i = 0; i < this->progress.size(); i++){
        cout << i << "-" << i + 1;
        for(vector<string>::size_type j = 0; j < this->progress[i].size(); j++){
            cout << "\t" << this->progress[i][j];
        }
        cout << endl;
    }

}