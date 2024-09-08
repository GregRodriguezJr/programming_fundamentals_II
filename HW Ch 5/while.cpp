// Greg Rodriguez 9/7/2024

#include <iostream>
using namespace std;

int main()
{
	char letter = 'a';

    do
    {
        cout << "Please enter a letter. The letter x will exit the program" << endl;
        cin >> letter;
        cout << "The letter you entered is " << letter << endl;
    } while(letter != 'x');

    return 0;	
}
