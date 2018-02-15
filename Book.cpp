#include "Book.h"

Book::Book(string fn, string ln, string t, Date co, Date ci)
{
    firstName = fn;
    lastName = ln;
    title = t;
    checkOut = co;
    due = ci;
}

Book::~Book()
{

}

string Book::getFirstName()
{
    return firstName;
}

string Book::getLastName()
{
    return lastName;
}

string Book::getTitle()
{
    return title;
}

Date Book::getCheckOutDate()
{
    return checkOut;
}

Date Book::getDueDate()
{
    return due;
}
