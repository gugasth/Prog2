#include <iostream>

using namespace std;
int main() {
    string frase_normal;
    cin >> frase_normal;

    int i=0, j = frase_normal.size()-1;

    for (; i < j; i++, j--){
        auto aux = frase_normal[i];
        frase_normal[i] = frase_normal[j];
        frase_normal[j] = aux;
    }
    cout << frase_normal;
    return 0;
}
