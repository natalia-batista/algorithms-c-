#include <iostream>
#include <string>
using namespace std;
//struct p/ armazenar dados dos alunos
struct dados{
	string nome;
	int matricula;
	int idade;
};
// funcao que registra os dados
dados registrar(){
	dados a1; 
	cin>>a1.matricula;
	cin>>a1.nome;
	cin>>a1.idade;
	return a1;
}
//criando funcao que pede a matricula e retorna os dados
//passar vetor pra funcao, usa [] e o tamanho do vetor

int matricular(int mat, int n, dados alunos[]){
	int inicio=0;
	int fim=n;
	
	int metade = (inicio+fim)/2;
	
	while(inicio <= fim){
		//calculando uma nova metade
		if(alunos[metade].matricula != mat){
			//a matricula desejada é menor que a metade
			if(alunos[metade].matricula > mat){
				fim = metade-1;
			}
			else{
				inicio = metade+ 1; //matricula desejada maior q a metade
			}
		}
		else{
			//retornar a posicao q o aluno foi encontrado
			return metade;
		}	
		metade = (inicio+fim)/2;
	}
	return -1;
	
}

int main(){
	//qtd de alunos matriculados
	int n;
	cin>>n;
	dados alunos[n];
	
	for(int i=0; i<n; i++)
	{
		alunos[i]=registrar();
	}
	
	//para mandar uma variavel pra funcao coloca-se o nome dela
	//no caso n coloca alunos[n], mas sim alunos
	cout << "insira a matricula desejada" << endl;
	int matric;
	cin >> matric;
	//como retorna a posicao do aluno
	
	//questao 1: busca binaria por matriculas ordenadas
	int resultado= matricular(matric, n, alunos);
	if(resultado == -1)
		cout << "aluno nao encontrado" << endl;
	else{
		cout << "nome: " << alunos[resultado].nome << endl;
		cout << "idade: " << alunos[resultado].idade << endl;
	}
	
    //questao 2: nao e possivel realizar busca binaria pelo nome
    //quando os alunos estao ordenados por matricula
	
	//questao 3: nao e possivel fazer essa busca, de somar as idades, pois nao
	//ha um elemento sendo procurado
	
	return 0;
}