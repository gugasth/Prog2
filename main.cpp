#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {
    // abre o arquivo
    ifstream arq(argv[1]);

    // verifica se foi aberto
    if (! arq.is_open()) {
        perror("Ao abrir /etc/hosts");
        return errno;
    }

    string linha;

    // enquanto ler linha
    while (getline(arq, linha)){

        // bool verifica se encontrou a sequencia de caracteres
        bool found = linha.find(argv[2]) != string::npos;

        // se a bool for true, imprime a linha
        if (found){
            cout << linha << endl;
        }
    }

    return 0;
}
