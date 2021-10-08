#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Agencia.h"


void test_a_Transacao() {
	/* Normal cn1(123, 100);
	 DeOperacao co1(456, 0.03, 200, 4);

	 ASSERT_EQUAL(true, cn1.levantamento(30));
	 ASSERT_EQUAL_DELTA(70, cn1.getSaldo(),0.001);
	 ASSERT_EQUAL(false,cn1.levantamento(80));
	 ASSERT_EQUAL(1,cn1.getNumTransacoes());
	 cn1.deposito(50);
	 ASSERT_EQUAL(120,cn1.getSaldo());

	 ASSERT_EQUAL(true, co1.levantamento(60));
	 ASSERT_EQUAL_DELTA(139.97, co1.getSaldo(),0.001);
	 ASSERT_EQUAL(false,co1.levantamento(150));
	 ASSERT_EQUAL(5,co1.getNumTransacoes());
	 co1.deposito(40);
	 ASSERT_EQUAL_DELTA(179.97,co1.getSaldo(),0.001);*/
}


void test_b_LevantamentoCliente() {
	/*Agencia a1("Areosa");
	Cliente *c1 = new Cliente("Rui Joao");
	Cliente *c2 = new Cliente("Maria Matos");
	Cliente *c3 = new Cliente("Filipa Costa");

	Conta *cn1= new Normal(111,100);
	Conta *cn2=new Normal(444,70);
	Conta *co1= new DeOperacao(777,0.05,300);

	c1->adicionaConta(cn1); c1->adicionaConta(co1);
	c3->adicionaConta(cn2);

	a1.adicionaCliente(c1);
	a1.adicionaCliente(c2);
	a1.adicionaCliente(c3);

	Conta *ct1;
	ct1=a1.levantamento("Maria Matos",50);
	ASSERT_EQUAL(-1, ct1->getNumConta());
	ct1=a1.levantamento("Filipa Costa",80);
	ASSERT_EQUAL(-1, ct1->getNumConta());
	ct1=a1.levantamento("Rui Joao",140);
	ASSERT_EQUAL(777,ct1->getNumConta());
	ASSERT_EQUAL_DELTA(159.95,ct1->getSaldo(),0.001);
	ct1=a1.levantamento("Filipa Costa",30);
	ASSERT_EQUAL(444, ct1->getNumConta());
	ASSERT_EQUAL_DELTA(40,ct1->getSaldo(),0.001);*/
}


void test_c_FimMes() {
	/*Agencia a1("Areosa");
	Cliente *c1 = new Cliente("Rui Joao");
	Cliente *c2 = new Cliente("Maria Matos");
	Cliente *c3 = new Cliente("Filipa Costa");

	Conta *cn1= new Normal(111,100);
	Conta *cn2=new Normal(444,70);
	Conta *cn3=new Normal(555,200);
	Conta *co1= new DeOperacao(777,0.05,300);

	c1->adicionaConta(cn1); c1->adicionaConta(co1);
	c1->adicionaConta(cn3);
	c3->adicionaConta(cn2);

	a1.adicionaCliente(c1);
	a1.adicionaCliente(c2);
	a1.adicionaCliente(c3);

	ASSERT_EQUAL_DELTA(665.5,a1.fimMes(),0.001);*/
}


void test_d_RemoveCliente() {
	/*Agencia a1("Areosa");
	Cliente *c1 = new Cliente("Rui Joao");
	Cliente *c2 = new Cliente("Maria Matos");
	Cliente *c3 = new Cliente("Filipa Costa");

	Conta *cn1= new Normal(111,100);
	Conta *cn2=new Normal(444,70);
	Conta *cn3=new Normal(555,200);
	Conta *co1= new DeOperacao(777,0.05,300);

	co1->setTitular2(c2);
	cn2->setTitular2(c1);

	c1->adicionaConta(cn1); c1->adicionaConta(co1);
	c1->adicionaConta(cn3);
	c3->adicionaConta(cn2);

	a1.adicionaCliente(c3);
	a1.adicionaCliente(c1);
	a1.adicionaCliente(c2);

	vector<Conta *> contasC=a1.removeCliente("Rui Joao");
	ASSERT_EQUAL(2,contasC.size());
	ASSERT_EQUAL(2,a1.getClientes().size());

	contasC=a1.removeCliente("Filipa Costa");

	vector<Cliente *> clis=a1.getClientes();
	ASSERT_EQUAL("Maria Matos", clis[0]->getNome());
	vector<Conta *> contas1=clis[0]->getContas();
	ASSERT_EQUAL(777,contas1[0]->getNumConta());*/
}



