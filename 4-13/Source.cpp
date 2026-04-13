#include "Book.h"

void comparePrice(Book& book1, Book& book2); 

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

	cout << "They are " << /*TODO*/ " Books. \n\n"; 



	return 0; 
}