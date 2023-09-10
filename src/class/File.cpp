#include "File.h"

File::File(string filename="entrada.txt"){
    this->filename=filename;
}

vector<Process *> File::read(){
    vector<Process *> processes_read;

    // Abre arquivo.
    ifstream myfile; 

    myfile.open(this->filename);
    if (!myfile.is_open()) {
		cout << "Erro ao abrir o arquivo!\n";
        return processes_read;
	}


    int a, b, c;

    // Para cada linha do arquivo.
    while (myfile >> a >> b >> c) {
        // Instancia um novo processo e adiciona na fila de processos lidos.
        Process *p = new Process(0, a, b, c);
        processes_read.push_back(p);
    }

    myfile.close();
    // Ordena os processos lidos em ordem de tempo de submissão.
    sort(processes_read.begin(), processes_read.end(), Process::compareSubmitTime);

    // Imprime quantidade de processos lidos.
    cout << "Quantidade de processos lidos do arquivo: " << processes_read.size() << endl;

    return processes_read;

}