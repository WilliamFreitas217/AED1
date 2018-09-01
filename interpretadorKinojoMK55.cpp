//Equipe
// William do Vale Cavalcante Freitas - 1615080545
// Artur da Silva Santos - 1615080247
#include <iostream>
#include<cstdlib>
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
  	NoAVL<Tipo> *predecessor(NoAVL<Tipo> *no, NoAVL<Tipo> *&no2);
  	int insere(Tipo &item, NoAVL<Tipo> *&no);
 	  NoAVL<Tipo> *busca(Tipo &item, NoAVL<Tipo> *no);
  	void percorreCentral(NoAVL<Tipo> *no, string &s);
	void balancear(NoAVL<Tipo> *no);
	void RSE(NoAVL<Tipo> *&noDesce);
	void RSD(NoAVL<Tipo> *&noDesce);
	void RDE(NoAVL<Tipo> *&noDesce);
	void RDD(NoAVL<Tipo> *&noDesce);
public:
	AVL();
	AVL(Tipo &item);
	NoAVL<Tipo>*getRaiz();
  	void insere(Tipo &item);
	NoAVL<Tipo> *busca(Tipo &item);
  	void percorreCentral();
	void Mostra(string ordem);
	void calcularFbs(NoAVL<Tipo> *no);
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
NoAVL<Tipo>*AVL<Tipo>::getRaiz(){
	return raiz;
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
          // cout<<"RSD"<<endl;
          return 0;
        }
        else{
          if(no->getEsq()->getFb()!=0){
            // cout<<"RDD"<<endl;
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
          // cout<<"RSE"<<endl;
          return 0;
        }
        else{
          if(no->getDir()->getFb()!=0){
            RDE(no);
            no->setFb(0);
            // cout<<"RDE"<<endl;
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
void AVL<Tipo>::percorreCentral(){
  	string s;
	percorreCentral(raiz, s);
  	// cout<<s;
}
template <class Tipo>
NoAVL<Tipo> *AVL<Tipo>::busca(Tipo &item){
	return busca(item, raiz);
}

template <class Tipo>
NoAVL<Tipo> *AVL<Tipo>::busca(Tipo &item, NoAVL<Tipo> *no){
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
void AVL<Tipo>::percorreCentral(NoAVL<Tipo> *no, string &s){
	if(no!=NULL){
		percorreCentral(no->getEsq(), s);
    	s+= no->getItem().getChave()+" ";
		percorreCentral(no->getDir(), s);
	}
}

template <class Tipo>
void AVL<Tipo>::Mostra(string ordem){
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
  	void insereComandoNaTabela(Comando comando);
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

void TabelaHashKinojo::insereComandoNaTabela(Comando comando){
	int chave = converteParaInteiro(comando.getChave());
	int i=funcaoHash(chave);
	programasKinojo[i].insere(comando);
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

void transferir(NoAVL<Comando> *no, TabelaHashKinojo *&resultado){
  if(no!=NULL){
    transferir(no->getEsq(), resultado);
    Comando c;
    c.setLinhaDeCodigo(no->getItem().getChave());
    resultado->insereComandoNaTabela(c);
    transferir(no->getDir(), resultado);
  }
}

void conferirETransferir(NoAVL<Comando> *no, TabelaHashKinojo *tabelaInter, TabelaHashKinojo *resultado, string operacao){
  if(no!=NULL){
    conferirETransferir(no->getEsq(), tabelaInter, resultado, operacao);
    Comando c;
    c.setLinhaDeCodigo(no->getItem().getChave());
    int cont = 0;
    for(int i=0; i<resultado->getTamDaHash(); i++){
      if(resultado->getProgramasKinojo()[i].getRaiz()!=NULL){
        Comando cAux;
        cAux.setLinhaDeCodigo(no->getItem().getChave());
        NoAVL<Comando> *noAux = resultado->getProgramasKinojo()[i].busca(cAux);
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

TabelaHashKinojo *comandoMinus(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo tabelaA;
	TabelaHashKinojo tabelaB;
	cin>>nome >> comando >> nomeTabelaA >> nomeTabelaB;
	tabelaA.setNome(nomeTabelaA);
	tabelaB.setNome(nomeTabelaB);
	NoAVL<TabelaHashKinojo> *A = new NoAVL<TabelaHashKinojo>();
	NoAVL<TabelaHashKinojo> *B = new NoAVL<TabelaHashKinojo>();
	A = TabelasHashKinojo.busca(tabelaA);
	B = TabelasHashKinojo.busca(tabelaB);
	if(A!=NULL){
		tabelaA = A->getItem();
	}
	if(B!=NULL){
		tabelaB = B->getItem();
	}
  	int tamDaHash = 0;
	if(tabelaA.getTamDaHash()+tabelaB.getTamDaHash()>=4){
		int num = tabelaA.getTamDaHash()-tabelaB.getTamDaHash();
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
	TabelaHashKinojo *R = new TabelaHashKinojo();
	R->setTamDaHash(tamDaHash);
	R->setNome(nome);
  	for(int i=0; i<tabelaA.getTamDaHash(); i++){
		if(tabelaA.getProgramasKinojo()[i].getRaiz()!= NULL){
      		transferir(tabelaA.getProgramasKinojo()[i].getRaiz(), R);
    	}
  	}
	for(int i=0; i<tabelaB.getTamDaHash(); i++){
		if(tabelaB.getProgramasKinojo()[i].getRaiz()!= NULL){
      		TabelaHashKinojo *t = new TabelaHashKinojo();
      		conferirETransferir(tabelaB.getProgramasKinojo()[i].getRaiz(),t, R, "MINUS");
   		}
	}
  	darZeroPraEle(R);
	return R;
}

TabelaHashKinojo *comandoInter(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo tabelaA;
	TabelaHashKinojo tabelaB;
	cin>>nome >> comando;
	cin>> nomeTabelaA >> nomeTabelaB;
	tabelaA.setNome(nomeTabelaA);
	tabelaB.setNome(nomeTabelaB);
	NoAVL<TabelaHashKinojo> *A = new NoAVL<TabelaHashKinojo>();
	NoAVL<TabelaHashKinojo> *B = new NoAVL<TabelaHashKinojo>();
	A = TabelasHashKinojo.busca(tabelaA);
	B = TabelasHashKinojo.busca(tabelaB);
	if(A!=NULL){
		tabelaA = A->getItem();
	}
	if(B!=NULL){
		tabelaB = B->getItem();
	}
	int menorTam = tabelaA.getTamDaHash();
	if(menorTam>tabelaB.getTamDaHash()){
		menorTam = tabelaB.getTamDaHash();
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	R->setTamDaHash(menorTam);
	R->setNome(nome);
	for(int j=0; j<tabelaA.getTamDaHash(); j++){
		if(tabelaA.getProgramasKinojo()[j].getRaiz()!=NULL){
      conferirETransferir(tabelaA.getProgramasKinojo()[j].getRaiz(), R, &tabelaB, "INTER");
		}
	}
  	darZeroPraEle(R);
	return R;
}

TabelaHashKinojo *comandoUnion(AVL<TabelaHashKinojo> TabelasHashKinojo){
	string nome, nomeTabelaA, nomeTabelaB, comando;
	TabelaHashKinojo tabelaA;
	TabelaHashKinojo tabelaB;
	cin>>nome >>comando;
	cin>> nomeTabelaA >> nomeTabelaB;
	tabelaA.setNome(nomeTabelaA);
	tabelaB.setNome(nomeTabelaB);
	NoAVL<TabelaHashKinojo> *A = new NoAVL<TabelaHashKinojo>();
	NoAVL<TabelaHashKinojo> *B = new NoAVL<TabelaHashKinojo>();
	A = TabelasHashKinojo.busca(tabelaA);
	B = TabelasHashKinojo.busca(tabelaB);
	if(A!=NULL){
		tabelaA = A->getItem();
	}
	if(B!=NULL){
		tabelaB = B->getItem();
	}
	int tamDaHash = 0;
	if(tabelaA.getTamDaHash()+tabelaB.getTamDaHash()>=4){
		tamDaHash = primo(tabelaA.getTamDaHash()+tabelaB.getTamDaHash());
	}
	TabelaHashKinojo *R = new TabelaHashKinojo();
	R->setTamDaHash(tamDaHash);
	R->setNome(nome);
  	for(int i=0; i<tabelaA.getTamDaHash(); i++){
		if(tabelaA.getProgramasKinojo()[i].getRaiz()!= NULL){
		  	transferir(tabelaA.getProgramasKinojo()[i].getRaiz(), R);
		}
	}
  	for(int i=0; i<tabelaB.getTamDaHash(); i++){
		if(tabelaB.getProgramasKinojo()[i].getRaiz()!= NULL){
      		TabelaHashKinojo *t = new TabelaHashKinojo();
		  	conferirETransferir(tabelaB.getProgramasKinojo()[i].getRaiz(),t, R, "UNION");
		}
	}
  	darZeroPraEle(R);
	return R;
}

void comandoPrint(AVL<TabelaHashKinojo> tabelas){
  	string nomeDaTabela, entrada, chave;
	cin >> nomeDaTabela >> entrada >> chave;
  	TabelaHashKinojo aSerPrintada;
  	aSerPrintada.setNome(nomeDaTabela);
  	NoAVL <TabelaHashKinojo> *no=tabelas.busca(aSerPrintada);
	if(no== NULL){
		cout <<"Tabela "<<aSerPrintada.getChave()<<" vazia"<<endl;
	}
	else{
	    aSerPrintada = no->getItem();
	    if(aSerPrintada.getTamDaHash()==0){
	      	cout <<"Tabela "<<aSerPrintada.getChave()<<" vazia"<<endl;
	    }
	    else{
	      	int k = aSerPrintada.converteParaInteiro(chave);
		    int i = aSerPrintada.funcaoHash(k);
			if(aSerPrintada.getProgramasKinojo()[i].getRaiz()!=NULL){
				Comando procurado;
				procurado.setLinhaDeCodigo(chave);
				NoAVL <Comando> *achado = new NoAVL <Comando>();
				achado = aSerPrintada.getProgramasKinojo()[i].busca(procurado);
				if(achado!=NULL){
					aSerPrintada.getProgramasKinojo()[i].Mostra("Central");
					cout<<endl;
				}
				else{
					cout<<"Chave "<< chave << " nao encontrada em Tabela " << aSerPrintada.getChave()<<endl;
				}
      		}
	      	else{
	        	cout<<"Chave "<< chave << " nao encontrada em Tabela " << nomeDaTabela<<endl;
	      	}
	    }
	}
}

TabelaHashKinojo comandoTH(){
  	string nome,entrada,chave;
  	int nChaves = 0;
  	cin >> nome >> entrada >> nChaves;
	int tamDaHash = primo(nChaves/4);
	TabelaHashKinojo aSerInserida;
  	aSerInserida.setNome(nome);
	aSerInserida.setTamDaHash(tamDaHash);
	for(int i = 0;i<nChaves;i++){
		Comando comando;
    	cin>>chave;
		comando.setLinhaDeCodigo(chave);
		aSerInserida.insereComandoNaTabela(comando);
	}
	return aSerInserida;
}

int main() {
	AVL<TabelaHashKinojo> TabelasHashKinojo;
	string comando;
	cin>>comando;
	while(comando!="FIM"){
		if(comando == "TH"){
			TabelaHashKinojo aux;
			aux = comandoTH();
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
			if(aux->getChave()!="Operacao invalida"){
				TabelasHashKinojo.insere(*aux);
			}
			else{
				cout<<"Operacao invalida"<<endl;
			}
		}
		cin>>comando;
	}
  TabelasHashKinojo.Mostra("Central");
	return 0;
}
