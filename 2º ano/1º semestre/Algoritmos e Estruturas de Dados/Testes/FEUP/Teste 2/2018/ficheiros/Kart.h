// Grupo com Pistas de Karts
#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

class CKart{
 	string nome;
    float cilindrada;
    int numero;
    bool avariado;
public:
	CKart(bool av,string no,int num,float cil){
    	avariado = av; nome = no; numero = num; cilindrada = cil;}    
	string getNome(){ return nome;}
	float getCilindrada(){ return cilindrada;}
	int getNumero(){ return numero;}
	bool getAvariado(){ return avariado; }
};

class CPista{
    string nomePista;
    vector <CKart> frotaKartsPista; //Karts na frota
    queue <CKart> kartsLinhaPartida; //Karts prontos a partir
    vector<CKart> kartsEmProva; //Karts actualmente em prova
public:
	CPista(string nPista, vector <CKart> fKarts){
    	nomePista = nPista;	frotaKartsPista = fKarts; }
    string getNome() { return nomePista; }
    vector <CKart> &getFrotaActual() {  return frotaKartsPista; }
    queue <CKart> getKartsLinhaPartida(){  return kartsLinhaPartida; }
    vector <CKart> getKartsEmProva(){  return kartsEmProva; }
    vector <CKart> getKartsAvariados();
    bool prepararCorrida(int numeroKarts, int cilind); //Ex 1c)
    int inicioCorrida();  //Ex 1d)
};

class CGrupo{
   vector <CPista> pistasG;  //Pistas do Grupo
public:
    vector <CPista> getPistas(){ return pistasG; }
	void adicionaPista(CPista pista) { pistasG.push_back(pista); }
    vector <CKart> ordenaKarts();  //Ex 1 a)
    int numAvariados(int cilind); //Ex 1 b)
};




