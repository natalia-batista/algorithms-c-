#include <iostream>
#include <algorithm>
using namespace std;
struct treenode{
	int info;
	treenode *left;
	treenode *right;
	int height;
};
typedef treenode *treenodeptr;

//Funcao para encontrar a altura da arvore
int height(treenodeptr p){
	if(p==NULL){
		return 0;
	}
	return p->height;
}

//rotacao para direita
treenodeptr rightRotate(treenodeptr y){
	treenodeptr x = y->left;
	treenodeptr t2 = x->right;
	
	//rotacionando
	x->right = y;
	y->left = t2;
	
	//atualizando as alturas
	y->height = max(height(y->left),height(y->right)) +1;
	x->height = max(height(x->left),height(x->right)) +1;
	
	//retornando a nova raiz
	return x;
}

treenodeptr leftRotate(treenodeptr x){
	treenodeptr y = x->right;
	treenodeptr t2 = y->left;
	
	//rotacionando
	y->left = x;
	x->right = t2;
	
	//atualizando as alturas
	y->height = max(height(y->left),height(y->right)) +1;
	x->height = max(height(x->left),height(x->right)) +1;
	
	//retornando a nova raiz
	return y;
}

int balance(treenodeptr p){
	if(p==NULL){
		return 0;
	}
	return height(p->left)-height(p->right);
}

//funcao para inserir nos
treenodeptr tInsert(treenodeptr &p, int x){
	//fazendo a insercao bst normalmente
	if(p==NULL){
		p = new treenode;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
		p->height = 1;
	}
	else if(x < p->info){
		p->left = tInsert(p->left, x); 
	}
	else{
		p->right = tInsert(p->right, x);
	}
	
	//atualizar a altura do no anterior
	p->height = max(height(p->left),height(p->right)) +1;
	
	//checar se o no anterior esta balanceado
	int balanceFactor = balance(p);
	
	//se o no estiver desbalanceado, seguir um dos quatro casos
	
	//Left Left
	if(balanceFactor>1 && x < p->left->info){
		return rightRotate(p);
	}
	//Right Right
	if(balanceFactor<-1 && x > p->right->info){
		return leftRotate(p);
	}
	//Left Right
	if(balanceFactor > 1 && x > p->left->info){
		p->left = leftRotate(p->left);
		return rightRotate(p);
	}
	//Right Left
	if(balanceFactor < -1 && x < p->right->info){
		p->right = rightRotate(p->right);
		return leftRotate(p);
	}
	
	return p;
	
}
void tPreOrder(treenodeptr p){
	if(p!=NULL){
		cout << p->info << endl;
		tPreOrder(p->left);
		tPreOrder(p->right);
	}
}

int main(){
	int n;
    cin >> n;
    int x;
    treenodeptr raiz = NULL;
    
    for(int i=0;i<n;i++){
        cin >> x;
        raiz = tInsert(raiz,x);
        
    }
	tPreOrder(raiz);
}