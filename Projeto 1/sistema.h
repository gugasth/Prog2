//
// Created by Guga on 02/10/2022.
//

#ifndef PROJETO_BRUNO_GABRIEL_GUSTAVO_SISTEMA_H
#define PROJETO_BRUNO_GABRIEL_GUSTAVO_SISTEMA_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

//valores da tabela são separados e salvos em strings diferentes
struct separa_Data_valor{
    string data;
    float valor;
};

// Função que separa uma string em várias substrings com base em um caracter delimitador
// recebe a string a ser separada e o caracter delimitador como parametros e retorna um vetor
vector<string> separa(const string &algo, char sep);

// Função que realiza o cálculo da média simples e retorna um vetor pronto pra ser impresso com as informações da data mais recente usada no cálculo da média. Além da média calculada.
// Recebe como parametros o intervalo que o usuário quer usar no cálculo, a struct separadora e o vetor do tipo separadora.
vector<separa_Data_valor> media(int intervalo, const vector<separa_Data_valor> &vetor);

// Função que realiza o cálculo da média ponderada e retorna um vetor pronto pra ser impresso com as informações da data mais recente usada no cálculo da média. Além da média calculada.
// Recebe como parametros o intervalo que o usuário quer usar no cálculo, a struct separadora e o vetor do tipo separadora.
vector<separa_Data_valor> media_ponderada(int intervalo, const vector<separa_Data_valor> &vetor);

#endif //PROJETO_BRUNO_GABRIEL_GUSTAVO_SISTEMA_H
