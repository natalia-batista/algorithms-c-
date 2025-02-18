#include <iostream>
#include <list>
using namespace std;

#define VERTICES 4

void bfs(bool adj[VERTICES][VERTICES],int vertices, int origem){
	list<int> fila_espera;
	bool visitado[vertices];//vetor auxiliar para marcar os vertices visitados
	
	for(int i=0;i<vertices;i++){
		visitado[i]=false;
	}
	
	fila_espera.push_back(origem);//inicializando a fila
	
	int atual;
	while(!fila_espera.empty()){
		atual = fila_espera.front();
		visitado[atual]=true;
		for(int i=0;i<vertices;i++){
			if(adj[atual][i] && visitado[i]==false){ //verificando os vizinhos do vertice de origem
				//adicionando o vizinho na fila de espera
				fila_espera.push_back(i);
			}
		}
		fila_espera.pop_front(); //tirando o elemento visitado da fila
		cout << atual << endl;
	}
	
}

bool eh_conexo(bool adj[VERTICES][VERTICES],int vertices){
	//precisamos visitar o grafo comecando por diferentes vertices
	list<int> fila_espera;
	bool visitado[vertices];
	
	for(int i=0;i<vertices;i++){
		visitado[i]=false;
	}
	
	fila_espera.push_back(0);
	
	int atual;
	while(!fila_espera.empty()){
		atual = fila_espera.front();
		visitado[atual]=true;
		for(int i=0;i<vertices;i++){
			if(adj[atual][i] && visitado[i]==false){ 
				fila_espera.push_back(i);
			}
		}
		fila_espera.pop_front(); 
		
	}
	//como o grafo é n direcionado, podemos ter certeza com apenas uma varredura
	for(int i=0;i<vertices;i++){
		if(visitado[i]==false){
			return false; //grafico desconexo
		}
	}
	return true;
}

int main(){
	bool matriz[VERTICES][VERTICES];
	
	for(int i=0;i<VERTICES;i++){
		for(int j=0;j<VERTICES;j++){
			matriz[i][j]=false;
		}
	}
	// int i=0,j=0;
	// 
	// while(i!=-1 && j!=-1){
	// 	cin>>i>>j;
	// 	matriz[i][j] = true;
	// 	matriz[j][i] = true; //grafo nao direcionado
	// }
	matriz[0][1]=true;
	matriz[1][0]=true;
	matriz[2][3]=true;
	matriz[3][2]=true;
	matriz[1][2]=true;
	matriz[2][1]=true;
		
	//bfs(matriz,4,3);
	
	if(eh_conexo(matriz,5)){
		cout << "conexo"<< endl;
	}else{
		cout <<"desconexo" << endl;
	}
	
	return 0;
}