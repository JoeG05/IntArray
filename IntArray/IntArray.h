#ifndef __INTARRAY__
#define __INTARRAY__

#include <iostream>
using namespace std;

class Array_Error{
private:
	string err_msg;
public:
	Array_Error(const string &s) : err_msg(s){}
	string get_message() { return err_msg; }
};

class IntArray{
private:
	int *p;				// pointer to the array data
	unsigned size;		// size of the array
public:
	//constructors
	IntArray();			//Default constructor
	IntArray(unsigned n, int val = 0);
	IntArray(const int *a, unsigned n);
	IntArray(const IntArray &a);	//copy constructor

	//destructor
	~IntArray();

	//Assignment operators
	IntArray &operator=(const IntArray &a);
	void assign(const int *a, unsigned n);

	//Subscript operators
	int &operator[](unsigned pos);
	const int &operator[](unsigned pos) const;	//const version
	int &begin();
	//const int begin(IntArray &a);
	int &end();
	//const end
	int front();
	//const front
	int back();
	//const back


	//size functions
	unsigned length() const { return size; }
	bool empty() const { return size == 0; }
	void resize(unsigned sz, int val = 0);

	
};

// I/O functions
ostream& operator<<(ostream& out, const IntArray &a);
istream& operator>>(istream& in, IntArray &a);

// Relational Operators
bool operator==(const IntArray &a1, const IntArray &a2);
bool operator!=(const IntArray &a1, const IntArray &a2);

//Relational Operators

//Default constructor, creates array of size 0
inline
IntArray::IntArray() : p(0), size(0){}

//Creates array of n elements all initialized to val
inline
IntArray::IntArray(unsigned n, int val) : p(new int[n]), size(n)
{
	for (unsigned i = 0; i < n; i++)
		p[i] = val;
}

//Creates a copy of integer array a
inline
IntArray::IntArray(const int *a, unsigned n) : p(new int[n]), size(n)
{
	for (unsigned i = 0; i < n; i++)
		p[i] = a[i];
}

//creates a copy of IntArray a
inline
IntArray::IntArray(const IntArray &a) : p(new int[a.size]), size(a.size)
{
	for (unsigned i = 0; i < size; i++)
		p[i] = a.p[i];
}

//Destructor
inline
IntArray::~IntArray()
{
	delete[] p;
}

//Subscript operators

//The following works for const arrays
inline
const int &IntArray::operator[](unsigned pos) const
{
	if (pos >= size)
		throw (Array_Error("Out of range"));
	return (p[pos]);
}

//The following works for non-const arrays
inline
int &IntArray::operator[](unsigned pos)
{
	return const_cast<int &>(static_cast<const IntArray&>(*this)[pos]);
}
#endif