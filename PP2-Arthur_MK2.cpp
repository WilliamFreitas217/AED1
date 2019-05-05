#include<iostream>
using namespace std;
#define BASE 100000007

template<class Type>
class Node{
private:
	Node<Type> *left;
	Node<Type> *right;
	Type item;
	int height;
public:
	Node(){
		this->left=NULL;
		this->right = NULL;
	}
	Node(Type item){
	this->item = item;
	this->left = NULL;
	this->right = NULL;
	}
	Type &getItem(){
		return item;
	}
	void setItem(Type &item){
		this->item = item;
	}
	Node<Type>*& getLeft(){
		return left;
	}
	void setLeft(Node<Type>* &left){
		this->left = left;
	}
	Node<Type>*& getRight(){
		return right;
	}
	void setRight(Node<Type>* &right){
		this->right = right;
	}
	int getHeight(){
		return height;
	}
	void setHeight(){
		this->height = height;
	}
};

template<class Type>
class AVL{
private:
	Node<Type> *root;
	void insert(Type, Node<Type>* &);
	void insertHash(string, Type&, Node<Type>* &);
	void remove(Type&, Node<Type>* &);
	void removeAux(Node<Type>* &, Node<Type>* &);
	Type search(Type, Node<Type>*);
	Type* searchHash(string, Node<Type>*);
	Type traversalPosOrderHash(Node<Type>*&);
	void traversalPreOrder(Node<Type>*&);
	void traversalCentral(Node<Type>*&);
	void traversalPosOrder(Node<Type>*&);
	int height(Node<Type>*);
	void balance(Node<Type>*&);
	int calcBalanceFactor(Node<Type>*);
    void rotationLeft(Node<Type>* &);
    void rotationRight(Node<Type>* &);
public:
	AVL(){root = NULL;}
  Node<Type>* getRoot(){return root;}
 	void insert(Type);
 	void insertHash(string, Type&);
	Type search(Type);
	Type* searchHash(string);
	void remove(Type);
	Type traversalPosOrderHash();
 	void traversalPreOrder();
	void traversalCentral();
	void traversalPosOrder();
	void balance(); //calculo do balanço
	int height();
	int maxHeight(int, int);
//  void rotationLeft(Node<Type>*); //RSE
};

template<class Type>
void AVL<Type>::insert(Type item){
	insert(item, root);
}
template<class Type>
void AVL<Type>::insert(Type item, Node<Type>* &pointer){
  if (pointer==NULL){
  	pointer = new Node<Type>(item);
  }
  else if(item > pointer->getItem()){
    insert(item, pointer->getRight());
  }
  else if(item < pointer->getItem()){
    insert(item, pointer->getLeft());
  }
}
template<class Type>
void AVL<Type>::insertHash(string name, Type &hash){
	insertHash(name, hash, root);
}
template<class Type>
void AVL<Type>::insertHash(string name, Type &hash, Node<Type>* &pointer){
	if (pointer == NULL){
		pointer = new Node<Type>();
		pointer->setItem(hash);
	}
	if (name > pointer->getItem().getName()){
		// cout<<"maior"<<endl;
		insertHash(name, hash, pointer->getRight());
	}
	if (name < pointer->getItem().getName()){
		// cout<<"menor"<<endl;
		insertHash(name, hash, pointer->getLeft());
	}
}

template <class Type>
Type *AVL<Type>::searchHash(string name){
	return searchHash(name, root);
}
template <class Type>
Type *AVL<Type>::searchHash(string name, Node<Type>* pointer){
	if(pointer==NULL){
		return NULL;
	}
	else if(name>pointer->getItem().getName()){
		return searchHash(name, pointer->getRight());
	}
	else if(name<pointer->getItem().getName()){
		return searchHash(name, pointer->getLeft());
	}
	else{
		return &pointer->getItem();
	}
}


