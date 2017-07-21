//--------------------------------------------------------------------
// Tyler Simoni - U25068858
//--------------------------------------------------------------------

#include <cstdlib>
using std::exit;
#include <iostream>
using std::cout;
using std::endl;

//--------------------------------------------------------------------
// SafeArray template class function-definitions
//--------------------------------------------------------------------
template <class T>
class SafeArray {
public:
	SafeArray(int firstInvalidIndex);
	SafeArray(int firstValidIndex, int firstInvalidIndex);
	SafeArray(const SafeArray &obj);
	~SafeArray();

	T& operator[] (int ndx);
	T& operator= (const T rhs);

	int length();

private:
	int firstValid;
	int firstInvalid;
	T *A;
};
//---------------------------------------------------------------------
// SafeArray template class implmentation of above function-definitions
//---------------------------------------------------------------------

//-------------------Constructor - 1 parameter------------------------
template <class T>
SafeArray<T>::SafeArray(int firstInvalidIndex)
{
	cout << "Normal SafeArray constructor." << endl;
	if (firstInvalidIndex <= 0){
		cout << "Safearray index is out of bounds." << endl;
		exit;
	}else {
		firstValid = 0;
		firstInvalid = firstInvalidIndex;
	}

	A = new T[length()];
}

//-------------------Constructor - 2 parameters-----------------------
template <class T>
SafeArray<T>::SafeArray(int firstValidIndex, int firstInvalidIndex)
{
	cout << "Arbitrary index SafeArray constructor." << endl;
	if (firstInvalidIndex <= firstValidIndex)
		exit;
	else {
		firstValid = firstValidIndex;
		firstInvalid = firstInvalidIndex;
	}

	A = new T[length()];
}

//--------------------------Copy constructor--------------------------
template <class T>
SafeArray<T>::SafeArray(const SafeArray<T> &obj)
{
	cout << "Copy constructor allocating new SafeArray." << endl;
	A = new T[length()];
	
	while (*A != NULL)
	{
		*A = *obj.A;
		A++;
	}
}

//----------------------------Destructor------------------------------
template <class T>
SafeArray<T>::~SafeArray()
{
	cout << "Freeing up memory!" << endl;
	delete [] A;
	A = NULL;
}

//----------------------Overloaded [] operator------------------------
template <class T>
T& SafeArray<T>::operator[] (int ndx)
{
	if (ndx < firstValid){
		cout << "SafeArray index " << ndx << " out of bounds: too small." << endl;
		exit;
	}
	else if (ndx >= firstInvalid){
		cout << "SafeArray index " << ndx << " out of bounds: too big." << endl;
		exit;
	}
	else {
		return A[ndx - firstValid];
	}
}

//---------------------Overloaded = operator--------------------------
template <class T>
T& SafeArray<T>::operator= (const T rhs)
{
	return *this;
}

//-----------------------length() function----------------------------
template <class T>
int SafeArray<T>::length()
{
	return (firstInvalid - firstValid);
}



