#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Project.h"
#include "Student.h"
#include "FEUPConsulting.h"

#include <vector>
#include <iostream>
using namespace std;

void test_A_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/


	FEUPConsulting organization;

	Student* s1 = new Student("Joao", "joao@gmail.com");
	Student* s2 = new Student("Maria", "maria@gmail.com");
	Student* s3 = new Student("Manuela", "manuela@gmail.com");
	Student* s4 = new Student("Pedro", "pedro@gmail.com");

	organization.addAvailability(s1, "OOP", 50);
	organization.addAvailability(s1, "Data Science", 100);
	organization.addAvailability(s2, "OOP", 40);
	organization.addAvailability(s3, "OOP", 50);
	organization.addAvailability(s3, "AI", 100);
	organization.addAvailability(s4, "OOP", 50);
	organization.addAvailability(s4, "GUI", 75);

	Expertize e1 = organization.getExpertize("OOP", 50);
	ASSERT_EQUAL(3, e1.getConsultants().size());
	Expertize e2 = organization.getExpertize("Data Science", 100);
	ASSERT_EQUAL(1, e2.getConsultants().size());
	Expertize e3 = organization.getExpertize("OOP", 40);
	ASSERT_EQUAL(1, e3.getConsultants().size());
	Expertize e4 = organization.getExpertize("OOP", 100);
	ASSERT_EQUAL(0, e4.getConsultants().size());

}

void test_B_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	FEUPConsulting organization;

	Student* s1 = new Student("Joao", "joao@gmail.com");
	Student* s2 = new Student("Maria", "maria@gmail.com");
	Student* s3 = new Student("Manuela", "manuela@gmail.com");
	Student* s4 = new Student("Pedro", "pedro@gmail.com");

	Expertize expertize1("OOP", 50);
	expertize1.addConsultant(s3);
	expertize1.addConsultant(s4);
	Expertize expertize2("OOP", 40);
	expertize2.addConsultant(s2);
	Expertize expertize3("Data Science", 100);
	expertize3.addConsultant(s1);
	Expertize expertize4("AI", 100);
	expertize4.addConsultant(s3);
	Expertize expertize5("GUI", 75);
	expertize5.addConsultant(s4);

	organization.addNewExpertize(expertize1);
	organization.addNewExpertize(expertize2);
	organization.addNewExpertize(expertize3);
	organization.addNewExpertize(expertize4);
	organization.addNewExpertize(expertize5);

	Project* p1 = new Project("Project 1", "OOP", 50);
	Project* p2 = new Project("Project 2", "OOP", 40);
	Project* p3 = new Project("Project 3", "Data Science", 75);
	Project* p4 = new Project("Project 4", "GUI", 75);

	p2->setConsultant(s1);
	s1->addProject(p2->getTitle());

	p3->setConsultant(s2);
	s2->addProject(p3->getTitle());

	organization.addProject(p1);
	organization.addProject(p2);
	organization.addProject(p3);
	organization.addProject(p4);

	vector<Student*> candidates1 = organization.getCandidateStudents(p1);
	ASSERT_EQUAL(2, candidates1.size());
	vector<Student*> candidates2 = organization.getCandidateStudents(p2);
	ASSERT_EQUAL(0, candidates2.size());
	vector<Student*> candidates3 = organization.getCandidateStudents(p3);
	ASSERT_EQUAL(0, candidates3.size());
	vector<Student*> candidates4 = organization.getCandidateStudents(p4);
	ASSERT_EQUAL(1, candidates4.size());

}

