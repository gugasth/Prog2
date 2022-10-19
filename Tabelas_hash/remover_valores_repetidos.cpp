#include <iostream>
#include <fstream>
#include <unordered_set>
#include <list>

using namespace std;

int main(int argc, char * argv[]) {
    ifstream arq(argv[1]);

    unordered_set<string>conjunto;
    list<string>lista;

    string linha;
    while(getline(arq, linha)){
        lista.push_back(linha);
    }

    for (auto & dado: lista){
        conjunto.insert(dado);
    }

    lista.clear();

    for (auto & dado: conjunto){
        lista.push_back(dado);
    }

    lista.sort();
    
    for (auto & dado: lista){
        cout << dado << " ";
    }

    return 0;
}
