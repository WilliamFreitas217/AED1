#include <iostream>
using namespace std;
template <class Tipo>
class No{
private:
	Tipo item;
	No *esq;
  No *dir;
  No *pai;
public:
	No();
	No(Tipo item);
	void setItem(Tipo item);
	void setEsq(No<Tipo> * no);
  void setDir(No<Tipo> * no);
  void setPai(No<Tipo> * pai);
	Tipo getItem();
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
class ABB{
private:
  No<Tipo> *raiz;
  No<Tipo> *predecessor(No<Tipo> *no, No<Tipo> *&no2);
  void insere(Tipo item, No<Tipo> *&no);
  Tipo remove(Tipo &item, No<Tipo> *&no);
  Tipo busca(Tipo &item, No<Tipo> *no);
  void percorrePreOrdem(No<Tipo> *no);
  void percorrePosOrdem(No<Tipo> *no);
  void percorreCentral(No<Tipo> *no);
 	Tipo remove_aux(No<Tipo> *&q, No<Tipo> *&r);
public:
	ABB();
	ABB(Tipo item);
  void insere(Tipo item);
  Tipo remove(Tipo &item);
  Tipo busca(Tipo &item);
  void percorrePosOrdem();
  void percorrePreOrdem();
  void percorreCentral();
	void Mostra(string ordem);
};

template <class Tipo>
ABB<Tipo>::ABB(){
	this->raiz = NULL;
}

template <class Tipo>
ABB<Tipo>::ABB(Tipo item){
	raiz->setItem(item);
}

template <class Tipo>
void ABB<Tipo>::insere(Tipo item, No<Tipo> *&no){
	if(no==NULL){
		no = new No<Tipo>();
		no->setItem(item);
	}
	else if(item>no->getItem()){
		insere(item, no->getDir());
	}
	else if(item<no->getItem()){
		insere(item, no->getEsq());
	}
	else{
		cout<<"já está na árvore"<<endl;
	}
}

template <class Tipo>
void ABB<Tipo>::percorrePreOrdem(){
	percorrePreOrdem(raiz);
}

template <class Tipo>
void ABB<Tipo>::percorrePosOrdem(){
	percorrePosOrdem(raiz);
}

template <class Tipo>
void ABB<Tipo>::percorreCentral(){
	percorreCentral(raiz);
}

template <class Tipo>
void ABB<Tipo>::insere(Tipo item){
	insere(item, raiz);
}

template <class Tipo>
Tipo ABB<Tipo>::busca(Tipo &item){
	return busca(item, raiz);
}

template <class Tipo>
Tipo ABB<Tipo>::busca(Tipo &item, No<Tipo> *no){
	if(no==NULL){
		cout<<"Não encontrado!"<<endl;
		return 0;
	}
	else if(item>no->getItem()){
		busca(item, no->getDir());
	}
	else if(item<no->getItem()){
		busca(item, no->getEsq());
	}
	else{
		item = no->getItem();
		return item;
	}
}

template <class Tipo>
void ABB<Tipo>::percorrePreOrdem(No<Tipo> *no){
	if(no!= NULL){
		cout<<no->getItem()<<endl;
		percorrePreOrdem(no->getEsq());
		percorrePreOrdem(no->getDir());
	}
}

template <class Tipo>
void ABB<Tipo>::percorreCentral(No<Tipo> *no){
	if(no!=NULL){
		percorreCentral(no->getEsq());
		cout<<no->getItem()<<endl;
		percorreCentral(no->getDir());
	}
}

template <class Tipo>
void ABB<Tipo>::percorrePosOrdem(No<Tipo> *no){
	if(no!=NULL){
		percorrePosOrdem(no->getEsq());
		percorrePosOrdem(no->getDir());
		cout<<no->getItem()<<endl;
	}
}
template <class Tipo>
Tipo ABB<Tipo>::remove_aux(No<Tipo> *&q, No<Tipo> *&r){
	Tipo item;
	if(r->getDir()!=NULL){
		remove_aux(q, r->getDir());
	}
	else{
		item = q->getItem();
		q->setItem(r->getItem());
		r= r->getEsq();
		delete r;
	}
	return item;
}

template <class Tipo>
Tipo ABB<Tipo>::remove(Tipo &item, No<Tipo> *&no){
	if(no==NULL){
		// a ser modificado dependendo do dado analisado;
		cout<<"Não encontrado!"<<endl;
		return 0;
	}
	else if(item<no->getItem()){
		remove(item, no->getEsq());
	}
	else if(item>no->getItem()){
		remove(item, no->getDir());
	}
	else if(no->getDir()==NULL){
		No<Tipo> *aux =  new No<Tipo>();
		aux=no;
		no = no->getEsq();
		delete(aux);
	}
	else if(no->getEsq()==NULL){
		No<Tipo> *aux =  new No<Tipo>();
		aux=no;
		no = no->getDir();
		delete(aux);
	}
	else{
		cout<<"Achou!"<<endl;
		item = remove_aux(no, no->getEsq());
		return item;
		// return &remove_aux(no, no->getEsq());
	}
}

template <class Tipo>
Tipo ABB<Tipo>::remove(Tipo &item){
	remove(item, raiz);
	return item;
}

template <class Tipo>
void ABB<Tipo>::Mostra(string ordem){
	if(ordem=="Pre"){
		percorrePreOrdem();
	}
	if(ordem=="Pos"){
		percorrePosOrdem();
	}
	if(ordem=="Central"){
		percorreCentral();
	}
}

struct inteiro{
	int x;
};

int main(int argc, char const *argv[]) {
  ABB<int> Arvore;
	inteiro inteiro1, inteiroB;
	inteiro1.x=2;
	// inteiro1.x=8;
	// cout<<inteiro1.x<<endl;
	Arvore.insere(2);
	Arvore.insere(4);
	Arvore.insere(8);
	Arvore.insere(1);
	Arvore.insere(3);
	// cout<<"Pos"<<endl;
	// Arvore.Mostra("Pos");
	// cout<<endl;
	// cout<<"Pre"<<endl;
	// Arvore.Mostra("Pre");
	// cout<<endl;
	// cout<<"Central"<<endl;
	// Arvore.Mostra("Central");
	// cout<<endl;
	Arvore.remove(inteiro1.x);
	cout<<endl;
	cout<<"Central"<<endl;
	Arvore.Mostra("Central");
	cout<<endl;
	// cout<<Arvore.busca(inteiroB.x)<<endl;
  return 0;
}
