#include <iostream>
#include <list>
using namespace std;
int main(){
	
	//inserindo valores no vetor de inteiros
	int vetor[10] = {33, 66, 99, 121, 155};
	
	//inserindo valores na lista de inteiros
	list<int> lista;

	lista.push_back(33);
	lista.push_back(66);
	lista.push_back(99);
	lista.push_back(121);
	lista.push_back(155);
	
	//mostrando valores do vetor
	
	
	for(int i=0; i<5;i++){
		cout << vetor[i] << endl;
	}
	
	//mostrando os valores na lista
	
	
	//ponteiro para a lista
	list<int>::iterator it;
	
	it = lista.begin();
	
	while(it != lista.end()){
		cout << *it << endl; //mostra o conteudo apontado pelo ponteiro it
		it++;
	}

	
	return 0;
}