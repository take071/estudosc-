#include <iostream>
using namespace std;

class Node {
public:
    int valor;
    Node* prox;

    Node(int v) {
        valor = v;
        prox = NULL;
    }
};


class Pilha {
private:
    Node* topo;

public:
    Pilha() {
        topo = NULL;
    }

    void push(int v) {
        Node* novo = new Node(v);
        novo->prox = topo;
        topo = novo;
    }

    void pop() {
        if (topo != NULL) {
            Node* temp = topo;
            topo = topo->prox;
            delete temp;
        }
    }

    int top() {
        if (topo != NULL)
            return topo->valor;
        return -1;
    }

    bool vazia() {
        return topo == NULL;
    }

    void imprimir() {
        Node* atual = topo;

        cout << "\n[TOPO] -> ";
        while (atual != NULL) {
            cout << atual->valor << " -> ";
            atual = atual->prox;
        }
        cout << "NULL\n";
    }
};

int main() {
    int opcao;

    cout << "1 - Decimal para Binario\n";
    cout << "2 - Binario para Decimal\n";
    cout << "Escolha: ";
    cin >> opcao;

    Pilha pilha;

   
    if (opcao == 1) {
        int num;

        cout << "\nDigite um numero decimal: ";
        cin >> num;

        while (num > 0) {
            int resto = num % 2;
            cout << "Empilhando resto: " << resto << endl;
            pilha.push(resto);
            num = num / 2;
        }

        cout << "\n Estado da pilha (ultimo resto fica no topo):";
        pilha.imprimir();

        cout << "\nConvertendo para binario (desempilhando): ";
        while (!pilha.vazia()) {
            cout << pilha.top();
            pilha.pop();
        }
        cout << endl;
    }

   
    else if (opcao == 2) {
        string binario;
        int decimal = 0;
        int base = 1;

        cout << "\nDigite um numero binario: ";
        cin >> binario;

        for (int i = 0; i < binario.length(); i++) {
            cout << "Empilhando digito: " << binario[i] << endl;
            pilha.push(binario[i] - '0');
        }

        cout << "\nEstado da pilha (bit menos significativo no topo):";
        pilha.imprimir();

        cout << "\nConvertendo para decimal:\n";

        while (!pilha.vazia()) {
            int valor = pilha.top();
            cout << valor << " * " << base << " = " << valor * base << endl;

            decimal += valor * base;
            pilha.pop();
            base *= 2;
        }

        cout << "\nResultado final em decimal: " << decimal << endl;
    }

    else {
        cout << "Opcao invalida!" << endl;
    }

    return 0;
}