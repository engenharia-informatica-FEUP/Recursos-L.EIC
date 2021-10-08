/*
 * Agencia.cpp
 */

#include "Agencia.h"


//Conta
Conta::Conta(int nConta, float sd, int nTrans): numConta(nConta), saldo(sd), numTransacoes(nTrans), titular2(NULL)
{ }

int Conta::getNumConta() const
{ return numConta; }

float Conta::getSaldo() const
{ return saldo; }

int Conta::getNumTransacoes() const
{ return numTransacoes; }


void Conta::setTitular2(Cliente *cli2)
{ titular2=cli2; }

Cliente *Conta::getTitular2() const
{ return titular2; }



Normal::Normal(int nConta, float sd, int nTrans): Conta(nConta, sd, nTrans)
{}

DeOperacao::DeOperacao(int nConta, float tx, float sd, int nTrans): Conta(nConta, sd, nTrans), taxa(tx)
{}


//Cliente
Cliente::Cliente (string nm): nome(nm)
{}

string Cliente::getNome() const
{ return nome; }

vector<Conta *> Cliente::getContas() const
{ return contas; }

void Cliente::adicionaConta(Conta *c1)
{ contas.push_back(c1); }


//Agencia
Agencia::Agencia(string desig): designacao(desig)
{}

string Agencia::getDesignacao() const
{ return designacao; }

vector<Cliente *> Agencia::getClientes() const
{ return clientes; }

vector<Gerente> Agencia::getGerentes() const
{ return gerentes; }

void Agencia::adicionaCliente(Cliente *cli1)
{ clientes.push_back(cli1); }


//Gerente
int Gerente::getID() const
{ return ID; }

string Gerente::getNome() const
{ return nome; }


