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
  	void insere(Tipo *&item, NoArvore<Tipo> *&no,NoArvore<Tipo> *&pai);
 	NoArvore<Tipo> *busca(Tipo &item, NoArvore<Tipo> *no);
  	void percorrePreOrdem(NoArvore<Tipo> *no);
	int h(NoArvore<Tipo> *no);
  	void percorrePosOrdem(NoArvore<Tipo> *no);
  	void percorreCentral(NoArvore<Tipo> *no, string &s);
	void balancear(NoArvore<Tipo> *no);
	void RSE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RSD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noPai, bool veioDeDupla);
	void RDE(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
	void RDD(NoArvore<Tipo> *&noDesce, NoArvore<Tipo> *&noSobe, NoArvore<Tipo> *&noDesce2, NoArvore<Tipo> *&noPai);
public:
	AVL();
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
	insere(item, raiz,raiz);
}

template <class Tipo>
void AVL<Tipo>::insere(Tipo *&item, NoArvore<Tipo> *&no, NoArvore<Tipo> *&pai){
	if(no==NULL){
		no = new NoArvore<Tipo>();
		no->setItem(item);
		no->setFb(0);
	}
	else if(item->getChave()>no->getItem()->getChave()){
		no->setFb(no->getFb()+1);
		insere(item, no->getDir(), no);
		if(no->getFb()>1 && no->getDir()->getFb()>=0){
			RSE(no, no->getDir(), pai, false);
		}
		if(no->getFb()>1 && no->getDir()->getFb()<0){
			RDE(no->getDir(), no->getDir()->getEsq(), no, pai);
		}
	}
	else if(item->getChave()<no->getItem()->getChave()){
		no->setFb(no->getFb()-1);
		insere(item, no->getEsq(), no);
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
  string s;
	percorreCentral(raiz, s);
  cout<<s;
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
void AVL<Tipo>::percorreCentral(NoArvore<Tipo> *no, string &s){
	if(no!=NULL){
		percorreCentral(no->getEsq(), s);
    s+= no->getItem()->getChave()+" ";
		percorreCentral(no->getDir(), s);
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
  AVL<Comando> *programasKinojo;
  string nome;
	int tamDaHash;
public:
  TabelaHashKinojo();
  TabelaHashKinojo(string nome, int tamDaHash);
  string getChave();
  AVL<Comando> *&getProgramasKinojo();
	int getTamDaHash();
	void setNome(string nome);
	void setProgramaKinojo(AVL<Comando> *programasKinojo);
	void setTamDaHash(int tamDaHash);
  int funcaoHash(unsigned long long int k);
  unsigned long long int eleva(int potencia);
  unsigned long long int converteParaInteiro(string k);
  void insereComandoNaTabela(Comando *comando);
};
TabelaHashKinojo::TabelaHashKinojo(){
	tamDaHash = 0;
  programasKinojo = new AVL<Comando>[tamDaHash];
}
TabelaHashKinojo::TabelaHashKinojo(string nome, int tamDaHash){
  	this->nome=nome;
    this->tamDaHash = tamDaHash;
  	programasKinojo = new AVL<Comando>[tamDaHash];
}
string TabelaHashKinojo::getChave(){
	return nome;
}
AVL<Comando> *&TabelaHashKinojo::getProgramasKinojo(){
	return programasKinojo;
}
void TabelaHashKinojo::setNome(string nome){
	this->nome = nome;
}
void TabelaHashKinojo::setProgramaKinojo(AVL<Comando> *programasKinojo){
	this->programasKinojo = programasKinojo;
}
void TabelaHashKinojo::setTamDaHash(int tamDaHash){
	this->tamDaHash=tamDaHash;
  programasKinojo =  new AVL<Comando>[tamDaHash];
}
int TabelaHashKinojo::getTamDaHash(){
	return tamDaHash;
}
int TabelaHashKinojo::funcaoHash(unsigned long long int k){
	int resultado = k%tamDaHash;
	return resultado;
}
unsigned long long int TabelaHashKinojo::eleva(int potencia){
	unsigned long long int numero=1;
	for(int i=0; i<potencia; i++){
		numero *= 1000000007;
		numero = numero%tamDaHash;
	}
	return numero;
}
unsigned long long int TabelaHashKinojo::converteParaInteiro(string k){
	int tam = (int)(k.size());
	int potencia=tam-1;
	unsigned long long int chaveEmInteiro=0;
	for(int i=0; i<tam; i++){
		chaveEmInteiro += ((int)(k[i])*eleva(potencia))%tamDaHash;
		potencia--;
	}
	return chaveEmInteiro%tamDaHash;
}

void TabelaHashKinojo::insereComandoNaTabela(Comando *comando){
	int chave = converteParaInteiro(comando->getChave());
	int i=funcaoHash(chave);
	programasKinojo[i].insere(comando);
}

void MostraAux(TabelaHashKinojo *aux){
  cout<<"Nome:::: "<<aux->getChave()<<endl;
  for(int i=0; i<aux->getTamDaHash(); i++){
    cout<<"Posicao::: "<< i<<endl;
    aux->getProgramasKinojo()[i].Mostra("Central");
    cout<<endl;
  }
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

// ------------------------------------------------------------------------------------------------
void transferir(NoArvore<Comando> *no, TabelaHashKinojo *&resultado){
  if(no!=NULL){
    transferir(no->getEsq(), resultado);
    Comando *c = new Comando();
    c->setLinhaDeCodigo(no->getItem()->getChave());
    resultado->insereComandoNaTabela(c);
    transferir(no->getDir(), resultado);
  }
}

void conferirETransferir(NoArvore<Comando> *no, TabelaHashKinojo *&tabelaInter, TabelaHashKinojo *&resultado, string operacao){
  if(no!=NULL){
    conferirETransferir(no->getEsq(), tabelaInter, resultado, operacao);
    Comando *c = new Comando();
    c->setLinhaDeCodigo(no->getItem()->getChave());
    int cont = 0;
    for(int i=0; i<resultado->getTamDaHash(); i++){
      if(resultado->getProgramasKinojo()[i].getRaiz()!=NULL){
        Comando cAux;
        cAux.setLinhaDeCodigo(no->getItem()->getChave());
        NoArvore<Comando> *noAux = resultado->getProgramasKinojo()[i].busca(cAux);
        if(noAux !=NULL){
          cont++;
          break;
        }
      }
    }
    if(cont==0 && (operacao == "UNION" || operacao == "MINUS")){
      resultado->insereComandoNaTabela(c);
    }
    if(cont!=0 && operacao == "INTER"){
      tabelaInter->insereComandoNaTabela(c);
    }
    conferirETransferir(no->getDir(), tabelaInter, resultado, operacao);
  }
}
void darZeroPraEle(TabelaHashKinojo *&resultado){
  int cont=0;
  for(int j=0; j<resultado->getTamDaHash(); j++){
    if(resultado->getProgramasKinojo()[j].getRaiz()!=NULL){
      cont++;
    }
  }
  if(cont==0){
    resultado->setTamDaHash(0);
  }
}
// ------------------------------------------------------------------------------------------------
TabelaHashKinojo *comandoMinus(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >> comando >> nomeTabelaA >> nomeTabelaB;
	tabelaA->setNome(nomeTabelaA);
	tabelaB->setNome(nomeTabelaB);
	NoArvore<TabelaHashKinojo> *A = new NoArvore<TabelaHashKinojo>();
	NoArvore<TabelaHashKinojo> *B = new NoArvore<TabelaHashKinojo>();
	A = TabelasHashKinojo.busca(*tabelaA);
	B = TabelasHashKinojo.busca(*tabelaB);
	if(A!=NULL){
		tabelaA = A->getItem();
	}
	if(B!=NULL){
		tabelaB = B->getItem();
	}
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
	TabelaHashKinojo *R = new TabelaHashKinojo();
	R->setTamDaHash(tamDaHash);
	R->setNome(nome);
  for(int i=0; i<tabelaA->getTamDaHash(); i++){
		if(tabelaA->getProgramasKinojo()[i].getRaiz()!= NULL){
      transferir(tabelaA->getProgramasKinojo()[i].getRaiz(), R);
    }
  }
  for(int i=0; i<tabelaB->getTamDaHash(); i++){
		if(tabelaB->getProgramasKinojo()[i].getRaiz()!= NULL){
      TabelaHashKinojo *t = new TabelaHashKinojo();
      conferirETransferir(tabelaB->getProgramasKinojo()[i].getRaiz(),t, R, "MINUS");
    }
  }
  darZeroPraEle(R);
	return R;
}

TabelaHashKinojo *comandoInter(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >> comando;
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
	if(B!=NULL){
		tabelaB = B->getItem();
	}
	int menorTam = tabelaA->getTamDaHash();
	if(menorTam>tabelaB->getTamDaHash()){
		menorTam = tabelaB->getTamDaHash();
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	R->setTamDaHash(menorTam);
	R->setNome(nome);
	if(A==NULL && B==NULL){
		R= new TabelaHashKinojo();
		return R;
	}
	for(int j=0; j<tabelaA->getTamDaHash(); j++){
		if(tabelaA->getProgramasKinojo()[j].getRaiz()!=NULL){
      conferirETransferir(tabelaA->getProgramasKinojo()[j].getRaiz(), R, tabelaB, "INTER");
		}
	}
  darZeroPraEle(R);
	return R;
}

TabelaHashKinojo *comandoUnion(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo *tabelaA = new TabelaHashKinojo();
	TabelaHashKinojo *tabelaB = new TabelaHashKinojo();
	cin>>nome >>comando;
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
	if(B!=NULL){
		tabelaB = B->getItem();
	}
	int contA = 0;
	int contB = 0;
	for(int i=0; i<tabelaA->getTamDaHash(); i++){
		if(tabelaA->getProgramasKinojo()[i].getRaiz()!= NULL){
			contA +=1;
      break;
		}
	}
	for(int i=0; i<tabelaB->getTamDaHash(); i++){
		if(tabelaB->getProgramasKinojo()[i].getRaiz()!= NULL){
			contB +=1;
      break;
		}
	}
	if(contA!=0 && contB!=0){
		int tamDaHash = 0;
		if(tabelaA->getTamDaHash()+tabelaB->getTamDaHash()>=4){
			tamDaHash = primo(tabelaA->getTamDaHash()+tabelaB->getTamDaHash());
		}
		TabelaHashKinojo *R = new TabelaHashKinojo();
		R->setTamDaHash(tamDaHash);
		R->setNome(nome);
    for(int i=0; i<tabelaA->getTamDaHash(); i++){
  		if(tabelaA->getProgramasKinojo()[i].getRaiz()!= NULL){
  		  transferir(tabelaA->getProgramasKinojo()[i].getRaiz(), R);
  		}
  	}
    for(int i=0; i<tabelaB->getTamDaHash(); i++){
  		if(tabelaB->getProgramasKinojo()[i].getRaiz()!= NULL){
        TabelaHashKinojo *t = new TabelaHashKinojo();
  		  conferirETransferir(tabelaB->getProgramasKinojo()[i].getRaiz(),t, R, "UNION");
  		}
  	}
    darZeroPraEle(R);
		return R;
	}
	else{
    TabelaHashKinojo *R =  new TabelaHashKinojo();
		if(contA!=0 && contB==0){
			int tamDaHash = tabelaA->getTamDaHash();
			R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
      for(int i=0; i<tabelaA->getTamDaHash(); i++){
    		if(tabelaA->getProgramasKinojo()[i].getRaiz()!= NULL){
    		  transferir(tabelaA->getProgramasKinojo()[i].getRaiz(), R);
    		}
    	}
		}
		if(contA==0 && contB!=0){
			int tamDaHash = tabelaB->getTamDaHash();
			R = new TabelaHashKinojo[tamDaHash];
			R->setTamDaHash(tamDaHash);
			R->setNome(nome);
      for(int i=0; i<tabelaB->getTamDaHash(); i++){
    		if(tabelaB->getProgramasKinojo()[i].getRaiz()!= NULL){
    		  transferir(tabelaB->getProgramasKinojo()[i].getRaiz(), R);
    		}
    	}
		}
		if(contA==0 && contB==0){
			int menorTam = tabelaA->getTamDaHash();
			if(menorTam>tabelaB->getTamDaHash()){
				menorTam = tabelaB->getTamDaHash();
			}
			R = new TabelaHashKinojo[menorTam];
			R->setTamDaHash(menorTam);
			R->setNome(nome);
		}
    darZeroPraEle(R);
    return R;
  }
}

void comandoPrint(AVL<TabelaHashKinojo> tabelas){
  string nomeDaTabela, entrada, chave;
	cin >> nomeDaTabela >> entrada >> chave;
  TabelaHashKinojo *aSerPrintada = new TabelaHashKinojo();
  aSerPrintada->setNome(nomeDaTabela);
  NoArvore <TabelaHashKinojo> *no=tabelas.busca(*aSerPrintada);
  if(no== NULL){
		cout <<"Tabela "<<aSerPrintada->getChave()<<" vazia"<<endl;
	}
  else{
    aSerPrintada = no->getItem();
    if(aSerPrintada->getTamDaHash()==0){
      cout <<"Tabela "<<aSerPrintada->getChave()<<" vazia"<<endl;
    }
    else{
      int k = aSerPrintada->converteParaInteiro(chave);
	    int i = aSerPrintada->funcaoHash(k);
			if(aSerPrintada->getProgramasKinojo()[i].getRaiz()!=NULL){
				Comando procurado;
				procurado.setLinhaDeCodigo(chave);
				NoArvore <Comando> *achado = new NoArvore <Comando>();
				achado = aSerPrintada->getProgramasKinojo()[i].busca(procurado);
				if(achado!=NULL){
					aSerPrintada->getProgramasKinojo()[i].Mostra("Central");
					cout<<endl;
				}
				else{
					cout<<"Chave "<< chave << " nao encontrada em Tabela " << aSerPrintada->getChave()<<endl;
				}
      }
      else{
        cout<<"Chave "<< chave << " nao encontrada em Tabela " << nomeDaTabela<<endl;
      }
    }
  }
}

TabelaHashKinojo *comandoTH(){
  string nome,entrada,chave;
  int nChaves = 0;
  cin >> nome >> entrada >> nChaves;
	int tamDaHash = primo(nChaves/4);
	TabelaHashKinojo *aSerInserida = new TabelaHashKinojo();
	aSerInserida->setTamDaHash(tamDaHash);
	aSerInserida->setNome(nome);
	if (entrada == "="){
		while(entrada != "."){
	  	for(int i = 0;i<nChaves;i++){
			Comando *comando=new Comando();
	    cin>>chave;
			comando->setLinhaDeCodigo(chave);
			aSerInserida->insereComandoNaTabela(comando);
	  	}
	  	cin>>entrada;
		}
	}
	return aSerInserida;
}

int main() {
	AVL<TabelaHashKinojo> TabelasHashKinojo;
	string comando;
	cin>>comando;
	while(comando!="FIM"){
		if(comando == "TH"){
			TabelaHashKinojo *aux=new TabelaHashKinojo();
			aux = comandoTH();
      // MostraAux(aux);
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
  // TabelaHashKinojo aux;
  // aux.setNome("kages");
  // NoArvore<TabelaHashKinojo> *no = TabelasHashKinojo.busca(aux);
  // if(no!=NULL){
  //   // MostraAux(no->getItem());
  // }
  // else{
  //   cout<<"nao"<<endl;
  // }
	return 0;
}
