#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int *vetor = new int[n];
    int pares_pos =0;
    
    for(int i=0;i<n;i++){
        if(vetor[i]%2==0 && vetor[i]>=0){
            pares_pos++;
        }
    }
    
    cout << pares_pos << endl;
    
    delete [] vetor;
    
    
    
    return 0;
}