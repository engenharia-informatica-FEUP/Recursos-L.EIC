/*
 * Mail.cpp
 */

#include "Mail.h"

Mail::Mail(string send, string rec, string zcode):
			sender(send),receiver(rec), zipCode(zcode)
{ }

Mail::~Mail()
{ }

string Mail::getZipCode() const {
	return zipCode;
}

RegularMail::RegularMail(string send, string rec, string zcode, unsigned int w):
			Mail(send, rec, zcode), weight(w)
{ }

GreenMail::GreenMail(string send, string rec, string zcode, string t):
			Mail(send, rec, zcode), type(t)
{ }







