/*
Name: Anne Marie Heidebreicht
NetID: alh1310

Program Description: Create a program that stores and changes information about books in a library.
*/

//Include header file.
#include "alh1310_prog3_BookClass.h"
#include <iostream>

using std::cin;
using std::getline;
using std::cout;
using std::string;
using namespace std;

void populateBookArray(Book library[]);
int lookupByISBN(Book library[]);

const int SIZE = 5;

// Create main() function. Let the menu repeat until Quit Progam is selected.
int main()
{
	//Create an array of Book objects to store our library in.
	Book library[SIZE];

	//Populate our library with sample books.
	populateBookArray(library);


	bool x = true;
	while (x == true)
	{
		int choice;
		cout << "1. Search the library of books by ISBN." << endl;
		cout << "2. Checkout a book." << endl;
		cout << "3. Return a book." << endl;
		cout << "4. Quit Program." << endl;
		cout << "---> ";
		cin >> choice;

		/*
		Search the library of books by ISBN. Get all of the information
		about the books. Run the "lookupByISBN()" function. Output the correct
		message. Return to the main menu.
		*/
		if (choice == 1)
		{
			library[0].getTitle();
			library[0].getAuthor();
			library[0].getISBN();

			library[1].getTitle();
			library[1].getAuthor();
			library[1].getISBN();

			library[2].getTitle();
			library[2].getAuthor();
			library[2].getISBN();

			library[3].getTitle();
			library[3].getAuthor();
			library[3].getISBN();

			library[4].getTitle();
			library[4].getAuthor();
			library[4].getISBN();

			int book = lookupByISBN(library);
			if (book == 0)
			{
				library[1].outputBook();
				x = true;
			}
			else if (book == 1)
			{
				library[1].outputBook();
				x = true;
			}
			else if (book == 2)
			{
				library[2].outputBook();
				x = true;
			}
			else if (book == 3)
			{
				library[3].outputBook();
				x = true;
			}
			else if (book == 4)
			{
				library[4].outputBook();
				x = true;
			}
			else
			{
				cout << "ERROR: INVALID ISBN NUMBER" << endl;
				x = true;
			}
		}

		/*
		Checkout a book. Get all of the information from
		the books (title, author, ISBN, and status). Call the lookupISBN() funtion.
		Get the status of the selected book. If it is checked out, output an
		error message. If not, get the user's name and
		run checkOutBook(). Return to the main menu.
		*/
		else if (choice == 2)
		{
			library[0].getTitle();
			library[0].getAuthor();
			library[0].getISBN();
			library[0].getStatus();

			library[1].getTitle();
			library[1].getAuthor();
			library[1].getISBN();
			library[1].getStatus();

			library[2].getTitle();
			library[2].getAuthor();
			library[2].getISBN();
			library[2].getStatus();

			library[3].getTitle();
			library[3].getAuthor();
			library[3].getISBN();
			library[3].getStatus();

			library[4].getTitle();
			library[4].getAuthor();
			library[4].getISBN();
			library[4].getStatus();

			int book = lookupByISBN(library);
			if (book == 0)
			{
				if (library[0].getStatus() == true)
				{
					cout << "ERROR: THIS BOOK IS ALREADY CHECKED OUT" << endl;
					x = true;
				}
				else if (library[0].getStatus() == false)
				{
					cout << "Enter your name: ";
					string name;
					cin.ignore();
					getline(cin, name);
					library[0].checkOutBook(name);
					x = true;
				}
			}
			else if (book == 1)
			{
				if (library[1].getStatus() == true)
				{
					cout << "ERROR: THIS BOOK IS ALREADY CHECKED OUT" << endl;
					x = true;
				}
				else if (library[1].getStatus() == false)
				{
					cout << "Enter your name: ";
					string name;
					cin.ignore();
					getline(cin, name);
					library[1].checkOutBook(name);
					x = true;
				}
			}
			else if (book == 2)
			{
				if (library[2].getStatus() == true)
				{
					cout << "ERROR: THIS BOOK IS ALREADY CHECKED OUT" << endl;
					x = true;
				}
				else if (library[2].getStatus() == false)
				{
					cout << "Enter your name: ";
					string name;
					cin.ignore();
					getline(cin, name);
					library[2].checkOutBook(name);
					x = true;
				}
			}
			else if (book == 3)
			{
				if (library[3].getStatus() == true)
				{
					cout << "ERROR: THIS BOOK IS ALREADY CHECKED OUT" << endl;
					x = true;
				}
				else if (library[3].getStatus() == false)
				{
					cout << "Enter your name: ";
					string name;
					cin.ignore();
					getline(cin, name);
					library[3].checkOutBook(name);
					x = true;
				}
			}
			else if (book == 4)
			{
				if (library[4].getStatus() == true)
				{
					cout << "ERROR: THIS BOOK IS ALREADY CHECKED OUT" << endl;
					x = true;
				}
				else if (library[4].getStatus() == false)
				{
					cout << "Enter your name: ";
					string name;
					cin.ignore();
					getline(cin, name);
					library[4].checkOutBook(name);
					x = true;
				}
			}
			else
			{
				cout << "ERROR: INVALID ISBN NUMBER" << endl;
				x = true;
			}
		}

		/*
		Return a book. Get all of the books' information (title, author, ISBN, and status).
		Get the status of the selected book. If the book is already checked out, run returnBook().
		If not, output an error message. Return to the main menu.
		*/
		else if (choice == 3)
		{
			library[0].getTitle();
			library[0].getAuthor();
			library[0].getISBN();
			library[0].getStatus();

			library[1].getTitle();
			library[1].getAuthor();
			library[1].getISBN();
			library[1].getStatus();

			library[2].getTitle();
			library[2].getAuthor();
			library[2].getISBN();
			library[2].getStatus();

			library[3].getTitle();
			library[3].getAuthor();
			library[3].getISBN();
			library[3].getStatus();

			library[4].getTitle();
			library[4].getAuthor();
			library[4].getISBN();
			library[4].getStatus();

			int book = lookupByISBN(library);
			if (book == 0)
			{
				if (library[0].getStatus() == false)
				{
					cout << "ERROR: NO ONE HAS CHECKED THIS BOOK OUT" << endl;
					x = true;
				}
				else if (library[0].getStatus() == true)
				{
					library[0].returnBook();
					x = true;
				}
			}
			else if (book == 1)
			{
				if (library[1].getStatus() == false)
				{
					cout << "ERROR: NO ONE HAS CHECKED THIS BOOK OUT" << endl;
					x = true;
				}
				else if (library[1].getStatus() == true)
				{
					library[1].returnBook();
					x = true;
				}
			}
			else if (book == 2)
			{
				if (library[2].getStatus() == false)
				{
					cout << "ERROR: NO ONE HAS CHECKED THIS BOOK OUT" << endl;
					x = true;
				}
				else if (library[2].getStatus() == true)
				{
					library[2].returnBook();
					x = true;
				}
			}
			else if (book == 3)
			{
				if (library[3].getStatus() == false)
				{
					cout << "ERROR: NO ONE HAS CHECKED THIS BOOK OUT" << endl;
					x = true;
				}
				else if (library[3].getStatus() == true)
				{
					library[3].returnBook();
					x = true;
				}
			}
			else if (book == 4)
			{
				if (library[4].getStatus() == false)
				{
					cout << "ERROR: NO ONE HAS CHECKED THIS BOOK OUT" << endl;
					x = true;
				}
				else if (library[4].getStatus() == true)
				{
					library[4].returnBook();
					x = true;
				}
			}
			else
			{
				cout << "ERROR: INVALID ISBN NUMBER" << endl;
				x = true;
			}

		}

		/*
		Quit the program. Simply exits out of the program.
		*/
		else if (choice == 4)
		{
			return 0;
		}

		/*
		Error message if the user selects a value not listed in the
		menu. Return to the main menu.
		*/
		else
		{
			cout << "ERROR: INVALID MENU OPTION" << endl;
			cout << "Please enter a correct number." << endl;
			cout << "---> ";
			cin >> choice;
			x = true;
		}
	}
}

