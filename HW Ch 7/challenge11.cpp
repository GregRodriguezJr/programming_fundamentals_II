// Ch. 7 PC #11 Exam Grader
// Created by Greg Rodriguez
// COSC 1437
// 9/12/24
// Purpose: To check a students answers for an exam and print out results.
// Input: Files are used to read data. Maximum 20 lines in the file for letters/chars.
// Output: Results are printed using cout with details about the test scores.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int MAXSIZE = 20;

ifstream dataIn;		                                            // defines an input stream for files
typedef char ScantronType[MAXSIZE];                                 // Creates a new data type array to hold char values
bool getAnswers(ScantronType, string);                              // This function gets the correct and students answers from user
void checkAnswers(ScantronType, ScantronType, ScantronType, int);   // Function to compare arrays and store results in new array
void printResults(const ScantronType, int);                         // Function to print results to terminal
void printWrongAnswers(const ScantronType, const ScantronType, const ScantronType, int);// Function to print wrong answers to the terminal


int main() {

    ScantronType correctAnswers;                        // Array to hold the correct answers
    ScantronType studentAnswers;                        // Array to hold student answers
    ScantronType resultAnswers;                         // Array to hold student results
    int arraySize = MAXSIZE;                            // Variable to hold size of the array
    string answerFile = "HW Ch 7/CorrectAnswers.txt";   // Variable to hold file name
    string studentFile = "HW Ch 7/StudentAnswers.txt";  // Variable to hold file name
    bool answersIsValid;                                // Variable to hold if read file is successful
    bool studentIsValid;                                // Variable to hold if read file is successful

    cout << setw(48) << "Welcome to Exam Grader\n";                        // Prompt user

    answersIsValid = getAnswers(correctAnswers, answerFile);    // function call to read file to get correct answers into an array
    studentIsValid = getAnswers(studentAnswers, studentFile);   // function call to read file to get student answers into an array

    if(answersIsValid && studentIsValid){                                    // functions calls if no error reading files
        checkAnswers(correctAnswers, studentAnswers, resultAnswers, arraySize);
        printResults(resultAnswers, arraySize);
        printWrongAnswers( resultAnswers, correctAnswers, studentAnswers, arraySize);
    }

    return 0;
}

//***********************************************************************
//                              getAnswers
//
//  task: To read files and put answers into an array and use validation if any errors
//  data in: Array to store answers and string for filename is taken in as an arguments.
//  data returned: Boolean, the function returns validation if storing arrays was successful.
//
//***********************************************************************
bool getAnswers(ScantronType array, string fileName){
    bool isValid;
    int pos = 0;
    dataIn.open(fileName);

    if(dataIn){

        while (dataIn >> array[pos]){
            pos++;
        }

        isValid = true;
        dataIn.close();

    } else {
        cout << "Error opening the file " << fileName << endl;
        isValid = false;
    }
    return isValid;
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
    int score;

    for (int i = 0; i < arraySize; ++i) {
        if(resultAnswers[i] == 'T') {
            numCorrect++;
        }
    }

    score = 100/arraySize * numCorrect;

    cout << "\nNumber of correct answers: " << numCorrect << endl;
    cout << "Number of incorrect answers: " << arraySize - numCorrect << endl;

    if(score >= 70) {
        cout << "Student Passed with a " << score << "%\n" << endl;
    } else {
        cout << "Student Failed with a " << score << "%\n" << endl;
    }
}

//***********************************************************************
//                              printWrongAnswers
//
//  task: To print incorrect answers and correct answers to display results.
//  data in: All arrays and array size is taken in as an arguments.
//  data returned: None, the function prints wrong questions with correct answers and "none" if they're all right.
//
//***********************************************************************
void printWrongAnswers(const ScantronType resultAnswers, const ScantronType correctAnswers, const ScantronType studentAnswers, int arraySize){
    int numWrong = 0;
    cout << "Incorrect answered questions \n";

    for (int i = 0; i < arraySize; ++i) {
        if(resultAnswers[i] == 'F'){
            cout << i + 1 << ". Student answer: " << studentAnswers[i] << "  correct answer: " << correctAnswers[i] << endl;
            numWrong++;
        }
    }

    if(numWrong == 0) {
        cout << "None";
    }
    cout << endl;
}