void test_C_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	vector<Project*> projects;
	Project* p1 = new Project("Project 1", "OOP", 50);
	Project* p2 = new Project("Project 2", "OOP", 40);
	Project* p3 = new Project("Project 3", "Data Science", 100);

	Student* s1 = new Student("Joao", "joao@gmail.com");
	Student* s2 = new Student("Maria", "maria@gmail.com");
	Student* s3 = new Student("Manuela", "manuela@gmail.com");

	projects.push_back(p1);
	projects.push_back(p2);
	FEUPConsulting organization(projects);

	Expertize expertize1("OOP", 50);
	expertize1.addConsultant(s1);
	expertize1.addConsultant(s3);
	Expertize expertize2("OOP", 40);
	expertize2.addConsultant(s2);
	Expertize expertize3("Data Science", 100);
	expertize3.addConsultant(s1);
	Expertize expertize4("AI", 100);
	expertize4.addConsultant(s3);

	organization.addNewExpertize(expertize1);
	organization.addNewExpertize(expertize2);
	organization.addNewExpertize(expertize3);
	organization.addNewExpertize(expertize4);

	bool assignment1 = organization.assignProjectToStudent(p1, s2);
	ASSERT_EQUAL(false, assignment1);

	bool assignment2 = organization.assignProjectToStudent(p1, s1);
	ASSERT_EQUAL(true, assignment2);
	ASSERT_EQUAL("Joao", p1->getConsultant()->getName());

	bool assignment3 = organization.assignProjectToStudent(p1, s3);
	ASSERT_EQUAL(false, assignment3);
	ASSERT_EQUAL("Joao", p1->getConsultant()->getName());

	bool assignment4 = organization.assignProjectToStudent(p2, s2);
	ASSERT_EQUAL(true, assignment4);
	ASSERT_EQUAL("Maria", p2->getConsultant()->getName());

	bool assignment5 = organization.assignProjectToStudent(p3, s1);
	ASSERT_EQUAL(false, assignment5);

}

void test_D_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	Student s1("Tiago", "t.silva@gmail.com");
	Student s2("Tiago", "t.silva@gmail.com");
	Student s3("Pedro", "pedro@gmail.com");
	Student s4("ana", "ana@gmail.com");
	Student s5("Maria", "maria.castro@gmail.com");
	Student s6("Tiago", "tiago@gmail.com");

	FEUPConsulting organization;

	// TODO: does it make sense to use the stack or should we use the heap?
	organization.addStudent(&s1);
	vector<StudentPtr> sl1 = organization.getStudents();
	ASSERT_EQUAL(1, sl1.size());
	ASSERT_EQUAL("t.silva@gmail.com", sl1[0].getEMail());

	organization.addStudent(&s2);
	vector<StudentPtr> sl2 = organization.getStudents();
	ASSERT_EQUAL(1, sl2.size());

	organization.addStudent(&s3);
	organization.addStudent(&s4);
	organization.addStudent(&s5);
	vector<StudentPtr> sl3 = organization.getStudents();
	ASSERT_EQUAL(4, sl3.size());

	organization.addStudent(&s6);
	vector<StudentPtr> sl4 = organization.getStudents();
	ASSERT_EQUAL(5, sl4.size());

}

void test_E_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	Student s1("Tiago", "t.silva@gmail.com");
	vector<StudentPtr> sl1;
	sl1.push_back(StudentPtr(&s1));

	FEUPConsulting o1;
	o1.setStudents(sl1);

	o1.changeStudentEMail(&s1, "tiago.sousa@gmail.com");

	sl1 = o1.getStudents();
	ASSERT_EQUAL("tiago.sousa@gmail.com", sl1[0].getEMail());

	vector<StudentPtr> sl2;
	Student s2("Pedro", "pedro@gmail.com");
	Student s3("Ana", "ana@gmail.com");

	sl2.push_back(StudentPtr(&s1));
	sl2.push_back(StudentPtr(&s2));
	sl2.push_back(StudentPtr(&s3));

	FEUPConsulting o2;
	o2.setStudents(sl2);

	o2.changeStudentEMail(&s3, "a.gomes@gmail.com");

	vector<StudentPtr> sl3 = o2.getStudents();

	for(unsigned i = 0; i < sl3.size(); i++) {
		if(sl3[i].getName() == "Ana") ASSERT_EQUAL("a.gomes@gmail.com", sl3[i].getEMail());
	}

}

