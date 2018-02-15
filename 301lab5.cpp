#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Date.h"
#include "Book.h"

using namespace std;


int main()
{
    int month, day, year;
	int search = 0;
	int counter = 0;
    char choice;
    string fName, lName, title;
    Book list[100];
	Book newBook;
	Date todaysDate, dueDate;
	bool found = false;
	bool overdue = false;

    cout << "Starting..." << endl;
    
	ifstream fin;
    fin.open("checkedOutBooks.txt");
	if (fin.is_open())
		cout << "File opened..." << endl;
	else
		cout << "FILE NOT OPENED" << endl;
	
    while(fin >> fName)
    {
		cout << "Book: " << counter + 1 << endl;
 		list[counter].setFirstName(fName);
		cout << list[counter].getFirstName() << endl;

		fin >> lName >> ws;
        list[counter].setLastName(lName);
		cout << list[counter].getLastName() << endl;

		getline(fin, title);
        list[counter].setTitle(title);
		cout << list[counter].getTitle() << endl;

		fin >> month >> day >> year;
		todaysDate.setDate(month, day, year);
		list[counter].setCheckOutDate(todaysDate);
		cout << "Check out date: " << list[counter].getCheckOutDate() << endl;

		fin >> month >> day >> year;
		dueDate.setDate(month, day, year);
		list[counter].setDueDate(dueDate);
		cout << "Due Date: " << list[counter].getDueDate() << endl;
	
        counter++;
    }

	cout << "Testing done." << endl << endl;

    cout << "Welcome to CS library program." << endl;
    cout << "Please enter the date in integers according to the following format-" << endl;
    cout << "mm dd yyyy: ";
    cin >> month >> day >> year;
	todaysDate.setDate(month, day, year);
	dueDate = todaysDate;
	dueDate += 14;

    do
    {
 		cout << "Please enter your one letter choice as follows:" << endl;
		cout << "    C:  Check out a book" << endl;
		cout << "    D:  Check in a book" << endl;
		cout << "    P:  Print all books currently checked out" << endl;
		cout << "    Q:  Quit this program" << endl;
		cout << "letter: ";
		cin >> choice;

		switch(choice)
		{
			case 'C': cout << endl;
				cout << "Please enter one line consisting the first and last names of the author followed by the title of the book." << endl;
				cout << "input: ";
				cin >> fName >> lName >> ws;
				getline(cin, title);
				newBook.setFirstName(fName);
				newBook.setLastName(lName);
				newBook.setTitle(title);
				newBook.setCheckOutDate(todaysDate);
				newBook.setDueDate(dueDate);
				cout << "Book is due " << newBook.getDueDate() << endl;
				list[counter] = newBook;
				counter++;
			break;

			case 'D': cout << endl;
				cout << "Please enter one line consisting of first and last names" << endl;
				cout << "of the author followed by the title of the book." << endl;
				cout << "input: ";
				cin >> fName >> lName >> ws;
				getline(cin, title);
				found = false;
				overdue = false;

				search = 0;
				while(!found && search < counter)
				{
					if((list[search].getFirstName() == fName) && (list[search].getLastName() == lName) && list[search].getTitle() == title)
					{
						found = true;
						if (list[search].getDueDate() < todaysDate)
							overdue = true;

						for (int i = search; i < counter; i++)
						{
							list[i] = list[i+1];
						}
					}	
					search++;
				}
			
				if(found)
				{
					if (overdue)
						cout << "Book is over due" << endl;
					else
						cout << "Book has been checked in on time" << endl;

					counter--;
				}
				else
					cout << "Book not found make sure spelling is correct" << endl;
			break;

			case 'P': cout << "\nChecked Out Books:" << endl;
			cout << left << setw(25) << "Author" << setw(22) << "Title" << setw(20)
				<< "Check Out Date" << setw(20) << "Due Date" << endl;
			for (int i = 0; i < counter; i++)
			{
				cout << setw(12) << list[i].getFirstName() << setw(12) << list[i].getLastName() <<  setw(23)<< list[i].getTitle()
				<< list[i].getCheckOutDate() << "      " << list[i].getDueDate() << endl;
			}
			break;

	    case 'Q': cout << "\nGoodBye!" << endl;
	        break;

	    default:
			cout << "\nPlease enter a letter from above in capital form" << endl;
	}

    }while(choice != 'Q');    

	fin.close();

	ofstream fout;
	fout.open("checkedOutBooks.txt");

	for (int i = 0; i < counter; i++)
	{
		fout << list[i].getFirstName() << endl;
		fout << list[i].getLastName() << endl;
		fout << list[i].getTitle() << endl;
		fout << list[i].getCheckOutDate().getMonth() << " ";
		fout << list[i].getCheckOutDate().getDay() << " ";
		fout << list[i].getCheckOutDate().getYear() << endl;
		fout << list[i].getDueDate().getMonth() << " ";
		fout << list[i].getDueDate().getDay() << " ";
		fout << list[i].getDueDate().getYear() << endl;
		fout << endl;
	}

	system("pause");
	fout.close();
	return 0;
}
