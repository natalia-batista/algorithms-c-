#include <iostream>
using namespace std;
int h1(int k, int m){
    return k%m;
}

int h2(int k, int m){
    return 1 + (k%(m-1));
    
}

int dhash(int k, int m, int i){
    return (h1(k, m) + i*h2(k, m)) % m;
    
    
}
int main(){
    int k, m, i;
    cin >> k >> m;
    
    for(i=0;i<m;i++){
        int s= dhash(k, m, i);
        cout << s <<" ";
    }
    
    return 0;
}