/*
 * Student.h
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#ifndef SRC_STUDENT_H_
#define SRC_STUDENT_H_

#include <string>
#include <vector>
#include <utility>

using namespace std;

class StudentPtr;

class Student {
	string name;
	string eMail;
	string currentProject;
	vector<string> pastProjects;
public:
	friend class StudentPtr;
	Student(string name, string eMail);
	string getName() const;
	string getEMail() const;
	void setEMail(string eMail);
	void addProject(string title);
	void closeProject();
	string getCurrentProject() const;
	vector<string> getPastProjects() const;
	//TODO:
	bool operator<(const Student& stu1) const;
};

// TODO
class StudentPtr {
	Student* student;
public:
	StudentPtr(Student* student);
	string getName() const;
	void setEMail(string eMail);
	string getEMail() const;
};

#endif /* SRC_STUDENT_H_ */
