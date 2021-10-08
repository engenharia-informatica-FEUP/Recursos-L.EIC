#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Escritorio.h"

TEST(test, test_a_ImpressorasSemResponsavel) {
	Escritorio e1;
	Impressora *imp1 = new ImpressoraPB("PBa", 2014, 25);   //codigo, ano, numPaginasToner
	Impressora *imp2 = new ImpressoraCores("Ca", 2014, 50);   //codigo, ano, numPaginasToner
	Impressora *imp3 = new ImpressoraPB("PBb", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp4 = new ImpressoraPB("PBc", 2014, 20);   //codigo, ano, numPaginasToner
	Impressora *imp5 = new ImpressoraCores("Cb", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp6 = new ImpressoraCores("Cc", 2014, 15);   //codigo, ano, numPaginasToner
	e1.adicionaImpressora(imp1);
	e1.adicionaImpressora(imp2);
	e1.adicionaImpressora(imp3);
	e1.adicionaImpressora(imp4);
	e1.adicionaImpressora(imp5);
	e1.adicionaImpressora(imp6);

	EXPECT_EQ(6, e1.numImpressorasSemResponsavel());

	Funcionario fa("fA");
	fa.adicionaImpressora(imp1);
	fa.adicionaImpressora(imp2);
	e1.adicionaFuncionario(fa);

	Funcionario fb("fB");
	e1.adicionaFuncionario(fb);

	EXPECT_EQ(4,e1.numImpressorasSemResponsavel());

	Funcionario fc("fC");
	fc.adicionaImpressora(imp4);
	e1.adicionaFuncionario(fc);

	EXPECT_EQ(3,e1.numImpressorasSemResponsavel());

	Funcionario fd("fD");
	fd.adicionaImpressora(imp5);
	fd.adicionaImpressora(imp6);
	fd.adicionaImpressora(imp3);
	e1.adicionaFuncionario(fd);

	EXPECT_EQ(0, e1.numImpressorasSemResponsavel());
}



TEST(test, test_b_retiraImpressoras) {
	Escritorio e1;
	Impressora *imp1 = new ImpressoraPB("PBa", 2011, 100);   //codigo, ano, numPaginasToner
	Impressora *imp2 = new ImpressoraCores("Ca", 2010, 100);   //codigo, ano, numPaginasToner
	Impressora *imp3 = new ImpressoraPB("PBb", 2008, 100);   //codigo, ano, numPaginasToner
	Impressora *imp4 = new ImpressoraPB("PBc", 2013, 100);   //codigo, ano, numPaginasToner
	Impressora *imp5 = new ImpressoraPB("PBd", 2011, 100);   //codigo, ano, numPaginasToner

	vector<Impressora *> res;
	res = e1.retiraImpressoras(2012);
	EXPECT_EQ (0, res.size());

	e1.adicionaImpressora(imp1);
	e1.adicionaImpressora(imp2);
	e1.adicionaImpressora(imp3);
	e1.adicionaImpressora(imp4);
	e1.adicionaImpressora(imp5);

	res = e1.retiraImpressoras(2009);
	EXPECT_EQ(1, res.size());
	EXPECT_EQ("PBb", res[0]->getCodigo());
	EXPECT_EQ(4,e1.getImpressoras().size());

	res = e1.retiraImpressoras(2012);
	EXPECT_EQ (3, res.size());
	EXPECT_EQ(1,e1.getImpressoras().size());
	EXPECT_EQ("PBc", e1.getImpressoras()[0]->getCodigo());
}



TEST(test, test_c_imprimeDoc) {
     Documento docPB1(100, 1, 0);  //numPaginas, pPreto, PAmarelo
	 Documento docPB2(40, 1, 0);  //numPaginas, pPreto, PAmarelo
	 Documento docC1(90, 0.8, 0.2);  //numPaginas, pPreto, PAmarelo
	 Documento docC2(90, 0.2, 0.8);  //numPaginas, pPreto, PAmarelo

	 ImpressoraPB impPB("PBa", 2014, 200);   //codigo, ano, numPaginasToner
	 ImpressoraCores impC("Ca", 2014, 100);   //codigo, ano, numPaginasToner

	 EXPECT_EQ(true,impPB.imprime(docC1));
	 EXPECT_EQ(110,impPB.getNumPaginasImprimir());
	 EXPECT_EQ(true,impPB.imprime(docPB1));
	 EXPECT_EQ(false,impPB.imprime(docPB2));
	 EXPECT_EQ(2,impPB.getDocumentosImpressos().size());
	 EXPECT_EQ(10,impPB.getNumPaginasImprimir());

	 EXPECT_EQ(true,impC.imprime(docPB2));
	 EXPECT_EQ(60,impC.getNumPaginasImprimir());
	 EXPECT_EQ(false,impC.imprime(docPB1));
	 EXPECT_EQ(1,impC.getDocumentosImpressos().size());
	 EXPECT_EQ(true,impC.imprime(docC2));
	 EXPECT_EQ(2,impC.getDocumentosImpressos().size());
	 EXPECT_EQ(28,impC.getNumPaginasImprimir());
	 EXPECT_EQ(false,impC.imprime(docC1));
}



TEST(test, test_d_ImpressoraImpressaoDoc) {
	Escritorio e1;
	Impressora *imp1 = new ImpressoraPB("PBa", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp2 = new ImpressoraCores("Ca", 2014, 200);   //codigo, ano, numPaginasToner
	Impressora *imp3 = new ImpressoraPB("PBb", 2014, 200);   //codigo, ano, numPaginasToner
	e1.adicionaImpressora(imp1);
	e1.adicionaImpressora(imp2);
	e1.adicionaImpressora(imp3);

	Documento docPB1(120, 1, 0);  //numPaginas, pPreto, PAmarelo
	Documento docC1(300, 0.3, 0.7);  //numPaginas, pPreto, PAmarelo
	Documento docC2(200, 0.8, 0.2);  //numPaginas, pPreto, PAmarelo
	Documento docPB2(70, 1, 0);  //numPaginas, pPreto, PAmarelo

	Impressora *res =e1.imprimeDoc(docC1);
	EXPECT_EQ("inexistente",res->getCodigo());

	res =e1.imprimeDoc(docC2);
	EXPECT_EQ("Ca",res->getCodigo());
	EXPECT_EQ(1, res->getDocumentosImpressos().size());

	res =e1.imprimeDoc(docPB2);
	EXPECT_EQ("PBa",res->getCodigo());
	EXPECT_EQ(1, res->getDocumentosImpressos().size());


	res =e1.imprimeDoc(docPB2);
	EXPECT_EQ("PBb",res->getCodigo());
	EXPECT_EQ(1, res->getDocumentosImpressos().size());

	res =e1.imprimeDoc(docPB2);
	EXPECT_EQ("PBb",res->getCodigo());
	EXPECT_EQ(2, res->getDocumentosImpressos().size());

	res =e1.imprimeDoc(docPB2);
	EXPECT_EQ("inexistente",res->getCodigo());
}



TEST(test, test_e_TonerBaixo) {
	Escritorio e1;
	Impressora *imp1 = new ImpressoraPB("PBa", 2014, 25);   //codigo, ano, numPaginasToner
	Impressora *imp2 = new ImpressoraCores("Ca", 2014, 50);   //codigo, ano, numPaginasToner
	Impressora *imp3 = new ImpressoraPB("PBb", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp4 = new ImpressoraPB("PBc", 2014, 20);   //codigo, ano, numPaginasToner
	Impressora *imp5 = new ImpressoraCores("Cb", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp6 = new ImpressoraCores("Cc", 2014, 15);   //codigo, ano, numPaginasToner

	vector<Impressora *> res;
	res = e1.tonerBaixo();
	EXPECT_EQ(0,res.size());

	e1.adicionaImpressora(imp1);
	e1.adicionaImpressora(imp2);
	e1.adicionaImpressora(imp3);

	res = e1.tonerBaixo();
	EXPECT_EQ(1,res.size());
	EXPECT_EQ("PBa", res[0]->getCodigo());

	e1.adicionaImpressora(imp4);
	e1.adicionaImpressora(imp5);
	e1.adicionaImpressora(imp6);

	res = e1.tonerBaixo();
	EXPECT_EQ(3,res.size());
	EXPECT_EQ(true, (res[0]->getCodigo()=="PBc" || res[1]->getCodigo()=="PBc" || res[2]->getCodigo()=="PBc"));
	EXPECT_EQ(true, (res[0]->getCodigo()=="Cc" || res[1]->getCodigo()=="Cc" || res[2]->getCodigo()=="Cc"));
}



TEST(test, test_f_operadorMais) {
	Documento d1(30,1,0);
	Documento d2(70,0.8,0.2);

	Documento dx=d1+d2;
	EXPECT_EQ(100,dx.getNumPaginas());
	EXPECT_NEAR(0.86,dx.getPercentagemPreto(),0.01);
	EXPECT_NEAR(0.14,dx.getPercentagemAmarelo(),0.01);

	Documento d3(50,1,0);
	Documento dy=d1+d3;
	EXPECT_EQ(80,dy.getNumPaginas());
	EXPECT_NEAR(1,dy.getPercentagemPreto(),0.01);
	EXPECT_NEAR(0,dy.getPercentagemAmarelo(),0.01);
}



TEST(test, test_g_operadorFuncao) {
	Escritorio e1;
	Impressora *imp1 = new ImpressoraPB("PBa", 2014, 25);   //codigo, ano, numPaginasToner
	Impressora *imp2 = new ImpressoraCores("Ca", 2014, 50);   //codigo, ano, numPaginasToner
	Impressora *imp3 = new ImpressoraPB("PBb", 2014, 100);   //codigo, ano, numPaginasToner
	Impressora *imp4 = new ImpressoraPB("PBc", 2014, 20);   //codigo, ano, numPaginasToner
	Impressora *imp5 = new ImpressoraCores("Cb", 2014, 100);   //codigo, ano, numPaginasToner

	Funcionario fa("fA");
	fa.adicionaImpressora(imp1);
	fa.adicionaImpressora(imp2);

	Funcionario fb("fB");
	fb.adicionaImpressora(imp3);

	Funcionario fc("fC");
	fc.adicionaImpressora(imp4);
	fc.adicionaImpressora(imp5);

	e1.adicionaFuncionario(fa);
	e1.adicionaFuncionario(fb);
	e1.adicionaFuncionario(fc);

	EXPECT_EQ("nulo", e1("PBx"));
	EXPECT_EQ("fC", e1("Cb"));
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

