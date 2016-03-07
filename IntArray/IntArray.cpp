#include <iomanip>
#include "IntArray.h"
using namespace std;

//Assignment operators
IntArray &IntArray::operator=(const IntArray &a)
{
	if (&a != this){ //Avoids self-assignment
		delete[] p;
		p = new int[a.size];
		size = a.size;
		for (unsigned i = 0; i < size; i++)
			p[i] = a.p[i];
	}
	return *this;
}

void IntArray::assign(const int *a, unsigned n)
{
	delete[] p;
	p = new int[n];
	size = n;
	for (unsigned i = 0; i < n; i++)
		p[i] = a[i];
}

//Resize array, initialize new elements to val
void IntArray::resize(unsigned sz, int val)
{
	int *temp = new int[sz];
	unsigned i;

	if (sz > size) {//Array is increasing in size
		for (i = 0; i < size; i++)
			temp[i] = p[i];
		for (; i < sz; i++)
			temp[i] = val;
	}
	else {//Array is decreasing in size
		for (i = 0; i < sz; i++)
			temp[i] = p[i];
	}
	delete[] p;
	p = temp;
	size = sz;
}

// I/O functions
ostream& operator<<(ostream& out, const IntArray &a)
{
	unsigned size = a.length();

	for (unsigned i = 0; i < size; i++)
		out << setw(6) << a[i];
	return out;
}

istream& operator>>(istream& in, IntArray &a)
{
	unsigned size = a.length();

	for (unsigned i = 0; i < size; i++)
		in >> a[i];
	return in;
}

//Relational operators
bool operator==(const IntArray &a1, const IntArray &a2)
{
	bool equal = false;

	if (a1.length() == a2.length()) {
		unsigned size = a1.length();
		unsigned i;

		for (i = 0; i < size && a1[i] == a2[i]; i++)
			;
		if (i == size)
			equal = true;
	}
	return equal;
}

bool operator!=(const IntArray &a1, const IntArray &a2)
{
	return !(a1 == a2);
}
