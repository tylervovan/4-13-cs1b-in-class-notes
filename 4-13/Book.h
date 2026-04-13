#pragma once


#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	// Only member functions (and friends) can access these
	string title;
	double cost;
	static int count;

public:
	Book();
	Book(string title, double cost);
	~Book();

	void setTitle(string title);
	void setCost(double cost);
	string getTitle();
	double getCost();

	void printBook();

	static int getCount();

	// --- OPERATOR OVERLOADS (member functions) ---
	// These ARE member functions because Book is on the LEFT side.
	//   book1 > book2   -->  book1.operator>(book2)
	//   book1 is "this", book2 is the parameter
	bool operator >(Book& book);

	//   book1 > 19.99   -->  book1.operator>(19.99)
	//   book1 is "this", 19.99 is the parameter
	bool operator >(float price);

	//   book1 + book2   -->  book1.operator+(book2)
	//   Returns the combined cost of both books
	float operator +(Book& book);

	// --- FRIEND FUNCTIONS (NOT member functions) ---
	//
	// Q: What is a friend function?
	//    A function that is NOT part of the class, but the class
	//    gives it a special pass to access private members (title, cost).
	//
	// Q: Why can't these just be member functions?
	//    comparePrices COULD be a member, but the professor made it
	//    friend to demonstrate the concept.
	//    operator<< CANNOT be a member — here's why:
	//
	//    When you write:    cout << book1
	//    The compiler sees:  cout.operator<<(book1)
	//    That means operator<< would need to be a member of cout's
	//    class (ostream). But we didn't write ostream — it's part of
	//    the C++ standard library, so we can't add members to it.
	//
	//    So operator<< MUST be a free function (lives outside any class).
	//    But it needs to print title and cost, which are private.
	//    Solution: make it a friend so it gets access.
	//
	// Q: How is this different from the > operator above?
	//    book1 > book2  -->  Book is on the LEFT, so it can be a member
	//    cout << book1  -->  ostream is on the LEFT, so it CANNOT be a member

	friend void comparePrices(Book& book1, Book& book2);

	friend ostream& operator << (ostream& stream, Book& book);


};

