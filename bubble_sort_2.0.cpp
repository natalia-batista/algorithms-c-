#include <iostream>
using namespace std;
int main(){
	int vetor[] = {4, 9, 2, 1, 7, 8};
	int i, j, aux;
	int n=6;
	

	for(j=(n-1); j>0; j--){
		//percorre o vetor da direita p/ esquerda
		//j controla a posicao ate onde a ordenaçao ja foi realizada 
		//na primeira iteraçao, essa posicao e o ultimo elemento do vetor
		for(i=0;i<j;i++){
			//percorre da esquerda p/ direita  até a posiçao j
			// a condicao i<j garante que apenas os elementos nao ordenados sejam trocados
			if(vetor[i]>vetor[i+1]){
				aux = vetor[i+1];
				vetor[i+1] = vetor[i];
				vetor[i]=aux;
			}
	  	  }	
		
	}

	for(i=0;i<n;i++){
		cout << vetor[i] << " ";
	}
	
	return 0;
}