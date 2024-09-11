// Ch. 7 PC #10 Driver's License Exam
// Created by Greg Rodriguez
// COSC 1437
// 9/11/24
// Purpose: To check a students answers for an exam.
// Input: User inputs letter choices from students exam from keyboard cin. Maximum input is 20 letters and only A, B, C, or D.
// Output: Results are printed using cout with details about the test scores.

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 20;

typedef char ScantronType[MAXSIZE];     // Creates a new data type array to hold char values

void getAnswers(ScantronType, int);     // This function gets the students answers from user
void checkAnswers(ScantronType, ScantronType, ScantronType, int);   // Function to compare arrays and store results in new array
void printResults(const ScantronType, int);   // Function to print results to terminal
void printWrongAnswers(const ScantronType, int);   // Function to print wrong answers to the terminal

int main() {

    // Array to hold correct answers
    ScantronType correctAnswers = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    ScantronType studentAnswers;    // Array to hold student answers
    ScantronType resultAnswers;     // Array to hold student wrong answers

    cout << setw(48) << "Welcome to Driver's License Exam\n";   // Prompt user
    cout << setw(50) << "Valid entries are capital A,B,C or D.\n\n";

    getAnswers(studentAnswers, MAXSIZE);    // Function call to get students answers
    checkAnswers(correctAnswers, studentAnswers, resultAnswers, MAXSIZE);   // Function call to compare arrays
    printResults(resultAnswers, MAXSIZE);   // Function call to print results
    printWrongAnswers(resultAnswers, MAXSIZE);   // Function call to print results

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
            cout << "Enter student's answer letter for Question " << i+1 << " : ";
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
void printResults(const ScantronType resultAnswers, int arraySize){
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
        cout << "Student Passed\n" << endl;
    } else {
        cout << "Student Failed\n" << endl;
    }
}

//***********************************************************************
//                              printWrongAnswers
//
//  task: To print incorrect answers and display results.
//  data in: ResultAnswers and array size is taken in as an arguments.
//  data returned: None, the function prints wrong questions and "none" if they're all right.
//
//***********************************************************************
void printWrongAnswers(const ScantronType resultAnswers, int arraySize){
    int numWrong = 0;
    cout << "Incorrect answered questions \n";

    for (int i = 0; i < arraySize; ++i) {
        if(resultAnswers[i] == 'F'){
            cout << i + 1 << "  ";
            numWrong++;
        }
    }

    if(numWrong == 0) {
        cout << "None";
    }
    cout << endl;
}