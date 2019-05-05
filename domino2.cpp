#include <iostream>
using namespace std;

class Pedra{
public:
	int esq, dir;
	Pedra();
  void print(*Pedra);
};

Pedra::Pedra(){}
void Pedra::print(*Pedra){
  cout << "["<< pedra.esq <<"|"<<pedra.dir<<"]"<<endl;
}

int main (){
	Pedra *pedra = new Pedra();
	pedra->esq = 2;
	pedra->dir = 5;
  pedra->print(&pedra);
	//cout << "["<< pedra->esq <<"|"<<pedra->dir<<"]"<<endl;
	return 0;
}
