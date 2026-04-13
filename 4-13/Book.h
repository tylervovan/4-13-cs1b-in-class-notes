#pragma once


#include <iostream>
#include <string>

using namespace std;

class Book
{
private: 
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

	bool operator >(Book& book); 

	bool operator >(float price); 

	float operator +(Book& book); 

	friend void comparePrices(Book& book1, Book& book2); 

	friend ostream& operator << (ostream& stream, Book& book); 
	// what does friend do? 
	// friend is a keyword that grants a non-member function (or anotehr class) access to the private and protected members of the class its declared in. 

	// this needs friend because the << operator for ostream cannot be a reuglar member function of Book. 


};

