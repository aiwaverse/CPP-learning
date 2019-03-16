#pragma once
#include <string>
#include <iostream>

class Mystring{
	friend std::ostream &operator<<(std::ostream &os, const Mystring& rhs); //overloaded insertion operator
	//done
	friend std::istream &operator>>(std::istream &in, Mystring& rhs); //overloaded extraction operator
	//done
	friend bool operator==(const Mystring& lhs, const Mystring& rhs);
	//done
	friend bool operator!=(const Mystring& lhs, const Mystring& rhs);
	friend bool operator<(const Mystring& lhs, const Mystring& rhs);
	friend bool operator>(const Mystring& lhs, const Mystring& rhs);
	friend Mystring operator-(const Mystring &obj);
	friend Mystring operator+(const Mystring& lhs, const Mystring& rhs);
	friend Mystring operator*(const Mystring& lhs, const unsigned int rhs);
	friend void operator*=(Mystring& lhs, const unsigned int rhs);
	friend void operator+=(Mystring& lhs, const Mystring& rhs);
	friend Mystring &operator++(Mystring &obj);
	friend Mystring operator++(Mystring &obj,int);
	friend Mystring &operator--(Mystring &obj);
	friend Mystring operator--(Mystring &obj,int);
private:
	char *str;
public:
	Mystring();  //no-args constructor
	Mystring(const char *s);    //overloaded one-arg constructor
	Mystring(const Mystring& source);   //copy constructor
	Mystring(Mystring &&source);    //move constructor
	~Mystring();    //destructor
	void display() const;       
	int get_length() const;
	const char *get_str() const;
	Mystring &operator=(const Mystring& rhs); //assigment copy overload
	Mystring &operator=(Mystring&& rhs);    //assigment move overload

};
