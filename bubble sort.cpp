#include <iostream>
using namespace std;
int main(){
	int i; 
	int n;
	int vetor[20];
	int aux;
	
	//inserindo elementos no vetor
	cin >> n; //+1
	for(i=0;i<n;i++){ //+1+3(n+1)+3n =6n+4
		cin >> vetor[i]; //+n
	}
	
	for(int j=0;j<n-1;j++){  //+1+4(n+1)+3n = 5+7n
		for(i=0;i< n-1;i++){  //+1+4(n+1)+3n = 5+7n
			if(vetor[i]>vetor[i+1]){ //+6n
				aux = vetor[i]; //+2n
				vetor[i] = vetor[i+1]; //+5n
				vetor[i+1] = aux; //+5n
			}
		}
	}

	
	for(i=0;i<n;i++){ //+1+3(n+1)+3n = 6n+4
		cout << vetor[i]<< " "; //+n
	}
	
	//análise modelo RAM
	//7n+5+5n+7+n(5+7n +18n)+7n+4
	//=19n+16+5n+25n^2
	//=25n^2+24n+16
	
	//Analise assintotica
	//O(n^2)
	return 0;
}