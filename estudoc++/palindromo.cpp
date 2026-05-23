#include <iostream>
#include <string>

using namespace std;

class Verificador {
private:
    char pilha[100];
    char fila[100];

    int topo;
    int ini;
    int fim;

public:
    Verificador() {
        topo = -1;
        ini = 0;
        fim = 0;
    }

    void inserir(string palavra) {
        for (int i = 0; i < palavra.size(); i++) {
            pilha[++topo] = palavra[i];
            fila[fim++] = palavra[i];
        }
    }

    int verificar() {
        while (topo >= 0 && ini < fim) {
            if (pilha[topo--] != fila[ini++]) {
                return 0;
            }
        }
        return 1;
    }
};

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    Verificador v;

    v.inserir(palavra);

    if (v.verificar() == 1)
        cout << "É palindromo\n";
    else
        cout << "Não é palindromo\n";

    return 0;
}