#include <iostream>
using namespace std;

class Pedra{
public:
	int esq, dir;
	Pedra();
};

Pedra::Pedra(){}

int main (){
	Pedra *pedra = new Pedra();
	pedra->esq = 2;
	pedra->dir = 5;

	cout << "["<< pedra->esq <<"|"<<pedra->dir<<"]"<<endl;
	return 0;
}
