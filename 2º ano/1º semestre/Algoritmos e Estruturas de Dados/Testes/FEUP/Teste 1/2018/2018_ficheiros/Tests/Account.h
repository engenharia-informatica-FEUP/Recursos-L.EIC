/*
 * Account.h
 */

#ifndef SRC_ACCOUNT_H_
#define SRC_ACCOUNT_H_

#include <string>
#include<iostream>
using namespace std;


class Account {
protected:
	string holder;
	string codeHolder;
	string codeIBAN;
	double balance;
public:
	Account(string hold, string codeH, string codeA, double bal);
	virtual ~Account();
	string getCodH() const;
	string getCodIBAN() const;
	double getBalance() const;
	//...

};


class CheckingAccount: public Account {
	double limit; //lower limit for free checking
public:
	CheckingAccount (string hold, string codeH, string codeA, double bal, double lim);
	//...

};


class SavingsAccount: public Account {
protected:
	double rate;
public:
	SavingsAccount(string hold, string codeH, string codeA, double bal, double pct); //pct = percentage interest rate
	//...

};


class TimeAccount: public SavingsAccount {
	double funds_avail;
public:
	TimeAccount(string hold, string codeH, string codeA, double bal, double pct);
	//...

};

#endif /* SRC_ACCOUNT_H_ */
