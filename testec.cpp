#include <iostream>
using namespace std;
template <class Tipo>
class NoAVL{
private:
  NoAVL<Tipo> *esq;
  NoAVL<Tipo> *dir;
  Tipo item;
  int fb;
public:
  NoAVL();
  NoAVL<Tipo> *&getEsq();
  NoAVL<Tipo> *&getDir();
  Tipo &getItem();
  int getFb();
  void setEsq(NoAVL<Tipo> *&no);
  void setDir(NoAVL<Tipo> *&no);
  void setItem(Tipo &item);
  void setFb(int fb);
};
template <class Tipo>
NoAVL<Tipo>::NoAVL(){
  this->esq = NULL;
  this->dir = NULL;
  this->fb = 0;
}
template <class Tipo>
NoAVL<Tipo> *&NoAVL<Tipo>::getEsq(){
  return esq;
}
template <class Tipo>
NoAVL<Tipo> *&NoAVL<Tipo>::getDir(){
  return dir;
}
template <class Tipo>
Tipo &NoAVL<Tipo>::getItem(){
  return item;
}
template <class Tipo>
int NoAVL<Tipo>::getFb(){
  return fb;
}
template <class Tipo>
void NoAVL<Tipo>::setEsq(NoAVL<Tipo> *&no){
  this->esq = no;
}
template <class Tipo>
void NoAVL<Tipo>::setDir(NoAVL<Tipo> *&no){
  this->dir = no;
}
template <class Tipo>
void NoAVL<Tipo>::setItem(Tipo &item){
  this->item = item;
}
template <class Tipo>
void NoAVL<Tipo>::setFb(int fb){
  this->fb = fb;
}
template <class Tipo>
class AVL{
private:
  NoAVL<Tipo> *raiz;
  void RSE(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noPai, bool veioDeRotDupla);
  void RSD(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noPai, bool veioDeRotDupla);
  void RDE(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noDesce2, NoAVL<Tipo> *&noPai);
  void RDD(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noDesce2, NoAVL<Tipo> *&noPai);
  bool insere(Tipo &item, NoAVL<Tipo> *&no, NoAVL<Tipo> *&noPai);
  int altura(int chave, NoAVL<Tipo> *&no, int h);
public:
  AVL();
  int altura(int chave);
  bool insere(Tipo &item);
};
template <class Tipo>
AVL<Tipo>::AVL(){
  raiz = NULL;
}
template <class Tipo>
bool AVL<Tipo>::insere(Tipo &item){
  return insere(item, raiz, raiz);
}
template <class Tipo>
bool AVL<Tipo>::insere(Tipo &item, NoAVL<Tipo> *&no, NoAVL<Tipo> *&noPai){
  if(no==NULL){
    no = new NoAVL<Tipo>();
    no->setItem(item);
    return true;
  }
  else if(item.getChave()<no->getItem().getChave()){
    no->setFb(no->getFb()-1);
    bool inseriu = insere(item, no->getEsq(), no);
    if(no->getFb()<-1 && no->getEsq()->getFb()<=0){
			// cout<<"RSD"<<endl;
      RSD(no, no->getEsq(), noPai, false);
    }
    if(no->getFb()<-1 && no->getEsq()->getFb()>0){
			// cout<<"RDD"<<endl;
      RDD(no->getEsq(), no->getEsq()->getDir(), no, noPai);
    }
    return inseriu;
  }
  else if(item.getChave()>no->getItem().getChave()){
    no->setFb(no->getFb()+1);
    bool inseriu = insere(item, no->getDir(), no);
    if(no->getFb()>1 && no->getDir()->getFb()>=0){
			// cout<<"RSE"<<endl;
      RSE(no, no->getDir(), noPai, false);
    }
    if(no->getFb()>1 && no->getDir()->getFb()<0){
			// cout<<"RDE"<<endl;
      RDE(no->getDir(), no->getDir()->getEsq(), no, noPai);
    }
    return inseriu;
  }
  else{
    return false;
  }
}
template <class Tipo>
void AVL<Tipo>::RSE(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noPai, bool veioDeRotDupla){
  NoAVL<Tipo> *aux = new NoAVL<Tipo>();
  aux->setItem(noDesce->getItem());
  if(noSobe->getEsq()!=NULL){
    aux->setDir(noSobe->getEsq());
  }
  if(noDesce->getEsq()!=NULL){
    aux->setEsq(noDesce->getEsq());
  }
  *noDesce = *noSobe;
  noDesce->setEsq(aux);
  noDesce->setFb(noDesce->getFb()-1);
  if(noDesce->getItem().getChave()!=noPai->getItem().getChave()){
    noPai->setFb(noPai->getFb()-1);
  }
  else if(veioDeRotDupla){
    noPai->getEsq()->setFb(noPai->getEsq()->getFb()-1);
  }
}
template <class Tipo>
void AVL<Tipo>::RSD(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noPai, bool veioDeRotDupla){
  NoAVL<Tipo> *aux = new NoAVL<Tipo>();
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
  if(noDesce->getItem().getChave()!=noPai->getItem().getChave()){
    noPai->setFb(noPai->getFb()+1);
  }
  else if(veioDeRotDupla){
    noPai->getDir()->setFb(noPai->getDir()->getFb()+1);
  }
}
template <class Tipo>
void AVL<Tipo>::RDE(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noDesce2, NoAVL<Tipo> *&noPai){
  RSD(noDesce, noSobe, noPai, true);
  RSE(noDesce2, noDesce, noPai, true);
}
template <class Tipo>
void AVL<Tipo>::RDD(NoAVL<Tipo> *&noDesce, NoAVL<Tipo> *&noSobe, NoAVL<Tipo> *&noDesce2, NoAVL<Tipo> *&noPai){
  RSE(noDesce, noSobe, noPai, true);
  RSD(noDesce2, noDesce, noPai, true);
}

template <class Tipo>
int AVL<Tipo>::altura(int chave, NoAVL<Tipo> *&no, int h){
  if(no!=NULL){
    if(chave==no->getItem().getChave()){
      cout<<"sim "<<chave<<" "<< h<<endl;
    }
    else{
      if(chave<no->getItem().getChave()){
        altura(chave, no->getEsq(), h+1);
      }
      if(chave>no->getItem().getChave()){
        altura(chave, no->getDir(), h+1);
      }
    }
  }
  else{
    cout<<"nao"<<endl;
    return -1;
  }
}
template <class Tipo>
int AVL<Tipo>::altura(int chave){
  return altura(chave, raiz, 0);
}
class item{
private:
  int x;
public:
  item();
  item(int x);
  void setX(int x);
  int getChave();
};
item::item(){
  x= 0;
}
item::item(int x){
  this->x=x;
}
void item::setX(int x){
  this->x = x;
}
int item::getChave(){
  return x;
}

// template <class Tipo>
// template <class Tipo>
// template <class Tipo>
// template <class Tipo>
// template <class Tipo>
int main(int argc, char const *argv[]) {
  AVL<item> arvore;
  item a,b, c, d, e, f, g;
  a.setX(56);
  b.setX(62);
  c.setX(103);
  d.setX(24);
  e.setX(16);
  f.setX(50);
  g.setX(84);
  arvore.insere(a);
  arvore.insere(b);
  arvore.insere(c);
  arvore.insere(d);
  arvore.insere(e);
  arvore.insere(f);
  arvore.insere(g);
  // arvore.percorrePre();
  return 0;
}
