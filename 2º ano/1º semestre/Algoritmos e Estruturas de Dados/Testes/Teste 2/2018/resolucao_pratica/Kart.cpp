#include <cstdlib>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <time.h>
#include "algorithm"
#include "Kart.h"

using namespace std;

//To help build better array
string itos(int i){
    stringstream s;
    s << i;
    return s.str();
}

void CGrupo::criaGrupo()
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
        adicionaPista(CPista("Pista - "+itos(i),frota));
    }
}

vector <CKart> CPista::getKartsAvariados()
{
    vector<CKart> aux;
    for (vector<CKart>::iterator it = frotaKartsPista.begin() ; it != frotaKartsPista.end(); ++it) {
        if ((it)->getAvariado()) aux.push_back((*it));
    }
    return aux;
}

bool CKart::operator< (CKart &kart) {
    return numero < kart.getNumero();
}


//Exercicio 1 a)
vector<CKart> CGrupo::ordenaKarts()
{
    vector<CKart> vord;
    vector<CKart> aux;
    for (auto &x: pistasG) {
        aux = x.getFrotaActual();
        for (auto &y: aux)
            vord.push_back(y);
        aux.clear();
    }
    sort(vord.begin(), vord.end());  // Implementar operador < para a classe CKart
    return vord;
}

//Exercicio 1 b)
int CGrupo::numAvariados(int cilind)
{
    int result = 0;
    vector<CKart> karts = ordenaKarts();
    for (auto &x: karts) {
        if (x.getAvariado() && (x.getCilindrada() == cilind))
            result++;
    }
    return result;
}

//Exercicio 1 c)
bool CPista::prepararCorrida(int numeroKarts, int cilind)
{
    unsigned int counter = 0;
    for (auto &x: frotaKartsPista) {
        if ((x.getCilindrada() == cilind) && !x.getAvariado()) {
            kartsLinhaPartida.push(x);
            counter++;
        }
    }
    return counter >= numeroKarts;
}

//Exercicio 1 d)
int CPista::inicioCorrida()
{
    int counter = 0;
    unsigned int size = kartsLinhaPartida.size();
    for (int i = 0; i < size; i++) {
        kartsEmProva.push_back(kartsLinhaPartida.front());
        kartsLinhaPartida.pop();
        counter++;
    }
    return counter;
}

