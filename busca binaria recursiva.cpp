#include <iostream>
using namespace std;

int vetor[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int busca_binaria(int elemento, int inicio, int fim){
	if(inicio >fim){
		return -1;
	}
	int meio = (inicio + fim) /2;
	
	if(vetor[meio]== elemento){
		return meio;
	}
	if(elemento > vetor[meio]){
		//esta na metade superior
		return busca_binaria(elemento, meio+1, fim);
	}
	else{
		//esta na metade inferior
		return busca_binaria(elemento, inicio, meio-1);
	}
}
int main(){
	
	
	return 0;
}