void test_e_OperadorMenor() {
	/*Cliente *c1 = new Cliente("Rui Joao");
	Cliente *c2 = new Cliente("Maria Matos");
	Cliente *c3 = new Cliente("Filipa Costa");

	Conta *cn1= new Normal(111,100);
	Conta *cn2=new Normal(444,1800);
	Conta *cn3=new Normal(555,200);
	Conta *co1= new DeOperacao(777,0.05,300);


	c1->adicionaConta(cn1); c1->adicionaConta(co1);
	c1->adicionaConta(cn3);
	c3->adicionaConta(cn2);

	Agencia a1("Areosa");
	a1.adicionaCliente(c1);


	Agencia a2("Paranhos");
	a2.adicionaCliente(c1);
	a2.adicionaCliente(c2);

	ASSERT_EQUAL(false,a1 < a2);

	a2.adicionaCliente(c3);
	ASSERT_EQUAL(true,a1 < a2);*/
}


void test_f_OperadorFuncao() {
	/*Cliente *c1 = new Cliente("Rui Joao");
	Cliente *c2 = new Cliente("Maria Matos");
	Cliente *c3 = new Cliente("Filipa Costa");

	Conta *cn1= new Normal(111,100);
	Conta *cn2=new Normal(444,1800);
	Conta *cn3=new Normal(555,200);
	Conta *co1= new DeOperacao(777,0.05,300);


	c1->adicionaConta(cn1); c1->adicionaConta(co1);
	c1->adicionaConta(cn3);
	c3->adicionaConta(cn2);

	Agencia a1("Areosa");
	a1.adicionaCliente(c1);
	a1.adicionaCliente(c2);
	a1.adicionaCliente(c3);

	float saldoC = a1("Rui Joao");
	ASSERT_EQUAL_DELTA(600,saldoC,0.001);

	saldoC=a1("Maria Matos");
	ASSERT_EQUAL_DELTA(0,saldoC,0.001);

	saldoC=a1("Mariana Silva");
	ASSERT_EQUAL_DELTA(-1,saldoC,0.001);*/
}



void test_g_IDGerente() {
	/*Agencia a1("Areosa");
	a1.setGerenteID(4);
	a1.adicionaGerente("Luis Jorge");
	a1.adicionaGerente("Raul Mario");

	vector<Gerente> gerentes=a1.getGerentes();
	ASSERT_EQUAL(2,gerentes.size());
	int cod1=0,cod2=0;
	if (gerentes[0].getNome()=="Luis Jorge")
		cod1=4;
	else if (gerentes[0].getNome()=="Raul Mario")
		cod1=5;
	if (gerentes[1].getNome()=="Luis Jorge")
		cod2=4;
	else if (gerentes[1].getNome()=="Raul Mario")
		cod2=5;

	ASSERT_EQUAL(cod1,gerentes[0].getID());
	ASSERT_EQUAL(cod2,gerentes[1].getID());*/
}



void runSuite(){
	cute::suite s;
	s.push_back(CUTE(test_a_Transacao));
	s.push_back(CUTE(test_b_LevantamentoCliente));
	s.push_back(CUTE(test_c_FimMes));
	s.push_back(CUTE(test_d_RemoveCliente));
	s.push_back(CUTE(test_e_OperadorMenor));
	s.push_back(CUTE(test_f_OperadorFuncao));
	s.push_back(CUTE(test_g_IDGerente));
	//cute::ide_listener lis;  //Boost 1.7
	cute::ide_listener<> lis;  //Boost 2
	cute::makeRunner(lis)(s, "AEDA 2013/2014 - Avaliação - 23/out - Testes Unitarios Estudantes");
}

int main(){
    runSuite();
    return 0;
}

