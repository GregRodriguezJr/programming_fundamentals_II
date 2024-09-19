// This program performs a linear search on a character array

#include<iostream>
using namespace std;

int searchList( const int[], int, int); // function prototype
const int SIZE = 8;

int main()
{
	int arr[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
	int found;
	int value;
    int sentinel = 0;

    while(sentinel != -1){
        cout << "Enter a number to search for or -1 to end the program:" << endl;
        cin >> value;

        if(value == -1){
            cout << "Goodbye" << endl;
            return 0;

        } else{
            found = searchList(arr, SIZE, value);
            if (found == -1)
                cout << "The number " << value
                     << " was not found in the list" << endl;
            else
                cout << "The number " << value <<" is in the " << found + 1
                     << " position of the list" << endl;
        }
    }



}


//*******************************************************************
//                      searchList
//
// task:	      This searches an array for a particular value
// data in:       List of values in an array, the number of 
//                elements in the array, and the value searched for
//                in the array
// data returned: Position in the array of the value or -1 if value
//                not found
//
//*******************************************************************

int searchList( const int arr[], int arrSize, int value)
{
	for (int i = 0;i <= arrSize; i++)
	{
		if (arr[i] == value)
                      // each array entry is checked to see if it contains
	                  // the desired value.
		 return i;
                     // if the desired value is found, the array subscript
			         // count is returned to indicate the location in the array
	}
	return -1;	     // if the value is not found, -1 is returned
}
