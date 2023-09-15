#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "class/File.h"

#include "class/scheduling/FCFS.h"
#include "class/scheduling/SJF.h"
#include "class/scheduling/RoundRobin.h"
#include "class/scheduling/ByPriority.h"


using namespace std;


int main(int argc, char *argv[])
{    
     if (argc != 2) {
        cout << "Arquivo de entrada não informado!" << endl;
        return 1; 
     }

     string filename = argv[1];

     File f(filename);
     vector<Process *> processes_read = f.read();

     if (processes_read.size() != 0){
          cout << "ESCALONADOR FCFS (First Come, First Served)" << endl;
          FCFS fcfs(processes_read);
          fcfs.run();
          fcfs.showResults();
          cout << endl;

          cout << "ESCALONADOR Shortest Job First" << endl;
          SJF sjf(processes_read);
          sjf.run();
          sjf.showResults();
          cout << endl;

          cout << "ESCALONADOR Por prioridade, sem preempção" << endl;
          ByPriority by_priority(processes_read);
          by_priority.runNoPreemptive();
          by_priority.showResults();
          cout << endl;

          cout << "ESCALONADOR Por prioridade, com preempção" << endl;
          ByPriority by_priority_p(processes_read);
          by_priority_p.runPreemptive();
          by_priority_p.showResults();
          cout << endl;

          cout << "ESCALONADOR Round-Robin com quantum = 2s, sem prioridade" << endl;
          RoundRobin round_robin(processes_read);
          round_robin.run();
          round_robin.showResults();


          for(vector<Process*>::size_type i = 0; i < processes_read.size() ; i++) {
               Process *p = processes_read[i];
               delete p;
          }
     }


}