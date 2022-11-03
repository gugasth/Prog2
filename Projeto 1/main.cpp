#include <iomanip>
#include "sistema.h"

int main(int argc, char *argv[]) {
    // cria o objeto "arq" da classe "ifstream", que representa um arquivo para leitura

    // a criação desse objeto já abre o arquivo
    ifstream arq(argv[1]);

    // verifica se o arquivo foi de fato aberto
    if (!arq.is_open()) {
        perror("Erro ao abrir arquivo");
        return errno;
    }

    string linha;
    //criado uma variavel valores que é do tipo struct separadora ,para receber valores e salvar em um vector

    separa_Data_valor valores;
    // referencia o struct do sistema.h

    //vector salvo recebe valores da função separa
    vector<string> salvo;

    //vector structSalva salva a struct inteira já com valores
    vector<separa_Data_valor> structSalva;

    int contador_linhas = 0;
    // conta quantas linhas/argumentos tem no arquivo, pois argumentos estão 1 pra 1 em linhas

    // variável inteira recebe o tamanho do intervalo da média a ser calculada
    int intervalo = stoi(argv[2]);

    while (getline(arq, linha)) {
        contador_linhas ++;

        //salvo recebe valores da função separa
        salvo = separa(linha,' ');

        //o valor recebido é separado e encaminhado para a variavel na struct correspondente
        valores.data = salvo[0];
        valores.valor = stod(salvo[1]);
        //a os valores data e valor  são salvos em um vector
        structSalva.push_back(valores);
    }
    // verifica se é possivel realizar a operação com os dados fornecidos
    if (intervalo > contador_linhas){
        cout << "O numero do periodo de tempo escolhido, foi maior que a quantidade de dados existentes no arquivo.txt." << endl;
        return 0;
    }
    // variável string recebe o tipo de média: mmp ou mms do terceiro argumento da linha de comando
    string tipo_media;
    // verifica caso o tipo de media não exista
    if (argc == 3) {
        tipo_media = "mms";
    }
    if(argc == 4) {
        tipo_media = argv[3];
    }

    // transforma em minúscula, pra caso o usuário tenha digitado em maiuscula não ter nenhum problema
    for (int i=0; i < tipo_media.size(); i++){
        tipo_media[i] = tolower(tipo_media[i]);
    }

    // Se o usuário escolheu mms, então faz o cálculo da mesma e apresenta os resultados
    // Se o usuário escolheu mmp, então faz o cálculo da mesma e apresenta os resultados
    // Se não escolheu nenhum dos dois, então emite um alerta de erro
    if (tipo_media == "mms") {
        vector<separa_Data_valor> mms;
        mms = media(intervalo,structSalva);
        for (auto &dado:mms) {
            cout << dado.data << " " << setprecision(4) << dado.valor << endl;
        }

    } else if (tipo_media == "mmp"){
        vector<separa_Data_valor> mmp;
        mmp = media_ponderada(intervalo,structSalva);
        for (auto &dado:mmp){
            cout << dado.data << " " << setprecision(4) << dado.valor << endl;
        }
    } else {
        cout << "Terceiro argumento invalido" << endl;
        cout << "Insira mmp ou mms" << endl;
    }
    return 0;
}