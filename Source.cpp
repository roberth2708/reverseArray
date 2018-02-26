#include <iostream>
using namespace std;

const int SIZE = 5;


///Reversing an array
//Version 1:  Using pointers. NO WORKING YET
/*void reverseArray1(int arr[], int arrLength) {

	int halfLength = arrLength / 2;
	int* aPtr = arr;

	if (arrLength % 2 != 0) {			//Verify if array has an odd number of elements
		// Length is odd 
		for (int index = 0; index < halfLength; index++) {
			int* swapPtr = arr;
			int temp = arrLength - index - 1;
			arr = arr + temp;
			(arr + temp) = swapPtr;
		}

	}

}*/

//Version 2: Creating a dynamic array 
int* reverseArray2(int array[], int arrayLenght) {
	int index, reverseIndex;
	int* revPtr = nullptr;

	revPtr = new int[arrayLenght];

	for (index = 0; index < arrayLenght; index++) {
		reverseIndex = arrayLenght - 1 - index;
		*(revPtr + reverseIndex) = array[index];
	}

	return revPtr;
	delete[] revPtr;
	revPtr = nullptr;
}

/// Rotating an array
// Version 1: Using an array. NO WORKING
void rotateArray(int array[], int arrLength, int distance) {
	int swapHolder;
	
	for (int i = 0; i < arrLength; i++) {
		int inIdx = i + distance;
		
		if (inIdx <= (arrLength - 1)) {
			swapHolder = array[inIdx];
			array[inIdx] = array[i];
			array[i] = swapHolder;
		}
		/*else {
			swapHolder = array[index - distance - 1];
			array[index - distance - 1] = array[index];
			array[index] = swapHolder;
		}*/

	}
}

//Version 2: Creating a dynamic array 
int* rotateArray2(int array[], int arrayLenght, int distance) {
	int* arrayPtr = new int[arrayLenght];

	for (int index = 0; index < arrayLenght; index++) {
		int inRangeIdx = index + distance;

		if (inRangeIdx <= (arrayLenght - 1))
			*(arrayPtr + inRangeIdx) = *(array + index);
		else {
			int outRangeIdx = index - distance - 1;
			*(arrayPtr + outRangeIdx) = *(array + index);
		}
	}
	return arrayPtr;
}



int main()
{
	int array[SIZE] = { 1, 7, 4, 9, 0 };
	//int* reversePtr = nullptr;
	int* rotatePtr = nullptr;
	int d = 1;

	cout << "Original array: ";
	for (int element : array)
		cout << element << " ";
	cout << endl << endl;

	/*
	reversePtr = reverseArray2(array, SIZE);

	for (int index = 0; index < SIZE; index++) {
		cout << *(reversePtr + index) << " ";
	}
	cout << endl;
	*/



	cout << "Rotate Array: " << endl;
	rotatePtr = rotateArray2(array, SIZE, d);
	for (int index = 0; index < SIZE; index++)
		cout << *(rotatePtr + index) << " ";

	cout << endl << endl;


		cin.get();
		return 0;
	
}