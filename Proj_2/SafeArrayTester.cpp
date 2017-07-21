#include <cstdlib>
#include <iostream>
#include "SafeArray.h"
using namespace std;

int main()
{
	//Stock SafeArrays
	SafeArray<int> ary1(3);
	SafeArray<int> ary2(2, 5);
	SafeArray<int> ary3(-5, 9);

	//Assignment of values

	//Copied SafeArrays
	SafeArray<int> ary4 = ary1;
	SafeArray<int> ary5 = ary2;
	
	//Test of assignment operator
	/*for (int i = 2; i < 5; i++)
	{
		cout << ary4[i] << endl;
	}*/

	//Loop to test copied safe array

	return 0;
}