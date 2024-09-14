// Ch. 5 & 7 PC #14 Lottery Application
// Created by Greg Rodriguez
// COSC 1437
// 9/14/24
// Purpose: User inputs 5 numbers and checks it against 5 random numbers.
// Input: User uses cin to capture number choices.
// Output: Prints the results of how many numbers matched the users.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

const int MAXSIZE = 5;            // max size of array
typedef vector<int> NumVecType;   // defines new vector data type

void getRandomNums(NumVecType&, int);                           // function to generate 5 random numbers
void getUserNums(NumVecType& , int);                            // function to get user input
int checkNums(NumVecType& , NumVecType& , NumVecType&);         // function to compare vectors
void printResults(NumVecType& , NumVecType&, NumVecType&, int); // function to display results

int main(){

    NumVecType lotteryNums, matchingNums, userNums;
    int arraySize = MAXSIZE;
    int count;

    getRandomNums(lotteryNums, arraySize);
    getUserNums(userNums, arraySize);
    count = checkNums(lotteryNums, userNums, matchingNums);
    printResults(lotteryNums, matchingNums, userNums, count);

    return 0;
}

//***********************************************************************
//                          getRandomNums
//
//  task: Generate 5 random numbers between 0 - 9
//  data in: LotteryNums and array size are the arguments of the function.
//  data returned: None, the function adds numbers to the array.
//
//***********************************************************************
void getRandomNums(NumVecType& lotteryNums, int arraySize){
    unsigned seed = time(nullptr);
    srand(seed);

    for (int i = 0; i < arraySize; ++i) {
        int randomNum = rand() % 10;
        lotteryNums.push_back(randomNum);
    }
}

//***********************************************************************
//                           getUserNums
//
//  task: Get user input numbers from cin.
//  data in: UserNums array and array size.
//  data returned: None, the function adds values to the array.
//
//***********************************************************************
void getUserNums(NumVecType& userNums, int arraySize){
    bool isValid;
    int num;

    for (int i = 0; i < arraySize; ++i) {
        cout << "Please input a number from 0 - 9" << endl;
        isValid = false;

        while(!isValid){
            cin >> num;

            if (num >= 0 && num <= 9){
                userNums.push_back(num);
                isValid = true;
            } else {
                cout << "Number input out of range, try again with 0 - 9." << endl;
            }

        }
    }
}

//***********************************************************************
//                         checkNums
//
//  task: Compare lotteryNums and userNums for matched numbers.
//  data in: LotteryNums, userNums, matchingNums, and array size are the arguments of the function.
//  data returned: Returns an int of how many matches there are.
//
//***********************************************************************
int checkNums(NumVecType& lotteryNums, NumVecType& userNums, NumVecType& matchingNums){
    int count = 0;
    sort(lotteryNums.begin(),lotteryNums.end());
    sort(userNums.begin(),userNums.end());

    for (int i = 0; i < lotteryNums.size(); ++i) {
        for (int j = 0; j < userNums.size(); ++j) {
            if(lotteryNums[i] == userNums[j]){
                matchingNums.push_back(lotteryNums[i]);
                count++;
                break;
            }
        }
    }
    return count;
}

//***********************************************************************
//                         printResults
//
//  task: Display the results of the matching numbers and lottery numbers.
//  data in: LotteryNums, userNums, matchingNums, and count size are the arguments of the function.
//  data returned: None, the results are printed to the terminal.
//
//***********************************************************************
void printResults(NumVecType& lotteryNums, NumVecType& matchingNums, NumVecType& userNums, int count){
    cout << "\nLottery Numbers" << endl;
    for (int lotteryNum : lotteryNums) {
        cout << setw(2) << lotteryNum;
    }

    cout << "\nYour Numbers" << endl;
    for (int userNum : userNums) {
        cout << setw(2) << userNum;
    }

    if(count > 0){
        cout << "\n\nThe match count is: " << count << endl;
        cout << "Your Matching Numbers" << endl;
        for (int matchingNum : matchingNums) {
            cout << setw(2) << matchingNum;
        }
    } else {
        cout << "No matching Numbers" << endl;
    }

    if(count == 5){
        cout << "\nGrand Prize Winner" << endl;
    }
}