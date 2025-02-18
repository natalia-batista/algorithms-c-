#include <iostream> 
using namespace std;

void selection(int vetor[], int tam){
	int min,aux,i,j;
	
	for(j=0;j<tam;j++){ //controla o que ja esta ordenado
		 min = j;
	 
		for(i=j;i<tam;i++){ //procurando o minimo no restante do vetor
			if(vetor[i]<vetor[min]){
				min = i;
			}
					
		}
		//fazendo a troca
		if(vetor[j]>vetor[min]){
			aux = vetor[j];
			vetor[j] = vetor[min];
			vetor[min] = aux;
		}
	}
}
void bubble(int vetor[], int tam){
	
	for(int j=tam-1;j>0;j--){//controla o que ja esta ordenado
		
		for(int i=0;i<j;i++){//ordenando o resto do vetor
			if(vetor[i] > vetor[i+1]){
				int aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
			}	
		}
	}
}
void insertion(int vetor[], int tam){
	
	for(int i=1; i<tam;i++){
		int chave = vetor[i];
		int j = i-1;
		while(j>=0 && vetor[j]>chave){
			vetor[j+1]=vetor[j]; // avanca o elemento uma casa
			j--;
		}
		
		vetor[j+1] = chave; //j parou uma casa antes da posicao da chave
	}
}
void swap(int vetor[], int l, int r){
	int temp = vetor[l];
	vetor[l] = vetor[r];
	vetor[r] = temp;
}
int partition(int vetor[], int inicio, int fim){
	int pivo = vetor[fim]; // coloca o pivo no final do vetor
	int l=inicio, r = fim-1;
	while(l<r){ //para garantir que percorremos todo o vetor
		while(vetor[l]<pivo && l<r){
			l++;
			//encontrando um elemento à esq. maior que o pivo
		}
		while(vetor[r]>pivo && l<r){
			r--;
			//encontrando elemento a direita menor que o pivo
		}
		//trocar esses dois elementos de lugar
		swap(vetor, l, r);
	}
	
	//colocando o pivo no lugar correto
	if(vetor[l]>pivo){
		//como o item left passou o item right (ao quebrar o loop while)
		//trocamos o elemento da esquerda com o pivo
		swap(vetor,l,fim);
	}
	return l; //retornando a posicao do pivo
}

void quicksort(int vetor[],int inicio,int fim ){
	if(inicio<fim){
		//colocando o pivo em sua devida posicao
		int pivo = partition(vetor, inicio, fim);
		
		//chamar a funcao para o vetor à esq do pivo
		quicksort(vetor, inicio, pivo-1);
		//chamar para o vetor à direita
		quicksort(vetor,pivo+1,fim);
	}
}
	
int main(){
	int vetor[]={3,6,8,1,0,7,10};
	int tam = 7;
	//selection(vetor,tam);
	//bubble(vetor,tam);
	//insertion(vetor,tam);
	//quicksort(vetor,0,6);
	
	for(int i=0;i<tam;i++){
		cout << vetor[i] << " ";
	}
	
	return 0;
}