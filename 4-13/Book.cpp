#include "Book.h"

Book::Book()
{
	title = {};
	cost = 0;
	count++;
}

Book::Book(string title, double cost)
{
	this->title = title; 
	this->cost = cost; 
	count++; 


}
Book::~Book()
{


}

void Book::setTitle(string title)
{
	this->title = title; 

}
void Book::setCost(double cost)
{
	this->cost = cost; 

}
string Book::getTitle()
{
	return title; 

}
double Book::getCost()
{

	return cost;
}

void Book::printBook()
{
	cout << "Title: " << title << endl; 
	cout << "Cost:  " << cost << endl; 


}

 int Book::getCount()
{

	 return count; 
}

 bool Book::operator >(Book& book2)
 {
	 if (cost > book2.cost)
	 {
		 return true;
	 }
	 else
		 return false; 

}




 bool Book::operator >(float price)
 {

	 return cost > price; 

}

 float Book::operator +(Book& book) 
 {
 
	 return cost + book.cost; 

 }

 friend void Book::comparePrices(Book& book1, Book& book2) {}

 friend ostream& Book::operator << (ostream& stream, Book& book) {}