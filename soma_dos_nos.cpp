#include <iostream>
#include <list>
using namespace std;
int soma(list<int> lista){
	int soma = 0;
	list<int>::iterator it;
	
	it = lista.begin();
	while(it != lista.end()){
		soma += *it;
		it++;
	}
	return soma;
}
int main(){
	list<int> lista;
	int valor;
	
	//inserindo valores na lista
	cin >> valor;
	while(valor != 0){
		lista.push_back(valor);
		cin >> valor;
	}
	
	int somatorio = soma(lista);
	cout << somatorio << endl;
	return 0;
}