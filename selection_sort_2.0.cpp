#include <iostream>
using namespace std;
int main(){
	int vetor[] ={7, 5, 1, 8, 3};
	int n = 5; //tamanho do vetor
	int i, j; //contadores
	int aux;
	int min_index;
	
	for(j=0;j<(n-1);j++){
		min_index = j;
		//procurando o minimo
		for(i=j;i< n;i++){ 
			if(vetor[i]<vetor[min_index]){
				min_index = i;
			}
		}
		//fazendo a troca
		if(vetor[j]>vetor[min_index]){
			aux = vetor[j];
			vetor[j]= vetor[min_index];
			vetor[min_index] = aux;
		}
	}
	for(i=0;i<n;i++){
		cout << vetor[i]<< " ";
	}
	
	
	return 0;
}