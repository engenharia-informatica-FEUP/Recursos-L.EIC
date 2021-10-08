/*
 * Condominio.cpp
 */

#include "Condominio.h"


Imovel::Imovel(int areaH, string prop, int id): areaHabitacao(areaH), proprietario(prop), ID(id)
{}

int Imovel::getID() const
{ return ID; }

void Imovel::setID(int id)
{ ID=id; }

int Imovel::getAreaHabitacao() const
{ return areaHabitacao; }

string Imovel::getProprietario() const
{ return proprietario; }


Apartamento::Apartamento(int areaH, int anda, string prop, int id): Imovel(areaH,prop,id), andar(anda)
{}

Vivenda::Vivenda(int areaH, int areaExt, bool pisc, string prop, int id):Imovel(areaH,prop,id), areaExterior(areaExt), piscina(pisc)
{}


Urbanizacao::Urbanizacao(string nm, int id): nome(nm), ID(id)
{}


void Urbanizacao::adicionaImovel(Imovel *im1)
{ imoveis.push_back(im1); }


vector<Imovel *> Urbanizacao::getImoveis() const
{ return imoveis; }

string Urbanizacao::getNome() const
{ return nome; }

int Urbanizacao::getID() const
{ return ID; }


void ECondominio::adicionaUrbanizacao(Urbanizacao urb1)
{ urbanizacoes.push_back(urb1); }

vector<Urbanizacao> ECondominio::getUrbanizacoes() const
{ return urbanizacoes; }

