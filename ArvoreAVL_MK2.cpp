#include <iostream>
#include<cstdlib>
using namespace std;
template <class Tipo>
class NoArvore{
private:
    Tipo item;
	NoArvore *esq;
  	NoArvore *dir;
	int fb;
public:
	NoArvore();
	NoArvore(Tipo item);
	void setFb(int fb);
	void setItem(Tipo item);
	void setEsq(NoArvore<Tipo> *&no);
 	void setDir(NoArvore<Tipo> *&no);
	Tipo &getItem();
	int getFb();
	NoArvore<Tipo> *&getEsq();
  	NoArvore<Tipo> *&getDir();
};
template <class Tipo>
NoArvore<Tipo>::NoArvore(){
 	this->esq = NULL;
  	this->dir = NULL;
  	this->fb = 0;
}
template <class Tipo>
NoArvore<Tipo>::NoArvore(Tipo item){
	this->item = item;
	this->esq = NULL;
  	this->dir = NULL;
  	this->fb = 0;
}
template <class Tipo>
Tipo &NoArvore<Tipo>::getItem(){
	return this->item;
}
template <class Tipo>
NoArvore<Tipo> *&NoArvore<Tipo>::getEsq(){
	return esq;
}
template <class Tipo>
NoArvore<Tipo> *&NoArvore<Tipo>::getDir(){
	return dir;
}
template <class Tipo>
int NoArvore<Tipo>::getFb(){
	return fb;
}
template <class Tipo>
void NoArvore<Tipo>::setItem(Tipo item){
	this->item = item;
}
template <class Tipo>
void NoArvore<Tipo>::setFb(int fb){
	this->fb = fb;
}
template <class Tipo>
void NoArvore<Tipo>::setEsq(NoArvore<Tipo> *&no){
	this->esq = no;
}
template <class Tipo>
void NoArvore<Tipo>::setDir(NoArvore<Tipo> *&no){
	this->dir = no;
}

template <class Tipo>
class AVL{
private:
  	NoArvore<Tipo> *raiz;
  	NoArvore<Tipo> *predecessor(NoArvore<Tipo> *no, NoArvore<Tipo> *&no2);
  	void insere(Tipo &item, NoArvore<Tipo> *&no,NoArvore<Tipo> *&pai);
 	NoArvore<Tipo> *busca(Tipo &item, NoArvore<Tipo> *no);
  	void percorreCentral(NoArvore<Tipo> *no, string &s);
	void balancear(NoArvore<Tipo> *no);
	void RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
	void RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
public:
	AVL();
	AVL(Tipo &item);
	NoArvore<Tipo>*getRaiz();
  	void insere(Tipo &item);
	NoArvore<Tipo> *busca(Tipo &item);
  	void percorreCentral();
	void Mostra(string ordem);
	void calcularFbs(NoArvore<Tipo> *no);
	void balancear();
};

template <class Tipo>
AVL<Tipo>::AVL(){
	this->raiz = NULL;
}
template <class Tipo>
AVL<Tipo>::AVL(Tipo &item){
	raiz->setItem(item);
}
template <class Tipo>
void AVL<Tipo>::balancear(){
	balancear(raiz);
}
template <class Tipo>
NoArvore<Tipo>*AVL<Tipo>::getRaiz(){
	return raiz;
}
template <class Tipo>
void AVL<Tipo>::RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla){
	NoArvore<Tipo> *aux = new NoArvore<Tipo>();
	aux->setItem(noDesce->getItem());
	if(noDesce->getEsq()!=NULL){
		aux->setEsq(noDesce->getEsq());
	}
	if(noSobe->getEsq()!=NULL){
		aux->setDir(noSobe->getEsq());
	}
	*noDesce = *noSobe;
	noDesce->setEsq(aux);
	noDesce->setFb(noDesce->getFb()-1);
	if(noDesce->getItem().getChave()!=noPai->getItem().getChave()){
		noPai->setFb(noPai->getFb()-1);
	}
	else{
		if(veioDeDupla){
			noPai->getEsq()->setFb(noPai->getEsq()->getFb()-1);
		}
	}
}
template <class Tipo>
void AVL<Tipo>::RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla){
	NoArvore<Tipo> *aux = new NoArvore<Tipo>();
  	aux->setItem(noDesce->getItem());
  	if(noSobe->getDir()!=NULL){
    	aux->setEsq(noSobe->getDir());
  	}
  	if(noDesce->getDir()!=NULL){
    	aux->setDir(noDesce->getDir());
  	}
  	*noDesce = *noSobe;
  	noDesce->setDir(aux);
	noDesce->setFb(noDesce->getFb()+1);
	if(noDesce!=noPai){
		noPai->setFb(noPai->getFb()+1);
	}
	else{
		if(veioDeDupla){
			noPai->getDir()->setFb(noPai->getDir()->getFb()+1);
		}
	}
}
template <class Tipo>
void AVL<Tipo>::RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai){
	if(noDesce != NULL && noSobe!=NULL){
		RSD(noDesce, noSobe, noPai, true);
		RSE(noDesce2, noDesce, noPai, true);
	}
}
template <class Tipo>
void AVL<Tipo>::RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai){
  	if(noDesce != NULL && noSobe!=NULL){
  		RSE(noDesce, noSobe, noPai, true);
  		RSD(noDesce2, noDesce, noPai, true);
  	}
}

