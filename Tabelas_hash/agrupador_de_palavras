#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <list>
#include <errno.h>
using namespace std;

int main (int argc, char * argv[]) {
    ifstream arq(argv[1]);

    if (!arq.is_open()){
        cout << "arquivo invalido" << endl;
    }


    list<string> lista;
    unordered_map<int,list<string>> tab;
    string palavra;

    while (arq >> palavra) {

        // usa o comprimento como chave pra adicionar a palavra na lista
        tab[palavra.size()].push_back(palavra);
    }

    list<int> lista_chaves;

    // adiciono todas as chaves em uma lista de chaves
    for (auto & par: tab){
        lista_chaves.push_back(par.first);
    }
    // ordeno a lista de chaves
    lista_chaves.sort();

    // para cada chave na lista de chaves
    for(auto & chave: lista_chaves){

        for (auto & palavra: tab[chave]){
            cout << palavra << ' ';
        }
        cout << endl;
    }
}
