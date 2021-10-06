/*
 * Escritorio.h
 *
 *  Created on: Oct 4, 2015
 *      Author: arocha
 */

#ifndef ESCRITORIO_H_
#define ESCRITORIO_H_

#include <vector>
#include <string>
using namespace std;


class Documento {
  int numPaginas;
  float pPreto, pAmarelo;
public:
   Documento(int nPag, float pP, float pA);
   ~Documento();
   int getNumPaginas() const;
   float getPercentagemPreto() const;
   float getPercentagemAmarelo() const;
	// …
};

class Impressora {
protected:
  const string codigo;
  const int ano;
  vector<Documento> docsImpressos;
public:
	Impressora(string cod, int a);
	virtual ~Impressora();
	string getCodigo() const;
	int getAno() const;
	vector<Documento> getDocumentosImpressos() const;
	// …
};

class ImpressoraPB: public Impressora {
  int numPagImprimir;
public:
   ImpressoraPB(string cod, int a, int toner);
   int getNumPaginasImprimir() const;
	// …
};

class ImpressoraCores: public Impressora {
  float numPagImprimirPreto;
  float numPagImprimirAmarelo;
public:
   ImpressoraCores(string cod, int a, int toner);
   int getNumPaginasImprimir() const;
	// …
};

class Funcionario {
  string codigo;
  vector<Impressora *> impressoras;
public:
  Funcionario(string cod);
  ~Funcionario();
  string getCodigo() const;
  void adicionaImpressora(Impressora *i1);
  vector<Impressora *> getImpressoras() const;
	// …
};

class Escritorio {
  vector<Impressora *> impressoras;
  vector<Funcionario> funcionarios;
public:
  Escritorio();
  ~Escritorio();
  void adicionaImpressora(Impressora *i1);
  void adicionaFuncionario(Funcionario f1);
  vector<Impressora *> getImpressoras() const;
  // …
};






#endif /* ESCRITORIO_H_ */
