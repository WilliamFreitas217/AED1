//Equipe
// William do Vale Cavalcante Freitas - 1615080545
// Artur da Silva Santos - 1615080247

#include <iostream>
#include<cstdlib>
using namespace std;
template <class Tipo>
class NoArvore{
private:
    Tipo *item;
	NoArvore *esq;
  	NoArvore *dir;
	int fb;
public:
	NoArvore();
	NoArvore(Tipo *item);
	void setFb(int fb);
	void setItem(Tipo *item);
	void setEsq(NoArvore<Tipo> *&no);
 	void setDir(NoArvore<Tipo> *&no);
	Tipo *getItem();
	int getFb();
	NoArvore<Tipo> *&getEsq();
  	NoArvore<Tipo> *&getDir();
};
template <class Tipo>
	NoArvore<Tipo>::NoArvore(){
 	this->esq = NULL;
  	this->dir = NULL;
}
template <class Tipo>
NoArvore<Tipo>::NoArvore(Tipo *item){
	this->item = item;
	this->esq = NULL;
  	this->dir = NULL;
}
template <class Tipo>
Tipo *NoArvore<Tipo>::getItem(){
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
void NoArvore<Tipo>::setItem(Tipo *item){
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
  	void insere(Tipo *&item, NoArvore<Tipo> *&no,NoArvore<Tipo> *&pai, bool esquerda, bool direita);
 	NoArvore<Tipo> *busca(Tipo &item, NoArvore<Tipo> *no);
  	void percorrePreOrdem(NoArvore<Tipo> *no);
	int h(NoArvore<Tipo> *no);
  	void percorrePosOrdem(NoArvore<Tipo> *no);
  	void percorreCentral(NoArvore<Tipo> *no);
	void balancear(NoArvore<Tipo> *no);
	void RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
	void RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
public:
	AVL();
	void h();
	AVL(Tipo *&item);
	NoArvore<Tipo>*getRaiz();
  	void insere(Tipo *&item);
  	void percorrePosOrdem();
	NoArvore<Tipo> *busca(Tipo &item);
  	void percorrePreOrdem();
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
AVL<Tipo>::AVL(Tipo *&item){
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
	if(noDesce->getItem()->getChave()!=noPai->getItem()->getChave()){
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
	RSD(noDesce, noSobe, noPai, true);
	RSE(noDesce2, noDesce, noPai, true);
}
template <class Tipo>
void AVL<Tipo>::RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai){
	RSE(noDesce, noSobe, noPai, true);
	RSD(noDesce2, noDesce, noPai, true);
}

template <class Tipo>
void AVL<Tipo>::insere(Tipo *&item){
	insere(item, raiz,raiz, false, false);
}

template <class Tipo>
void AVL<Tipo>::insere(Tipo *&item, NoArvore<Tipo> *&no, NoArvore<Tipo> *&pai, bool esquerda, bool direita){
	if(no==NULL){
		no = new NoArvore<Tipo>();
		no->setItem(item);
		no->setFb(0);
	}
	else if(item->getChave()>no->getItem()->getChave()){
		no->setFb(no->getFb()+1);
		insere(item, no->getDir(), no, false, true);
		if(no->getFb()>1 && no->getDir()->getFb()>=0){
			RSE(no, no->getDir(), pai, false);
		}
		if(no->getFb()>1 && no->getDir()->getFb()<0){
			RDE(no->getDir(), no->getDir()->getEsq(), no, pai);
		}
	}
	else if(item->getChave()<no->getItem()->getChave()){
		no->setFb(no->getFb()-1);
		insere(item, no->getEsq(), no, true, false);
		if(no->getFb()<-1 && no->getEsq()->getFb()<=0){
			RSD(no, no->getEsq(), pai, false);
		}
		if(no->getFb()<-1 && no->getEsq()->getFb()>0){
			RDD(no->getEsq(), no->getEsq()->getDir(), no, pai);
		}
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
NoArvore<Tipo> *AVL<Tipo>::busca(Tipo &item){
	return busca(item, raiz);
}

template <class Tipo>
NoArvore<Tipo> *AVL<Tipo>::busca(Tipo &item, NoArvore<Tipo> *no){
	if(no==NULL){
		return NULL;
	}
	else if(item.getChave()>no->getItem()->getChave()){
		return busca(item, no->getDir());
	}
	else if(item.getChave()<no->getItem()->getChave()){
		return busca(item, no->getEsq());
	}
	else{
		item = *no->getItem();
		return no;
	}
}

template <class Tipo>
void AVL<Tipo>::percorrePreOrdem(NoArvore<Tipo> *no){
	if(no!= NULL){
		cout<<no->getItem()->getChave()<<endl;
		percorrePreOrdem(no->getEsq());
		percorrePreOrdem(no->getDir());
	}
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(NoArvore<Tipo> *no){
	if(no!=NULL){
		percorreCentral(no->getEsq());
		cout<<no->getItem()->getChave()<<" ";
		percorreCentral(no->getDir());
	}
}

template <class Tipo>
void AVL<Tipo>::percorrePosOrdem(NoArvore<Tipo> *no){
	if(no!=NULL){
		percorrePosOrdem(no->getEsq());
		percorrePosOrdem(no->getDir());
	}
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
class No{
private:
	Tipo item;
	No *prox;
public:
	No();
	No(Tipo);
	void setItem(Tipo);
	void setNo(No<Tipo> *);
	void cria();
	Tipo getItem();
	No<Tipo> *getProx();
};
template <class Tipo>
No<Tipo>::No(){
 	this->prox = NULL;
}
template <class Tipo>
void No<Tipo>::cria(){
	this->prox = NULL;
}
template <class Tipo>
No<Tipo>::No(Tipo item){
	this->item = item;
	this->prox = NULL;
}
template <class Tipo>
Tipo No<Tipo>::getItem(){
	return this->item;
}
template <class Tipo>
No<Tipo> *No<Tipo>::getProx(){
	return prox;
}
template <class Tipo>
void No<Tipo>::setItem(Tipo item){
	this->item = item;
}
template <class Tipo>
void No<Tipo>::setNo(No<Tipo> *no){
	this->prox = no;
}
template <class Tipo>
class Lista{
private:
	No<Tipo> *prim;
	No<Tipo> *ult;
public:
	Lista();
	void Insere(Tipo);
	No<Tipo> Busca(Tipo);
	void Mostra();
	No<Tipo>* PredecessorDe(No<Tipo>*);
	void setPrim(No<Tipo> *);
	void setUlt(No<Tipo> *);
	No<Tipo> *getPrim();
	No<Tipo> *getUlt();
};
template <class Tipo>
void Lista<Tipo>::setPrim(No<Tipo> *prim){
	this->prim = prim;
}
template <class Tipo>
void Lista<Tipo>::setUlt(No<Tipo> *ult){
	this->ult = ult;
}
template <class Tipo>
No<Tipo> *Lista<Tipo>::getPrim(){
	return prim;
}
template <class Tipo>
No<Tipo> *Lista<Tipo>::getUlt(){
	return ult;
}
template <class Tipo>
Lista<Tipo>::Lista(){
	prim = new No<Tipo>();
	ult = prim;
}
template <class Tipo>
void Lista<Tipo>::Insere(Tipo item){
	ult->setNo(new No<Tipo>());
	ult = ult->getProx();
	ult->setItem(item);
}
template <class Tipo>
void Lista<Tipo>::Mostra(){
	No<Tipo> *p = prim->getProx();
	while(p!= NULL){
    	cout<<p->getItem().getChave()<<endl;
    	p = p->getProx();
    }
}
template <class Tipo>
No<Tipo> *Lista<Tipo>::PredecessorDe(No<Tipo> *r){
	No<Tipo> *p = prim;
	while(p->getProx()->getItem()->getNome() != r->getItem()->getNome()){
    	p = p->getProx();
	}
  	return p;
}
template <class Tipo>
No<Tipo> Lista<Tipo>::Busca(Tipo objeto){
	No<Tipo> *p = prim->getProx();
	while((p->getItem().getChave() != objeto.getChave())&&(p!=NULL)){
    	p = p->getProx();
  	}
  	return p;
}

class Comando{
private:
	string linhaDeCodigo;
public:
	Comando();
	Comando(string linhaDeCodigo);
	void setLinhaDeCodigo(string linhaDeCodigo);
	string getChave();
};
Comando::Comando(){
}
Comando::Comando(string linhaDeCodigo){
	this->linhaDeCodigo = linhaDeCodigo;
}
void Comando::setLinhaDeCodigo(string linhaDeCodigo){
	this->linhaDeCodigo = linhaDeCodigo;
}
string Comando::getChave(){
	return linhaDeCodigo;
}

class TabelaHashKinojo{
private:
  	AVL<Comando> programaKinojo;
  	string nome;
	int tamDaHash;
public:
  	TabelaHashKinojo();
  	TabelaHashKinojo(string nome, AVL<Comando> programaKinojo);
  	string getChave();
  	AVL<Comando> *getProgramaKinojo();
	int getTamDaHash();
	void setNome(string nome);
	void setProgramaKinojo(AVL<Comando> programaKinojo);
	void setTamDaHash(int tamDaHash);
};
TabelaHashKinojo::TabelaHashKinojo(){
	tamDaHash = 0;
}
TabelaHashKinojo::TabelaHashKinojo(string nome, AVL<Comando> programaKinojo){
  	this->nome=nome;
  	this->programaKinojo = programaKinojo;
}
string TabelaHashKinojo::getChave(){
	return nome;
}
AVL<Comando> *TabelaHashKinojo::getProgramaKinojo(){
	return &programaKinojo;
}
void TabelaHashKinojo::setNome(string nome){
	this->nome = nome;
}
void TabelaHashKinojo::setProgramaKinojo(AVL<Comando> programaKinojo){
	this->programaKinojo = programaKinojo;
}
void TabelaHashKinojo::setTamDaHash(int tamDaHash){
	this->tamDaHash=tamDaHash;
}
int TabelaHashKinojo::getTamDaHash(){
	return tamDaHash;
}

int funcaoHash(unsigned long long int k, int tamDaHash){
	int resultado = k%tamDaHash;
	return resultado;
}
unsigned long long int eleva(int potencia,int tamDaHash){
	unsigned long long int numero=1;
	for(int i=0; i<potencia; i++){
		numero *= 1000000007;
		numero = numero%tamDaHash;
	}
	return numero;
}
unsigned long long int converteParaInteiro(string k, int tamDaHash){
	int tam = (int)(k.size());
	int potencia=tam-1;
	unsigned long long int chaveEmInteiro=0;
	for(int i=0; i<tam; i++){
		chaveEmInteiro += ((int)(k[i])*eleva(potencia, tamDaHash))%tamDaHash;
		potencia--;
	}
	return chaveEmInteiro%tamDaHash;
}

void insereComandoNaTabela(TabelaHashKinojo *&tabela, Comando *comando, int tamDaHash){
	int chave = converteParaInteiro(comando->getChave(), tamDaHash);
	int i=funcaoHash(chave, tamDaHash);
	tabela[i].getProgramaKinojo()->insere(comando);
}

int primo(int nChaves){
	int cont=0;
	int maiorNPRimo = 0;
	for(int i=1; i<=nChaves; i++){
		for(int j=1; j<=i; j++){
			if(i%j==0){
				cont++;
			}
		}
		if(cont<=2){
			if(maiorNPRimo<i){
				maiorNPRimo = i;
			}
		}
		cont=0;
	}
	return maiorNPRimo;
}

void transfereTodos(Lista<Comando> &listaDeComandosA, TabelaHashKinojo *&resultado){
	No<Comando> *p = listaDeComandosA.getPrim()->getProx();
	while(p!=NULL){
		Comando *c = new Comando();
		c->setLinhaDeCodigo(p->getItem().getChave());
		insereComandoNaTabela(resultado, c, resultado->getTamDaHash());
		p= p->getProx();
	}
}

void verificaETransfere(Lista<Comando> &listaDeComandosA, TabelaHashKinojo *&resultado){
	No<Comando> *p = listaDeComandosA.getPrim()->getProx();
	while(p!=NULL){
    NoArvore<Comando> *no = new NoArvore<Comando>();
    int cont =0;
    for(int i=0; i<resultado->getTamDaHash(); i++){
      Comando c;
  		c.setLinhaDeCodigo(p->getItem().getChave());
      no = resultado[i].getProgramaKinojo()->busca(c);
      if(no!= NULL){
        cont++;
        break;
      }
    }
    if(cont==0){
      Comando *c = new Comando();
  		c->setLinhaDeCodigo(p->getItem().getChave());
      insereComandoNaTabela(resultado, c, resultado->getTamDaHash());
    }
		p = p->getProx();
	}
}

void transfere(Lista<Comando> &listaDeComandosA, Lista<Comando> &listaDeComandosB, TabelaHashKinojo *&resultado, string operacao){
	No<Comando> *p = listaDeComandosA.getPrim()->getProx();
	while(p!=NULL){
		No<Comando> *q = listaDeComandosB.getPrim();
		while(q!=NULL){
			if(p->getItem().getChave() == q->getItem().getChave()){
				if(operacao=="INTER"){
					Comando *c = new Comando();
					c->setLinhaDeCodigo(p->getItem().getChave());
					insereComandoNaTabela(resultado, c, resultado->getTamDaHash());
				}
			}
			q = q->getProx();
		}
		p = p->getProx();
	}
}

void transferePraUmVetor(NoArvore<Comando> *no, Lista<Comando> &listaDeComandos){
	if(no!=NULL){
		listaDeComandos.Insere(*no->getItem());
		transferePraUmVetor(no->getEsq(), listaDeComandos);
		transferePraUmVetor(no->getDir(), listaDeComandos);
	}
}

TabelaHashKinojo *comandoMinus(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >> comando;
	if(comando=="="){
		cin>> nomeTabelaA >> nomeTabelaB;
		tabelaA->setNome(nomeTabelaA);
		tabelaB->setNome(nomeTabelaB);
		NoArvore<TabelaHashKinojo> *A = new NoArvore<TabelaHashKinojo>();
		NoArvore<TabelaHashKinojo> *B = new NoArvore<TabelaHashKinojo>();
		A = TabelasHashKinojo.busca(*tabelaA);
		B = TabelasHashKinojo.busca(*tabelaB);
		if(A!=NULL){
			tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			tabelaB = B->getItem();
		}
		else{
			tabelaB = new TabelaHashKinojo[1];
			tabelaB->setTamDaHash(1);
		}
    Lista<Comando> listaDeComandosA, listaDeComandosB;
		transferePraUmVetor(tabelaA->getProgramaKinojo()->getRaiz(), listaDeComandosA);
		transferePraUmVetor(tabelaB->getProgramaKinojo()->getRaiz(), listaDeComandosB);
    int tamDaHash = 0;
		if(tabelaA->getTamDaHash()+tabelaB->getTamDaHash()>=4){
			int num = tabelaA->getTamDaHash()-tabelaB->getTamDaHash();
			if(num<2){
				TabelaHashKinojo *R = new TabelaHashKinojo();
				R->setNome("Operacao invalida");
				return R;
			}
			else{
        if(num!=2){
          tamDaHash = primo(num);
        }
        else{
          if(num==2){
            tamDaHash =2;
          }
        }
			}
		}
		else{
			tamDaHash = 1;
		}
		TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
		R->setTamDaHash(tamDaHash);
		R->setNome(nome);
		verificaETransfere(listaDeComandosB, R);
		return R;
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	return R;
}

TabelaHashKinojo *comandoInter(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >> comando;
	if(comando=="="){
		cin>> nomeTabelaA >> nomeTabelaB;
		tabelaA->setNome(nomeTabelaA);
		tabelaB->setNome(nomeTabelaB);
		NoArvore<TabelaHashKinojo> *A = new NoArvore<TabelaHashKinojo>();
		NoArvore<TabelaHashKinojo> *B = new NoArvore<TabelaHashKinojo>();
		A = TabelasHashKinojo.busca(*tabelaA);
		B = TabelasHashKinojo.busca(*tabelaB);
		if(A!=NULL){
			tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			tabelaB = B->getItem();
		}
		else{
			tabelaB = new TabelaHashKinojo[1];
			tabelaB->setTamDaHash(1);
		}
		int menorTam = tabelaA->getTamDaHash();
		if(menorTam>tabelaB->getTamDaHash()){
			menorTam = tabelaB->getTamDaHash();
		}
		TabelaHashKinojo *R = new TabelaHashKinojo[menorTam];
		R->setTamDaHash(menorTam);
		R->setNome(nome);
		if(A==NULL && B==NULL){
			R= new TabelaHashKinojo();
			return R;
		}
		Lista<Comando> listaDeComandosA, listaDeComandosB;
		for(int j=0; j<tabelaA->getTamDaHash(); j++){
			if(tabelaA[j].getProgramaKinojo()->getRaiz()!=NULL){
				transferePraUmVetor(tabelaA[j].getProgramaKinojo()->getRaiz(), listaDeComandosA);
			}
		}
		for(int j=0; j<tabelaB->getTamDaHash(); j++){
			if(tabelaB[j].getProgramaKinojo()->getRaiz()!=NULL){
				transferePraUmVetor(tabelaB[j].getProgramaKinojo()->getRaiz(), listaDeComandosB);
			}
		}
		transfere(listaDeComandosA, listaDeComandosB, R, "INTER");
		return R;
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	return R;
}

TabelaHashKinojo *comandoUnion(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >>comando;
	if(comando=="="){
		cin>> nomeTabelaA >> nomeTabelaB;
		tabelaA->setNome(nomeTabelaA);
		tabelaB->setNome(nomeTabelaB);
		NoArvore<TabelaHashKinojo> *A = new NoArvore<TabelaHashKinojo>();
		NoArvore<TabelaHashKinojo> *B = new NoArvore<TabelaHashKinojo>();
		A = TabelasHashKinojo.busca(*tabelaA);
		B = TabelasHashKinojo.busca(*tabelaB);
		if(A!=NULL){
			tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			tabelaB = B->getItem();
		}
		else{
			tabelaB = new TabelaHashKinojo[1];
			tabelaB->setTamDaHash(1);
		}
	}
	int contA = 0;
	int contB = 0;
	for(int i=0; i<tabelaA->getTamDaHash(); i++){
		if(tabelaA[i].getProgramaKinojo()->getRaiz()!= NULL){
			contA +=1;
		}
	}
	for(int i=0; i<tabelaB->getTamDaHash(); i++){
		if(tabelaB[i].getProgramaKinojo()->getRaiz()!= NULL){
			contB +=1;
		}
	}
	if(contA!=0 && contB!=0){
		int tamDaHash = 0;
		if(tabelaA->getTamDaHash()+tabelaB->getTamDaHash()>=4){
			tamDaHash = primo(tabelaA->getTamDaHash()+tabelaB->getTamDaHash());
		}
		else{
			tamDaHash = 1;
		}
		TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
		R->setTamDaHash(tamDaHash);
		R->setNome(nome);
		Lista<Comando> listaDeComandosA, listaDeComandosB;
    for(int i=0; i<tabelaA->getTamDaHash(); i++){
  		if(tabelaA[i].getProgramaKinojo()->getRaiz()!= NULL){
  		  transferePraUmVetor(tabelaA[i].getProgramaKinojo()->getRaiz(), listaDeComandosA);
        transfereTodos(listaDeComandosA, R);
  		}
  	}
    for(int i=0; i<tabelaB->getTamDaHash(); i++){
  		if(tabelaB[i].getProgramaKinojo()->getRaiz()!= NULL){
  		  transferePraUmVetor(tabelaB[i].getProgramaKinojo()->getRaiz(), listaDeComandosB);
        verificaETransfere(listaDeComandosB, R);
  		}
  	}
		return R;
	}
	else{
		if(contA!=0 && contB==0){
			int tamDaHash = tabelaA->getTamDaHash();
			TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
			Lista<Comando> listaDeComandosA;
      for(int i=0; i<tabelaA->getTamDaHash(); i++){
    		if(tabelaA[i].getProgramaKinojo()->getRaiz()!= NULL){
    		  transferePraUmVetor(tabelaA[i].getProgramaKinojo()->getRaiz(), listaDeComandosA);
          transfereTodos(listaDeComandosA, R);
    		}
    	}
			return R;
		}
		if(contA==0 && contB!=0){
			int tamDaHash = tabelaB->getTamDaHash();
			TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
			Lista<Comando> listaDeComandosB;
      for(int i=0; i<tabelaA->getTamDaHash(); i++){
    		if(tabelaA[i].getProgramaKinojo()->getRaiz()!= NULL){
    		  transferePraUmVetor(tabelaB[i].getProgramaKinojo()->getRaiz(), listaDeComandosB);
          transfereTodos(listaDeComandosB, R);
    		}
    	}
			return R;
		}
		if(contA==0 && contB==0){
			int menorTam = tabelaA->getTamDaHash();
			if(menorTam>tabelaB->getTamDaHash()){
				menorTam = tabelaB->getTamDaHash();
			}
			TabelaHashKinojo *R = new TabelaHashKinojo[menorTam];
			R->setTamDaHash(menorTam);
			R->setNome(nome);
			return R;
		}
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	return R;
}

void comandoPrint(AVL<TabelaHashKinojo> tabelas){
	string nomeDaTabela, entrada, chave;
	cin >> nomeDaTabela >> entrada;
	if(entrada == "KEY"){
		cin >> chave;
		TabelaHashKinojo *aSerPrintada = new TabelaHashKinojo();
		aSerPrintada->setNome(nomeDaTabela);
    NoArvore <TabelaHashKinojo> *no=new NoArvore <TabelaHashKinojo>();
    no = tabelas.busca(*aSerPrintada);
		if(no== NULL){
			cout <<"Tabela "<<aSerPrintada->getChave()<<" vazia"<<endl;
		}
		else{
			if(no->getItem()->getTamDaHash() != 0){
		    aSerPrintada = no->getItem();
		  	aSerPrintada->setTamDaHash(no->getItem()->getTamDaHash());
		    int k = converteParaInteiro(chave, aSerPrintada->getTamDaHash());
		    int i = funcaoHash(k, aSerPrintada->getTamDaHash());
				if(aSerPrintada[i].getProgramaKinojo()->getRaiz()!=NULL){
					Comando procurado;
					procurado.setLinhaDeCodigo(chave);
					NoArvore <Comando> *achado = new NoArvore <Comando>();
					achado = aSerPrintada[i].getProgramaKinojo()->busca(procurado);
					if(achado!=NULL){
						aSerPrintada[i].getProgramaKinojo()->Mostra("Central");
						cout<<endl;
					}
					else{
						cout<<"Chave "<< chave << " nao encontrada em Tabela " << aSerPrintada->getChave()<<endl;
					}
				}
				else{
					int c = 0;
					for(int j=0; j<aSerPrintada->getTamDaHash(); j++){
						if(aSerPrintada[j].getProgramaKinojo()->getRaiz()!=NULL){
							c++;
						}
					}
					if(c==0){
						cout <<"Tabela "<<aSerPrintada->getChave()<<" vazia"<<endl;
					}
					else{
						cout<<"Chave "<< chave << " nao encontrada em Tabela " << aSerPrintada->getChave()<<endl;
					}
				}
			}
			else{
				cout <<"Tabela "<<aSerPrintada->getChave()<<" vazia"<<endl;
			}
		}
	}
}

TabelaHashKinojo *comandoTH(){
  string nome,entrada,chave;
  int nChaves = 0;
  cin >> nome >> entrada >> nChaves;
	int tamDaHash = primo(nChaves/4);
	TabelaHashKinojo *aSerInserida = new TabelaHashKinojo[tamDaHash];
	aSerInserida->setTamDaHash(tamDaHash);
	aSerInserida->setNome(nome);
	if (entrada == "="){
		while(entrada != "."){
	  	for(int i = 0;i<nChaves;i++){
			Comando *comando=new Comando();
	    cin>>chave;
			comando->setLinhaDeCodigo(chave);
			insereComandoNaTabela(aSerInserida, comando, tamDaHash);
	  	}
	  	cin>>entrada;
		}
	}
	return aSerInserida;
}

int main(int argc, char const *argv[]) {
	AVL<TabelaHashKinojo> TabelasHashKinojo;
	string comando;
	cin>>comando;
	while(comando!="FIM"){
		if(comando == "TH"){
			TabelaHashKinojo *aux=new TabelaHashKinojo();
			aux = comandoTH();
			TabelasHashKinojo.insere(aux);
		}
		if(comando == "PRINT"){
			comandoPrint(TabelasHashKinojo);
		}
		if(comando == "UNION"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
	  	aux = comandoUnion(TabelasHashKinojo);
			TabelasHashKinojo.insere(aux);
		}
		if(comando == "INTER"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
		  aux = comandoInter(TabelasHashKinojo);
			TabelasHashKinojo.insere(aux);
		}
    if(comando == "MINUS"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
			aux = comandoMinus(TabelasHashKinojo);
			if(aux->getChave()!="Operacao invalida"){
				TabelasHashKinojo.insere(aux);
			}
			else{
				cout<<"Operacao invalida"<<endl;
			}
		}
		cin>>comando;
	}
	return 0;
}
