#ifndef CPU_H
#define CPU_H
#include "../structures/Registers.h"
#include <iostream>
#include <random>
#include <stdint.h>
#include <cstdint>

using namespace std;

class CPU{
    private:
        Registers registers; // Registradores da CPU.

    public:
        // Construtor
        CPU();

        // Destrutor
        ~CPU();

        // Altera os registradores para valores aleatórios.
        void changeRegisters(mt19937_64* generator);

        // Get
        Registers* getRegisters();
        
        // Set
        void setRegisters(Registers* registers);
};

#endif