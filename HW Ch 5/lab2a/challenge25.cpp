// Ch. 5 & 7 PC #25 Using Files - Student line up
// Created by Greg Rodriguez
// COSC 1437
// 9/13/24
// Purpose: To read a file with a list of students and determine who is first and last in alphabetical order.
// Input: Text file to read the list of strings.
// Output: The first and last student, and also a full list in alphabetical order.

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

ifstream dataIn;		                // defines an input stream for files
typedef vector<string> ListType;        // defines new vector data type
bool readFile(ListType&, string);       // function to read and validate data from a file
void sortStudentNames(ListType&);       // function to sort names
void printResults(ListType&);           // function to print results to terminal

int main(){

    ListType studentNames;                          // variables to hold vectors
    string fileName = "LineUp.txt";                 // variable to hold file names
    bool isValid;                                   // variable to hold validation boolean

    cout << setw(48) << "Welcome to Student Line Up\n\n";   // Prompt user

    isValid = readFile(studentNames, fileName);  // returns boolean to check for errors or continue program

    if(isValid){                                    // if no errors the functions will be called to proceed
        sortStudentNames(studentNames);
        printResults(studentNames);
    }

    return 0;
}

//***********************************************************************
//                              readFile
//
//  task: Validate file being read and put data into a vector, display error message if not read.
//  data in: StudentNames vector and fileName is taken in as an arguments.
//  data returned: Boolean is return to validate if file was read successfully.
//
//***********************************************************************
bool readFile(ListType& studentNames, string fileName){
    bool isValid;
    dataIn.open(fileName);

    if(dataIn){
        string name;
        while(dataIn >> name){
            studentNames.push_back(name);
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
//                              sortStudentNames
//
//  task: Sort the list in alphabetic order.
//  data in: StudentNames vector.
//  data returned: None, the function mutates the original vector.
//
//***********************************************************************
void sortStudentNames(ListType& studentNames){
    sort(studentNames.begin(), studentNames.end());
}

//***********************************************************************
//                              printResults
//
//  task: Print the first, last, and ordered list.
//  data in: StudentNames vector.
//  data returned: None, the function prints results.
//
//***********************************************************************
void printResults(ListType& studentNames){
    cout << studentNames[0] << " would be at the front of the line." << endl;
    cout << studentNames[studentNames.size() - 1] << " would be at the end of the line.\n" << endl;

    cout << "Complete list in order:" << endl;
    for (const string& studentName : studentNames) {
        cout << studentName << endl;
    }
}