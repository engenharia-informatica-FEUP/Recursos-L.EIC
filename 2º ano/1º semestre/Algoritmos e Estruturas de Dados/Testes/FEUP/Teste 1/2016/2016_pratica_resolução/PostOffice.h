/*
 * PostOffice.h
 */

#ifndef SRC_POSTOFFICE_H_
#define SRC_POSTOFFICE_H_

#include "Mail.h"
#include "Postman.h"
#include <vector>


class PostOffice {
	vector<Mail *> mailToSend;
	vector<Mail *> mailToDeliver;
	vector<Postman> postmen;
	string firstZipCode, lastZipCode;
public:
	PostOffice();
	PostOffice(string firstZCode, string lastZCode);
	void addMailToSend(Mail *m);
	void addMailToDeliver(Mail *m);
	void addPostman(const Postman &p);
	vector<Mail *> getMailToSend() const;
	vector<Mail *> getMailToDeliver() const;
	vector<Postman> getPostman() const;

	vector<Mail *> removePostman(string name);
	vector<Mail *> endOfDay(unsigned int &balance);
	Postman addMailToPostman(Mail *m, string name);
};

class NoPostmanException {
    string name;
public:
    explicit NoPostmanException(string name) : name(name) {};
    string getName() const { return name; }
};

template<class T>
unsigned int numberDifferent(const vector<T> &v1) {
    unsigned int count = 0;
    bool unique;

    // N^2 solution, N log N could be achieved by sorting the vector first but we don't know if T has operator< defined
    for (typename vector<T>::const_iterator it1 = v1.begin(); it1 != v1.end(); it1++) {
        unique = true;
        for (typename vector<T>::const_iterator it2 = v1.begin(); it2 != it1; it2++) {
            if ((*it1) == (*it2)) {
                unique = false;
                break;
            }
        }

        if (unique) {
            count++;
        }
    }

    return count;
}

#endif /* SRC_POSTOFFICE_H_ */
