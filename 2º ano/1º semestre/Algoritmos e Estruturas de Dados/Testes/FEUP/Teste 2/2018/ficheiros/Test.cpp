#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include "Kart.h"
#include "CStack.h"
#include "CSimpleList.h"

using namespace std;

CGrupo grupo1;

void test_1a() {
    vector<CKart> kartsOrdenados = grupo1.ordenaKarts();
    ASSERT_EQUAL(kartsOrdenados.size(), 2500);
    for (unsigned int i=0;i<kartsOrdenados.size()-1;i++){
    	ASSERT_LESS_EQUAL(kartsOrdenados[i].getNumero(), kartsOrdenados[i+1].getNumero());
	}
}

void test_1b() {
    ASSERT_EQUAL(grupo1.numAvariados(134), 210);
    ASSERT_EQUAL(grupo1.numAvariados(250), 219);
    ASSERT_EQUAL(grupo1.numAvariados(450), 212);
    ASSERT_EQUAL(grupo1.numAvariados(600), 206);
}

void test_1c() {
	vector <CPista> vecP = grupo1.getPistas();

	vecP[0].prepararCorrida(10, 134);

	queue<CKart> q1= vecP[0].getKartsLinhaPartida();
	ASSERT_EQUAL(false, q1.empty());
	ASSERT_EQUAL(13,q1.front().getNumero());
	q1.pop();
	ASSERT_EQUAL(31,q1.front().getNumero());
	q1.pop();
	ASSERT_EQUAL(33,q1.front().getNumero());
}

void test_1d() {
	vector <CPista> vecP = grupo1.getPistas();
	vecP[0].prepararCorrida(10, 134);

	ASSERT_EQUAL(7,vecP[0].inicioCorrida());

	vector<CKart> v1= vecP[0].getKartsEmProva();
	ASSERT_EQUAL(false, v1.empty());
	ASSERT_EQUAL(13,v1[0].getNumero());
	ASSERT_EQUAL(31,v1[1].getNumero());
	ASSERT_EQUAL(33,v1[2].getNumero());
}

void test_2a()
{
	CStack s1(20);
	s1.push(1); s1.push(2); s1.push(3);
	s1.adicionaN(4); //s1.print();
	ASSERT_EQUAL("7 6 5 4 3 2 1 ",s1.toStr());
	s1.adicionaN(2); //s1.print();
	ASSERT_EQUAL("9 8 7 6 5 4 3 2 1 ",s1.toStr());
}

void test_2b()
{
	CStack s2(20);
	s2.push(1); s2.push(2); s2.push(3);
	ASSERT_EQUAL(false,s2.inverte4());
	s2.push(4); s2.push(5);
	s2.inverte4(); //s2.print();
	ASSERT_EQUAL("2 3 4 5 1 ",s2.toStr());
	s2.push(6); s2.push(7);
	s2.inverte4(); //s2.print();
	ASSERT_EQUAL("3 2 6 7 4 5 1 ",s2.toStr());
}

void test_2c()
{
	CSimpleList l1, l2, l3;
	l1.insert_end(1); l1.insert_end(2); l1.insert_end(3);
	l1.insert_end(4); l1.insert_end(5);
	l2.insert_end(6); l2.insert_end(7); l2.insert_end(8);
	//l1.print(); l2.print();
	l1.intercalar(l2); //l1.print();
	ASSERT_EQUAL("1 6 2 7 3 8 4 5 ",l1.toStr());
	l1.intercalar(l2); //l1.print();
	ASSERT_EQUAL("1 6 6 7 2 8 7 3 8 4 5 ",l1.toStr());
}

void test_2d()
{
	CSimpleList l3;
	int elem[14]  = {1,1,2,2,2,3,3,3,3,4,4,7,8,8};
	for(int i=0; i<14; i++) l3.insert_end(elem[i]);
	l3.print();
	//cout << "Zipados: " << l3.zipar() << endl;
	ASSERT_EQUAL(8,l3.zipar());
	ASSERT_EQUAL("1 2 3 4 7 8 ",l3.toStr());
	l3.print();
	CSimpleList l4;
	int elem2[10]  = {1,1,1,2,4,6,6,6,6,7};
	for(int i=0; i<10; i++) l4.insert_end(elem2[i]);
	l4.print();
	//cout << "Zipados: " << l3.zipar() << endl;
	ASSERT_EQUAL(5,l4.zipar());
	ASSERT_EQUAL("1 2 4 6 7 ",l4.toStr());
	l4.print();
}

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void runSuite(){
	cute::suite s;

	s.push_back(CUTE(test_1a));
	s.push_back(CUTE(test_1b));
	s.push_back(CUTE(test_1c));
	s.push_back(CUTE(test_1d));
	s.push_back(CUTE(test_2a));
	s.push_back(CUTE(test_2b));
	s.push_back(CUTE(test_2c));
	s.push_back(CUTE(test_2d));
	cute::ide_listener<> lis;
	cute::makeRunner(lis)(s, "AEDA 2018/2019 - Avaliacao CI2 - 21/nov - CUTE");
}

void criaGrupo()
{
    float cilindradas[4]  = {134,250,450,600};
	bool avariados[3]  = {true,false,false};

	srand (1);   //Criar Pistas e Karts de Teste
	for(int i=1;i<=50;i++){
	   vector<CKart> frota;
	   for(int j=1;j<=50;j++){
	      frota.push_back(CKart(avariados[rand()% 3],
	    		  ("KART - "+itos(i))+itos(j),(i-1)*50+j,cilindradas[(rand() % 4)]));
	   }
	   grupo1.adicionaPista(CPista("Pista - "+itos(i),frota));
	}
}

int main(){
	criaGrupo();
    runSuite();
    return 0;
}

/*
int main(){


	vector <CPista> vecP = grupo1.getPistas();

	cout << vecP[1].prepararCorrida(2, 250) << endl;
	cout << vecP[2].prepararCorrida(3, 600) << endl;

	cout << vecP[1].inicioCorrida() << endl;
	cout << vecP[2].inicioCorrida() << endl;
}
*/