void test_F_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	Student s0("Tiago", "tiago@gmail.com");
	Student s1("Joao", "joao@gmail.com");
	Student s2("Maria", "maria@gmail.com");
	Student s3("Pedro", "pedro@gmail.com");
	Student s4("ana", "ana@gmail.com");
	Student s5("Miguel", "miguel@gmail.com");

	s1.addProject("Project 1");
	s1.addProject("Project 2");
	s1.addProject("Project 3");
	s1.addProject("Project 4");

	s2.addProject("Project 5");
	s2.addProject("Project 6");

	s3.addProject("Project 7");
	s3.addProject("Project 8");
	s3.addProject("Project 9");
	s3.addProject("Project 10");
	s3.addProject("Project 11");

	s5.addProject("Project 12");
	s5.addProject("Project 13");

	vector<Student> candidates_0;
	candidates_0.push_back(s0);

	vector<Student> candidates_2;
	candidates_2.push_back(s2);
	candidates_2.push_back(s5);

	vector<Student> candidates_5;
	candidates_5.push_back(s1);
	candidates_5.push_back(s2);
	candidates_5.push_back(s3);
	candidates_5.push_back(s4);
	candidates_5.push_back(s5);

	FEUPConsulting o1;

	o1.addActiveStudents(candidates_5, 4);
	ASSERT_EQUAL(1, o1.getActiveStudents().size());

	FEUPConsulting o2;
	o2.addActiveStudents(candidates_0, 2);
	ASSERT_EQUAL(0, o2.getActiveStudents().size());

	FEUPConsulting o3;
	o3.addActiveStudents(candidates_5, 3);
	ASSERT_EQUAL(2, o3.getActiveStudents().size());
	ASSERT_EQUAL("Pedro",o3.getActiveStudents().top().getName());

	vector<Student> candidates_a;
	candidates_a.push_back(s1);
	candidates_a.push_back(s3);

	FEUPConsulting o4;
	o4.addActiveStudents(candidates_a, 4);
	ASSERT_EQUAL(1, o4.getActiveStudents().size());

	vector<Student> candidates_b;
	s3.closeProject();
	candidates_b.push_back(s1);
	candidates_b.push_back(s3);

	FEUPConsulting o5;
	o5.addActiveStudents(candidates_b, 4);
	ASSERT_EQUAL(1, o5.getActiveStudents().size());

}


void test_G_() {
	/*
	ASSERTM("Failed on purpose!", false);
	*/

	Student s0("Tiago", "tiago@gmail.com");
	Student s1("Joao", "joao@gmail.com");
	Student s2("Maria", "maria@gmail.com");
	Student s3("Pedro", "pedro@gmail.com");
	Student s4("ana", "ana@gmail.com");
	Student s5("Miguel", "miguel@gmail.com");
	Student s6("Hugo", "hugo@gmail.com");

	s1.addProject("Project 1");
	s1.addProject("Project 2");
	s1.addProject("Project 3");
	s1.addProject("Project 4");

	s2.addProject("Project 5");
	s2.addProject("Project 6");

	s3.addProject("Project 7");
	s3.addProject("Project 8");
	s3.addProject("Project 9");
	s3.addProject("Project 10");
	s3.addProject("Project 11");

	s5.addProject("Project 12");
	s5.addProject("Project 13");

	s6.addProject("Project 14");

	Student maximus("","");

	priority_queue<Student> candidates_a;
	FEUPConsulting o1;
	o1.setActiveStudents(candidates_a);
	ASSERT_EQUAL(0, o1.mostActiveStudent(maximus));

	priority_queue<Student> candidates_b;
	candidates_b.push(s2);
	candidates_b.push(s5);
	candidates_b.push(s6);

	FEUPConsulting o2;
	o2.setActiveStudents(candidates_b);
	ASSERT_EQUAL(0, o2.mostActiveStudent(maximus));
	ASSERT_EQUAL(3, o2.getActiveStudents().size());

	priority_queue<Student> candidates_c;
	candidates_c.push(s1);
	candidates_c.push(s2);
	candidates_c.push(s3);

	FEUPConsulting o3;
	o3.setActiveStudents(candidates_c);
	ASSERT_EQUAL(3, o3.mostActiveStudent(maximus));
	ASSERT_EQUAL("Pedro", maximus.getName());
	ASSERT_EQUAL(3, o3.getActiveStudents().size());

	priority_queue<Student> candidates_d;
	candidates_d.push(s2);
	candidates_d.push(s6);

	FEUPConsulting o4;
	o4.setActiveStudents(candidates_d);
	ASSERT_EQUAL(2, o4.mostActiveStudent(maximus));
	ASSERT_EQUAL("Maria", maximus.getName());
	ASSERT_EQUAL(2, o4.getActiveStudents().size());

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(test_A_));
	s.push_back(CUTE(test_B_));
	s.push_back(CUTE(test_C_));
	s.push_back(CUTE(test_D_));
	s.push_back(CUTE(test_E_));
	s.push_back(CUTE(test_F_));
	s.push_back(CUTE(test_G_));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



