//  This program has the user input a number n and then finds the
//  mean of the first n positive integers

// Greg Rodriguez 9/7/2024

#include <iostream>
using namespace std;


int main()
{
	int startValue;  // Value is some positive number n
    int endValue;    // Value is some positive number m
 	int total = 0;   // total holds the sum of the first n positive numbers
   	int number;      // the amount of numbers
  	float mean;      // the average of the first n positive numbers
    int counter = 0; // counter to keep track of iterations

  	cout << "Please enter a positive integer to start with." << endl;
   	cin >> startValue;

    cout << "Please enter a positive integer to end with." << endl;
   	cin >> endValue;

  	if (startValue > 0 && endValue > 0)
  	{
      	for (number = startValue ; number <= endValue; number++)
        {
 	  	    total = total + number;

            // Counter to keep track of the amount of iterations
            counter++;

		}  // curly braces are optional since there is only one statement 
		
        mean = float(total) / counter;        // note the use of the typecast
		                                     // operator here
		cout << "\nThe mean average between the positive integers " << startValue << " and " << endValue
             << " is " << mean << endl;
    }
    else 
        cout << "Invalid input - integer must be positive" << endl;

   return 0;	
}