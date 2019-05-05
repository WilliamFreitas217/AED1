#include <iostream>
using namespace std;
template <class Tipo>
class No{
private:
  No<Tipo> *prox;
  Tipo item;
public:
  No();
  No(Tipo &item);
  No<Tipo> *&getProx();
  Tipo &getItem();
  void setProx(No<Tipo> *no);
  void setItem(Tipo &item);
};
template <class Tipo>
No<Tipo>::No(){
  this->prox = NULL;
}
template <class Tipo>
No<Tipo>::No(Tipo &item){
  this->item = item;
  this->prox = NULL;
}
template <class Tipo>
No<Tipo> *&No<Tipo>::getProx(){
  return prox;
}
template <class Tipo>
Tipo &No<Tipo>::getItem(){
  return item;
}
template <class Tipo>
void No<Tipo>::setProx(No<Tipo> *no){
  prox = no;
}
template <class Tipo>
void No<Tipo>::setItem(Tipo &item){
  this->item = item;
}
template <class Tipo>
class Lista{
private:
  No<Tipo> *prim;
  No<Tipo> *ult;
public:
  Lista();
  No<Tipo> *&getPrim();
  No<Tipo> *&getUlt();
  void setPrim(No<Tipo> *&no);
  void setUlt(No<Tipo> *&no);
  void insere(Tipo &item);
  No<Tipo> *&busca(Tipo chave);
  void mostra();
};
template <class Tipo>
Lista<Tipo>::Lista(){
  prim = new No<Tipo>();
  ult=prim;
}
template <class Tipo>
No<Tipo> *&Lista<Tipo>::getPrim(){
  return prim;
}
template <class Tipo>
No<Tipo> *&Lista<Tipo>::getUlt(){
  return ult;
}
template <class Tipo>
void Lista<Tipo>::setPrim(No<Tipo> *&no){
  this->prim= no;
}
template <class Tipo>
void Lista<Tipo>::setUlt(No<Tipo> *&no){
  this->ult= no;
}
template <class Tipo>
void Lista<Tipo>::insere(Tipo &item){
  ult->setProx(new No<Tipo>());
  ult = ult->getProx();
  ult->setItem(item);
}
template <class Tipo>
No<Tipo> *&Lista<Tipo>::busca(Tipo chave){
  No<Tipo> *p = prim->getProx();
  while(p!=NULL){
    if(chave==p->getItem().getChave()){
      return p;
    }
    else{
      p= p->getProx();
    }
  }
  return p;
}
template <class Tipo>
void Lista<Tipo>::mostra(){
  No<Tipo> *p = prim->getProx();
  while(p!=NULL){
    cout<<p->getItem().getChave()<<endl;
    p=p->getProx();
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
  Lista<item> lista;
  item a,b, c, d, e, f, g;
  a.setX(56);
  b.setX(62);
  c.setX(103);
  d.setX(24);
  e.setX(16);
  f.setX(50);
  g.setX(84);
  lista.insere(a);
  lista.insere(b);
  lista.insere(c);
  lista.insere(d);
  lista.insere(e);
  lista.insere(f);
  lista.insere(g);
  lista.mostra();
  return 0;
}
