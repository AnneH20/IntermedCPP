#pragma once
#include <iostream>
#include <string>

using namespace std;

/*
Define the class name.
*/
class Book
{
/*
List all of the private members given by the UML diagram.
*/
private:
	string title;
	string author;
	int ISBN;
	bool status;
	string CheckedOutBy;

/*
List all the public members given by the UML diagram.
*/
public:
	/*
	Create a constructor according to the UML diagram.
	*/
	Book(string p_title = "N/A", string p_author = "N/A", int p_ISBN = 0, bool p_status = false)
	{
		title = p_title;
		author = p_author;
		ISBN = p_ISBN;
		status = p_status;
	}

	/*
	Create the "getter" methods as stated in the UML diagram.
	*/
	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	int getISBN()
	{
		return ISBN;
	}
	bool getStatus()
	{
		return status;
	}

	/*
	Create the "setter" methods as stated in the UML diagram.
	*/
	void setTitle(string new_title)
	{
		title = new_title;
	}
	void setAuthor(string new_author)
	{
		author = new_author;
	}
	void setISBN(int new_ISBN)
	{
		ISBN = new_ISBN;
	}

	/*
	Create the utility methods as stated by the UML diagram.
	*/
	bool checkOutBook(string name)
	{
		if (status == false)
		{
			status = true;
			CheckedOutBy = name;
			bool checkOutBook = true;
			return checkOutBook;
		}
		else
		{
			bool checkOutBook = false;
			return checkOutBook;
		}
	}
	void returnBook()
	{
		status = false;
		CheckedOutBy = "";
	}
	void outputBook()
	{
		cout << title << endl;
		cout << "	by " << author << endl;
		cout << "	ISBN: " << ISBN << endl;
		if (status == true)
		{
			cout << "	Checked out by: " << CheckedOutBy << endl;
		}
	}
};