/*
 * Project.h
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#ifndef SRC_PROJECT_H_
#define SRC_PROJECT_H_

#include <string>

#include "Student.h"
using namespace std;

class Project {
	const string title;
	const unsigned cost;
	const string expertize;
	Student* consultant;
public:
	Project(string title, string expertize, unsigned price);
	string getTitle() const;
	string getExpertize() const;
	unsigned getCost() const;
	void setConsultant(Student* student);
	Student* getConsultant() const;
};

#endif /* SRC_PROJECT_H_ */
