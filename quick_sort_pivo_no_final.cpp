#include <iostream>
using namespace std;
void troca(int vetor[], int i, int j){
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}
int divide(int vetor[],int inicio,int fim){
    int pivo = (inicio+(fim-inicio))/2;
    int i=inicio;
    int j=fim;
    while(i<=j){
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
    if(inicio<fim){
        int meio = divide(vetor, inicio, fim);
        quicksort(vetor, inicio, meio-1);
        quicksort(vetor, meio+1, fim);
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
    
    int fim = i;
    quicksort(vetor,0,fim);
    
    for(int j=0;j<fim;j++){
        cout << vetor[j]<< " ";
    }
    
    
    return 0;
}