#include <iostream>
using namespace std;

class No {
public:
    int info;
    No* prox;

    No(int valor) {
        info = valor;
        prox = NULL;
    }
};

class Vetor {
private:
    No* inicio;

public:
    Vetor() {
        inicio = NULL;
    }

    int Tamanho() {
        int cont = 0;
        No* aux = inicio;
        while (aux != NULL) {
            cont++;
            aux = aux->prox;
        }
        return cont;
    }

    void Append(int valor) {
        No* novo = new No(valor);

        if (inicio == NULL) {
            inicio = novo;
            return;
        }

        No* aux = inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    void InserePos(int valor, int pos) {
        if (pos < 0 || pos > Tamanho()) {
            cout << "Posicao invalida\n";
            return;
        }

        No* novo = new No(valor);

        if (pos == 0) {
            novo->prox = inicio;
            inicio = novo;
            return;
        }

        No* aux = inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    void Retira(int valor) {
        if (inicio == NULL) return;

        if (inicio->info == valor) {
            No* temp = inicio;
            inicio = inicio->prox;
            delete temp;
            return;
        }

        No* aux = inicio;
        while (aux->prox != NULL && aux->prox->info != valor) {
            aux = aux->prox;
        }

        if (aux->prox != NULL) {
            No* temp = aux->prox;
            aux->prox = temp->prox;
            delete temp;
        } else {
            cout << "Valor nao encontrado\n";
        }
    }

    void Ordena() {
        for (No* i = inicio; i != NULL; i = i->prox) {
            for (No* j = i->prox; j != NULL; j = j->prox) {
                if (i->info > j->info) {
                    int t = i->info;
                    i->info = j->info;
                    j->info = t;
                }
            }
        }
    }

    void Imprime() {
        No* aux = inicio;
        while (aux != NULL) {
            cout << aux->info << " ";
            aux = aux->prox;
        }
        cout << endl;
    }
};

int main() {
    Vetor v;
    int op;

    do {
        cout << "\n1 Append\n2 Inserir\n3 Remover\n4 Imprimir\n5 Ordenar\n6 Tamanho\n0 Sair\n";
        cout << "Opcao: ";
        cin >> op;

        int valor, pos;

        switch (op) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                v.Append(valor);
                break;

            case 2:
                cout << "Valor e posicao: ";
                cin >> valor >> pos;
                v.InserePos(valor, pos);
                break;

            case 3:
                cout << "Valor: ";
                cin >> valor;
                v.Retira(valor);
                break;

            case 4:
                v.Imprime();
                break;

            case 5:
                v.Ordena();
                cout << "Ordenado\n";
                break;

            case 6:
                cout << "Tamanho: " << v.Tamanho() << endl;
                break;
        }

    } while (op != 0);

    return 0;
}
