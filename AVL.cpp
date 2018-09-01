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
  NoAVL(Tipo &item);
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
NoAVL<Tipo>::NoAVL(Tipo &item){
  this->item = item;
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
  esq = no;
}
template <class Tipo>
void NoAVL<Tipo>::setDir(NoAVL<Tipo> *&no){
  dir = no;
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
  NoAVL<Tipo> *&busca(Tipo chave, NoAVL<Tipo> *&no);
  int insere(Tipo &item, NoAVL<Tipo> *&no);
  void RSE(NoAVL<Tipo> *&noDesce);
  void RSD(NoAVL<Tipo> *&noDesce);
  void RDE(NoAVL<Tipo> *&noDesce);
  void RDD(NoAVL<Tipo> *&noDesce);
  void percorrePre(NoAVL<Tipo> *no);
  void percorrePos(NoAVL<Tipo> *no);
  void percorreCentral(NoAVL<Tipo> *no);
public:
  AVL();
  void insere(Tipo &item);
  NoAVL<Tipo> *&busca(Tipo chave);
  void percorrePre();
  void percorrePos();
  void percorreCentral();
};
template <class Tipo>
AVL<Tipo>::AVL(){
  raiz = NULL;
}
template <class Tipo>
void AVL<Tipo>::insere(Tipo &item){
  insere(item, raiz);
}
template <class Tipo>
int AVL<Tipo>::insere(Tipo &item, NoAVL<Tipo> *&no){
  if(no == NULL){
    no = new NoAVL<Tipo>();
    no->setItem(item);
    return 1;
  }
  if(item.getChave()<no->getItem().getChave()){
    int conferidor = insere(item, no->getEsq());
    if(conferidor==1){ //inseriu na esquerda
      // cout<<"aqui"<<endl;
      if(no->getFb()==1){
        no->setFb(0);
        return 0;
      }
      else if(no->getFb()==0){
        no->setFb(-1);
      }
      else{
        if(no->getEsq()->getFb()==-1){
          RSD(no);
          no->setFb(0);
          cout<<"RSD"<<endl;
          return 0;
        }
        else{
          if(no->getEsq()->getFb()!=0){
            cout<<"RDD"<<endl;
            RDD(no);
            no->setFb(0);
            return 0;
          }
        }
      }
      return 1;
    }
  }
  if(item.getChave()>no->getItem().getChave()){
    int conferidor = insere(item, no->getDir());
    if(conferidor==1){ //inseriu na direita
      // cout<<"aqui"<<endl;
      if(no->getFb()==-1){
        no->setFb(0);
        return 0;
      }
      else if(no->getFb()==0){
        no->setFb(1);
      }
      else{
        if(no->getDir()->getFb()==1){
          RSE(no);
          no->setFb(0);
          cout<<"RSE"<<endl;
          return 0;
        }
        else{
          if(no->getDir()->getFb()!=0){
            RDE(no);
            no->setFb(0);
            cout<<"RDE"<<endl;
            return 0;
          }
        }
      }
      return 1;
    }
  }
  else if(item.getChave()==no->getItem().getChave()){
    return 0;
  }
}
template <class Tipo>
void AVL<Tipo>::RSE(NoAVL<Tipo> *&noDesce){
  NoAVL<Tipo> *p1= new NoAVL<Tipo>();
  *p1 = *noDesce->getDir();
  noDesce->setDir(p1->getEsq());
  p1->getEsq()=noDesce;
  noDesce->setFb(0);
  noDesce = p1;
}

template <class Tipo>
void AVL<Tipo>::RSD(NoAVL<Tipo> *&noDesce){
  NoAVL<Tipo> *p1= new NoAVL<Tipo>();
  *p1 = *noDesce->getEsq();
  noDesce->setEsq(p1->getDir());
  p1->getDir()=noDesce;
  noDesce->setFb(0);
  noDesce = p1;
}

template <class Tipo>
void AVL<Tipo>::RDE(NoAVL<Tipo> *&noDesce){
  NoAVL<Tipo> *p1= new NoAVL<Tipo>();
  *p1 = *noDesce->getDir();
  NoAVL<Tipo> *p2= new NoAVL<Tipo>();
  *p2 = *p1->getEsq();
  p1->setEsq(p2->getDir());
  p2->setDir(p1);
  noDesce->setDir(p2->getEsq());
  p2->setEsq(noDesce);
  if(p2->getFb()== 1){
    noDesce->setFb(-1);
  }
  else{
    noDesce->setFb(0);
  }
  if(p2->getFb()== -1){
    p1->setFb(1);
  }
  else{
    p1->setFb(0);
  }
  noDesce = p2;
}
template <class Tipo>
void AVL<Tipo>::RDD(NoAVL<Tipo> *&noDesce){
  NoAVL<Tipo> *p1= new NoAVL<Tipo>();
  *p1 = *noDesce->getEsq();
  NoAVL<Tipo> *p2= new NoAVL<Tipo>();
  *p2 = *p1->getDir();
  p1->setDir(p2->getEsq());
  p2->setEsq(p1);
  noDesce->setEsq(p2->getDir());
  p2->setDir(noDesce);
  if(p2->getFb()== -1){
    noDesce->setFb(1);
  }
  else{
    noDesce->setFb(0);
  }
  if(p2->getFb()== 1){
    p1->setFb(-1);
  }
  else{
    p1->setFb(0);
  }
  noDesce = p2;
}
template <class Tipo>
void AVL<Tipo>::percorrePre(){
  percorrePre(raiz);
}
template <class Tipo>
void AVL<Tipo>::percorrePre(NoAVL<Tipo> *no){
  if(no!=NULL){
    cout<<"Item:: "<<no->getItem().getChave()<<" fb:: "<< no->getFb()<<endl;
    percorrePre(no->getEsq());
    percorrePre(no->getDir());
  }
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

int main(int argc, char const *argv[]) {
  AVL<item> arvore;
  item a,b, c, d, e, f, g, h;
  a.setX(1);
  b.setX(2);
  c.setX(13);
  d.setX(5);
  e.setX(8);
  f.setX(3);
  g.setX(21);
  // h.setX(8);
  arvore.insere(a);
  arvore.insere(b);
  arvore.insere(c);
  arvore.insere(d);
  arvore.insere(e);
  arvore.insere(f);
  arvore.insere(g);
  // arvore.insere(h);
  arvore.percorrePre();
  return 0;
}
