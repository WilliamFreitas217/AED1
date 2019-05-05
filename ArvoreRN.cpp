#include <iostream>
using namespace std;
template <class Tipo>
class No{
private:
	Tipo item;
	int cor;
	No *esq;
  No *dir;
  No *pai;
public:
	No();
	No(Tipo item);
	void setItem(Tipo item);
	void setCor(int cor);
	void setEsq(No<Tipo> * no);
  void setDir(No<Tipo> * no);
  void setPai(No<Tipo> * pai);
	Tipo getItem();
	int getCor(int cor);
	No<Tipo> *&getEsq();
  No<Tipo> *&getDir();
  No<Tipo> *&getPai();
};
template <class Tipo>
No<Tipo>::No(){
 	this->esq = NULL;
  this->dir = NULL;
}
template <class Tipo>
No<Tipo>::No(Tipo item){
	this->item = item;
	this->esq = NULL;
  this->dir = NULL;
}
template <class Tipo>
Tipo No<Tipo>::getItem(){
	return this->item;
}
template <class Tipo>
No<Tipo> *&No<Tipo>::getEsq(){
	return esq;
}
template <class Tipo>
No<Tipo> *&No<Tipo>::getDir(){
	return dir;
}
template <class Tipo>
No<Tipo> *&No<Tipo>::getPai(){
	return pai;
}
template <class Tipo>
void No<Tipo>::setCor(int cor){
	this->cor = cor;
}
template <class Tipo>
int No<Tipo>::getCor(int cor){
	return cor;
}
template <class Tipo>
void No<Tipo>::setItem(Tipo item){
	this->item = item;
}
template <class Tipo>
void No<Tipo>::setEsq(No<Tipo> *no){
	this->esq = no;
}
template <class Tipo>
void No<Tipo>::setDir(No<Tipo> *no){
	this->dir = no;
}
template <class Tipo>
void No<Tipo>::setPai(No<Tipo> * pai){
  this->pai = pai;
}
template <class Tipo>
class ABBRN{
private:
	No<Tipo> *raiz;
public:
	No<Tipo>* RN_BUSCA(Tipo chave, No<Tipo> *p);
	void rodaEsq(No<Tipo> *&x);
	void rodaDir(No<Tipo> *&x);
};
template <class Tipo>
No<Tipo>* ABBRN<Tipo>::RN_BUSCA(Tipo chave, No<Tipo> *p){
	if(p == NULL || chave == p->getItem().getChave()){
		return p;
	}
	else if(chave<p->getItem().getChave()){
		return RN_BUSCA(chave, p->getEsq());
	}
	else{
		return RN_BUSCA(chave, p->getDir());
	}
}
template <class Tipo>
void ABBRN<Tipo>::rodaEsq(No<Tipo> *&x){
	No<Tipo> *y = x->getDir();
	x->setDir(y->getEsq());
	if(y->getEsq()!= NULL){
		y->getEsq()->getPai()=x;
	}
	y->getPai()=x->getPai();
	if(x->getPai()==NULL){
		this->raiz = y;
	}
	else if(x==x->getPai()->getEsq()){
		x->getPai()->getEsq()= y;
	}
	else{
		x->getPai()->getDir()=y;
	}
	y->getEsq()=x;
	x->getPai()=y;
}
template <class Tipo>
void ABBRN<Tipo>::rodaDir(No<Tipo> *&x){
	No<Tipo> *y = x->getEsq();
	x->setEsq(y->getDir());
	if(y->getDir()!= NULL){
		y->getDir()->getPai()=x;
	}
	y->getPai()=x->getPai();
	if(x->getPai()==NULL){
		this->raiz = y;
	}
	else if(x==x->getPai()->getDir()){
		x->getPai()->getDir()= y;
	}
	else{
		x->getPai()->getEsq()=y;
	}
	y->getDir()=x;
	x->getPai()=y;
}
template <class Tipo>
void ABBRN<Tipo>::RN_INSERE(No<Tipo> *&z){
	No<Tipo> *y = NULL;
	x = raiz;
	while (x!=NULL) {
		y=x;
		if()
	}
}
int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}
