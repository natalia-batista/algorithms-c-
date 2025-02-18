#include <iostream>
using namespace std;

int busca_sequencial(int vetor[], int n, int x){
	
	for(int i=0;i<n;i++){
		if(vetor[i]==x){
			 return i++;
		}
	}
	return -1;
}

int busca_binaria_interativa(int vetor[],int inicio, int fim, int x){
	while(inicio <fim){
	   	int meio = (inicio+fim)/2;
		if(vetor[meio]==x)
			return meio;
		else if(x <vetor[meio])
			fim = meio-1;
		else
		{
			inicio = meio +1;
		}
	}
	return -1;
}
int busca_binaria_recursiva(int vetor[], int inicio, int fim, int x){
	if(inicio>fim)
		return -1;
	int meio = (inicio+fim)/2;
	if(x==vetor[meio])
		return meio;
	else if(x<vetor[meio])
		busca_binaria_recursiva(vetor,inicio, meio-1, x);
	else
	{
		busca_binaria_recursiva(vetor, meio+1, fim, x);
	}
	
}
void selection(int vetor[], int n){
	int j, i;
	int pos_menor;
	for(j=0;j<n;j++){ //controla onde a ordenação já foi realizada
		pos_menor = j;
		for(i=j;i<n;i++){ 
			if(vetor[i]<vetor[pos_menor])
				pos_menor = i;
		}
		if(vetor[j]>vetor[pos_menor]){
			int temp = vetor[j];
			vetor[j]=vetor[pos_menor];
			vetor[pos_menor]=temp;
		}
	
	}
}

void bubble(int vetor[], int n){
	
	for(int j=n-1;j>0;j--){ //controla onde a ordenação já foi realizada
		for(int i=0;i<j;i++){
			if(vetor[i]>vetor[i+1]){
			int temp = vetor[i];
			vetor[i] = vetor[i+1];
			vetor[i+1] = temp;
			}
		}
	}

}

void insertion(int vetor[], int n){
	int chave;
	for(int i=1;i<n;i++){
		chave=vetor[i];
		int j =i-1;
		while(vetor[j]>chave && j>=0){
			vetor[j+1]=vetor[j];
			j--;
		}
		vetor[j+1] = chave;
	}
}
void troca(int vetor[], int i, int j){
	int temp = vetor[i];
	vetor[i]=vetor[j];
	vetor[j]=temp;
}

int divide(int vetor[], int inicio, int fim){
	int pivo = vetor[(inicio +(fim-inicio))/2];
	int i = inicio;
	int j=fim;
	while(i<=j){
		while(vetor[i]<pivo && i<fim)
			i++;
		while(vetor[j]>pivo && j>inicio)
			j--;
		troca(vetor, i, j);
		i++;
		j--;
	}
	return i;
}

void quick(int vetor[], int inicio, int fim){
	if(inicio<fim){
		int meio = divide(vetor, inicio, fim);
		quick(vetor, inicio, meio-1);
		quick(vetor, meio+1, fim);
	}
}
	
int main(){ 
	int vetor[]={9,8,7,6,5,4,3,2,1};
	int n =9;
	int k;
	
	//selection(vetor, n);
	//bubble(vetor, n);
	//insertion(vetor, n);
	quick(vetor,0,n);
	
	//int x=busca_sequencial(vetor,n, 6);
	//int x = busca_binaria_interativa(vetor, 0, n, 6);
	int x = busca_binaria_recursiva(vetor, 0, n, 6);
	if(x!=-1)
		cout << "elemento 6 encontrado na pos " << x << endl;
	else
	{
		cout << "elemento nao encontrado" << endl;
	}
	
	for(k=0;k<n;k++){
		cout << vetor[k] << " ";
	}
	
	return 0;
}