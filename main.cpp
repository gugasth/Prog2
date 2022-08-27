#include <iostream>
#include <queue>
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


int main(int argc, char * argv[]) {
    string data = argv[1];
    int conta_barra = 0;



    for (int i=0; i < data.size(); i++){
        if (data[i] == '/'){
        conta_barra++;
        if (!isdigit(i-1) && isdigit(i+1)){
            conta_barra = conta_barra + 999;
            break;
        }
        }
    }
    // primeiro teste de data invalida
    if (conta_barra != 2){
        cout << "data invalida";
        return 0;
    }

    // cria uma fila e separa o dia, mês e ano nessa fila
    queue<string>fila;
    separa(data, '/', fila);

    // atribui as informações da fila nas variáveis inteiras e inicia o loop de verificação de erros
    int dia = stoi(fila.front());
    fila.pop();

    int mes = stoi(fila.front());
    fila.pop();

    int ano = stoi(fila.front());
    fila.pop();


    // se o dia for maior que o dia 31 ele não existe, então exibe a mensagem de data invalida
    if (dia > 31){
        cout << "data invalida" << endl;
        return 0;
    }
    // se o mês for maior que o mês 12 ele não existe, então exibe a mensagem de data invalida
    if (mes > 12){
        cout << "data invalida" << endl;
        return 0;
    }
    // se o ano for maior que o ano de 2050 ele não existe (ou pelo menos ta muuuito longe)
    //  então exibe a mensagem de data invalida
    if (ano > 2050){
        cout << "data invalida" << endl;
        return 0;
    }

    cout << data << endl;
    return 0;
}
