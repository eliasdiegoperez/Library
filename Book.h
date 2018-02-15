// Definition of class Date
#ifndef BOOK1_H
#define BOOK1_H
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

const Date date;

class Book
{
private:
    string firstName;
    string lastName;
    string title;
    Date checkOut;
    Date due;

public:
    Book(string f = " ", string l = " ", string title = " ", Date x = date, Date y = date); // Put in default values 
    ~Book();
	Book & setCheckOutDate(Date c) { checkOut = c; return *this; }
	Book & setDueDate(Date d) { due = d; return *this; }
	Book & setFirstName(string f) { firstName = f; return *this; }
	Book & setLastName(string l) { lastName = l; return *this; }
	Book & setTitle(string t) { title = t; return *this; }
    string getFirstName();
    string getLastName();
    string getTitle();
    Date getCheckOutDate();
    Date getDueDate();
};

#endif
