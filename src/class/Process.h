#ifndef Process_H
#define Process_H
#include "../structures/Registers.h"
#include <iostream>
#include <random>
#include <stdint.h>
#include <cstdint>

using namespace std;

class Process{
    private:
        int pid; // Pid do processo.
        int submit_time; // Tempo de submissão.
        int start_time; // Tempo de inicialização.
        int end_time; // Tempo de encerramento.
        int priority; // Prioridade.
        int necessary_time; // Tempo necessário para execução.
        int time_exec; // Tempo total executado.
        int current_time_exec; // Tempo executado a partir do momento em que vai para o estado Executando.
        Registers registers; // Registradores.
        
        int state;       /*
                        Estado do processo
                            {
                                -1: Processo ainda não foi submetido.
                                0 : Criado
                                1 : Pronto, 
                                2 : Executando, 
                                3 : Bloqueado, 
                                4 : Terminado
                            }
                        */
        


    public:
        // Construtor.
        Process(int pid, int submit_time, int priority, int necessary_time);

        // Destrutor.
        ~Process();
        
        // Get
        int getPid();
        int getSubmitTime();
        int getStartTime();
        int getEndTime();
        int getPriority();
        int getState();
        int getNecessaryTime();
        int getTimeExec();
        int getCurrentTimeExec();
        Registers* getRegisters();

        
        // Set
        void setPid(int pid);
        void setStartTime(int start_time);
        void setEndTime(int end_time);
        void setState(int state);
        void setTimeExec(int time_exec);
        void setCurrentTimeExec(int current_time_exec);
        void setRegisters(Registers* registers);

        // Verifica se processo a < processo b.
        static bool compareSubmitTime(Process *a, Process *b);

        // Calcula o tempo de resposta (Turnaround time).
        int calculateTurnaroundTime();

        // Calcula o tempo médio de espera.
        int calculateAverageWaitingTime();

        // Gera valores aleatórios para os registradores.
        void generateRandomValuesForRegisters(mt19937_64* generator);
};

#endif

