//
// Created by Greg Rodriguez on 9/10/24.
//

// print if student passed or failed

// print total number of correctly and incorrectly answered questions and which numbers were wrong

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 20;

// Creates a new data type array to hold char values
typedef char ScantronType[MAXSIZE];

// This function gets the students answers from user
void getStudentAnswers(ScantronType, int);

int main() {

    // Array to hold correct answers
    ScantronType correctAnswers = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D',
                               'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    // Array to hold student answers
    ScantronType studentAnswers;

    // Array to hold student wrong answers
    ScantronType wrongAnswers;

    // Prompt user
    cout << setw(48) << "Welcome to Driver's License Exam\n";
    cout << setw(50) << "Valid entries are capital A,B,C or D.\n";

    // Function call to get students answers
    getStudentAnswers(studentAnswers, MAXSIZE);


    return 0;
}

//***********************************************************************
//                              getStudentAnswers
//
//  task: Validate user input and put entries into an array.
//  data in: StudentAnswers array and array size is taken in as an arguments.
//  data returned: None, the function mutates the original array.
//
//***********************************************************************
void getStudentAnswers(ScantronType studentAnswers, int arraySize){

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
