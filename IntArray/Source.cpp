#include "IntArray.h"
#include <iostream>

using namespace std;

int main()
{
	
	int arr[4] = { 1, 2, 3, 4 };
	IntArray a;
	a.assign(arr, 4);

	int *p = &a.begin();
	int *q = &a.end();
	
	int r = a.front();
	cout << r << endl;

	int s = a.back();
	cout << s << endl;

	
	
	system("Pause");
}