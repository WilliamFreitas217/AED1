// Equipe 8
// William do Vale Cavalcante Freitas - 1615080545
// Artur da Silva Santos - 1615080247

#include <iostream>
#include<cstdlib>
using namespace std;

template <class Tipo>
class No{
private:
	Tipo *item;
	No *prox;
public:
	No();
	No(Tipo*);
	void setItem(Tipo*);
	void setNo(No<Tipo> *);
	void cria();
	Tipo *getItem();
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
No<Tipo>::No(Tipo *item){
	this->item = item;
	this->prox = NULL;
}
template <class Tipo>
Tipo *No<Tipo>::getItem(){
	return this->item;
}
template <class Tipo>
No<Tipo> *No<Tipo>::getProx(){
	return prox;
}
template <class Tipo>
void No<Tipo>::setItem(Tipo *item){
	this->item = item;
}
template <class Tipo>
void No<Tipo>::setNo(No<Tipo> *no){
	this->prox = no;
}

template <class Tipo>
class PilhaDinamica{
private:
	No<Tipo> *topo;
	No<Tipo> *fundo;
public:
	PilhaDinamica();
	No<Tipo> *getTopo();
	No<Tipo> *getFundo();
	void empilha(Tipo*);
	Tipo* desempilha(Tipo *);
	void Mostra();
};
template <class Tipo>
PilhaDinamica<Tipo>::PilhaDinamica(){
	topo = new No<Tipo>();
	fundo = topo;
}
template <class Tipo>
void PilhaDinamica<Tipo>::empilha(Tipo *item){
	No<Tipo> *aux = new No<Tipo>();
	topo->setItem(item);
	aux->setNo(topo);
	topo = aux;
}

template <class Tipo>
No<Tipo> *PilhaDinamica<Tipo>::getTopo(){
	return topo;
}

template <class Tipo>
No<Tipo> *PilhaDinamica<Tipo>::getFundo(){
	return fundo;
}

template <class Tipo>
void PilhaDinamica<Tipo>::Mostra(){
	No<Tipo> *p = topo->getProx();
	while(p!= NULL){
    p->getItem()->print();
    p = p->getProx();
  	}
}

template <class Tipo>
Tipo *PilhaDinamica<Tipo>::desempilha(Tipo *item){
	No<Tipo> *aux = topo;
	item = new Tipo;
	topo = topo->getProx();
	item = topo->getItem();
	delete aux;
	return item;
}

template <class Tipo>
class FilaDinamica{
private:
	No<Tipo> *frente;
	No<Tipo> *tras;
public:
	FilaDinamica();
	No<Tipo> *getFrente();
	No<Tipo> *getTras();
	void enfileira(Tipo*);
	Tipo* desenfileira(Tipo*);
	void Mostra();
};

template <class Tipo>
FilaDinamica<Tipo>::FilaDinamica(){
	frente = new No<Tipo>();
	tras= frente;
}
template <class Tipo>
No<Tipo> *FilaDinamica<Tipo>::getFrente(){
	return frente;
}
template <class Tipo>
No<Tipo> *FilaDinamica<Tipo>::getTras(){
	return tras;
}
template <class Tipo>
void FilaDinamica<Tipo>::enfileira(Tipo *item){
	tras->setNo(new No<Tipo>());
	tras = tras->getProx();
	tras->setItem(item);
}

template <class Tipo>
Tipo* FilaDinamica<Tipo>::desenfileira(Tipo *item){
 	No<Tipo> *p = frente;
	item = new Tipo;
 	frente = frente->getProx();
	item = frente->getItem();
	delete p;
	return item;
}

template <class Tipo>
class Lista{
private:
	No<Tipo> *prim;
	No<Tipo> *ult;
public:
	Lista();
	void Insere(Tipo*);
	void Remove(No<Tipo>*);
	No<Tipo> *Busca(Tipo*);
	void Mostra();
	No<Tipo>* PredecessorDe(No<Tipo>*);
	void setPrim(No<Tipo> *);
	void setUlt(No<Tipo> *);
	No<Tipo> *getPrim();
	No<Tipo> *getUlt();
	No<Tipo> *menor();
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
void Lista<Tipo>::Insere(Tipo *item){
	ult->setNo(new No<Tipo>());
	ult = ult->getProx();
	ult->setItem(item);
}
template <class Tipo>
void Lista<Tipo>::Mostra(){
	No<Tipo> *p = prim->getProx();
	while(p!= NULL){
    	p->getItem()->print();
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
No<Tipo> *Lista<Tipo>::Busca(Tipo *objeto){
	No<Tipo> *p = prim->getProx();
	while((p->getItem()->getNome() != objeto->getNome())&&(p!=NULL)){
    	p = p->getProx();
  	}
  	return p;
}

template <class Tipo>
No<Tipo> *Lista<Tipo>::menor(){
	No<Tipo> *p = prim->getProx();
	No<Tipo> *menor = prim->getProx();
	while(p!= NULL){
		if(menor->getItem()->getForca()>p->getItem()->getForca()){
			menor = p;
		}
		p = p->getProx();
	}
	return menor;
}

class Caidos{
private:
	string nome;
	string raca;
	unsigned long long int forca;
public:
	Caidos();
	Caidos(string, string, unsigned long long int);
	void setNome(string);
	void setRaca(string);
 	void setForca(unsigned long long int);
 	string getNome();
 	string getRaca();
 	unsigned long long int getForca();
 	void print();
};
Caidos::Caidos(){}
Caidos::Caidos(string nome, string raca,unsigned long long int forca){
	this->nome = nome;
	this->raca = raca;
	this->forca	= forca;
}
void Caidos::setNome(string nome){
	this->nome = nome;
}
void Caidos::setRaca(string raca){
	this->raca = raca;
}
void Caidos::setForca(unsigned long long int forca){
	this->forca = forca;
}
string Caidos::getNome(){
	return nome;
}
string Caidos::getRaca(){
	return raca;
}
unsigned long long int Caidos::getForca(){
	return forca;
}
void Caidos::print(){
	cout<<nome<<", "<<forca<<", "<<raca<<endl;
}

class Soldado {
private:
	string nome;
	string raca;
	unsigned long long int forca;
	FilaDinamica<Caidos> soldadosCaidos;
public:
	Soldado();
	Soldado(string, string,unsigned long long int);
	void setNome(string);
	void setRaca(string);
	void setForca(unsigned long long int);
	string getNome();
	string getRaca();
	unsigned long long int getForca();
	FilaDinamica<Caidos> *getSoldadosCaidos();
	Caidos *entregaSoldadoCaido(Caidos*);
	void addSoldadoCaido(Caidos *);
	Caidos *cair();
	void print();
};

Soldado::Soldado(){
}
Soldado::Soldado(string nome, string raca, unsigned long long int forca){
	this->nome = nome;
	this->raca = raca;
	this->forca	= forca;
}
void Soldado::setNome(string nome){
	this->nome = nome;
}
void Soldado::setRaca(string raca){
	this->raca = raca;
}
void Soldado::setForca(unsigned long long int forca){
	this->forca = forca;
}
string Soldado::getNome(){
	return nome;
}
string Soldado::getRaca(){
	return raca;
}
unsigned long long int Soldado::getForca(){
	return forca;
}
FilaDinamica<Caidos> *Soldado::getSoldadosCaidos(){
	return &soldadosCaidos;
}
void Soldado::addSoldadoCaido(Caidos *caido){
	this->forca += caido->getForca();
	soldadosCaidos.enfileira(caido);
}
Caidos *Soldado::entregaSoldadoCaido(Caidos* maisVelho){
	maisVelho = getSoldadosCaidos()->desenfileira(maisVelho);
	return maisVelho;
}
void Soldado::print(){
	cout<<"["<<nome<< " "<<raca<<" "<<forca<<"]";
}
Caidos *Soldado::cair(){
	Caidos *soldadoCaido= new Caidos;
	soldadoCaido->setNome(nome);
	soldadoCaido->setRaca(raca);
	soldadoCaido->setForca(forca);
	return soldadoCaido;
}

class Tropa{
private:
	PilhaDinamica<Soldado> tropa;
	long double forcaDaTropa;
	int numeroDeSoldados;
public:
	Tropa();
	Tropa(PilhaDinamica<Soldado>);
	PilhaDinamica<Soldado> *getTropa();
	long double getForcaDaTropa();
	void setForcaDaTropa(long double);
	void addSoldado(Soldado*);
	Soldado* removeSoldado(Soldado*);
	void entrarEmFormacao();
	void chamada();
	void setNumDeSoldados(int);
	int getNumeroDeSoldados();
};

Tropa::Tropa(){
	forcaDaTropa = 0;
	numeroDeSoldados = 0;
}
Tropa::Tropa(PilhaDinamica<Soldado> tropa){
	this->tropa = tropa;
}
PilhaDinamica<Soldado> *Tropa::getTropa(){
	return &tropa;
}
long double Tropa::getForcaDaTropa(){
	return forcaDaTropa;
}
int	Tropa::getNumeroDeSoldados(){
	return numeroDeSoldados;
}
void Tropa::setForcaDaTropa(long double forca){
	forcaDaTropa = forca;
}
void Tropa::setNumDeSoldados(int numero){
	numeroDeSoldados = numero;
}
void Tropa::addSoldado(Soldado *soldado){
	setForcaDaTropa(forcaDaTropa+soldado->getForca());
	setNumDeSoldados(getNumeroDeSoldados()+1);
	tropa.empilha(soldado);
}
Soldado* Tropa::removeSoldado(Soldado* soldadoRemovido){
	soldadoRemovido = tropa.desempilha(soldadoRemovido);
	setForcaDaTropa(forcaDaTropa-soldadoRemovido->getForca());
	setNumDeSoldados(getNumeroDeSoldados()-1);
	return soldadoRemovido;
}
void Tropa::chamada(){
	tropa.Mostra();
}
void Tropa::entrarEmFormacao(){
	Lista<Soldado> corrigir;
	No<Soldado> *aux = tropa.getTopo()->getProx();
	while(aux!=NULL){
		Soldado *soldado = removeSoldado(soldado);
		corrigir.Insere(soldado);
		aux = aux->getProx();
	}
	while (corrigir.getPrim()->getProx()!=NULL) {
		No<Soldado> *soldadoMaisFraco = corrigir.menor();
		addSoldado(soldadoMaisFraco->getItem());
		No<Soldado> *aSerRemovido = new No<Soldado>(soldadoMaisFraco->getItem());
		corrigir.Remove(aSerRemovido);
	}
}

class FileiraDoSantuario{
private:
	Lista<Caidos> linha;
public:
	FileiraDoSantuario();
	void setLinha(Lista<Caidos>);
	Lista<Caidos> *getLinha();
	unsigned long long int getForcaDasAlmas();
};
FileiraDoSantuario::FileiraDoSantuario(){
}
void FileiraDoSantuario::setLinha(Lista<Caidos> linha){
	this->linha= linha;
}
Lista<Caidos> *FileiraDoSantuario::getLinha(){
	return &linha;
}
unsigned long long int FileiraDoSantuario::getForcaDasAlmas(){
	No<Caidos> *p = linha.getPrim()->getProx();
	unsigned long long int Forca=0;
	while(p!=NULL){
		Forca += p->getItem()->getForca();
		p =	p->getProx();
	}
	return Forca;
}

Tropa** cria(){
	Tropa **campoDeBatalha = new Tropa*[10];
	for(int i=0; i<10; i++){
		campoDeBatalha[i]=new Tropa[10];
	}
	return campoDeBatalha;
}

int funcaoHash(unsigned long long int k){
	int resultado = k%43;
	return resultado;
}

unsigned long long int eleva(unsigned long long int numero, int potencia){
	numero =1;
	for(int i=0; i<potencia; i++){
		numero *=31;
		numero = numero %43;
	}
	return numero;
}
unsigned long long int converteParaInteiro(string k){
	int tam = (int)(k.size());
	int potencia=tam-1;
	unsigned long long int chaveEmInteiro=0;
	for(int i=0; i<=tam; i++){
		chaveEmInteiro += ((int)(tolower(k[i]))*eleva(31, potencia))%43;
		potencia--;
	}
	return chaveEmInteiro%43;
}

void encadeamentoHashInsere(FileiraDoSantuario *lista, Caidos *soldado){
	string conc = soldado->getNome()+soldado->getRaca();
	int chave =converteParaInteiro(conc);
	int i=funcaoHash(chave);
	lista[i].getLinha()->Insere(soldado);
}

bool verificaRaca(Tropa tropaA, Tropa tropaB){
	if(tropaA.getTropa()->getTopo()->getProx()->getItem()->getRaca()==tropaB.getTropa()->getTopo()->getProx()->getItem()->getRaca()){
		return true;
	}
	else{
		return false;
	}
}

bool taLivre(Tropa** campoDeBatalha, int i2, int j2){
	if(campoDeBatalha[i2][j2].getNumeroDeSoldados()== 0){
		return true;
	}
	else{
		return false;
	}
}
void contarSoldados(Tropa *tropa){
	int cont = 0;
	No<Soldado> *p = tropa->getTropa()->getTopo()->getProx();
	while(p!= NULL){
		cont++;
		p=	p->getProx();
	}
	tropa->setNumDeSoldados(cont);
}
void posicionar(Tropa** campoDeBatalha, Tropa tropa, int i, int j){
	if(taLivre(campoDeBatalha, i, j)){
		campoDeBatalha[i][j]=tropa;
		campoDeBatalha[i][j].entrarEmFormacao();
		contarSoldados(&campoDeBatalha[i][j]);
	}
	else{
		if(verificaRaca(campoDeBatalha[i][j], tropa)){
			campoDeBatalha[i][j].getTropa()->empilha(tropa.getTropa()->getTopo()->getProx()->getItem());
			contarSoldados(&campoDeBatalha[i][j]);
			campoDeBatalha[i][j].entrarEmFormacao();
			campoDeBatalha[i][j].setForcaDaTropa(campoDeBatalha[i][j].getForcaDaTropa()+tropa.getForcaDaTropa());

		}
	}
}

Tropa** arrumarCampoEspelho(Tropa** campoDeBatalha, Tropa** campoDeBatalhaEspelhado){
	campoDeBatalhaEspelhado= cria();
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			No<Soldado> *p = new No<Soldado>();
			p = campoDeBatalha[i][j].getTropa()->getTopo()->getProx();
			if(p!=NULL){
				Tropa tropaEspelho2;
				while(p!=NULL){
					string nomeEspelho = p->getItem()->getNome();
					string racaEspelho = p->getItem()->getRaca();
					unsigned long long int forcaEspelho = p->getItem()->getForca();
					FilaDinamica<Caidos> *capturados= new FilaDinamica<Caidos>();
					capturados =	p->getItem()->getSoldadosCaidos();
					No<Caidos> *aux = capturados->getFrente()->getProx();
					Soldado *soldadoEspelho2 = new Soldado();
					soldadoEspelho2->setNome(nomeEspelho);
					soldadoEspelho2->setRaca(racaEspelho);
					while(aux!=NULL){
						soldadoEspelho2->addSoldadoCaido(aux->getItem());
						aux = aux->getProx();
					}
					forcaEspelho -= soldadoEspelho2->getForca();
					soldadoEspelho2->setForca(forcaEspelho+soldadoEspelho2->getForca());
					tropaEspelho2.addSoldado(soldadoEspelho2);
					p = p->getProx();
				}
				posicionar(campoDeBatalhaEspelhado, tropaEspelho2, i, j);
			}
		}
	}
	return campoDeBatalhaEspelhado;
}

void removeTropa(Tropa *tropa){
	No<Soldado> *p = tropa->getTropa()->getTopo()->getProx();
	while(p!= NULL){
		Soldado *soldado = new Soldado();
		soldado = tropa->getTropa()->desempilha(soldado);
		p=	p->getProx();
	}
	tropa->setForcaDaTropa(0);
	tropa->setNumDeSoldados(0);
}

void adicionarTropa(Tropa *tropaA, Tropa *tropaB){
	No<Soldado> *p = tropaA->getTropa()->getTopo()->getProx();
	int cont = 0;
	while(p!= NULL){
		Soldado *soldado =	new Soldado();
		soldado=tropaA->getTropa()->desempilha(soldado);
		tropaA->setNumDeSoldados(tropaA->getNumeroDeSoldados()-1);
		tropaB->getTropa()->empilha(soldado);
		cont++;
		tropaB->setNumDeSoldados(cont);
		p=	p->getProx();
	}
	tropaB->setForcaDaTropa(tropaA->getForcaDaTropa());
}

Tropa** verificaEMovimenta(Tropa** campoDeBatalha, int i1, int j1, int i2, int j2, FileiraDoSantuario *santuario, int caso){
	if(campoDeBatalha[i1][j1].getTropa()->getTopo()->getProx()!=NULL){
		if(taLivre(campoDeBatalha, i2, j2)){
			adicionarTropa(&campoDeBatalha[i1][j1], &campoDeBatalha[i2][j2]);
			campoDeBatalha[i2][j2].entrarEmFormacao();
			return campoDeBatalha;
		}
		else{
			if(verificaRaca(campoDeBatalha[i1][j1], campoDeBatalha[i2][j2])&&(caso==1)){
				No<Soldado> *p = campoDeBatalha[i1][j1].getTropa()->getTopo()->getProx();
				while (p!=NULL) {
					campoDeBatalha[i2][j2].addSoldado(p->getItem());
					p = p->getProx();
				}
				removeTropa(&campoDeBatalha[i1][j1]);
				campoDeBatalha[i2][j2].entrarEmFormacao();
				return campoDeBatalha;
			}
			else{
				if(campoDeBatalha[i1][j1].getForcaDaTropa()>campoDeBatalha[i2][j2].getForcaDaTropa()){
					No<Soldado> *p = campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx();
					if(p->getItem()->getSoldadosCaidos()->getFrente()->getProx()!=NULL){
						Caidos *capturado = new Caidos();
						capturado = campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx()->getItem()->entregaSoldadoCaido(capturado);
						encadeamentoHashInsere(santuario, capturado);
						if(caso==1){
							cout<<"Ataque bem sucedido"<<endl;
						}
						return campoDeBatalha;
					}
					else{
						Soldado *lider= new Soldado();
						lider = campoDeBatalha[i2][j2].removeSoldado(lider);
						Caidos *liderCaido= lider->cair();
						campoDeBatalha[i1][j1].getTropa()->getTopo()->getProx()->getItem()->addSoldadoCaido(liderCaido);
						campoDeBatalha[i1][j1].setForcaDaTropa(campoDeBatalha[i1][j1].getForcaDaTropa()+liderCaido->getForca());
						if(campoDeBatalha[i2][j2].getNumeroDeSoldados()==0){
							removeTropa(&campoDeBatalha[i2][j2]);
							adicionarTropa(&campoDeBatalha[i1][j1], &campoDeBatalha[i2][j2]);
							removeTropa(&campoDeBatalha[i1][j1]);
							campoDeBatalha[i2][j2].entrarEmFormacao();
							No<Soldado> *q = campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx();
							unsigned long long int forca = 0;
							while(q!=NULL){
								forca+=q->getItem()->getForca();
								q = q->getProx();
							}
							campoDeBatalha[i2][j2].setForcaDaTropa(forca);
						}
						if(taLivre(campoDeBatalha, i1, j1)){
							if(caso==3){
								cout<< "unidade "<< campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx()->getItem()->getNome()<<"+"<<campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx()->getItem()->getRaca()<< " avanca para ("<<i2<< ", "<<j2<< ")"<< endl;
							}
							if(caso==1){
								cout<<"Ataque bem sucedido"<<endl;
								cout<< "unidade "<< campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx()->getItem()->getNome()<<"+"<<campoDeBatalha[i2][j2].getTropa()->getTopo()->getProx()->getItem()->getRaca()<< " avanca para ("<<i2<< ", "<<j2<< ")"<< endl;
							}
							return campoDeBatalha;
						}
						else{
							if(caso==1){
								cout<<"Ataque bem sucedido"<<endl;
							}
							return campoDeBatalha;
						}
					}
					if(campoDeBatalha[i1][j1].getForcaDaTropa()==campoDeBatalha[i2][j2].getForcaDaTropa()){
						return campoDeBatalha;
					}
				}
				else{
					if(campoDeBatalha[i1][j1].getForcaDaTropa()<=(campoDeBatalha[i2][j2].getForcaDaTropa()*2/3)){
						Soldado *soldado =	new Soldado();
						soldado = campoDeBatalha[i1][j1].getTropa()->getTopo()->getProx()->getItem();
						string conc = soldado->getNome()+soldado->getRaca();
						int indiceDeConsulta = funcaoHash(converteParaInteiro(conc));
						long double forcaExtra = santuario[indiceDeConsulta].getForcaDasAlmas()*0.7;
						long double forcaDasAlmas= forcaExtra+campoDeBatalha[i1][j1].getForcaDaTropa();
						if(forcaDasAlmas>(campoDeBatalha[i2][j2].getForcaDaTropa())){
							campoDeBatalha[i1][j1].setForcaDaTropa(forcaDasAlmas);
							campoDeBatalha = verificaEMovimenta(campoDeBatalha, i1, j1, i2, j2, santuario, caso);
							campoDeBatalha[i1][j1].setForcaDaTropa((campoDeBatalha[i1][j1].getForcaDaTropa()-forcaDasAlmas)+(forcaDasAlmas-forcaExtra));
							return campoDeBatalha;
						}
						else{
							if(caso==1){
								cout<<"Contra-ataque!"<<endl;
								caso = 3;
							}
							campoDeBatalha = verificaEMovimenta(campoDeBatalha, i2, j2, i1, j1, santuario, caso);
							return campoDeBatalha;
						}
					}
					else{
						return campoDeBatalha;
					}
				}
			}
		}
	}
	else{
		return campoDeBatalha;
	}
}

bool valida(int linha,int coluna){
	if((linha>=0)&&(linha<10)){
		if((coluna>=0)&&(coluna<10)){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}

bool sondar(int x1, int y1, int x2, int y2){
	int matriz[48];
	int indice=0;
	int xAux= x1-3;
	int yAux = y1;
	for(int k=0; k<3; k++){
		matriz[indice]=xAux;
		matriz[indice+1]=yAux;
		indice+=2;
		xAux++;
		yAux++;
	}
	for(int k=0; k<3; k++){
		matriz[indice]=xAux;
		matriz[indice+1]=yAux;
		indice+=2;
		xAux++;
		yAux--;
	}
	for(int k=0; k<3; k++){
		matriz[indice]=xAux;
		matriz[indice+1]=yAux;
		indice+=2;
		xAux--;
		yAux--;
	}
	for(int k=0; k<3; k++){
		matriz[indice]=xAux;
		matriz[indice+1]=yAux;
		indice+=2;
		xAux--;
		yAux++;
	}
	indice =0;
	for(indice=0; indice<23; indice+=2){
		if((x2==matriz[indice])&&(y2==matriz[indice+1])){
			return true;
		}
	}
	return false;
}

Tropa** movimenta(Tropa** campoDeBatalha, int i1, int j1, int i2, int j2, FileiraDoSantuario *santuario, int caso){
	if(sondar(i1,j1, i2, j2)){
		campoDeBatalha = verificaEMovimenta(campoDeBatalha, i1, j1, i2, j2, santuario, caso);
		return campoDeBatalha;
	}
	else{
		return campoDeBatalha;
	}
}

void forca_raca(Tropa** campoDeBatalha, string raca){
	unsigned long long int forcaTotalDaRaca=0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(!taLivre(campoDeBatalha, i, j)){
				if(campoDeBatalha[i][j].getTropa()->getTopo()->getProx()->getItem()->getRaca()==raca){
					forcaTotalDaRaca +=campoDeBatalha[i][j].getForcaDaTropa();
				}
			}
		}
	}
	cout<< forcaTotalDaRaca<< endl;
}

void forcaUta(Tropa tropa){
	if(tropa.getTropa()->getTopo()->getProx()!=NULL){
		unsigned long long int forca = tropa.getForcaDaTropa();
		cout<<forca<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
}
void terr(Tropa tropa){
	if(tropa.getTropa()->getTopo()->getProx()==NULL){
		cout<<"[ ]"<<endl;
	}
	else{
		if(tropa.getTropa()->getTopo()->getProx()->getProx()==NULL){
			tropa.chamada();
			cout<<endl;
		}
		else{
			unsigned long long int forca = tropa.getForcaDaTropa();
			cout<<"[["<<tropa.getTropa()->getTopo()->getProx()->getItem()->getNome()<<" "<<tropa.getTropa()->getTopo()->getProx()->getItem()->getRaca()<<" "<<forca<<"]]"<<endl;
		}
	}
}
long double resultadoDoCombate(Tropa** campoDeBatalha, string chave){
	long double r=0;
	for(int linha = 0; linha<10; linha++){
		for(int coluna = 0; coluna<10; coluna++){
			No<Soldado> *p = campoDeBatalha[linha][coluna].getTropa()->getTopo()->getProx();
			if((p!=NULL)&&((p->getItem()->getNome()+p->getItem()->getRaca())==chave)){
				r =campoDeBatalha[linha][coluna].getForcaDaTropa();
			}
		}
	}
	return r;
}
void max_ataque(Tropa**campoDeBatalha, Tropa**campoDeBatalhaDoMax, int i, int j, FileiraDoSantuario *santuarioDoMax, int caso){
	if(taLivre(campoDeBatalha, i, j)){
		cout<<"-1"<<endl;
	}
	else{
		campoDeBatalhaDoMax = arrumarCampoEspelho(campoDeBatalha, campoDeBatalhaDoMax);
		unsigned long long int forcas[12];
		for(int k = 0; k<12; k++){
			forcas[k]=0;
		}
		int indice=0;
		long double r =0;
		No<Soldado> *p = campoDeBatalhaDoMax[i][j].getTropa()->getTopo()->getProx();
		string chave = p->getItem()->getNome()+p->getItem()->getRaca();
		bool temUnidadeNoAlcance = false;
		if(campoDeBatalhaDoMax[i][j].getForcaDaTropa()==0){
			cout<<"0"<<endl;
		}
		else{
			for(int k = 0; k<10; k++){
				for(int l = 0; l<10; l++){
					if(sondar(i, j, k, l)){
						if(!taLivre(campoDeBatalha, k, l)){
							if(!verificaRaca(campoDeBatalhaDoMax[i][j], campoDeBatalhaDoMax[k][l])){
								campoDeBatalhaDoMax = movimenta(campoDeBatalhaDoMax, i, j, k, l, santuarioDoMax, 2);
								r = resultadoDoCombate(campoDeBatalhaDoMax, chave);
								if(r==0){
									campoDeBatalhaDoMax = arrumarCampoEspelho(campoDeBatalha, campoDeBatalhaDoMax);
									r = resultadoDoCombate(campoDeBatalhaDoMax, chave);
								}
								forcas[indice]=r;
								indice++;
								temUnidadeNoAlcance = true;
								campoDeBatalhaDoMax = arrumarCampoEspelho(campoDeBatalha, campoDeBatalhaDoMax);
							}
						}
					}
				}
			}
			if(temUnidadeNoAlcance){
				unsigned long long int maior = forcas[0];
				for(int k=1; k<12; k++){
					if(maior<forcas[k]){
						maior= forcas[k];
					}
				}
			cout<<maior<<endl;
			}
			else{
				cout<<"-1"<<endl;
			}
		}
	}
}
unsigned long long int converteForca(string k){
	unsigned long long int potDez = 1;
	for(int i=0; i<(int)(k.size()-1); i++){
		potDez*=10;
	}
	unsigned long long int num=0;
	string c="";
	for(int i=0; i<(int)(k.size()); i++){
		c = k[i];
		num+= atoi(c.c_str())*potDez;
		potDez /=10;
	}
	return num;
}
void inserirCapturadoNaFila(string capturado, Soldado *soldado){
	string nome,raca,forcaString;
	int ind = 0;
	unsigned long long int forca=0;
	while(capturado[ind]!=' '){
		nome += capturado[ind];
		ind++;
	}
	ind++;
	while(capturado[ind]!=' '){
		raca += capturado[ind];
		ind++;
	}
	ind++;
	while(capturado[ind]!='\0'&&capturado[ind]!=' '){
		forcaString += capturado[ind];
		ind++;
	}
	forca = converteForca(forcaString);
	Caidos *caido= new Caidos(nome, raca, forca);
	soldado->addSoldadoCaido(caido);
}
void soldadoCapturado(string entrada,int pos, Soldado* soldado){
	string soldCapturado = "";
	int cont = 0;
	while(entrada[pos]!='\0'){
		if(entrada[pos]==' ' || entrada[pos+1]=='\0'){
			cont++;
		}
		soldCapturado += entrada[pos];
		if (cont==3){
			inserirCapturadoNaFila(soldCapturado, soldado);
			soldCapturado = "";
			cont = 0;
		}
		pos++;
	}
}
void inserirSoldNoSantuario(string sold, FileiraDoSantuario *santuario, FileiraDoSantuario *santuarioEspelho){
	if(sold!=""){
		string nome,raca,forcaString;
		unsigned long long int forca;
		int ind = 0;
		while(sold[ind]!=' '){
			nome += sold[ind];
			ind++;
		}
		ind++;
		while(sold[ind]!=' '){
			raca += sold[ind];
			ind++;
		}
		ind++;
		while(sold[ind]!='\0'&& sold[ind]!=' '){
			forcaString += sold[ind];
			ind++;
		}
		forca = converteForca(forcaString);
		Caidos *caido= new Caidos(nome, raca, forca);
		Caidos *caidoEspelho= new Caidos(nome, raca, forca);
		encadeamentoHashInsere(santuario, caido);
		encadeamentoHashInsere(santuarioEspelho, caidoEspelho);
	}
}
bool verificaExistencia(Tropa **campoDeBatalha, string raca){
	int cont =0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(campoDeBatalha[i][j].getTropa()->getTopo()->getProx()!=NULL){
				if(campoDeBatalha[i][j].getTropa()->getTopo()->getProx()->getItem()->getRaca()==raca){
					cont++;
				}
			}
		}
	}
	if((cont==0)){
		return false;
	}
	else{
		return true;
	}
}

int main(int argc, char const *argv[]) {
	FileiraDoSantuario *santuario = new FileiraDoSantuario[43];
	FileiraDoSantuario *santuarioEspelho = new FileiraDoSantuario[43];
	Tropa **campoDeBatalha = cria();
	Tropa **campoDeBatalhaEspelhado=cria();
	string entrada = "UTA";
	string nome,raca,capturados;
	unsigned long long int forca;
	int i,j;
	int cont = 1;
	int I=0, U=0, A=0;
	while(entrada!="FIM"){
		if(cont!= 1){
			cin>>entrada;
		}
		if(entrada == "UTA"){
			while(entrada=="UTA"){
				cin>>nome>>raca>>i>>j>>forca;
				if(i<10 && i>=0){
					if(j<10 && j>=0){
						getline(cin,capturados);
						if(capturados.size() == 0){
							Tropa tropa;
							Soldado *soldado;
							soldado = new Soldado(nome, raca, forca);
							if(raca=="UMASHI"){
								U=1;
							}
							if(raca=="AZURI"){
								A=1;
							}
							if(raca=="IANTECO"){
								I=1;
							}
							tropa.addSoldado(soldado);
							posicionar(campoDeBatalha, tropa, i, j);
						}
						else{
							Tropa tropa;
							Soldado *soldado;
							soldado = new Soldado(nome, raca, forca);
							if(raca=="UMASHI"){
								U=1;
							}
							if(raca=="AZURI"){
								A=1;
							}
							if(raca=="IANTECO"){
								I=1;
							}
							soldadoCapturado(capturados,1, soldado);
							tropa.addSoldado(soldado);
							posicionar(campoDeBatalha, tropa, i, j);
						}
					}
				}
			cin>>entrada;
			}
		}
		if(entrada == "STO"){
			string almas;

			getline(cin,almas);
			while(almas!= "CMD"){
				inserirSoldNoSantuario(almas, santuario, santuarioEspelho);
				getline(cin,almas);
			}
			if(almas == "CMD"){
				entrada = "CMD";
			}
		}
		if(I==0){
			I=2;
		}
		if(U==0){
			U=2;
		}
		if(A==0){
			A=2;
		}
		if(entrada == "CMD"){
			string comando;
			cin>>comando;
			while(comando!= "FIM"){
				if(comando!="FORCA_RACA"){
					cin>>i;
					cin>>j;
				}
				if(comando=="FORCA"){
					if(valida(i, j)){
						forcaUta(campoDeBatalha[i][j]);
					}
					else{
						cout<<"-1"<<endl;
					}
				}
				if(comando=="TERR"){
					if(valida(i, j)){
						terr(campoDeBatalha[i][j]);
					}
					else{
						cout<<"[ ]"<<endl;
					}
				}
				if(comando=="MOVA"){
					int i2, j2, existe;
					cin>>i2;
					cin>>j2;
					if(valida(i, j)&&valida(i2, j2)){
					campoDeBatalha = movimenta(campoDeBatalha, i, j, i2, j2, santuario, 1);
					if(U!=0){
						existe = verificaExistencia(campoDeBatalha, "UMASHI");
						if(!existe){
							if(U!=2){
								cout<<"UMASHI foi eliminada"<<endl;
								U=0;
							}
							if((U==0)&&(A==0)){
								if(I!=2){
									cout<<"IANTECO tem supremacia sobre Tau!"<<endl;
								}
								I=2;
							}
							if((U==0)&&(I==0)){
								if(A!=2){
									cout<<"AZURI tem supremacia sobre Tau!"<<endl;
								}
								A=2;
							}
						}
						if((A==0)&&(I==0)){
							if(U!=2){
								cout<<"UMASHI tem supremacia sobre Tau!"<<endl;
							}
							U=2;
						}
					}
					if(I!=0){
						existe = verificaExistencia(campoDeBatalha, "IANTECO");
						if(!existe){
							if(I!=2){
								cout<<"IANTECO foi eliminada"<<endl;
								I=0;
							}
							if((A==0)&&(I==0)){
								if(U!=2){
									cout<<"UMASHI tem supremacia sobre Tau!"<<endl;
								}
								U=2;
							}
							if((U==0)&&(I==0)){
								if(A!=2){
									cout<<"AZURI tem supremacia sobre Tau!"<<endl;
								}
								A=2;
							}
						}
						if((U==0)&&(A==0)){
							if(I!=2){
								cout<<"IANTECO tem supremacia sobre Tau!"<<endl;
							}
							I=2;
						}
					}
					if(A!=0){
						existe = verificaExistencia(campoDeBatalha, "AZURI");
						if(!existe){
							if(A!=2){
								cout<<"AZURI foi eliminada"<<endl;
								A=0;
							}
							if((U==0)&&(A==0)){
								if(I!=2){
									cout<<"IANTECO tem supremacia sobre Tau!"<<endl;
								}
								I=2;
							}
							if((A==0)&&(I==0)){
								if(U!=2){
									cout<<"UMASHI tem supremacia sobre Tau!"<<endl;
								}
								U=2;
							}
						}
						if((U==0)&&(I==0)){
							if(A!=2){
								cout<<"AZURI tem supremacia sobre Tau!"<<endl;
							}
							A=2;
						}
					}
				}
			}
			if(comando=="MAX_ATAQUE"){
				if(valida(i, j)){
					max_ataque(campoDeBatalha, campoDeBatalhaEspelhado, i, j, santuarioEspelho, 2);
				}
				else{
					cout<<"-1"<<endl;
				}
			}
			if(comando=="FORCA_RACA"){
				string racaASerProcurada;
				cin>>racaASerProcurada;
				forca_raca(campoDeBatalha, racaASerProcurada);
			}
			cin>>comando;
			}
			if(comando== "FIM"){
				entrada = "FIM";
			}
			if(comando == "UTA"){
				entrada = "UTA";
			}
		}
		cont++;
	}
	return 0;
}
