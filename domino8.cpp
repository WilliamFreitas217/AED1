#include <iostream>
using namespace std;

class Pedra{
public:
  int esq, dir;
  Pedra();
  void print();
};

Pedra::Pedra(){}

void Pedra::print(){
  cout<<"["<<esq<<"|"<<dir<<"]"<<endl;
}

void print(Pedra *pedra, int tam){
  for(int i = 0;i<tam;i++){
    pedra[i].print();
  }
}

int main(){
  int TAM = 1;
  Pedra pedra[TAM];
  pedra[0].esq = 2;
  pedra[0].dir = 5;
  print(pedra,TAM);
  return 0;
}
