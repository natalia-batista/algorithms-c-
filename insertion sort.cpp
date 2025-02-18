#include <iostream>
using namespace std;
int main(){
	int vetor[] = {4, 7, 2, 5, 4, 0};
	int i, j;
	int n=6;
	int chave;
	
	for(i=1;i<n;i++){
		chave = vetor[i]; //elemento
		j = i-1; //sublista
		while(j>=0 && vetor[j]>chave){
			vetor[j+1] = vetor[j]; //avança o elemento da sublista em uma casa
			j = j-1; //decrementa a pos da sublista pra continuar comparando
		}
		//a posicao em q o j parou, é uma antes da pos de inserção da chave
		vetor[j+1] = chave;
	}
	
	for(i=0;i<n;i++){
		cout << vetor[i] << " ";
	}
	return 0;
}

/*
	 ANÁLISE DE COMPLEXIDADE DO INSERTION SORT
	 
	for(i=1;i<n;i++){ //1+3(n-1+1)+3(n-1)
		chave = vetor[i]; //3(n-1)
		j = i-1; //3(n-1)
		while(j>=0 && vetor[j]>chave){ // n*7*(n-1)
			vetor[j+1] = vetor[j]; //5(n-1)(n-2)
			j = j-1; //3(n-1)(n-2)
		}
		
		vetor[j+1] = chave; //(n-1)*4
	}
	
//RAM: 1+13(n-1)+3n+7n(n-1)+8(n-1)(n-2)
//15n^2-25n+4
//Analise assintotica: O(n^2)
	return 0;
}