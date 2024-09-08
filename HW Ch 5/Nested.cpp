// This program finds the average time spent programming by a student
// each day over a three day period.

// Greg Rodriguez 9/7/2024

#include <iostream>
using namespace std;

int main()
{
	int numStudents;
	float numCodingHours, codingTotal, codingAverage, numBioHours, bioTotal, bioAverage;
    int student,day = 0;    // these are the counters for the loops
    int numberOfDays;       // variable for users input for number of days

	cout << "This program will find the average number of hours a day" 
         << " that a student spent on biology and programming over a long weekend\n\n";
    cout << "How many students are there ?" << endl << endl;
    cin >> numStudents;

    cout << "How many days are there ?" << endl << endl;
    cin >> numberOfDays;
       
    for( student = 1; student <= numStudents; student++)
    {
		codingTotal = 0;
		for(day = 1; day <= numberOfDays; day++)
		{
			cout << "Please enter the number of hours worked by student " 
				 << student <<" on day " << day << " in programming." << endl;
            cin >> numCodingHours;

            codingTotal = codingTotal + numCodingHours;
		}

        codingAverage = codingTotal / numberOfDays;

        bioTotal = 0;
        for(day = 1; day <= numberOfDays; day++)
        {
            cout << "Please enter the number of hours worked by student "
                 << student <<" on day " << day << " in biology." << endl;
            cin >> numBioHours;

            bioTotal = bioTotal + numBioHours;
        }

        bioAverage = bioTotal / numberOfDays;

		cout << endl;

        if(codingAverage > bioAverage) {
            cout << "The most time spent was programming with the average number of hours per day by "
                 << "student " << student << " is " << codingAverage
                 << endl << endl << endl;
        } else {
            cout << "The most time spent was in biology with the average number of hours per day by "
                 << "student " << student << " is " << bioAverage
                 << endl << endl << endl;
        }

	}

    return 0;	
}