/*
 * Expertize.h
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#ifndef SRC_EXPERTIZE_H_
#define SRC_EXPERTIZE_H_

#include <string>

#include "Student.h"
using namespace std;

class Expertize {
	string name;
	unsigned cost;
	vector<Student*> consultants;
public:
	Expertize(string name, unsigned cost);
	string getName() const;
	unsigned getCost() const;
	vector<Student*> getConsultants() const;
	void setConsultants(vector<Student*> students);
	void addConsultant(Student* consultant);
    bool operator<(const Expertize &exp1) const;
    bool operator==(const Expertize &exp1) const;
};


#endif /* SRC_EXPERTIZE_H_ */
