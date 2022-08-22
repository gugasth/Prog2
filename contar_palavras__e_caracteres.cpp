#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int main() {
    int contador_palavras=0;
    string frase;
    getline(cin, frase);

    for (int i=0; i<frase.size(); i++){
        if ((frase[i]) != ' '){
            if (frase[i+1] == ' '){
                contador_palavras++;
            }
        }
    }

    // Considera a última palavra que o loop principal (for) não considera, apenas caso ela exista
    if (! frase.empty()){
         contador_palavras ++;
    }


    cout << (contador_palavras) << " " << frase.size() << endl;

}
