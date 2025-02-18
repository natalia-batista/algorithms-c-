#include <iostream>
using namespace std;
void troca(int vetor[], int i, int j){
	int temp = vetor[j];
	vetor[j] = vetor[i];
	vetor[i] = temp;
}
int divide(int vetor[], int inicio, int fim){
	int i,j,pivo;
	i = inicio;
	j = fim;
	pivo =  vetor[(inicio+(fim-inicio))/2];
	while(i <=j){
		while(vetor[i]<pivo && i <fim)
			i++; 
		while(vetor[j]>pivo && j>inicio)
			j--;
		troca(vetor, i, j);
		i++;
		j--;
	}
	return i;
}
void quicksort(int vetor[], int inicio, int fim){
	if(inicio < fim){
		int meio = divide(vetor, inicio, fim);
		quicksort(vetor, inicio, meio-1);
		quicksort(vetor,meio+1, fim);
	}
}
int main(){
	int vetor[20];
	int i=0;
    
    cin>> vetor[i];
    while(vetor[i] != -1){
        i++;
        cin >> vetor[i];
    }
    int fim = i-1;
    quicksort(vetor,0,fim);
	
	for(int i=0;i<9;i++){
		cout << vetor[i] << " ";
	}
	
	return 0;
}