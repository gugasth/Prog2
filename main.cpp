#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
int main() {
    string palavra;
    cin >> palavra;

    for (int i=0; i<palavra.size(); i++ ){
        palavra[i] = toupper(palavra[i]);
    }
    cout << palavra << endl;
}
