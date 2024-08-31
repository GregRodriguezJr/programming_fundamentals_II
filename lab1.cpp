// Program prompts user to get lowest, highest, sum, or average of an array.
// Input is number from keyboard with the options 1,2,3, or 4 using cin.
// Output is the results of the chosen option displayed with cout.

#include <iostream>
using namespace std;

// Declare a new array data type with max 12 elements
const int MAXSIZE = 12;
typedef float ArrayType[MAXSIZE];

// Function prints menu options and returns users input
int printMenu();

// Function calculates the lowest number and displays result
void getLowestNum(const ArrayType, int);

// Function calculates the highest number and displays result
void getHighestNum(const ArrayType, int);

// Function calculates the total and displays result
void getTotal(const ArrayType, int);

// Function calculates the average and displays result
void getAverage(const ArrayType, int);

int main() {

    ArrayType arr = {47,89,65,36,12,25,17,8,62,10,87,62};

    int userChoice = printMenu();

    switch (userChoice) {
        case 1 : getLowestNum(arr, MAXSIZE);
            break;
        case 2 : getHighestNum(arr, MAXSIZE);
            break;
        case 3 : getTotal(arr, MAXSIZE);
            break;
        case 4 : getAverage(arr,MAXSIZE);
            break;
        default: cout << "There was an unexpected error";
    }

    return 0;
}

int printMenu() {
    int userChoice;
    do {
        cout << "\nPlease enter one of the following choices: \n"
                "1 for lowest number\n"
                "2 for highest number\n"
                "3 for the Total of the numbers\n"
                "4 for the Average of the numbers\n";
        cin >> userChoice;
    } while (userChoice <= 0 || userChoice > 4);

    return userChoice;
}

void getLowestNum(const ArrayType localArr, int arrLength) {
    float result = localArr[0];

    for (int i = 0; i < arrLength; ++i) {
        if(result > localArr[i]){
            result = localArr[i];
        }
    }
    cout << "The lowest number in the array is: "  << result;
}

void getHighestNum(const ArrayType localArr, int arrLength) {
    float result = localArr[0];

    for (int i = 0; i < arrLength; ++i) {
        if(result < localArr[i]){
            result = localArr[i];
        }
    }
    cout << "The highest number in the array is: "  << result;
}

void getTotal(const ArrayType localArr, int arrLength) {
    float result = 0;

    for (int i = 0; i < arrLength; ++i) {
        result += localArr[i];
    }
    cout << "The total of the numbers in the array is: "  << result;
}

void getAverage(const ArrayType localArr, int arrLength) {
    float result = 0;

    for (int i = 0; i < arrLength; ++i) {
        result += localArr[i];
    }
    result = result / arrLength;
    cout << "The average of the numbers in the array is: "  << result;
}
