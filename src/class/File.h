#ifndef FILE_H
#define FILE_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

#include "Process.h"


using namespace std;

class File{
    private:
        // Path do arquivo.
        string filename;
    
    public:
        // Construtor
        File(string filename);


        /*
            Lê processo de um arquivo e coloca em uma fila de processos lidos
            em ordem de tempo de submissão de cada processo.
        */
        vector<Process *> read();
};

#endif







