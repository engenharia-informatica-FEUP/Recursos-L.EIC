#include "ClubeVideo.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const Filme& umFilme) {
	os << umFilme.titulo << " " << umFilme.emprestimos;
	return os;
}

ostream& operator<<(ostream& os, const PedidoCliente& pc) {
	os << "Cliente " << pc.nome << " em espera para " << pc.titulo << endl;
	return os;
}

ostream& operator<<(ostream& os, const Cliente& c1) {
	os << c1.nome << " tem " << c1.filmesEmprestados.size() << " filmes!\n";
	return os;
}


//
// Incluir abaixo a implementação das suas funções
//





