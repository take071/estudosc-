#include <iostream>
using namespace std;
 struct Pilha{
  int itens[5];
  int topo;};

 void push (Pilha &p, int valor){
    if(p.topo < 4){
    p.topo++; 
     p.itens[p.topo]=valor;
     cout << "entrando: " << valor << "\n";
  }
 }
 void pop(Pilha &p){
  if(p.topo >= 0){
  cout << "saindo: " << p.itens[p.topo] << "\n";
  p.topo--; }
 }
 
int main(){
 Pilha minhaPilha;
  minhaPilha.topo = -1;
 
  push(minhaPilha, 10); 
  push(minhaPilha, 20);
  push(minhaPilha, 30);
  push(minhaPilha, 40);
 
  cout<<"--- removendo --- \n";

 pop(minhaPilha);
 pop(minhaPilha);
  return 0;
 }
