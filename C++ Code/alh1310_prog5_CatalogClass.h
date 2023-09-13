#pragma once
#include <vector>
#include "BookClass.h"

using std::vector;
class Catalog
{
private:
	// Vector
	vector<Book> books;
public:
	// Constructor
	Catalog()
	{

	}

	//Destructor
	~Catalog()
	{
		emptyCatalog();
	}

	// Setter
	void emptyCatalog()
	{
		books.clear();
	}

	//Getter
	int getNumBooks()
	{
		return books.size();
	}

	//Utility Methods (From Part 2)
	bool listBookByAuthor(string author_name)
	{
		int count = 0;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getAuthor() == author_name)
			{
				books[i].outputBook();
				count++;
			}
			else
			{
				cout << "ERROR: Invalid author.";
				break;
			}
		}

		return (bool)count;
	}
	bool getBookByTitle(string title, Book& book)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getTitle() == title)
			{
				book = books[i];
				return true;
			}
		}

		return false;
	}
	bool getBookByISBN(int isbn, Book& book)
	{
		for (int i = 0; i < books.size(); i++)
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
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getISBN() == isbn)
			{
				bool result = books[i].checkOutBook(name);
				return result;
			}
		}

		return false;
	}
	bool checkInBook(int isbn)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getISBN() == isbn)
			{
				books[i].returnBook();
				return true;
			}
		}

		return false;
	}
	bool addBook(Book new_book)
	{
		Book found;
		bool exist = getBookByISBN(new_book.getISBN(), found);

		if (exist == true)
			return false;
		else
		{
			books.push_back(new_book);
			return true;
		}
	}
	void outputCatalog()
	{
		for (int i = 0; i < books.size(); i++)
		{
			books[i].outputBook();
		}
	}

	// Utility Methods (From Part 3)
	bool listBooksByGenre(string genre)
	{
		int count = 0;
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getGenre() == genre)
			{
				books[i].outputBook();
				count++;
			}
			else
			{
				cout << "ERROR: Invalid genre.";
				break;
			}
		}

		return (bool)count;
	}

	/*

	Quick Sort Pseudocode

	Source Title: Advanced Sorting Lecture Slides #10
	Source Author: Chad McDaniel

	*/

	// Swap Method
	void swap(Book& a, Book& b)
	{
		Book t = a;
		a = b;
		b = t;
	}
	
	// Partition Methods
	int partitionTitle(vector<Book>& books, int left_index, int right_index)
	{
		int p_index = left_index + (right_index - left_index) / 2;
		Book pivot_value = books[p_index];

		swap(books[p_index], books[right_index]);

		int new_location = left_index - 1;

		for (int j = left_index; j < right_index; j++)
		{
			if (books[j].compareByTitle(pivot_value))
			{
				new_location += 1;
				swap(books[new_location], books[j]);
			}

		}
		swap(books[new_location + 1], books[right_index]);
		return new_location + 1;
	}
	int partitionAuthor(vector<Book>& books, int left_index, int right_index)
	{
		int p_index = left_index + (right_index - left_index) / 2;
		Book pivot_value = books[p_index];

		swap(books[p_index], books[right_index]);

		int new_location = left_index - 1;

		for (int j = left_index; j < right_index; j++)
		{
			if (books[j].compareByAuthor(pivot_value))
			{
				new_location += 1;
				swap(books[new_location], books[j]);
			}

		}
		swap(books[new_location + 1], books[right_index]);
		return new_location + 1;
	}
	int partitionGenre(vector<Book>& books, int left_index, int right_index)
	{
		int p_index = left_index + (right_index - left_index) / 2;
		Book pivot_value = books[p_index];

		swap(books[p_index], books[right_index]);

		int new_location = left_index - 1;

		for (int j = left_index; j < right_index; j++)
		{
			if (books[j].compareByGenre(pivot_value))
			{
				new_location += 1;
				swap(books[new_location], books[j]);
			}

		}
		swap(books[new_location + 1], books[right_index]);
		return new_location + 1;
	}

	// Quicksort Methods
	void QuickSortTitle(vector<Book>& books, int low_index, int high_index)
	{
		if (low_index >= high_index)
			return;

		int pivot = partitionTitle(books, low_index, high_index);
		QuickSortTitle(books, low_index, pivot - 1);
		QuickSortTitle(books, pivot + 1, high_index);
	}
	void QuickSortAuthor(vector<Book>& books, int low_index, int high_index)
	{
		if (low_index >= high_index)
			return;

		int pivot = partitionAuthor(books, low_index, high_index);
		QuickSortAuthor(books, low_index, pivot - 1);
		QuickSortAuthor(books, pivot + 1, high_index);
	}
	void QuickSortGenre(vector<Book>& books, int low_index, int high_index)
	{
		if (low_index >= high_index)
			return;

		int pivot = partitionGenre(books, low_index, high_index);
		QuickSortGenre(books, low_index, pivot - 1);
		QuickSortGenre(books, pivot + 1, high_index);
	}

	// Sorting Methods
	void sortBooksByTitle()
	{
		QuickSortTitle(books, 0, books.size() - 1);
	}
	void sortBooksByAuthor()
	{
		QuickSortAuthor(books, 0, books.size() - 1);
	}
	void sortBooksByGenre()
	{
		QuickSortGenre(books, 0, books.size() - 1);
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
		for (int i = 0; i < books.capacity(); i++)
		{
			if (ISBN == books[i].getISBN())
				return i;
		}

		return -1;
	}


};