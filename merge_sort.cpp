#include <iostream>
using namespace std;
void merge(int vetor[], int inicio, int meio, int fim){
	//fazendo os subvetores
	int n1 = meio- inicio +1; //qtd de elementos de cada metade
	int n2 = fim -meio;
	int esquerda[n1], direita[n2];
	//passando os elementos pra essas novas listas
	for(int i=0;i<n1;i++){
		esquerda[i] = vetor[inicio+i];
	}
	for(int i=0;i<n2; i++){
		direita[i] = vetor[meio+1+i];
	}
	int i=0, j=0; //i gerencia o topo da esquerda e j gerencia o topo da direita
	for(int k=inicio;k<=fim;k++){
		//se todos os elementos da esquerda ja foram incrementados
		if (i >= n1){
			//coloco o elemento do topo na direita
			vetor[k] = direita[j];
			j++;
		}
		//se todos elementos da direita ja foram incrementados
		else if(j>=n2){
			//coloco o elemento do topo da esquerda
			vetor[k] = esquerda[i];
			i++;
		}
		//se o elemento do topo esquerdo for menor que o do direito
		else if(esquerda[i]<direita[j]){
			//coloco o elemento da esquerda
			vetor[k] = esquerda[i];
			i++;
		}
		//se o elemento do topo da direita for menor
		else{
			//coloco o elemento da direita em k
			vetor[k] = direita[j];
			j++;
		}
	}
	
}
void merge_sort(int vetor[], int inicio, int fim){
	//se o tamanho da lista for maior que 1
	if(fim - inicio > 1){
		int meio = (inicio+fim)/2; //calcula o meio
		merge_sort(vetor, inicio, meio);
		merge_sort(vetor, meio, fim);
		merge(vetor, inicio, meio, fim);
		}
	 
}
int main(){
	int vetor[8] = {4, 7, 2, 6, 4, 1, 8, 3};
	merge_sort(vetor, 0, 7);
	
	for(int i=0; i<8;i++){
		cout << vetor[i] << " ";
	}
	return 0;
}