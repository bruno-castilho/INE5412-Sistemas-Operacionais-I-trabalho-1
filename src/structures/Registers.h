#ifndef Registers_H
#define Registers_H

#include <stdint.h>

// Registradores de 64 bits 
struct Registers {
    uint64_t s0;
    uint64_t s1;
    uint64_t s2;
    uint64_t s3;
    uint64_t s4;
    uint64_t s5;
    uint64_t SP;
    uint64_t PC;
    uint64_t ST;
};

#endif
