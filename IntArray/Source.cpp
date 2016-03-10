#include "IntArray.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	
	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	IntArray a;
	a.assign(arr, 7);

	int arr2[7] = { 0, 2, 3, 4, 5, 6, 7 };
	IntArray b;
	b.assign(arr2, 7);

	if (a < b)
		cout << "true" << endl;

	if (b < a)
		cout << "true" << endl;
	
	IntArray c(a.length());
	cout << c.length() << endl;

	c.add(a, b);

	cout << c << endl;
	c.multiply(a, b);
	cout << c << endl;
	
	system("Pause");
}