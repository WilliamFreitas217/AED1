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
	Tipo getItem();
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
NoArvore<Tipo>::NoArvore(Tipo item){
	this->item = item;
	this->esq = NULL;
  	this->dir = NULL;
}
template <class Tipo>
Tipo NoArvore<Tipo>::getItem(){
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
  	void insere(Tipo item, NoArvore<Tipo> *&no);
  	Tipo remove(Tipo &item, NoArvore<Tipo> *&no);
 	NoArvore<Tipo> *busca(Tipo &item, NoArvore<Tipo> *no);
  	void percorrePreOrdem(NoArvore<Tipo> *no);
	int h(NoArvore<Tipo> *no);
  	void percorrePosOrdem(NoArvore<Tipo> *no);
  	void percorreCentral(NoArvore<Tipo> *no);
 	Tipo remove_aux(NoArvore<Tipo> *&q, NoArvore<Tipo> *&r);
	void balancear(NoArvore<Tipo> *no);
	void RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe);
	void RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe);
	void RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2);
	void RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2);
public:
	AVL();
	void h();
	AVL(Tipo item);
	NoArvore<Tipo>*getRaiz();
  	void insere(Tipo item);
  	Tipo remove(Tipo &item);
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
AVL<Tipo>::AVL(Tipo item){
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
void AVL<Tipo>::RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe){
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
	calcularFbs(raiz);
}
template <class Tipo>
void AVL<Tipo>::RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe){
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
	calcularFbs(raiz);
}
template <class Tipo>
void AVL<Tipo>::RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2){
	RSD(noDesce, noSobe);
	RSE(noDesce2, noDesce);
}
template <class Tipo>
void AVL<Tipo>::RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2){
	RSE(noDesce, noSobe);
	RSD(noDesce2, noDesce);
}
template <class Tipo>
void AVL<Tipo>::calcularFbs(NoArvore<Tipo> *no){
	if(no!=NULL){
		int fb= ((-1)*h(no->getEsq()))+h(no->getDir());
		no->setFb(fb);
		calcularFbs(no->getEsq());
		calcularFbs(no->getDir());
	}
}
template <class Tipo>
void AVL<Tipo>::balancear(NoArvore<Tipo> *no){
	if(no!=NULL){
		calcularFbs(no);
		balancear(no->getEsq());
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
void AVL<Tipo>::insere(Tipo item, NoArvore<Tipo> *&no){
	if(no==NULL){
		no = new NoArvore<Tipo>();
		no->setItem(item);
		balancear();
	}
	else if(item.getChave()>no->getItem().getChave()){
		insere(item, no->getDir());
	}
	else if(item.getChave()<no->getItem().getChave()){
		insere(item, no->getEsq());
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
	else if(item.getChave()>no->getItem().getChave()){
		busca(item, no->getDir());
	}
	else if(item.getChave()<no->getItem().getChave()){
		busca(item, no->getEsq());
	}
	else{
		NoArvore<Tipo> *aux=new NoArvore<Tipo>();
		aux= no;
		item = no->getItem();
		return no;
	}
}

template <class Tipo>
void AVL<Tipo>::percorrePreOrdem(NoArvore<Tipo> *no){
	if(no!= NULL){
		cout<<no->getItem().getChave()<<endl;
		percorrePreOrdem(no->getEsq());
		percorrePreOrdem(no->getDir());
	}
}

template <class Tipo>
void AVL<Tipo>::percorreCentral(NoArvore<Tipo> *no){
	if(no!=NULL){
		percorreCentral(no->getEsq());
		cout<<no->getItem().getChave()<<endl;
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
Tipo AVL<Tipo>::remove_aux(NoArvore<Tipo> *&q, NoArvore<Tipo> *&r){
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
Tipo AVL<Tipo>::remove(Tipo &item, NoArvore<Tipo> *&no){
	if(no==NULL){
		return 0;
	}
	else if(item->getNome()<no->getItem()->getNome()){
		remove(item, no->getEsq());
	}
	else if(item->getNome()>no->getItem()->getNome()){
		remove(item, no->getDir());
	}
	else if(no->getDir()==NULL){
		NoArvore<Tipo> *aux =  new NoArvore<Tipo>();
		aux=no;
		no = no->getEsq();
		delete(aux);
	}
	else if(no->getEsq()==NULL){
		NoArvore<Tipo> *aux =  new NoArvore<Tipo>();
		aux=no;
		no = no->getDir();
		delete(aux);
	}
	else{
		cout<<"Achou!"<<endl;
		item = remove_aux(no, no->getEsq());
		return item;
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
int AVL<Tipo>::h(NoArvore<Tipo> *no){
	if(no!=NULL){
		if(no->getDir()==NULL && no->getEsq()==NULL){
			return 1;
		}
		else{
			int a, b;
			a = h(no->getEsq());
			b = h(no->getDir());
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
void AVL<Tipo>::h(){
	cout<<h(raiz)<<endl;
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
	void Remove(No<Tipo>*);
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
void Lista<Tipo>::Remove(No<Tipo> *r){
	if((r==prim)||(r==NULL)){
    	cout<<"vazia"<< endl;
  	}
  	else{
    	No<Tipo> *p = PredecessorDe(r);
    	p->setNo(Busca(r->getItem())->getProx());
    	if(p==NULL){
      		ult = p;
    	}
		if((p ==prim)&&(p->getProx()==ult)){
			ult=prim;
		}
    	delete r;
  	}
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
unsigned long long int eleva(unsigned long long int numero, int potencia, int tamDaHash){
	numero =1;
	for(int i=0; i<potencia; i++){
		numero *=1000000007;
		numero = numero %tamDaHash;
	}
	return numero;
}
unsigned long long int converteParaInteiro(string k, int tamDaHash){
	int tam = (int)(k.size());
	int potencia=tam-1;
	unsigned long long int chaveEmInteiro=0;
	for(int i=0; i<=tam; i++){
		chaveEmInteiro += ((int)(tolower(k[i]))*eleva(1000000007, potencia, tamDaHash))%tamDaHash;
		potencia--;
	}
	return chaveEmInteiro%tamDaHash;
}

void insereComandoNaTabela(TabelaHashKinojo *&tabela, Comando comando, int tamDaHash){
	int chave = converteParaInteiro(comando.getChave(), tamDaHash);
	int i=funcaoHash(chave, tamDaHash);
	tabela[i].getProgramaKinojo()->insere(comando);
}
int primo(int nChaves){
	int cont=0;
	int maiorNPRimo = 0;
	for(int i=1; i<=(int)(nChaves/4); i++){
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
		insereComandoNaTabela(resultado, p->getItem(), resultado->getTamDaHash());
		p= p->getProx();
	}
}
void verificaETransfere(Lista<Comando> &listaDeComandosA, Lista<Comando> &listaDeComandosB, TabelaHashKinojo *&resultado){
	No<Comando> *p = listaDeComandosA.getPrim()->getProx();
	bool temIgualdade = false;
	while(p!=NULL){
		No<Comando> *q = listaDeComandosB.getPrim();
		while(q!=NULL){
			if(p->getItem().getChave() == q->getItem().getChave()){
				temIgualdade = true;
			}
			q = q->getProx();
		}
		if(temIgualdade==false){
			insereComandoNaTabela(resultado, p->getItem(), resultado->getTamDaHash());
		}
		temIgualdade = false;
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
					insereComandoNaTabela(resultado, p->getItem(), resultado->getTamDaHash());
				}
			}
			q = q->getProx();
		}
		p = p->getProx();
	}
}

void transferePraUmVetor(NoArvore<Comando> *no, Lista<Comando> &listaDeComandos){
	if(no!=NULL){
		listaDeComandos.Insere(no->getItem());
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
			*tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			*tabelaB = B->getItem();
		}
		else{
			tabelaB = new TabelaHashKinojo[1];
			tabelaB->setTamDaHash(1);
		}
		int tamDaHash = 0;
		if(tabelaA->getTamDaHash()+tabelaB->getTamDaHash()>=4){
			tamDaHash = primo(tabelaA->getTamDaHash()-tabelaB->getTamDaHash());
		}
		else{
			tamDaHash = 1;
		}

		if(tamDaHash<0){
			tamDaHash*=-1;
		}
		TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
		R->setTamDaHash(tamDaHash);
		R->setNome(nome);
		Lista<Comando> listaDeComandosA, listaDeComandosB;
		transferePraUmVetor(tabelaA->getProgramaKinojo()->getRaiz(), listaDeComandosA);
		transferePraUmVetor(tabelaB->getProgramaKinojo()->getRaiz(), listaDeComandosB);
		verificaETransfere(listaDeComandosA, listaDeComandosB, R);
		return R;
	}
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
			*tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			*tabelaB = B->getItem();
		}
		else{
			tabelaB = new TabelaHashKinojo[1];
			tabelaB->setTamDaHash(1);
		}
		int menorTam = tabelaA->getTamDaHash();
		int caso =1;
		if(menorTam>tabelaB->getTamDaHash()){
			menorTam = tabelaB->getTamDaHash();
			caso =2;
		}
		TabelaHashKinojo *R = new TabelaHashKinojo[menorTam];
		R->setTamDaHash(menorTam);
		R->setNome(nome);
		if(A==NULL && B==NULL){
			R= new TabelaHashKinojo();
			return R;
		}
		Lista<Comando> listaDeComandosA, listaDeComandosB;
		transferePraUmVetor(tabelaA->getProgramaKinojo()->getRaiz(), listaDeComandosA);
		transferePraUmVetor(tabelaB->getProgramaKinojo()->getRaiz(), listaDeComandosB);
		transfere(listaDeComandosA, listaDeComandosB, R, "INTER");
		return R;
	}
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
			*tabelaA = A->getItem();
		}
		else{
			tabelaA = new TabelaHashKinojo[1];
			tabelaA->setTamDaHash(1);
		}
		if(B!=NULL){
			*tabelaB = B->getItem();
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
		transferePraUmVetor(tabelaA->getProgramaKinojo()->getRaiz(), listaDeComandosA);
		transferePraUmVetor(tabelaB->getProgramaKinojo()->getRaiz(), listaDeComandosB);
		transfereTodos(listaDeComandosA, R);
		verificaETransfere(listaDeComandosB, listaDeComandosA, R);
		return R;
	}
	else{
		if(contA!=0 && contB==0){
			int tamDaHash = tabelaA->getTamDaHash();
			TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
			Lista<Comando> listaDeComandosA;
			transferePraUmVetor(tabelaA->getProgramaKinojo()->getRaiz(), listaDeComandosA);
			transfereTodos(listaDeComandosA, R);
			return R;
		}
		if(contA==0 && contB!=0){
			int tamDaHash = tabelaB->getTamDaHash();
			TabelaHashKinojo *R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
			Lista<Comando> listaDeComandosB;
			transferePraUmVetor(tabelaB->getProgramaKinojo()->getRaiz(), listaDeComandosB);
			transfereTodos(listaDeComandosB, R);
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
    	*aSerPrintada = no->getItem();
  		aSerPrintada->setTamDaHash(no->getItem().getTamDaHash());
    	int k = converteParaInteiro(chave, aSerPrintada->getTamDaHash());
    	int i = funcaoHash(k, aSerPrintada->getTamDaHash());
		if(i+1 > aSerPrintada->getTamDaHash()){
			cout<<"Chave "<< chave << "não encontrada em tabelas " << aSerPrintada->getChave()<<endl;
		}
		if(aSerPrintada[i].getProgramaKinojo()->getRaiz() == NULL){
			cout <<"tabelas "<<aSerPrintada->getChave()<<" vazia"<<endl;
		}
		else{
			cout<<"PRINT"<<endl;
			aSerPrintada[i].getProgramaKinojo()->Mostra("Central");
			cout<<endl;
		}
	}
}

TabelaHashKinojo *comandoTH(){
  	string nome,entrada,chave;
  	int nChaves = 0;
  	cin >> nome >> entrada >> nChaves;
	int tamDaHash = primo(nChaves);
	TabelaHashKinojo *aSerInserida = new TabelaHashKinojo[tamDaHash];
	aSerInserida->setTamDaHash(tamDaHash);
	aSerInserida->setNome(nome);
	if (entrada == "="){
		while(entrada != "."){
			Comando comando;
		  	for(int i = 0;i<nChaves;i++){
		    	cin>>chave;
				comando.setLinhaDeCodigo(chave);
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
	cout<<"Digite o comando"<<endl;
	cin>>comando;
	while(comando!="FIM"){
		if(comando == "TH"){
			TabelaHashKinojo aux;
			aux = *comandoTH();
		  	TabelasHashKinojo.insere(aux);
		}
		if(comando == "PRINT"){
			comandoPrint(TabelasHashKinojo);
		}
		if(comando == "UNION"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
	  		aux = comandoUnion(TabelasHashKinojo);
			TabelasHashKinojo.insere(*aux);
		}
		if(comando == "INTER"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
		  	aux = comandoInter(TabelasHashKinojo);
			TabelasHashKinojo.insere(*aux);
		}
		if(comando == "MINUS"){
			TabelaHashKinojo *aux = new TabelaHashKinojo();
			aux = comandoMinus(TabelasHashKinojo);
			TabelasHashKinojo.insere(*aux);
		}
		cin>>comando;
	  }
	  return 0;
}
