#include <iostream>

using namespace std;
struct dado{
	int valor;
	int status;
	//status = 1 -> preenchido
	//status = 0 ->vazio
	//status = 2 ->deletado
};
int hash_aux(int k, int m){
	return k%m;
}
int hash_aux2(int k, int m){
	return 1+(k%(m-1));
}
int hash_linear(int k, int m, int i){
	return (hash_aux(k, m)+i)%m;
}
int hash_quadratico(int k, int m, int i){
	int c1=1, c2=3;
	return (hash_aux(k,m)+i*c1+c2*i*i) % m;
}
int double_hash(int k, int m, int i){
	return (hash_aux(k,m)+i*hash_aux2(k, m))%m;
}
int insere_valor(dado tabela_hash[], int numero, int m){
	int pos=-1, i=0;
	while(i<m){
	    //pos = hash_linear(numero, m, i);
	    //pos = hash_quadratico(numero, m, i);
	    pos = double_hash(numero, m, i);
	    
		if(tabela_hash[pos].status != 1){
			tabela_hash[pos].valor=numero;
			tabela_hash[pos].status=1;
			break;
		}
		i++; //caso a posicao esteja cheia, o loop continua
		//assim, é incrementado o contador de colisoes
	}
	return pos;
}
int hash_busca(dado tabela_hash[], int numero, int m){
	int i=0;
	while(tabela_hash[pos].status != 0 && i<m){
		int j = double_hash(numero, m, i);
		if(tabela_hash[j]==j){
			return j;
		}
		i++
	}
	return -1;
}
int hash_delete(dado tabela_hash[], int numero, int m){
	int j=hash_busca(tabela_hash, numero, m);
	if(j!=-1){
		tabela_hash[j].status = 2;
		tabela_hash[j].valor = -1;
		return 0; //consegui remover
	}
	return -1; //k nao esta na tabela
}
int main(){
	int m=20;
	dado tabela_hash[m];
	
	//iniciando a tabela toda com status vazio
	for(int i=0;i<m;i++){
		tabela_hash[i].valor = -1;
		tabela_hash[i].status = 0;
	}
	
	//inserindo os valores
	
	char op = 's';
	int elemento;
	while(op != 'n'){
		cout<<"Digite um numero para inserir na tabela hash: ";
		cin>>elemento;
		int pos = insere_valor(tabela_hash, elemento, m);
		if(pos != -1)
			cout<<"Elemento inserido na posicao "<<pos<<endl;
		else{
			cout<<"Tabela cheia!";
			break;
		}		
		cout<<"Desaja inserir um novo numero na tabela? (s/n) ";
		cin>>op;
	}
	
	char op2 = 's';
	int deletar;
	while(op!='n'){
		cout << "Digite um numero para deletar na tabela hash: ";
		cin >> deletar;
		int delet = hash_delete(tabela_hash, deletar, m);
		if(delet == 0)
			cout << "numero" << deletar << "removido com sucesso" << endl;
		else
		{
			cout << "esse numero nao estava na tabela" << endl;
		}
		cout << "Deseja remover outro numero da tabela? (s/n)";
		cin >> op2;
	}
	
	//mostra todas as posicoes da tabela 
	
	for(int i=0;i<m;i++){
		cout<<"Posicao "<<i<<": ";
		if(tabela_hash[i].status == 1)
			cout<<tabela_hash[i].valor;
		else if(tabela_hash[i].status == 2)
			cout<<"Valor deletado.";
		else
			cout<<"Vazia.";
		cout<<endl;
	}

	
	
	return 0;
}