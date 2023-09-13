/*
Name: Anne Marie Heidebreicht
NetID: alh1310

Program Description: Add on to the previously created program to create a catalog
					 of all the books in a "library".
*/

#include "alh1310_prog4_CatalogClass.h"
#include "BookClass.h"
#include <string>

using std::cin;
using std::getline;
using std::cout;
using std::endl;

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
	string checkedOutBy;

	do
	{
		cout << "\n\n";
		choice = display_menu();
		cout << "\n\n";

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
				cout << "Enter book author: ";
				cin.ignore();
				getline(cin, author);
				my_catalog.listBooksByAuthor(author);
				break;
			}

			//4. Add a New Book to the Catalog
			case 4:
			{
				cout << "Enter book title: ";
				cin.ignore();
				getline(cin, title);
				cout << "Enter Author: ";
				getline(cin, author);
				cout << "Enter ISBN: ";
				cin >> isbn;
				Book book = Book(title, author, isbn);
				my_catalog.addBook(book);
				break;
			}

			//5. Get Check Out Status of Book
			case 5:
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

			//6. Check in a book
			case 6:
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

			// 7.  Check out a book
			case 7:
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

			// 8. Exit Program
			case 8:
			{
				my_catalog.~Catalog();
				return 0;
				break;
			}
			default:
				break;
		}


	} while (choice >= 1 && choice < 8);

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
		cout << "4.  Add a New Book to the Catalog\n";
		cout << "5.  Get Check Out Status of Book\n";
		cout << "6.  Check in a book\n";
		cout << "7.  Check out a book\n";
		cout << "8.  Exit Program\n";

		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 and choice > 8)
		{
			cout << "Error: Not a valid Selection!  ";
		}

	} while (choice < 1 || choice > 8);

	return choice;

}

void populate_catalog(Catalog& my_catalog)
{
	Book temp_obj;
	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Sorcerers Stone");
	temp_obj.setISBN(98346);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Chamber of Secrets");
	temp_obj.setISBN(19285);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Prisioner of Azkaban");
	temp_obj.setISBN(88224);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Goblet of Fire");
	temp_obj.setISBN(21001);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Order of Phoenix");
	temp_obj.setISBN(66754);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Half-Blood Prince");
	temp_obj.setISBN(50125);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("J.K. Rowling");
	temp_obj.setTitle("Harry Potter and the Deathly Hallows");
	temp_obj.setISBN(68304);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Lion, the Witch, and the Wardrobe");
	temp_obj.setISBN(45336);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("Prince Caspian");
	temp_obj.setISBN(76689);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Voyage of the Dawn Treader");
	temp_obj.setISBN(34982);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Silver Chair");
	temp_obj.setISBN(45993);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("A Horse and His Boy");
	temp_obj.setISBN(42398);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("The Magician's Nephew");
	temp_obj.setISBN(39203);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("C.S. Lewis");
	temp_obj.setTitle("TheLast Battle");
	temp_obj.setISBN(56342);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("E. B. White");
	temp_obj.setTitle("Charlotte's Web");
	temp_obj.setISBN(47851);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("F. Scott Fitzgerald");
	temp_obj.setTitle("The Great Gasby");
	temp_obj.setISBN(11934);
	my_catalog.addBook(temp_obj);

	temp_obj.setAuthor("S. E. Hinton");
	temp_obj.setTitle("The Outsiders");
	temp_obj.setISBN(72331);
	my_catalog.addBook(temp_obj);

	/*
		Feel free to add more books below to experiment
		with the catalog class!
	*/
}