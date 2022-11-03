#include "sistema.h"

/* Função separa- Separa paralavras de uma linha delimitadas por um caractere,
 * e retorna uma lista com as palavras.
*/
vector<string> separa(const string &algo, char sep) {
    int pos1 = 0;
    vector<string> fila;

    while (pos1 < algo.size()) {
        int pos2 = algo.find(sep, pos1);
        if (pos2 == string::npos) {
            fila.push_back(algo.substr(pos1));
            break;
        }
        else {
            fila.push_back(algo.substr(pos1, pos2 - pos1));
        }
        pos1 = pos2 + 1;
    }
    return fila;
}

// função media normal, vai retirar valores da struct separadora e retornar a media deles
vector<separa_Data_valor> media(int intervalo, const vector<separa_Data_valor> &vetor){
    float total = 0;
    int i = 0, j = 0, k = -1;
    vector<separa_Data_valor>media;
    separa_Data_valor media_simples;

    // percorre a linha de dados do arquivo e vai fazendo o somatório de valores
    while (media.size() < vetor.size()-intervalo + 1) {
        for (int cont = i; cont < intervalo + i; cont++) {
            total += vetor[cont].valor;
        }

        // adiciona ao vetor a data mais recente usada no cálculo da média além da
        // divisão do somatório dos valores pelo intervalo
        string aux = vetor[intervalo+k].data;
        media_simples.data = aux;
        media_simples.valor = (total/intervalo);
        media.push_back(media_simples);
        total = 0;
        i = j + 1;
        j++, k++;
    }
    return media;
}

vector<separa_Data_valor> media_ponderada(int intervalo, const vector<separa_Data_valor> &vetor){
    float total = 0;
    int i = 0, j = 0, k = -1;
    int soma_pesos = 0;
    vector<separa_Data_valor> media;
    separa_Data_valor media_ponderada;
    int peso = 1;

    // percorre a linha de dados do arquivo e vai fazendo o somatório dos valores multiplicados pelos pesos
    // sendo que o peso inicia em 1 e é incrementado a cada linha dentro do intervalo
    // o somatório de pesos vai recebendo todos os valores de pesos
    while (media.size() < vetor.size()-intervalo + 1) {
        for (int cont = i; cont < intervalo + i; cont++) {
            total += vetor[cont].valor*peso;
            soma_pesos += peso;
            peso++;
        }
        // adiciona ao vetor a data mais recente usada no cálculo da média além da
        // divisão do somatório 'total' pela soma dos pesos


        string aux = vetor[intervalo+k].data;
        media_ponderada.data = aux;
        media_ponderada.valor = total/soma_pesos;
        media.push_back(media_ponderada);
        // depois do cálculo da média esse peso volta pro valor 1 e fica pronto pra recomeçar
        // junto com a somatória dos pesos que volta ao valor 0 e fica pronta pro próximo cálculo de média

        total = 0;
        i = j + 1;
        j++, k++;
        peso = 1;
        soma_pesos = 0;
    }
    return media;
}