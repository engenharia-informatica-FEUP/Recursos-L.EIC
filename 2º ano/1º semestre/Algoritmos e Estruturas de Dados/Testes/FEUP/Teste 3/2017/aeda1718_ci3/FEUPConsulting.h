/*
 * FEUPConsulting.h
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#ifndef SRC_FEUPCONSULTING_H_
#define SRC_FEUPCONSULTING_H_

#include "BST.h"
#include <vector>
#include <unordered_set>
#include <queue>
#include "Expertize.h"
#include "Student.h"
#include "Project.h"

using namespace std;

struct StudentPtrHash
{
	int operator() (const StudentPtr& student) const
	{
		//TODO:
		return 0;
	}

	bool operator() (const StudentPtr& student1, const StudentPtr& student2) const
	{
		//TODO:
		return true;
	}
};


typedef unordered_set<StudentPtr, StudentPtrHash, StudentPtrHash> HashTabStudentPtr;

class FEUPConsulting {
	vector<Project*> projects;
	BST<Expertize> expertizes;
	HashTabStudentPtr students;
	priority_queue<Student> activeStudents;
public:
	FEUPConsulting();
	FEUPConsulting(vector<Project*> projects);

	void addProjects(vector<Project*> projects);
	vector<Project*> getProjects() const;

	// Part I   - BST
	Expertize getExpertize(string name, unsigned cost);
	void addNewExpertize(const Expertize & expertize1);
	void addProject(Project* project);
	BST<Expertize> getExpertizes() const;
	// Part II  - Hash Table
	vector<StudentPtr> getStudents() const;
	void setStudents(vector<StudentPtr>& newStudents);
	// Part III - Priority Queue
	priority_queue<Student> getActiveStudents() const;
	void setActiveStudents(priority_queue<Student>& students);


	// TODO: Implement methods below...
	// Part I   - BST
	/* A */ void addAvailability(Student* student, string expertize, unsigned cost);
	/* B */ vector<Student*> getCandidateStudents(Project* book) const;
	/* C */ bool assignProjectToStudent(Project* project, Student* student);

	// Part II  - Hash Table
	/* D */ void addStudent(Student* user);
	/* E */ void changeStudentEMail(Student* student, string newEMail);

	// Part III - Piority Queue
	/* F */ void addActiveStudents(const vector<Student>& candidates, int min);
	/* G */ int mostActiveStudent(Student& studentMaximus);
};




#endif /* SRC_FEUPCONSULTING_H_ */
