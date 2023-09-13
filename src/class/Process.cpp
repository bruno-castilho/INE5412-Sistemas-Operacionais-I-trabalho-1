#include "Process.h"

Process::Process(int pid, int submit_time, int necessary_time, int priority){
    this->pid = pid;
    this->submit_time = submit_time;
    this->priority = priority;
    this->state = -1; 
    this->necessary_time = necessary_time;
    this->time_exec = 0;
    this->current_time_exec = 0;
}

Process::~Process(){}

int Process::getPid(){
    return this->pid;
}

int Process::getSubmitTime(){
    return this->submit_time;
}

int Process::getStartTime(){
    return this->start_time;
}

int Process::getEndTime(){
    return this->end_time;
}

int Process::getPriority(){
    return this->priority;
}

int Process::getState(){
    return this->state;
}

int Process::getNecessaryTime(){
    return this->necessary_time;
}

int Process::getTimeExec(){
    return this->time_exec;
}

int Process::getCurrentTimeExec() {
    return this->current_time_exec;
}

Registers* Process::getRegisters(){
    return &this->registers;
}

void Process::setPid(int pid){
    this->pid = pid;
}

void Process::setStartTime(int start_time){
    this->start_time = start_time;
}

void Process::setEndTime(int end_time){
    this->end_time = end_time;
}

void Process::setState(int state){
    this->state = state;
}

void Process::setTimeExec(int time_exec){
    this->time_exec = time_exec;
}

void Process::setCurrentTimeExec(int current_time_exec){
    this->current_time_exec = current_time_exec;
}

void Process::setRegisters(Registers* registers){
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

bool Process::compareSubmitTime(Process *a, Process *b) {
    return a->getSubmitTime() < b->getSubmitTime();
}

int Process::calculateTurnaroundTime(){
    return this->end_time - this->submit_time;
}

int Process::calculateAverageWaitingTime(){
    return this->end_time - this->submit_time - this->time_exec;
}

void Process::generateRandomValuesForRegisters(mt19937_64* generator){
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

void Process::showRegisters(){
    cout << "s0 " << this->registers.s0 << endl;
    cout << "s1 " << this->registers.s1 << endl;
    cout << "s2 " << this->registers.s2 << endl;
    cout << "s3 " << this->registers.s3 << endl;
    cout << "s4 " << this->registers.s4 << endl;
    cout << "s5 " << this->registers.s5 << endl;
    cout << "SP " << this->registers.SP << endl;
    cout << "PC " << this->registers.PC << endl;
    cout << "ST " << this->registers.ST << endl;
}