template<class Type>
void AVL<Type>::remove(Type item){
	remove(item, root);
}
template<class Type>
void AVL<Type>::remove(Type &item, Node<Type>* &pointer){
	Node<Type> *aux = pointer;
	if (pointer == NULL)
		cout << "Item não esta na arvore" << endl;
	else if(item < pointer->getItem())
		remove(item, pointer->getLeft());
	else if(item > pointer->getItem())
		remove(item, pointer->getRight());
	else if (pointer->getRight() == NULL){
		aux = pointer;
		pointer = pointer->getLeft();
		delete aux;
	}
	else if (pointer->getLeft() == NULL){
		aux = pointer;
		pointer = pointer->getRight();
		delete aux;
	}
	else
		removeAux(pointer, pointer->getLeft());
}
template<class Type>
void AVL<Type>::removeAux(Node<Type>* &q, Node<Type>* &r){
	if (r->getRight() != NULL)
		removeAux(q, r->getRight());
	else{
		q->setItem(r->getItem());
		r = r->getLeft();
	}
}

template<class Type>
Type AVL<Type>::search(Type item){
	return search(item, root);
}
template<class Type>
Type AVL<Type>::search(Type item, Node<Type>* pointer){
		if (pointer==NULL)
			cout<<"Item not Found"<< endl;
		else if (item > pointer->getItem())
			return search(item, pointer->getRight());
		else if (item < pointer->getItem())
			return search(item, pointer->getLeft());
		else{
			cout<<"Item Found: " << item << endl;
			return pointer->getItem();
		}
}
template<class Type>
Type AVL<Type>::traversalPosOrderHash(){
    return traversalPosOrderHash(root);
}
template<class Type>
Type AVL<Type>::traversalPosOrderHash(Node<Type>* &pointer){
    if (pointer != NULL){
        traversalPreOrder(pointer->getLeft());
        traversalPreOrder(pointer->getRight());
        return (pointer->getItem());
    }
}


template<class Type>
void AVL<Type>::traversalPreOrder(){
    traversalPreOrder(root);
}
template<class Type>
void AVL<Type>::traversalPreOrder(Node<Type>* &pointer){
    if (pointer != NULL){
        cout << pointer->getItem().getName() << " ";
        traversalPreOrder(pointer->getLeft());
        traversalPreOrder(pointer->getRight());
    }
}

template<class Type>
void AVL<Type>::traversalCentral(){
    traversalCentral(root);
}
template<class Type>
void AVL<Type>::traversalCentral(Node<Type>* &pointer){
	if (pointer != NULL){
		traversalCentral(pointer->getLeft());
		cout << pointer->getItem()<< endl;
		traversalCentral(pointer->getRight());
	}
}

template<class Type>
void AVL<Type>::traversalPosOrder(){
    traversalPosOrder(root);
}
template<class Type>
void AVL<Type>::traversalPosOrder(Node<Type>* &pointer){
    if (pointer != NULL){
        traversalPosOrder(pointer->getLeft());
        traversalPosOrder(pointer->getRight());
		cout << pointer->getItem() << " ";
    }
    cout << endl;
}

template<class Type>
int AVL<Type>::maxHeight(int height1, int height2){
	if (height1 > height2)
		return height1;
	else
		return height2;
}
template<class Type>
int AVL<Type>::height(){
	return height(root);

}
template<class Type>
int AVL<Type>::height(Node<Type>* pointer){
	if (pointer == NULL){
   		return -1;
 	}
  	return (maxHeight(height(pointer->getLeft()), height(pointer->getRight()))+1);
}

template<class Type>
void AVL<Type>::balance(){
	balance(root);
}
template<class Type>
void AVL<Type>::balance(Node<Type>* &pointer){
	if ((calcBalanceFactor(pointer) > 1) && (calcBalanceFactor(pointer->getRight()) >= 0)){
		rotationLeft(pointer);
		cout << "RSE" << endl;
	}
	else if ((calcBalanceFactor(pointer) > 1) && (calcBalanceFactor(pointer->getRight()) < 0)){
		rotationRight(pointer->getRight());
		rotationLeft(pointer);
		cout << "RDE" << endl;
	}
	else if ((calcBalanceFactor(pointer) < -1) && (calcBalanceFactor(pointer->getLeft()) <= 0)){
		rotationRight(pointer);
		cout << "RSD" << endl;
	}
	else if ((calcBalanceFactor(pointer) < -1) && (calcBalanceFactor(pointer->getLeft()) > 0)){
		rotationLeft(pointer->getLeft());
		rotationRight(pointer);
		cout << "RDD" << endl;
	}
	else
		cout << "Esta balanceada" << endl;

}
template<class Type>
int AVL<Type>::calcBalanceFactor(Node<Type> *pointer){
	return (height(pointer->getRight()) - height(pointer->getLeft()));
}

