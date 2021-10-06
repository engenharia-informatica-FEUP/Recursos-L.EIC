/*
 * Condominio.h
 */

#ifndef CONDOMINIO_H_
#define CONDOMINIO_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Imovel {
	int areaHabitacao;
	string proprietario;
	int ID;
public:
	Imovel(int areaH, string prop, int id=0);
	int getID() const;
	int getAreaHabitacao() const;
	string getProprietario() const;
	void setID(int id);

};

class Apartamento: public Imovel {
	int andar;
public:
	Apartamento(int areaH, int anda, string prop, int id=0);

};

class Vivenda: public Imovel {
   int areaExterior;
   bool piscina;
public:
   Vivenda(int areaH, int areaExt, bool pisc, string prop, int id=0);

};


class Urbanizacao {
	string nome;
	int ID;
	vector<Imovel *> imoveis;

public:
	Urbanizacao(string nm, int id);
	void adicionaImovel(Imovel *im1);
	vector<Imovel *> getImoveis() const;
	string getNome() const;
	int getID() const;

};


class ECondominio {
	vector<Urbanizacao> urbanizacoes;
public:
	void adicionaUrbanizacao(Urbanizacao urb1);
	vector<Urbanizacao> getUrbanizacoes() const;

};

#endif /* CONDOMINIO_H_ */
