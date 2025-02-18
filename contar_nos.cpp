#include <iostream>
#include <list>
using namespace std;
int contar(list<int> lista){
	list<int>::iterator it;
	int i=0;
	
	it = lista.begin();
	while(it != lista.end()){
		i++;
		it++;
	}
	return i;
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
	int contador = contar(lista);
	cout << contador << endl;
	
	return 0;
}