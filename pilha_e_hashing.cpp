#include <iostream>
#include <list>
using namespace std;
struct dado{
	int valor;
	int status;
	// 1-> preenchido
	// 0-> vazio 
	// 2-> deletado
};
int h1(int k, int m){
	return k%m;
}
int h2(int k, int m){
	return 1+(k%(m-1));
}
int hash_duplo(int k, int m, int i){
	return (h1(k,m)+i*h2(k,m))%m;
}
void insere_valor(dado tabela[], int valor, int m){
	int i=0; //controla as colisoes
	int pos = -1; 
	while(i<m){
		pos = hash_duplo(valor,m,i);
		
		if(tabela[pos].status != 1){
			tabela[pos].status = 1;
			tabela[pos].valor = valor;
			break;
		}
		i++; 
	}
		
}
int main(){
	int m;
	cout << "insira o tamanho da tabela hash: ";
	cin>> m;
	cout << "insira a quantidade de elementos: ";
	int qtd;
	cin>>qtd;
	
	list<int> pilha;
	int valor;
	
	dado tabela_hash[m];
	//inicializando a tabela hash
	for(int i=0;i<m;i++){
		tabela_hash[i].valor = -1;
		tabela_hash[m].status = 0;
	}

	cout << "insira os elementos na pilha: " << endl;
	//inserindo os elementos na pilha
	for(int i=0;i<qtd;i++){
		cin >> valor;
		pilha.push_front(valor);
	}
	
	// removendo os elementos da pilha e colocando na tabela hash
	for(int i=0;i<qtd;i++){
		insere_valor(tabela_hash, pilha.front(), m);
		pilha.pop_front();
	}
	
	//mostrando a tabela hash
	for(int i=0;i<m;i++){
		cout << tabela_hash[i].valor << " ";
	}
	
	
	return 0;
}