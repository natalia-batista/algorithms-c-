#include <iostream>
using namespace std;
int main(){
	int n;
	int vetor[20];
	int menor;
	int temp;
	int i;
	int j;
	int pos_menor;
	
	//inserindo os numeros no vetor
	cin >> n;	//+1
	for(i=0;i<n;i++){ //6n+4
		cin >> vetor[i]; //n
	}
	
	
	for(j=0;j<n;j++){ //6n+4
		menor = 10000; //+1n
		for(i=j;i<n;i++){ //+6n+4
			if(vetor[i]<menor){ //+4n
				menor = vetor[i]; //atualiza o menor valor encontrado  //+3n
				pos_menor = i; //atualiza a posicao do menor elemento   //+n
				
			}
		}
		temp = vetor[j]; //3n
		vetor[j] = vetor[pos_menor]; //5n
		vetor[pos_menor]=temp; //3n

	}
	
	//mostrando o vetor ordenado
	for(i=0;i<n;i++){ //6n+4
		cout << vetor[i] << " "; //+n
	}
	
	//Modelo RAM
	//14n+10+6n+4+n+6n+4+n[4n+3n+n]+11n
	//8n^2+38n+18
	
	//Análise Assintotica
	//O(n^2)
	
	return 0;
}