//Note: This function assumes that there are 5 elements in this array.
//Function populates our library with popular novels.   
//ISBN numbers are just random 5 digit numbers.
//You can assume for the rest of your functions that the library
//array is always 5 elements.
void populateBookArray(Book library[])
{
	library[0].setAuthor("JK Rowling");
	library[0].setTitle("Harry Potter and the Sorcerers Stone");
	library[0].setISBN(98346);

	library[1].setAuthor("C.S. Lewis");
	library[1].setTitle("The Lion, the Witch, and the Wardrobe");
	library[1].setISBN(45336);

	library[2].setAuthor("E. B. White");
	library[2].setTitle("Charlotte's Web");
	library[2].setISBN(12345);

	library[3].setAuthor("F. Scott Fitzgerald");
	library[3].setTitle("The Great Gasby");
	library[3].setISBN(11934);

	library[4].setAuthor("S. E. Hinton");
	library[4].setTitle("The Outsiders");
	library[4].setISBN(72331);
}


//Asks the user for the ISBN number of the book
//and searches the library for that book.
//If found, returns the book element's index
//if not found, returns -1.
int lookupByISBN(Book library[])
{
	int ISBN;

	cout << "Enter the ISBN: ";
	cin >> ISBN;

	for (int i = 0; i < SIZE; i++)
	{
		if (ISBN == library[i].getISBN())
			return i;
	}

	return -1;
}