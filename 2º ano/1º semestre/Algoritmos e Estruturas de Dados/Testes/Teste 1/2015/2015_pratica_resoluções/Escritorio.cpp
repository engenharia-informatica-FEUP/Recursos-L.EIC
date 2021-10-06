#include "Escritorio.h"
#include <iostream>


//Documento
Documento::Documento(int nPag, float pP, float pA):
			numPaginas(nPag), pPreto(pP), pAmarelo(pA)
{ }
Documento::~Documento() {}

int Documento::getNumPaginas() const { return numPaginas; }

float Documento::getPercentagemPreto() const { return pPreto; }

float Documento::getPercentagemAmarelo() const { return pAmarelo; }

Documento Documento::operator+(const Documento& rhs) const {
    int nPag = numPaginas + rhs.numPaginas;
    float pP = (pPreto * numPaginas + rhs.pPreto * rhs.numPaginas) / nPag;
    float pA = (pAmarelo * numPaginas + rhs.pAmarelo * rhs.numPaginas) / nPag;

    return Documento(nPag, pP, pA);
}


//Impressora
Impressora::Impressora(string cod, int a): codigo(cod), ano(a)
{}
Impressora::~Impressora() {}

string Impressora::getCodigo() const
{ return codigo; }

int Impressora::getAno() const
{ return ano; }

vector<Documento> Impressora::getDocumentosImpressos() const
{ return docsImpressos; }



//ImpressoraPB
ImpressoraPB::ImpressoraPB(string cod, int a, int toner): Impressora(cod, a), numPagImprimir(toner)
{}

int ImpressoraPB::getNumPaginasImprimir() const
{ return numPagImprimir; }

bool ImpressoraPB::imprime(Documento doc1) {
    if (numPagImprimir < doc1.getNumPaginas()) {
        return false;
    }
    else {
        numPagImprimir -= doc1.getNumPaginas();
        docsImpressos.push_back(doc1);
        return true;
    }
}


//ImpressoraCores
ImpressoraCores::ImpressoraCores(string cod, int a, int toner): Impressora(cod, a),
		numPagImprimirPreto(toner), numPagImprimirAmarelo(toner)
{}

int ImpressoraCores::getNumPaginasImprimir() const {
	if (numPagImprimirPreto < numPagImprimirAmarelo) return (int)numPagImprimirPreto;
	return (int)numPagImprimirAmarelo;
}

bool ImpressoraCores::imprime(Documento doc1) {
    float pagPreto = doc1.getNumPaginas() * doc1.getPercentagemPreto(), pagAmarelo = doc1.getNumPaginas() * doc1.getPercentagemAmarelo();

    if (numPagImprimirPreto < pagPreto || numPagImprimirAmarelo < pagAmarelo) {
        return false;
    }
    else {
        numPagImprimirPreto -= pagPreto;
        numPagImprimirAmarelo -= pagAmarelo;
        docsImpressos.push_back(doc1);
        return true;
    }
}


//Funcionario
Funcionario::Funcionario(string cod): codigo(cod)
{}
Funcionario::~Funcionario() {}

void Funcionario::adicionaImpressora(Impressora *i1)
{ impressoras.push_back(i1); }

vector<Impressora *> Funcionario::getImpressoras() const
{ return impressoras; }

string Funcionario::getCodigo() const
{ return codigo; }



//Escritorio
Escritorio::Escritorio() {}
Escritorio::~Escritorio() {}

void Escritorio::adicionaImpressora(Impressora *i1)
{ impressoras.push_back(i1); }

void Escritorio::adicionaFuncionario(Funcionario f1)
{ funcionarios.push_back(f1); }

vector<Impressora *> Escritorio::getImpressoras() const
{ return impressoras; }

int Escritorio::numImpressorasSemResponsavel() const {
    int total = 0;
    bool semResponsavel;

    for (vector<Impressora *>::const_iterator itImp = impressoras.begin(); itImp != impressoras.end(); itImp++) {
        semResponsavel = true;

        for (vector<Funcionario>::const_iterator itFunc = funcionarios.begin(); itFunc != funcionarios.end(); itFunc++) {
            vector<Impressora *> impressorasFunc = itFunc->getImpressoras();
            for (vector<Impressora *>::const_iterator itImpFunc = impressorasFunc.begin(); itImpFunc != impressorasFunc.end(); itImpFunc++) {
                if ((*itImp)->getCodigo() == (*itImpFunc)->getCodigo()) {
                    semResponsavel = false;
                    break;
                }
            }

            if (!semResponsavel) {
                break;
            }
        }

        if (semResponsavel) {
            ++total;
        }
    }

    return total;
}

vector<Impressora *> Escritorio::retiraImpressoras(int ano1) {
    vector<Impressora *> impressorasRemovidas;

    for (vector<Impressora *>::iterator it = impressoras.begin(); it != impressoras.end(); it++) {
        if ((*it)->getAno() < ano1) {
            impressorasRemovidas.push_back(*it);
            it = impressoras.erase(it);
            it--;
        }
    }

    return impressorasRemovidas;
}

Impressora* Escritorio::imprimeDoc(Documento doc1) const {
    Impressora* inex = new ImpressoraPB("inexistente", 0, 0);

    for (vector<Impressora *>::const_iterator it = impressoras.begin(); it != impressoras.end(); it++) {
        if ((*it)->imprime(doc1)) {
            return *it;
        }
    }

    return inex;
}

vector<Impressora *> Escritorio::tonerBaixo() const {
    vector<Impressora *> res;

    for (vector<Impressora *>::const_iterator it = impressoras.begin(); it != impressoras.end(); it++) {
        ImpressoraPB* pb = dynamic_cast<ImpressoraPB *>(*it);
        ImpressoraCores* cores = dynamic_cast<ImpressoraCores *>(*it);

        if (pb != nullptr) {
            if (pb->getNumPaginasImprimir() < 30) {
                res.push_back(*it);
            }
        }
        else if (cores != nullptr) {
            if (cores->getNumPaginasImprimir() < 20) {
                res.push_back(*it);
            }
        }
    }

    return res;
}

string Escritorio::operator()(string cod) const {
    for (vector<Funcionario>::const_iterator itFunc = funcionarios.begin(); itFunc != funcionarios.end(); itFunc++) {
        vector<Impressora *> impressorasFunc = itFunc->getImpressoras();
        for (vector<Impressora *>::const_iterator itImp = impressorasFunc.begin(); itImp != impressorasFunc.end(); itImp++) {
            if ((*itImp)->getCodigo() == cod) {
                return itFunc->getCodigo();
            }
        }
    }

    return "nulo";
}


