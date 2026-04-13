#include "Book.h"

// Static members must be defined (initialized) outside the class.
// This gives "count" actual storage in memory and sets it to 0.
int Book::count = 0;

Book::Book()
{
	title = {};
	cost = 0;
	count++;
}

Book::Book(const string& title, double cost)
{
	this->title = title;
	this->cost = cost;
	count++;


}
Book::~Book()
{


}

void Book::setTitle(const string& title)
{
	this->title = title;

}
void Book::setCost(double cost)
{
	this->cost = cost; 

}
string Book::getTitle() const
{
	return title;

}
double Book::getCost() const
{

	return cost;
}

void Book::printBook() const
{
	cout << "Title: " << title << endl;
	cout << "Cost:  " << cost << endl;


}

 int Book::getCount()
{

	 return count; 
}

 // --- MEMBER operator > (Book vs Book) ---
 // This IS a member function, so it uses Book::
 // "cost" here means this->cost (the book on the left side)
 // book2.cost is the book on the right side
 //
 // Example:  book1 > book2
 //           book1 is "this", book2 is the parameter
 bool Book::operator >(const Book& book2) const
 {
	 if (cost > book2.cost)
	 {
		 return true;
	 }
	 else
		 return false;

}

 // --- MEMBER operator > (Book vs float) ---
 // Same idea, but comparing a book's cost to a raw number
 //
 // Example:  book1 > 19.99
 //           book1 is "this", 19.99 is "price"
 bool Book::operator >(float price) const
 {

	 return cost > price;

}

 // --- MEMBER operator + ---
 // Adds the costs of two books together
 //
 // Example:  book1 + book2  -->  returns book1.cost + book2.cost
 float Book::operator +(const Book& book) const
 {

	 return cost + book.cost;

 }

// comparePrices is defined in Source.cpp (see there for the implementation)

// --- FRIEND operator << ---
// Notice: NO "Book::" — this is a free function, not a member.
//
// When you write:   cout << myBook
// "stream" is cout, "book" is myBook.
// It can access book.title and book.cost because it's a friend.
//
// Returns stream so you can chain:  cout << book1 << book2
ostream& operator << (ostream& stream, const Book& book) {

	stream << "\nTitle is: " << book.title << endl;
	stream << "\nCost is: $" << book.cost << endl;
	return stream;
}