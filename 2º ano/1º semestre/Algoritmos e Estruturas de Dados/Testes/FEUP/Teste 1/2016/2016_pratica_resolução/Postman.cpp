/*
 * Postman.cpp
 */
#include "Postman.h"
#include "PostOffice.h"

unsigned int Postman::nextId = 1;

Postman::Postman(): id(0) {}

Postman::Postman(string name) : id(nextId++), name(name) {}

void Postman::setName(string nm){
	name = nm;
}

string Postman::getName() const{
	return name;
}

vector<Mail *> Postman::getMail() const {
	return myMail;
}

void Postman::addMail(Mail *m) {
	myMail.push_back(m);
}

void Postman::addMail(vector<Mail *> mails) {
	myMail.insert(myMail.end(),mails.begin(),mails.end());
}

unsigned int Postman::getID() const{
	return id;
}

bool Postman::operator<(const Postman &rhs) {
    vector<string> leftZipCodes, rightZipCodes;

    for (vector<Mail *>::const_iterator it = myMail.begin(); it != myMail.end(); it++) {
        leftZipCodes.push_back((*it)->getZipCode());
    }

    for (vector<Mail *>::const_iterator it = rhs.myMail.begin(); it != rhs.myMail.end(); it++) {
        rightZipCodes.push_back((*it)->getZipCode());
    }

    unsigned int leftPlaces = numberDifferent(leftZipCodes), rightPlaces = numberDifferent(rightZipCodes);

    return leftPlaces < rightPlaces;
}




