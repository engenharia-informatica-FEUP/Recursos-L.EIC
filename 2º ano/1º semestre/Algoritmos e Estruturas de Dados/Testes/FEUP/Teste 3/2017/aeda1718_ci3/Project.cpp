/*
 * Project.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "Project.h"

Project::Project(string title, string expertize, unsigned cost):
	title(title), cost(cost), expertize(expertize) {
	consultant = 0; // TODO: shouldnt this be NULL?
}

string Project::getTitle() const {
	return this->title;
}

unsigned Project::getCost() const {
	return this->cost;
}

string Project::getExpertize() const {
	return this->expertize;
}

void Project::setConsultant(Student* student) {
	this->consultant = student;
}

Student* Project::getConsultant() const {
	return this->consultant;
}
