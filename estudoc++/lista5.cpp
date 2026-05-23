#include <iostream>
#include <string>

using namespace std;

struct No {
    string palavra;
    No *ant;
    No *prox;
};

No* criarNo(string palavra) {
    No *novo = new No;
    novo->palavra = palavra;
    novo->ant = novo;
    novo->prox = novo;
    return novo;
}

void inserirDepois(No **atual, string novaPalavra) {
    No *novo = criarNo(novaPalavra);
    if (*atual == NULL) {
        *atual = novo;
    } else {
        No *proximo = (*atual)->prox;
        novo->prox = proximo;
        novo->ant = *atual;
        (*atual)->prox = novo;
        proximo->ant = novo;
    }
}

void removerAtual(No **atual) {
    if (*atual == NULL) return;
    No *noRemover = *atual;
    if (noRemover->prox == noRemover) {
        *atual = NULL;
    } else {
        No *anterior = noRemover->ant;
        No *proximo = noRemover->prox;
        anterior->prox = proximo;
        proximo->ant = anterior;
        *atual = proximo;
    }
    delete noRemover;
}

void exibirInterface(No *inicio, No *atual) {
    system("clear || cls");
    cout << "FRASE: ";
    if (inicio != NULL) {
        No *temp = inicio;
        do {
            cout << temp->palavra << " ";
            temp = temp->prox;
        } while (temp != inicio);
    }
    cout << "\n--------------------------------" << endl;
    if (atual != NULL) {
        cout << "Palavra atual: " << atual->palavra << endl;
    } else {
        cout << "Lista vazia." << endl;
    }
    cout << "\nC: Corrigir | I: Inserir | R: Retirar" << endl;
    cout << "<: Anterior | >: Proxima | S: Sair" << endl;
    cout << "Digite sua opcao: ";
}

int main() {
    No *atual = NULL;
    char opcao;
    string buffer;

    inserirDepois(&atual, "Estrutura");
    inserirDepois(&(atual->prox), "Dados");
    inserirDepois(&(atual->prox->prox), "I");

    do {
        exibirInterface(atual, atual);
        cin >> opcao;
        opcao = toupper(opcao);

        switch(opcao) {
            case 'C':
                if (atual) {
                    cout << "Nova palavra: ";
                    cin >> atual->palavra;
                }
                break;
            case 'I':
                cout << "Palavra a inserir: ";
                cin >> buffer;
                inserirDepois(&atual, buffer);
                break;
            case 'R':
                removerAtual(&atual);
                break;
            case '<':
                if (atual) atual = atual->ant;
                break;
            case '>':
                if (atual) atual = atual->prox;
                break;
        }
    } while (opcao != 'S');

    return 0;
}
