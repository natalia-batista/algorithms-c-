#include <iostream>
using namespace std;
struct ponto{
	int x;
	int y;
};
float area_triangulo(ponto a, ponto b, ponto c){
	float area = a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x;
	area = area/2;
	return area;
}
float posicao_relativa(ponto a, ponto b, ponto c){
	float area = area_triangulo(a,b,c);
	if(area>0){
		return 1; //ponto a direita
	}else if(area <0){
		return -1; //ponto a esquerda
	}else{
		return 0;
	}
}
int main(){
	/*
	ponto a,b,c;
	a.x=1;
	a.y=2;
	b.x=4;
	b.y=4;
	c.x=4;
	c.y=1;
	cout << area_triangulo(a,b,c) << endl;	
	*/
	
	ponto p = {3,2};
	ponto p1 = {1,2};
	ponto p2 = {4,4};
	ponto p3 = {4,1};
	/*
	float area = area_triangulo(p1,p2,p3);
	float l1 = area_triangulo(p,p2,p3)/area;
	float l2 = area_triangulo(p1,p,p3)/area;
	float l3 = area_triangulo(p1,p2,p)/area;
	
	cout << l1 << endl;
	cout << l2 << endl;
	cout << l3 << endl;
	*/
	
	int pos = posicao_relativa(p1,p2,p);
	if(pos == 1){
		cout << "a esquerda " << endl;
	}else if(pos==-1){
		cout << "a direita " << endl;
	}else{
		cout << "colineares" << endl;
	}
	return 0;
}