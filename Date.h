// Definition of class Date
#ifndef DATE1_H
#define DATE1_H
#include <iostream>
#include <string>

using namespace std;

class Date {
   friend ostream &operator<<( ostream &, const Date & );
   friend bool operator< (const Date&, const Date&);
  
public:
   Date( int m = 1, int d = 1, int y = 1900 ); // constructor, note the default values
   void setDate( int, int, int ); // set the date
   void operator+=( int ); // add days, modify object
   bool leapYear(int year) const;    // is this a leap year?
   bool endOfMonth( int ) const;  // is this end of month?
   int getMonth ( ) const; 		
   int getDay ( ) const;			
   int getYear ( ) const; 			
   string getMonthString( ) const;  
private:
   int month;
   int day;
   int year;
   static const int days[];         // array of days per month
   static const string monthName[]; // array of month names
   void helpIncrement();            // utility function
};

#endif
