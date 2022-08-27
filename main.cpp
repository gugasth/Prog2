#include <iostream>
#include <queue>
#include <string>
#include <ctype.h>

using namespace std;

void separa(const string & algo, char sep, queue<string> & q){
    string x = algo;
    int pos;

    if(!algo.empty()){
        // enquanto não for o final da string
        // põe a substring de 0 até pos dentro da fila
        // remove a substring usada
        while(pos!=string::npos){
            pos = x.find(sep);
            q.push(x.substr(0,pos));
            x.erase(0,pos + 1);
        }
    }
}

bool etapa_um(string teste, string primeiro_verificador){
// Multiplica-se cada um dos 9 primeiros dígitos pela sequência decrescente de números de 10 a 2, somando-se os resultados
// Multiplica-se por 10 o resultado obtido no passo 1, e então obtém-se o restado da divisão por 11 O número obtido deve ser igual ao primeiro dígito verificador.

    int j = 10;
    int soma = 0;
    for (int i=0; i < teste.size(); i++,j--){
        soma = soma + teste[i]* j;
    }
    int resultado = (soma * 10) % 11;
    if (resultado == stoi(primeiro_verificador)){
        return true;
    } else{
        return false;
    }

}
bool etapa_dois(string teste, string primeiro_verificador, string segundo_verificador){
// Multiplica-se cada um dos 9 primeiros dígitos, e também o primeiro dígito verificador, pela sequência decrescente de números de 11 a 2, somando-se os resultados.
// Multiplica-se por 10 o resultado obtido no passo 3, e então obtém-se o restado da divisão por 11 O número obtido deve ser igual ao segundo dígito verificador.
    int j = 11;
    int soma = 0;
    for (int i=0; i < teste.size(); i++,j--){
        soma = soma + teste[i]* j;
    }
    soma = soma + (stoi(primeiro_verificador) * 2);

    int resultado = (soma * 10) % 11;
    if (resultado == stoi(segundo_verificador)){
        return true;
    } else{
        return false;
    }
}
int main(int argc, char * argv[]) {
    string cpf = argv[1];
    string somente_numeros;
    int j=0;

    // variável somente_numeros ta bugada, n ta recebendo o cpf[i]
    for (int i=0;i<cpf.size();i++){
        if (isdigit(cpf[i])){
            somente_numeros[j++] = cpf[i];
        }
    }

    queue<string>fila;
    separa(cpf, '.',fila);
    string teste = fila.front();

    string primeiro_verificador,segundo_verificador;

    if (teste.size() == 11) {
       primeiro_verificador = teste[9];
       segundo_verificador = teste[10];
       teste.erase(teste.begin()+9,teste.end()); // remove os dois verificadores

        if (etapa_um(teste, primeiro_verificador)) {
            cout << "invalido" << endl;
            return 0;
        }
        if (etapa_dois(teste,primeiro_verificador, segundo_verificador)) {
            cout << "invalido" << endl;
            return 0;
        }

    } else {
        cout << "invalido" << endl;
        return 0;
    }

    cout << argv[1] << endl;
    return 0;
}
