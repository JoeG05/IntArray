#include "IntArray.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	IntArray a, b;
	//test assign
	a.assign(arr1, 10);
	b.assign(arr2, 10);
	cout << "a: " << a << endl << "b: " << b << endl;
	
	//test swap
	a.swap(b);
	cout << "a: " << a << endl << "b: " << b << endl;

	//test add and multiply
	IntArray c(a.length());
	c.add(a, b);
	cout << "c: " << c << endl;
	c.multiply(a, b);
	cout << "c: " << c << endl;

	//test string comparison operators
	(a < b) ? (cout << "true\n") : (cout << "false\n");
	(a <= b) ? (cout << "true\n") : (cout << "false\n");
	(a > b) ? (cout << "true\n") : (cout << "false\n");
	(a >= b) ? (cout << "true\n") : (cout << "false\n");

	//part a member functions
	cout << "a->front: " << a.front() << endl;
	cout << "b-> back: " << b.back() << endl;

	//insert and delete member functions
	a.insert(3, 100);
	b.insert(3, 2, 100);
	cout << "a: " << a << endl << "b: " << b << endl;
	
	a.push_back(50);
	b.pop_back();
	cout << "a: " << a << endl << "b: " << b << endl;
	
	a.erase(3);
	b.erase(3, 5);
	cout << "a: " << a << endl << "b: " << b << endl;

	b.clear();
	cout << "b: " << b << endl;

	system("Pause");
}