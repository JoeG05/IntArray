#include <iomanip>
#include <string>
#include <sstream>
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

bool operator<(const IntArray &a1, const IntArray &a2)
{
	stringstream out1, out2;
	string s1 = "";
	string s2 = "";

	for (unsigned i = 0; i < a1.length(); ++i)
	{
		out1 << a1[i];
		s1 += out1.str();
	}

	for (unsigned i = 0; i < a2.length(); ++i)
	{
		out2 << a2[i];
		s2 += out2.str();
	}
	if (s1 < s2)
		return true;
	return false;
}

bool operator<=(const IntArray &a1, const IntArray &a2)
{
	stringstream out1, out2;
	string s1 = "";
	string s2 = "";

	for (unsigned i = 0; i < a1.length(); ++i)
	{
		out1 << a1[i];
		s1 += out1.str();
	}

	for (unsigned i = 0; i < a2.length(); ++i)
	{
		out2 << a2[i];
		s2 += out2.str();
	}
	if (s1 <= s2)
		return true;
	return false;
}

bool operator>(const IntArray &a1, const IntArray &a2)
{
	stringstream out1, out2;
	string s1 = "";
	string s2 = "";

	for (unsigned i = 0; i < a1.length(); ++i)
	{
		out1 << a1[i];
		s1 += out1.str();
	}

	for (unsigned i = 0; i < a2.length(); ++i)
	{
		out2 << a2[i];
		s2 += out2.str();
	}
	if (s1 > s2)
		return true;
	return false;
}

bool operator>=(const IntArray &a1, const IntArray &a2)
{
	stringstream out1, out2;
	string s1 = "";
	string s2 = "";

	for (unsigned i = 0; i < a1.length(); ++i)
	{
		out1 << a1[i];
		s1 += out1.str();
	}

	for (unsigned i = 0; i < a2.length(); ++i)
	{
		out2 << a2[i];
		s2 += out2.str();
	}
	if (s1 >= s2)
		return true;
	return false;
}

int &IntArray::begin()
{
	return *p;
}

const int IntArray::begin(IntArray &a)
{
	return *p;
}

int &IntArray::end()
{
	return p[size];
}

const int IntArray::end(IntArray &a)
{
	return p[size];
}

int IntArray::front()
{
	return p[0];
}

const int IntArray::front(IntArray &a)
{
	return p[0];
}

int IntArray::back()
{
	return p[size - 1];
}

const int IntArray::back(IntArray &a)
{
	return p[size - 1];
}

void IntArray::swap(IntArray &a)
{
	int *temp1 = new int[size];
	int *temp2 = new int[a.size];

	unsigned sz1 = size;
	unsigned sz2 = a.size;

	for (unsigned i = 0; i < sz1; ++i)
	{
		temp1[i] = p[i];
	}

	for (unsigned i = 0; i < sz2; ++i)
	{
		temp2[i] = a.p[i];
	}

	size = sz2;
	a.size = sz1;

	for (unsigned i = 0; i < sz2; ++i)
		p[i] = temp2[i];

	for (unsigned i = 0; i < sz1; ++i)
		a.p[i] = temp1[i];

	delete[] temp1;
	delete[] temp2;

}

void IntArray::insert(unsigned pos, int x)
{
	int *temp = new int[size + 1];
	unsigned i;

	for (i = 0; i < pos; ++i)
		temp[i] = p[i];

	temp[pos] = x;

	for (i = pos + 1; i < size + 1; ++i)
		temp[i] = p[i - 1];

	delete[] p;
	p = temp;
	size = size + 1;
}

void IntArray::insert(unsigned pos, unsigned n, int x)
{
	int *temp = new int[size + n];
	unsigned i;
	for (i = 0; i < pos; ++i)
		temp[i] = p[i];

	for (i = 0; i < n; ++i)
		temp[pos + i] = x;

	for (i = pos + n; i < size + n; ++i)
		temp[i] = p[i - n];

	delete[] p;
	p = temp;
	size = size + n;
}

void IntArray::push_back(int x)
{
	int *temp = new int[size + 1];
	for (unsigned i = 0; i < size; ++i)
		temp[i] = p[i];

	temp[size] = x;
	delete[] p;
	p = temp;
	size = size + 1;

}

void IntArray::pop_back()
{
	int *temp = new int[size - 1];
	for (unsigned i = 0; i < size - 1; ++i)
		temp[i] = p[i];

	delete[] p;
	p = temp;
	size = size - 1;
}

void IntArray::erase(unsigned pos)
{
	int *temp = new int[size - 1];
	unsigned i;
	for (i = 0; i < pos; ++i)
		temp[i] = p[i];
	
	++i;
	
	for (; i < size; ++i)
		temp[i - 1] = p[i];

	delete[] p;
	p = temp;
	size = size - 1;
}

void IntArray::erase(unsigned first, unsigned last)
{
	int *temp = new int[size - (last - first)];
	unsigned i;

	for (i = 0; i < first; ++i)
		temp[i] = p[i];

	for (i = last; i < size; ++i)
		temp[i - first] = p[i];
		
	delete[] p;
	p = temp;
	size = size - (last - first);
}

void IntArray::clear()
{
	int *temp = new int[0];
	delete[] p;
	p = temp;
	size = 0;
}

void IntArray::add(IntArray &a1, IntArray &a2)
{
	
	if (a1.length() != a2.length())
		cout << "Not the same size" << endl;

	else
	{
		for (unsigned i = 0; i < a1.length(); ++i)
		{
			p[i] = a1[i] + a2[i];
		}
	}

	
}

void IntArray::multiply(IntArray &a1, IntArray &a2)
{
	
	if (a1.length() != a2.length())
		cout << "Not the same size" << endl;

	else
	{
		for (unsigned i = 0; i < a1.length(); ++i)
		{
			p[i] = a1[i] * a2[i];
		}
	}
	
}