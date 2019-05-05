#include <iostream>
using namespace std;
template <class Tipo>
class No{
private:
	Tipo item;
	No *esq;
  No *dir;
  // No *pai;
	int fb;
public:
	No();
	No(Tipo item);
	void setFb(int fb);
	void setItem(Tipo item);
	void setEsq(No<Tipo> *&no);
  void setDir(No<Tipo> *&no);
  // void setPai(No<Tipo> *&pai);
	Tipo getItem();
	int getFb();
	No<Tipo> *&getEsq();
  No<Tipo> *&getDir();
  No<Tipo> *&getPai();
};
template <class Tipo>
No<Tipo>::No(){
 	this->esq = NULL;
  this->dir = NULL;
	// this->pai= NULL;
}
template <class Tipo>
No<Tipo>::No(Tipo item){
	this->item = item;
	this->esq = NULL;
  this->dir = NULL;
	// this->pai= NULL;
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
// template <class Tipo>
// No<Tipo> *&No<Tipo>::getPai(){
	// return pai;
// }
template <class Tipo>
int No<Tipo>::getFb(){
	return fb;
}
template <class Tipo>
void No<Tipo>::setItem(Tipo item){
	this->item = item;
}
template <class Tipo>
void No<Tipo>::setFb(int fb){
	this->fb = fb;
}
template <class Tipo>
void No<Tipo>::setEsq(No<Tipo> *&no){
	this->esq = no;
}
template <class Tipo>
void No<Tipo>::setDir(No<Tipo> *&no){
	this->dir = no;
}
// template <class Tipo>
// void No<Tipo>::setPai(No<Tipo> *&pai){
  // this->pai = pai;
// }

template <class Tipo>
class AVL{
private:
  No<Tipo> *raiz;
  No<Tipo> *predecessor(No<Tipo> *no, No<Tipo> *&no2);
  void insere(Tipo item, No<Tipo> *&no);
  Tipo remove(Tipo &item, No<Tipo> *&no);
  No<Tipo> *busca(Tipo &item, No<Tipo> *no);
  void percorrePreOrdem(No<Tipo> *no);
	int he(No<Tipo> *no);
	int hd(No<Tipo> *no);
  void percorrePosOrdem(No<Tipo> *no);
  void percorreCentral(No<Tipo> *no);
 	Tipo remove_aux(No<Tipo> *&q, No<Tipo> *&r);
	void balancear(No<Tipo> *no);
	void RSE(No<Tipo> *&noDesce, No<Tipo> *&noSobe);
	void RSD(No<Tipo> *&noDesce, No<Tipo> *&noSobe);
	void RDE(No<Tipo> *&noDesce, No<Tipo> *&noSobe, No<Tipo> *&noDesce2);
	void RDD(No<Tipo> *&noDesce, No<Tipo> *&noSobe, No<Tipo> *&noDesce2);
public:
	AVL();
	void he();
	void hd();
	AVL(Tipo item);
	No<Tipo>*getRaiz();
  void insere(Tipo item);
  Tipo remove(Tipo &item);
  void percorrePosOrdem();
	No<Tipo> *busca(Tipo &item);
  void percorrePreOrdem();
  void percorreCentral();
	void Mostra(string ordem);
	void calcularFbs(No<Tipo> *no);
	void balancear();
};

template <class Tipo>
AVL<Tipo>::AVL(){
	this->raiz = NULL;
}
template <class Tipo>
AVL<Tipo>::AVL(Tipo item){
	raiz->setItem(item);
}
template <class Tipo>
void AVL<Tipo>::balancear(){
	balancear(raiz);
}
template <class Tipo>
No<Tipo>*AVL<Tipo>::getRaiz(){
	return raiz;
}
template <class Tipo>
void AVL<Tipo>::RSE(No<Tipo> *&noDesce, No<Tipo> *&noSobe){
	No<Tipo> *aux = new No<Tipo>();
  aux->setItem(noDesce->getItem());
  if(noDesce->getEsq()!=NULL){
    aux->setEsq(noDesce->getEsq());
  }
  if(noSobe->getEsq()!=NULL){
    aux->setDir(noSobe->getEsq());
  }
  *noDesce = *noSobe;
  noDesce->setEsq(aux);
	calcularFbs(raiz);
	Mostra("Pre");
	cout<<endl;
}
template <class Tipo>
void AVL<Tipo>::RSD(No<Tipo> *&noDesce, No<Tipo> *&noSobe){
	No<Tipo> *aux = new No<Tipo>();
  aux->setItem(noDesce->getItem());
  if(noSobe->getDir()!=NULL){
    aux->setEsq(noSobe->getDir());
		// cout<<aux->getEsq()->getItem()<<endl;
  }
  if(noDesce->getDir()!=NULL){
    aux->setDir(noDesce->getDir());
  }
  *noDesce = *noSobe;
  noDesce->setDir(aux);
	calcularFbs(raiz);
	Mostra("Pre");
	cout<<endl;
}
template <class Tipo>
void AVL<Tipo>::RDE(No<Tipo> *&noDesce, No<Tipo> *&noSobe, No<Tipo> *&noDesce2){
	RSD(noDesce, noSobe);
	RSE(noDesce2, noDesce);
}
template <class Tipo>
void AVL<Tipo>::RDD(No<Tipo> *&noDesce, No<Tipo> *&noSobe, No<Tipo> *&noDesce2){
	RSE(noDesce, noSobe);
	RSD(noDesce2, noDesce);
}
template <class Tipo>
void AVL<Tipo>::calcularFbs(No<Tipo> *no){
	if(no!=NULL){
		int fb= ((-1)*he(no->getEsq()))+hd(no->getDir());
		no->setFb(fb);
		calcularFbs(no->getEsq());
		calcularFbs(no->getDir());
	}
}
template <class Tipo>
void AVL<Tipo>::balancear(No<Tipo> *no){
	if(no!=NULL){
		calcularFbs(no);
		balancear(no->getEsq());
		// cout<<"sim"<<endl;
		if(no->getFb()>1 && no->getDir()->getFb()>=0){
			RSE(no, no->getDir());
		}
		if(no->getFb()>1 && no->getDir()->getFb()<0){
			RDE(no->getDir(), no->getDir()->getEsq(), no);
		}
		if(no->getFb()<(-1) && no->getEsq()->getFb()<=0){
			RSD(no, no->getEsq());
		}
		if(no->getFb()<-1 && no->getEsq()->getFb()>0){
			RDD(no->getEsq(), no->getEsq()->getDir(), no);
		}
		calcularFbs(no);
		balancear(no->getDir());
	}
}
template <class Tipo>
void AVL<Tipo>::insere(Tipo item){
	insere(item, raiz);
}
template <class Tipo>
void AVL<Tipo>::insere(Tipo item, No<Tipo> *&no){
	if(no==NULL){
		no = new No<Tipo>();
		no->setItem(item);
		balancear();
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
void AVL<Tipo>::percorrePreOrdem(){
	percorrePreOrdem(raiz);
}
template <class Tipo>
void AVL<Tipo>::percorrePosOrdem(){
	percorrePosOrdem(raiz);
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(){
	percorreCentral(raiz);
}

template <class Tipo>
No<Tipo> *AVL<Tipo>::busca(Tipo &item){
	return busca(item, raiz);
}

template <class Tipo>
No<Tipo> *AVL<Tipo>::busca(Tipo &item, No<Tipo> *no){
	if(no==NULL){
		cout<<"Não encontrado!"<<endl;
		return NULL;
	}
	else if(item>no->getItem()){
		busca(item, no->getDir());
	}
	else if(item<no->getItem()){
		busca(item, no->getEsq());
	}
	else{
		No<Tipo> *aux=new No<Tipo>();
		aux= no;
		item = no->getItem();
		return no;
	}
}

template <class Tipo>
void AVL<Tipo>::percorrePreOrdem(No<Tipo> *no){
	if(no!= NULL){
		cout<<no->getItem()<<endl;
		cout<<"FB: "<<no->getFb()<<endl;
		percorrePreOrdem(no->getEsq());
		percorrePreOrdem(no->getDir());
	}
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(No<Tipo> *no){
	if(no!=NULL){
		percorreCentral(no->getEsq());
		cout<<no->getItem()<<endl;
		cout<<"FB: "<<no->getFb()<<endl;
		// cout<<"he e hd::: "<<he(no, 0)<<", "<<hd(no, 0)<<endl;
		percorreCentral(no->getDir());
	}
}

template <class Tipo>
void AVL<Tipo>::percorrePosOrdem(No<Tipo> *no){
	if(no!=NULL){
		percorrePosOrdem(no->getEsq());
		percorrePosOrdem(no->getDir());
		cout<<no->getItem()<<endl;
		// cout<<"FB: "<<no->getFb()<<endl;
	}
}
template <class Tipo>
Tipo AVL<Tipo>::remove_aux(No<Tipo> *&q, No<Tipo> *&r){
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
Tipo AVL<Tipo>::remove(Tipo &item, No<Tipo> *&no){
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
Tipo AVL<Tipo>::remove(Tipo &item){
	remove(item, raiz);
	return item;
}

template <class Tipo>
void AVL<Tipo>::Mostra(string ordem){
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
template <class Tipo>
int AVL<Tipo>::he(No<Tipo> *no){
	if(no!=NULL){
		if(no->getDir()==NULL && no->getEsq()==NULL){
			return 1;
		}
		else{
			int a, b;
			// if()
			a = he(no->getEsq());
			b = he(no->getDir());
			// cout<<a<<", "<<b<<endl;
			if(a>b){
				return a+1;
			}
			else{
				return b+1;
			}
		}
	}
	else{
		return 0;
	}
}
template <class Tipo>
void AVL<Tipo>::he(){
	cout<<he(raiz)<<endl;
}
template <class Tipo>
int AVL<Tipo>::hd(No<Tipo> *no){
	if(no!=NULL){
		if(no->getDir()==NULL && no->getEsq()==NULL){
			return 1;
		}
		else{
			int a, b;
			// if()
			a = hd(no->getEsq());
			b = hd(no->getDir());
			// cout<<a<<", "<<b<<endl;
			if(a>b){
				return a+1;
			}
			else{
				return b+1;
			}
		}
	}
	else{
		return 0;
	}
}
template <class Tipo>
void AVL<Tipo>::hd(){
	cout<<hd(raiz)<<endl;
}
struct inteiro{
	int x;
};

int main(int argc, char const *argv[]) {
  AVL<int> Arvore;
	inteiro inteiro1, inteiroB;
	inteiro1.x = 5;
	Arvore.insere(4);
	Arvore.insere(5);
	Arvore.insere(7);
	Arvore.insere(2);
	Arvore.insere(1);
	Arvore.insere(3);
	Arvore.insere(6);
  return 0;
}
