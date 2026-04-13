#pragma once


#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	// Only member functions (and friends) can access these
	std::string title;
	double cost;
	static int count;

public:
	Book();
	Book(const std::string& title, double cost);
	~Book();

	void setTitle(const std::string& title);
	void setCost(double cost);
	std::string getTitle()const;
	double getCost()const;
	void printBook()const;

	static int getCount();

	// ============================================================
	// OPERATOR OVERLOADING
	// ============================================================
	//
	// What is it?
	//   C++ knows how to use >, +, <<, == etc. with basic types
	//   like int, double, and string. But it does NOT know what
	//   those symbols mean for YOUR class (Book).
	//
	//   Operator overloading lets you DEFINE what >, +, << etc.
	//   do when used with Book objects.
	//
	// How does it work?
	//   "operator>" is just a function with a special name.
	//   When you write:     book1 > book2
	//   The compiler sees:  book1.operator>(book2)
	//   It's literally calling a function named "operator>" on book1.
	//
	// Why do it?
	//   Without overloading, this would be a compiler error:
	//     if (book1 > book2)   // error: can't compare two Books
	//   After overloading, you've taught C++ what > means for Books.
	//
	// Rules:
	//   - You can only overload EXISTING operators (>, +, <<, ==, etc.)
	//   - You CANNOT invent new operators (no ** or @@ or >>>)
	//   - You decide what the operator does (> could compare titles,
	//     costs, page counts — whatever makes sense for your class)
	// ============================================================

	// --- OPERATOR OVERLOADS (member functions) ---
	// These ARE member functions because Book is on the LEFT side.
	//   book1 > book2   -->  book1.operator>(book2)
	//   book1 is "this", book2 is the parameter
	bool operator >(const Book& book)const;

	//   book1 > 19.99   -->  book1.operator>(19.99)
	//   book1 is "this", 19.99 is the parameter
	bool operator >(float price)const;

	//   book1 + book2   -->  book1.operator+(book2)
	//   Returns the combined cost of both books
	float operator +(const Book& book)const;

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

	friend void comparePrices(const Book& book1, const Book& book2);

	friend std::ostream& operator << (std::ostream& stream, const Book& book);


};

