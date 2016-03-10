#include "IntArray.h"
#include <iostream>

using namespace std;

int main()
{
	
	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	IntArray a;
	a.assign(arr, 7);

	a.erase(2, 4);

	cout << a << endl;

	
	
	system("Pause");
}