#include "IntArray.h"
#include <iostream>

using namespace std;

int main()
{
	
	int arr[4] = { 1, 2, 3, 4 };
	IntArray a;
	a.assign(arr, 4);

	int arr2[3] = { 5, 6, 7 };
	IntArray b(arr2, 3);


	b.swap(a);
	cout << b << endl << a << endl;

	
	
	system("Pause");
}