#include "Book.h"

int main()
{
	Book book1("the Great Man", 15.99);

	Book book2("The Catcher in the Rye", 12.99);

	Book book3("To Kill a Mockingbird", 19.99); 

	book1.printBook(); 
	cout << endl; 

	book2.printBook(); 
	cout << endl; 

	book3.printBook();
	cout << endl; 

	cout << endl;

	cout << "They are " << Book::getCount() << " Books. \n\n"; 

	if (book1 > book2)
	{
		cout << "The price of book1 is greater tahn book2. \n"; 
	}

	else
	{
		cout << "Book2 is more expensive than book1.\n";
	}

	if (book1 > 1000)
	{
		cout << "Book1 is great than $1000.\n";
	}

	else
	{
		cout << "Book2 is less than $2000. \n"; 
	}

	double avg{}; 

	avg = (book1 + book2) / 2.0;

	cout << "The average book cost is " << avg << endl; 

	cout << "\nPrinting books using operator <<\n";

	cout << "\nBook1:\n" << book1 << "Book2:\n" << book2 << "Book3:\n" << book3 << endl << endl; 
	return 0; 
}

void comparePrices(Book& book1, Book& book2)
{
	if (book1.cost > book2.cost)
	{
		cout << book1.title << " is more expensive than " << book2.title << endl; 
	}
	else if (book1.cost < book2.cost)
	{
		cout << book2.title << " is more expensive than " << book1.title << endl;
	}
	else
	{
		cout << book1.title << " is the same price as " << book2.title << endl; 
	}
}