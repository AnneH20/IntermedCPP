/*
Name: Anne Marie Heidebreicht
NetID: alh1310

Program Description: Add on to the previously created program to create a catalog
					 of all the books in a "library".
*/

#include "alh1310_prog5_CatalogClass.h"
#include <string>
#include <iostream>

using std::cin;
using std::getline;

void populate_catalog(Catalog& my_catalog);
int display_menu();

int main()
{
	Catalog my_catalog;
	populate_catalog(my_catalog);

	cout << "Welcome to the Library!\n";
	int choice = 0;

	string title;
	int isbn;
	string author;
	string genre;
	string checkedOutBy;
	do
	{
		cout << "\n\n";
		choice = display_menu();
		cout << "\n\n";

		string input_str;
		int isbn;
		Book book_obj;
		bool result;

		/* ********************************************
			Enter the code for your commands here.
		   ********************************************
		*/
		switch (choice)
		{
		// 1. Search by Book Title
		case 1:
		{
			Book book;
			cout << "Enter book title: ";
			cin.ignore();
			getline(cin, title);
			if (my_catalog.getBookByTitle(title, book))
			{
				book.outputBook();
			}
			else
			{
				cout << "ERROR: Invalid title.";
			}
			break;
		}

		// 2. Search by Book ISBN
		case 2:
		{
			Book book;
			cout << "Enter ISBN: ";
			cin >> isbn;
			if (my_catalog.getBookByISBN(isbn, book))
			{
				book.outputBook();
			}
			else
			{
				cout << "ERROR: Invalid ISBN.";
			}
			break;
		}

		//3. Output all books by Author
		case 3:
		{
			Book book;
			cout << "Enter book author: ";
			cin.ignore();
			getline(cin, author);
			my_catalog.listBookByAuthor(author);
			break;
		}

		// 4. Output all books by Genre
		case 4:
		{
			cout << "Enter genre: ";
			cin.ignore();
			getline(cin, genre);
			my_catalog.listBooksByGenre(genre);
			break;
		}

		//5. Add a New Book to the Catalog
		case 5:
		{
			cout << "Enter book title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter author: ";
			getline(cin, author);
			cout << "Enter genre: ";
			getline(cin, genre);
			cout << "Enter ISBN: ";
			cin >> isbn;
			Book book = Book(title, author, genre, isbn);
			my_catalog.addBook(book);
			break;
		}

		// 6. Get Check Out Status of Book
		case 6:
		{
			cout << "Enter ISBN: ";
			cin >> isbn;
			if (my_catalog.getBookStatus(isbn, checkedOutBy))
			{
				cout << "The book is checked out by " << checkedOutBy << "." << endl;
			}
			else
			{
				cout << "The book is not checked out by anyone." << endl;
			}
			break;
		}

		// 7. Check in a book
		case 7:
		{
			cout << "Enter ISBN: ";
			cin >> isbn;
			if (my_catalog.checkInBook(isbn))
			{
				cout << "SUCCESS: The book is checked in." << endl;
			}
			else
			{
				cout << "ERROR: Cannot check book in." << endl;
			}
			break;
		}

		// 8.  Check out a book
		case 8:
		{
			cout << "Enter ISBN: ";
			cin >> isbn;
			cout << "Enter name: ";
			cin.ignore();
			getline(cin, checkedOutBy);
			if (my_catalog.checkOutBook(isbn, checkedOutBy))
			{
				cout << "SUCCESS: Book is checked out." << endl;
			}
			else
			{
				cout << "ERROR: Cannot check out book." << endl;
			}
			break;
		}

		// 9. Output Catalog
		case 9:
		{
			my_catalog.outputCatalog();
			break;
		}

		// 10. Sort Books by Title
		case 10:
		{
			my_catalog.sortBooksByTitle();
			break;
		}

		// 11. Sort Books by Author
		case 11:
		{
			my_catalog.sortBooksByAuthor();
			break;
		}

		// 12. Sort Books Genre
		case 12:
		{
			my_catalog.sortBooksByGenre();
			break;
		}

		// 13. Exit Program
		case 13:
		{
			my_catalog.~Catalog();
			return 0;
			break;
		}
		default:
			break;
		}


	} while (choice >= 1 && choice < 13);

	return 0;
}

int display_menu()
{
	int choice;
	do
	{
		cout << "Main Menu\n";
		cout << "1.  Search by Book Title\n";
		cout << "2.  Search by Book ISBN\n";
		cout << "3.  Output all books by Author\n";
		cout << "4.  Output all books by Genre\n";
		cout << "5.  Add a New Book to the Catalog\n";
		cout << "6.  Get Check Out Status of Book\n";
		cout << "7.  Check in a book\n";
		cout << "8.  Check out a book\n";
		cout << "9.  Output Catalog\n";
		cout << "10. Sort Books by Title\n";
		cout << "11. Sort Books by Author\n";
		cout << "12. Sort Books by Genre\n";
		cout << "13. Exit Program\n";

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 and choice > 13)
		{
			cout << "Error: Not a valid Selection!  ";
		}

	} while (choice < 1 || choice > 13);

	return choice;

}

void populate_catalog(Catalog& my_catalog)
{
	Book temp_obj;
	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Sorcerers Stone");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(98346);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Prisioner of Azkaban");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(88224);
	my_catalog.addBook(temp_obj);


	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Deathly Hallows");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(68304);
	my_catalog.addBook(temp_obj);


	temp_obj.setAuthor("E. B. White");
	temp_obj.setTitle("Charlotte's Web");
	temp_obj.setGenre("fantasy");
	temp_obj.setISBN(47851);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("F. Scott Fitzgerald");
	temp_obj.setTitle("The Great Gasby");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(34266);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("William Shakespeare");
	temp_obj.setTitle("Hamlet");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(55673);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Steinback");
	temp_obj.setTitle("Of Mice and Men");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(28886);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Green");
	temp_obj.setTitle("The Fault in Our Stars");
	temp_obj.setGenre("tragedy");
	temp_obj.setISBN(31122);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("S. E. Hinton");
	temp_obj.setTitle("The Outsiders");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(72331);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Andre Aciman");
	temp_obj.setTitle("Call Me by Your Name");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(94457);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.D. Salinger");
	temp_obj.setTitle("The Catcher in the Rye");
	temp_obj.setGenre("coming-of-age");
	temp_obj.setISBN(55438);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("Mary Shelly");
	temp_obj.setTitle("Frankenstien");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32116);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("H. G. Wells");
	temp_obj.setTitle("War of Worlds");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32216);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("H. G. Wells");
	temp_obj.setTitle("The Time Machine");
	temp_obj.setGenre("science fiction");
	temp_obj.setISBN(32136);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Troubled Blood");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(29332);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Grisham");
	temp_obj.setTitle("A Time to Kill");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(32661);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("John Grisham");
	temp_obj.setTitle("Sycamore Row");
	temp_obj.setGenre("crime fiction");
	temp_obj.setISBN(91023);
	my_catalog.addBook(temp_obj);

	/*
		Feel free to add more books below to experiment
		with the catalog class!
	*/

	return;
}