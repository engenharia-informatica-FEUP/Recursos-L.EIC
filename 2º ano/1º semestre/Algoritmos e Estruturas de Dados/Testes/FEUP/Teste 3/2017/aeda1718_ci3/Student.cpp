/*
 * Student.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "Student.h"

Student::Student(string name, string eMail) {
	this->name = name;
	this->eMail = eMail;
}

string Student::getName() const {
	return this->name;
}

void Student::setEMail(string eMail) {
	this->eMail = eMail;
}

string Student::getEMail() const {
	return this->eMail;
}

void Student::addProject(string title) {
	// if the current project is blank, set current project
	if(this->currentProject == "") {
		this->currentProject = title;
	}
	//replace current project, and add previous to past projects
	else {
		this->pastProjects.push_back(this->currentProject);
		this->currentProject = title;
	}
}

void Student::closeProject() {
	if(currentProject != "") {
		pastProjects.push_back(currentProject);
		currentProject = "";
	}
}

string Student::getCurrentProject() const {
	return this->currentProject;
}

vector<string> Student::getPastProjects() const {
	return this->pastProjects;
}

// TODO
bool Student::operator<(const Student& stu1) const {
	//TODO
	return true;
}



/*
 * Implementation of Class StudentPtr
 */

StudentPtr::StudentPtr(Student* student) {
	this->student= student;
}

string StudentPtr::getName() const {
	return this->student->name;
}

void StudentPtr::setEMail(string eMail) {
	this->student->eMail = eMail;
}

string StudentPtr::getEMail() const {
	return this->student->eMail;
}