template <class Tipo>
void AVL<Tipo>::insere(Tipo &item){
	insere(item, raiz,raiz);
}

template <class Tipo>
void AVL<Tipo>::insere(Tipo &item, NoArvore<Tipo> *&no, NoArvore<Tipo> *&pai){
	if(no==NULL){
		no = new NoArvore<Tipo>();
		no->setItem(item);
		no->setFb(0);
	}
	else if(item.getChave()>no->getItem().getChave()){
		no->setFb(no->getFb()+1);
		insere(item, no->getDir(), no);
		if(no->getFb()>1 && no->getDir()->getFb()>=0){
      // cout<<"RSE "<<no->getItem().getChave()<<" "<<no->getDir()->getItem().getChave()<<endl;
      // percorreCentral();
			RSE(no, no->getDir(), pai, false);
		}
		if(no->getFb()>1 && no->getDir()->getFb()<0){
      // cout<<"RDE "<<no->getItem().getChave()<<" "<<no->getDir()->getItem().getChave()<<endl;
      // percorreCentral();
			RDE(no->getDir(), no->getDir()->getEsq(), no, pai);
		}
	}
	else if(item.getChave()<no->getItem().getChave()){
		no->setFb(no->getFb()-1);
		insere(item, no->getEsq(), no);
		if(no->getFb()<-1 && no->getEsq()->getFb()<=0){
      cout<<"RSD"<<endl;
      // percorreCentral();
			RSD(no, no->getEsq(), pai, false);
		}
		if(no->getFb()<-1 && no->getEsq()->getFb()>0){
      cout<<"RDD"<<endl;
      // percorreCentral();
			RDD(no->getEsq(), no->getEsq()->getDir(), no, pai);
		}
	}
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(){
  	string s;
	percorreCentral(raiz, s);
  	// cout<<s;
}
template <class Tipo>
NoArvore<Tipo> *AVL<Tipo>::busca(Tipo &item){
	return busca(item, raiz);
}

template <class Tipo>
NoArvore<Tipo> *AVL<Tipo>::busca(Tipo &item, NoArvore<Tipo> *no){
	if(no==NULL){
		return NULL;
	}
	else if(item.getChave()>no->getItem().getChave()){
		return busca(item, no->getDir());
	}
	else if(item.getChave()<no->getItem().getChave()){
		return busca(item, no->getEsq());
	}
	else{
		item = no->getItem();
		return no;
	}
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(NoArvore<Tipo> *no, string &s){
	if(no!=NULL){
    cout<<no->getItem().getChave()<<endl;
		percorreCentral(no->getEsq(), s);
    	// s+= no->getItem().getChave()+" ";
		percorreCentral(no->getDir(), s);
	}
}

template <class Tipo>
void AVL<Tipo>::Mostra(string ordem){
	if(ordem=="Central"){
		percorreCentral();
	}
}
class item{
private:
  int x;
public:
  item();
  void setX(int x);
  int getChave();
};
item::item(){
}
void item::setX(int x){
  this->x = x;
}
int item::getChave(){
  return x;
}
int main(int argc, char const *argv[]) {
  item a, b, c, d, e, f, g;
  a.setX(56);
  // cout<<a.getChave()<<endl;
  b.setX(62);
  c.setX(103);
  d.setX(24);
  e.setX(16);
  f.setX(50);
  g.setX(84);
  AVL<item> inteiros;
  inteiros.insere(a);
  inteiros.insere(b);
  inteiros.insere(c);
  inteiros.insere(d);
  inteiros.insere(e);
  inteiros.insere(f);
  inteiros.insere(g);
  inteiros.Mostra("Central");
  return 0;
}
