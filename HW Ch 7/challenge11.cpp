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
void printWrongAnswers(const ScantronType, int);                    // Function to print wrong answers to the terminal


int main() {

    ScantronType correctAnswers;                        // Array to hold the correct answers
    ScantronType studentAnswers;                        // Array to hold student answers
    ScantronType resultAnswers;                         // Array to hold student results
    int arraySize = MAXSIZE;                            // Variable to hold size of the array
    string answerFile = "HW Ch 7/CorrectAnswers.txt";   // Variable to hold file name
    string studentFile = "HW Ch 7/StudentAnswers.txt";  // Variable to hold file name
    bool answersIsValid;                                // Variable to hold if read file is successful
    bool studentIsValid;                                // Variable to hold if read file is successful

    answersIsValid = getAnswers(correctAnswers, answerFile);    // function call to read file to get correct answers into an array
    studentIsValid = getAnswers(studentAnswers, studentFile);   // function call to read file to get student answers into an array

    if(answersIsValid && studentIsValid){
        // read file of student answers into an array

        // compare arrays to check for incorrect answers
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


// print the following
//A list of the questions missed by the student, showing the correct answer and the
//incorrect answer provided by the student for each missed question
//The total number of questions missed
//The percentage of questions answered correctly.
//This can be calculated as: Correctly Answered Questions ÷ Total Number of Questions
//If the percentage of correctly answered questions is 70% or greater,
//the program should indicate that the student passed the exam. Otherwise,
//it should indicate that the student failed the exam.