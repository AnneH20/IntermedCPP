#pragma once
#include <iostream>
#include <string>
#include "BookClass.h"

using std::cout;
using std::endl;
using std::string;


class Catalog
{
private:
	Book* books;
	int next_slot;
	int capacity;

	void emptyCatalog()
	{
		next_slot = 0;
		if (books != NULL)
		{
			delete[] books;
			books = NULL;
		}
	}
	void growCatalog()
	{
		Book* temp = books;

		capacity *= 2;
		books = new Book[capacity];

		for (int i = 0; i < next_slot; i++)
			books[i] = temp[i];
		
		delete[] temp;
		temp = nullptr;
	}

public:
	// Constructor
	Catalog(int init_size = 1)
	{
		books = new Book[init_size];
		next_slot = 0;
		capacity = init_size;
	}
	// Destructor
	~Catalog()
	{
		emptyCatalog();
	}

	// Getter
	int getNumBooks()
	{
		return next_slot;
	}

	// Utility Methods
	bool getBookByTitle(string title, Book& book)
	{
		for (int i = 0; i < next_slot; i++)
		{
			if (books[i].getTitle() == title)
			{
				book = books[i];
				return true;
			}
		}
		return false;
	}

	bool listBooksByAuthor(string author)
	{
		bool found = false;
		for (int i = 0; i < next_slot; i++)
		{
			if (books[i].getAuthor() == author)
			{
				books[i].outputBook();
				found = true;
			}
		}
		return found;
	}

	bool getBookByISBN(int isbn, Book& book)
	{
		for (int i = 0; i < next_slot; i++)
		{
			if (books[i].getISBN() == isbn)
			{
				book = books[i];
				return true;
			}
		}
		return false;
	}

	bool checkOutBook(int isbn, string name)
	{
		for (int i = 0; i < next_slot; i++)
		{
			if (books[i].getISBN() == isbn)
			{
				if (books[i].getStatus() == false)
				{
					books[i].checkOutBook(name);
					return true;
				}
			}
		}
		return false;
	}

	bool checkInBook(int isbn)
	{
		for (int i = 0; i < next_slot; i++)
		{
			if (books[i].getISBN() == isbn)
			{
				if (books[i].getStatus() == true)
				{
					books[i].returnBook();
					return true;
				}
			}
		}
		return false;
	}

	void addBook(Book new_book)
	{
		if (next_slot == capacity)
		{
			growCatalog();
		}
		books[next_slot] = new_book;
		next_slot++;
	}

	void outputCatalog()
	{
		for (int i = 0; i < next_slot; i++)
		{
			books[i].outputBook();
		}
	}

	// Additional helper methods
	bool getBookStatus(int isbn, string& checkedOutBy)
	{
		Book book;
		checkedOutBy = "";
		if (getBookByISBN(isbn, book))
		{
			if (book.getStatus())
			{
				checkedOutBy = book.getCheckedOutBy();
				return true;
			}
		}
		return false;
	}

	int lookupByISBN(Book& book, int ISBN)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (ISBN == books[i].getISBN())
				return i;
		}
		return -1;
	}
};