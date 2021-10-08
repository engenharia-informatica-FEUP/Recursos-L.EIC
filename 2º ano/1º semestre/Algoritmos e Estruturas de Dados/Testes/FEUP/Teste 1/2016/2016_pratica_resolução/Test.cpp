#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Mail.h"
#include "Postman.h"
#include "PostOffice.h"
#include <vector>
#include <string>
using namespace std;

TEST(test, test_a) {
	vector<int> v1;
	v1.push_back(10); v1.push_back(8);
	v1.push_back(12); v1.push_back(8);
	ASSERT_EQ(3, numberDifferent(v1));
	vector<string> v2;
	v2.push_back("ola"); v2.push_back("ola");
	ASSERT_EQ(1, numberDifferent(v2));
	v2.push_back("rio"); v2.push_back("arvore");
	v2.push_back("sol"); v2.push_back("sol");
	ASSERT_EQ(4, numberDifferent(v2));
}

TEST(test, test_b) {
	PostOffice po;
	Postman p1;
	p1. setName("joao");
	p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
	p1.addMail(new RegularMail("luis", "rui","4400-146", 33));
	Postman p2;
	p2. setName("paulo");
	p2.addMail(new RegularMail("rui", "ana","3330-454", 33));
	p2.addMail(new RegularMail("luis", "maria","8600-306", 67));
	p2.addMail(new RegularMail("carla", "lara","7100-514", 67));
	Postman p3;
	p3.setName("fernando");
	p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
	po.addPostman(p1);
	po.addPostman(p2);
	po.addPostman(p3);

	vector <Mail *> mailP = po.removePostman("paulo");
	ASSERT_EQ(3, mailP.size());
	ASSERT_EQ(2,po.getPostman().size());

	mailP.clear();
	mailP = po.removePostman("sergio");
	ASSERT_EQ(0, mailP.size());

	mailP.clear();
	mailP = po.removePostman("fernando");
	ASSERT_EQ(1, mailP.size());

	mailP.clear();
	mailP = po.removePostman("joao");
	ASSERT_EQ(2, mailP.size());

	ASSERT_EQ(0,po.getPostman().size());
}

TEST(test, test_c) {
	RegularMail m1("manuel", "ana","3330-454", 33);
	RegularMail m2("ana", "rui","4400-146", 550);
	GreenMail m3("maria", "luis","2520-110", "bag");
	GreenMail m4("carla", "lara","7100-514", "envelope");

	ASSERT_EQ(75, m1.getPrice());
	ASSERT_EQ(325, m2.getPrice());
	ASSERT_EQ(200, m3.getPrice());
	ASSERT_EQ(80, m4.getPrice());
}

TEST(test, test_d) {
	PostOffice po("3100-000", "4409-999");
	po.addMailToSend(new RegularMail("manuel", "ana","3330-454", 33));
	po.addMailToSend(new RegularMail("ana", "rui","4400-146", 550));
	po.addMailToSend(new GreenMail("maria", "luis","2520-110", "bag"));
	po.addMailToSend(new GreenMail("carla", "lara","7100-514", "envelope"));

	unsigned int bal = 0;
	vector<Mail *> mailToOtherPO = po.endOfDay(bal);
	ASSERT_EQ(680, bal);
	ASSERT_EQ(2,mailToOtherPO.size());
	ASSERT_EQ(2,po.getMailToDeliver().size());
	ASSERT_EQ(0,po.getMailToSend().size());

	PostOffice po2("3100-000", "4409-999");
	po2.addMailToSend(new RegularMail("rita", "joana","5200-514", 120));

	mailToOtherPO = po2.endOfDay(bal);
	ASSERT_EQ(140, bal);
	ASSERT_EQ(1,mailToOtherPO.size());
	ASSERT_EQ(0,po2.getMailToDeliver().size());
	ASSERT_EQ(0,po2.getMailToSend().size());
}

TEST(test, test_e) {
	Postman p1("joao");
	Postman p2("rui");
	Postman p3("paulo");

	ASSERT_EQ(1, p1.getID());
	ASSERT_EQ(2, p2.getID());
	ASSERT_EQ(3, p3.getID());
}

TEST(test, test_f) {
	Postman p1;
	p1. setName("joao");
	p1.addMail(new RegularMail("rui", "ana","3330-454", 33));
	p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
	p1.addMail(new RegularMail("luis", "rui","4400-146", 33));

	Postman p2;
	p2. setName("paulo");
	p2.addMail(new RegularMail("rui", "ana","3330-454", 33));
	p2.addMail(new RegularMail("carla", "lara","7100-514", 67));
	p2.addMail(new RegularMail("luis", "maria","8600-306", 67));

	ASSERT_EQ(true, p1<p2);
	ASSERT_EQ(false, p2<p1);

	p1.addMail(new RegularMail("joana", "rui","4400-146", 33));
	p1.addMail(new RegularMail("rita", "joana","5200-514", 120));
	p1.addMail(new RegularMail("maria", "lara","7100-514", 67));

	p2.addMail(new RegularMail("maria", "lara","8600-306", 67));

	ASSERT_EQ(false, p1<p2);
	ASSERT_EQ(true, p2<p1);
}

TEST(test, test_g) {
	PostOffice po;
	Postman p1;
	p1. setName("joao");
	p1.addMail(new RegularMail("ana", "rui","4400-146", 33));
	p1.addMail(new RegularMail("luis", "rui","4400-146", 33));
	Postman p2;
	p2. setName("paulo");
	Postman p3;
	p3.setName("fernando");
	p3.addMail(new RegularMail("manuel", "ana","3330-454", 33));
	po.addPostman(p1);
	po.addPostman(p2);
	po.addPostman(p3);

	Postman px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"paulo");
	ASSERT_EQ(1,px.getMail().size());

	ASSERT_THROW(po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"luis"), NoPostmanException);

	try {
		px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"joao");
		ASSERT_EQ(3,px.getMail().size());
		px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"ricardo");
	}
	catch(NoPostmanException &e) {
		ASSERT_EQ("ricardo", e.getName());
	}

	px = po.addMailToPostman(new RegularMail("rui", "ana","3330-454", 33),"fernando");
	ASSERT_EQ(2,px.getMail().size());
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();;
}

