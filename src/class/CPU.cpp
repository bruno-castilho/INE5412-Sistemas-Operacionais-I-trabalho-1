#include "CPU.h"

CPU::CPU(){}

CPU::~CPU(){}

Registers* CPU::getRegisters(){
    return &this->registers;
}


void CPU::setRegisters(Registers* registers){
    this->registers.s0  =  registers->s0;
    this->registers.s1  =  registers->s1;
    this->registers.s2  =  registers->s2;
    this->registers.s3  =  registers->s3;
    this->registers.s4  =  registers->s4;
    this->registers.s5  =  registers->s5;
    this->registers.SP  =  registers->SP;
    this->registers.PC  =  registers->PC;
    this->registers.ST  =  registers->ST;
}

void CPU::changeRegisters(mt19937_64* generator){
    this->registers.s0 = (*generator)();
    this->registers.s1 = (*generator)();
    this->registers.s2 = (*generator)();
    this->registers.s3 = (*generator)();
    this->registers.s4 = (*generator)();
    this->registers.s5 = (*generator)();
    this->registers.SP = (*generator)();
    this->registers.PC = (*generator)();
    this->registers.ST = (*generator)();
}