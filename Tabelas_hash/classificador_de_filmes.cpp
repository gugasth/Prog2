#include "questao.h"

void sumariza(const unordered_map<string,Categoria> & filmes, unordered_map<Categoria,int> & sumario){
    // recebo uma tabela que a chave é nome do filme, e valor é a classificação

    int quantidade=1;

        for (auto &pair: filmes) {
            // Se já tem a classificação no sumário, então:
            if (sumario.count(pair.second) > 0) {
                // incremento a quantidade de vezes que a classificação apareceu
                sumario[pair.second]++;
            } else {
                // Se a categoria acabou de surgir no sumário, então:
                sumario.emplace(pair.second, quantidade);
            }
        }


    // retorno uma tabela que a chave é a classificação, e o valor é quantidade dessa classificação
}
