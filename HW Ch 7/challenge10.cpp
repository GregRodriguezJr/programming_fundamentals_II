//
// Created by Greg Rodriguez on 9/10/24.
//
// print total number of correctly and incorrectly answered questions and which numbers were wrong

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 2;

// Creates a new data type array to hold char values
typedef char ScantronType[MAXSIZE];

// This function gets the students answers from user
void getAnswers(ScantronType, int);

// Function to compare arrays and store results in new array
void checkAnswers(ScantronType, ScantronType, ScantronType, int);

// Function to print results to terminal
void printResults(ScantronType, int);

int main() {

    // Array to hold correct answers
    ScantronType correctAnswers = {'A','B'};
//            {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D',
//                               'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    // Array to hold student answers
    ScantronType studentAnswers;

    // Array to hold student wrong answers
    ScantronType resultAnswers;

    // Prompt user
    cout << setw(48) << "Welcome to Driver's License Exam\n";
    cout << setw(50) << "Valid entries are capital A,B,C or D.\n";

    // Function call to get students answers
    getAnswers(studentAnswers, MAXSIZE);

    // Function call to compare arrays
    checkAnswers(correctAnswers, studentAnswers, resultAnswers, MAXSIZE);

    // Function call to print results
    printResults(resultAnswers, MAXSIZE);

    return 0;
}

//***********************************************************************
//                              getAnswers
//
//  task: Validate user input and put entries into an array.
//  data in: StudentAnswers array and array size is taken in as an arguments.
//  data returned: None, the function mutates the original array.
//
//***********************************************************************
void getAnswers(ScantronType studentAnswers, int arraySize){

    char gradeLetter;
    bool isValid;

    for (int i = 0; i < arraySize; i++) {
        isValid = false;

        while(!isValid) {
            cout << "\nEnter student's answer letter for Question " << i+1 << " : ";
            cin >> gradeLetter;

            if(gradeLetter == 'A' || gradeLetter == 'B' ||gradeLetter == 'C' || gradeLetter == 'D'){
                studentAnswers[i] = gradeLetter;
                isValid = true;
            } else {
                cout << "\nInvalid entry, letter grade must be A,B,C, or D." << endl;
            }
        }
    }
}

//***********************************************************************
//                              checkAnswers
//
//  task: Comparing two arrays and putting results into a new array.
//  data in: StudentAnswers, correctAnswers, resultAnswers and array size is taken in as an arguments.
//  data returned: None, the function stores the new array with results.
//
//***********************************************************************
void checkAnswers(ScantronType correctAnswers,ScantronType studentAnswers, ScantronType resultAnswers, int arraySize){
    for(int i = 0; i < arraySize; i++){
        if(studentAnswers[i] == correctAnswers[i]){
            resultAnswers[i] = 'T';
        } else{
            resultAnswers[i] = 'F';
        }
    }
}

//***********************************************************************
//                              printResults
//
//  task: To print number of correct answers, incorrect answers, and if pass/fail.
//  data in: ResultAnswers and array size is taken in as an arguments.
//  data returned: None, the function calculates passing grade prints results.
//
//***********************************************************************
void printResults(ScantronType resultAnswers, int arraySize){
    int numCorrect = 0;
    int passScore;

    for (int i = 0; i < arraySize; ++i) {
        if(resultAnswers[i] == 'T') {
            numCorrect++;
        }
    }

    passScore = 100/arraySize * numCorrect;

    cout << "\nNumber of correct answers: " << numCorrect << endl;
    cout << "Number of incorrect answers: " << arraySize - numCorrect << endl;

    if(passScore >= 60) {
        cout << "Student Passed" << endl;
    } else {
        cout << "Student Failed\n" << endl;
    }
}