template<class Type>
void AVL<Type>::rotationLeft(Node<Type>* &pointer){
	Node<Type>* aux = pointer;
	pointer = pointer->getRight(); //RIGHT AGORA É RAIZ
	aux->setRight(pointer->getLeft());
	pointer->setLeft(aux);
}
template<class Type>
void AVL<Type>::rotationRight(Node<Type>* &pointer){
	Node<Type>* aux = pointer;
	pointer = pointer->getLeft(); //RIGHT AGORA É RAIZ
	aux->setLeft(pointer->getRight());
	pointer->setRight(aux);
}

template<class Type>
class HashTable{
private:
	int tam;
	AVL<Type> *vetor;
	string name;
public:
	HashTable(){
		tam = 0;
		vetor = new AVL<Type>();
	}
	HashTable(int tam, string name){
		this->tam = tam;
		vetor = new AVL<Type>[tam];
		this->name = name;
	}
	int getTam(){
		return tam;
	}
	void setTam(int tam){
		this->tam = tam;
		vetor = new AVL<Type>[tam];
	}
	string getName(){
		return name;
	}
	void setName(string name){
		this->name = name;
	}

	void insertTable(Type);
	void removeTable(Type);
	Type searchTable(Type);
	void printTable();
	int hashing(Type);
	unsigned long int power(int, int);
	void hashSum(HashTable<Type>, HashTable<Type>);
};

template<class Type>
void HashTable<Type>::insertTable(Type item){
	vetor[hashing(item)].insert(item);
}
template<class Type>
void HashTable<Type>::removeTable(Type item){
	vetor[hashing(item)].remove(item);
}
template<class Type>
Type HashTable<Type>::searchTable(Type item){
	return vetor[hashing(item)].search(item);
}
template<class Type>
void HashTable<Type>::printTable(){
	cout<<name<<endl;
	for (int i=0; i<getTam(); i++){
		cout<<"Posicao: "<< i << endl;
		vetor[i].traversalCentral();
	}
}
template<class Type>
int HashTable<Type>::hashing(Type word){
	int hash = 0;
	int cont = int(word.size());
	for (int i =0; i < cont; i++){
		hash += (int(word[i])*(power(BASE,i)))%getTam();
	}
	return hash%getTam();
}
template<class Type>
unsigned long int HashTable<Type>::power(int base, int exp){
	for (int i=0; i < exp; i++){
		base*=base%getTam();
	}
	return base;
}

template<class Type>
void HashTable<Type>::hashSum(HashTable<Type> p, HashTable<Type> q){
	cout<<"Entrou"<<endl;
	// for(int i=0; i<p.getTam(); i++){
	// 	//insertTable(p.vetor[i].traversalPosOrderHash());
	// }
}


int primeNumber(int number){
	int cont, aux;
	aux = 0;
	for(int i=1; i<= number; i++){
		cont = 0;
		for (int j=1; j<= number; j++){
			if (i%j == 0){
				cont+=1;
			}
		}
		if(cont == 2){
			aux=i;
		}
	}
	return aux;
}


int main(){
	AVL<HashTable<string>> tree;
	string comand;
	string name, key;
	char specialChar;
	int numberKey;

	while(comand != "FIM"){
		if (comand == "TH"){
			cin >> name >> specialChar >> numberKey;
			// cout<<name<<specialChar<<numberKey<<endl;
			HashTable<string> *hash = new HashTable<string>(primeNumber(numberKey/4), name);
			for(int i=0; i<numberKey; i++){
				cin >> key;
				hash->insertTable(key);
			}
			// hash->printTable();
			tree.insertHash(name, *hash);
			cin>>specialChar;
		}
		if (comand == "UNION"){
			HashTable<string> *p = new HashTable<string>();
			HashTable<string> *q = new HashTable<string>();
			string result, alpha, beta;
			cin >> result >> specialChar >> alpha >> beta >> specialChar;
			if(tree.searchHash(alpha)!=NULL){
				p = tree.searchHash(alpha);
				// p->printTable();
			}
			if(tree.searchHash(beta)!=NULL){
				q = tree.searchHash(beta);
				// q->printTable();
			}
			HashTable<string> sum((p->getTam()+q->getTam()), result);
			sum.hashSum(*p, *q);
		}
		cin >> comand;
	}
	// tree.traversalPosOrderHash();
	return 0;
}
