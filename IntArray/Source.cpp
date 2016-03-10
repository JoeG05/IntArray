#include "IntArray.h"
#include <iostream>

using namespace std;

int main()
{
	
	int arr[4] = { 1, 2, 3, 4 };
	IntArray a;
	a.assign(arr, 4);

	a.insert(2, 5, 0);

	cout << a << endl;

	
	
	system("Pause");
}