#include <iostream>
using namespace std;
class No{
public:
  int valor;
  No* proximo;

   No(int novoValor){
    valor = novoValor;
    proximo = nullptr;
    }
};

 class ListaEncadeada{
  private: No* cabeca;

public: 
 ListaEncadeada(){
   cabeca = nullptr;}

void inserir(int valor){
No* novoNo = new No(valor);
 novoNo->proximo = cabeca;
  cabeca = novoNo;}
   
   void exibir(){
   No* atual = cabeca;
   while(atual != nullptr){
    cout << atual-> valor<<"->";
    atual = atual->proximo;
      }
     cout<<"NULL"<< endl;
     }
  };

   int main(){

   ListaEncadeada minhaL;

 minhaL.inserir(10);
 minhaL.inserir(20);
 minhaL.inserir(30);

  cout<<"conteudo da lista: ";
  minhaL.exibir();

   return 0;
}

