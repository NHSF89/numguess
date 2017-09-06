/*
numberguessprogram.cpp
This is the primary program for the number guess program.
The file is accompanied by 'numberguess.h' and 'numberguess.cpp'.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "numberguess.cpp"

using namespace std;

/*Starting Help menu Function - This function houses information on 
operating the program as well as the necessary input to use the program*/
void helpMenu()
{
    cout << endl <<" - First, you must enter the range you would like to test";
    cout << endl << endl <<" - Next, the program will begin asking whether a guess it makes it higher lower or correct.";
    cout << endl << endl <<" - Answer the prompts with either \"h\" (higher),\n   \"l\" (lower), or \"c\" (correct).";
    cout << endl << endl <<" - Eventually, your number will be guessed correctly.";
    cout << endl << endl << endl << "                  Let's begin, shall we?" << endl << endl << endl;
}

/*PlayAgain? Function - This function determines whether or not a player would 
like to replay the program or exit by using a bool statement*/
bool shouldPlayAgain()
{
    char response;
		 
	cout << endl << "Successfully guessed your number! Would you like to restart the program? ( \"Y\" / \"N\" ): ";
    cin >> response;
    
    while (toupper(response)!='Y' && toupper(response)!='N')
	{
	    cout << endl << "Please enter either \"Y\" or \"N\": ";
		cin >> response;
	}
     	
    if (toupper(response)=='N')
    return 0;
     	
    else if (toupper(response)=='Y')
    return 1; 	
}

void welcomeDisplay()
{
	char starthelp;
	
	cout << endl << "***************************************************************";
	cout << endl << "*         Welcome to the Number Guessing Machine!             *";
	cout << endl << "*     \"h\" is higher, \"l\" is lower, \"c\" is correct.            *";
	cout << endl << "***************************************************************" << endl << endl;
	cout << endl << "Type \"P\" to start or \"H\" for instructions: ";
	cin >> starthelp;
	
	while (toupper(starthelp) !='P' && toupper(starthelp)!='H')
	{
		cout << endl << "Please enter either \"P\" to start or \"H\" for further instruction: ";
		cin >> starthelp;
	}
	 
	if (toupper(starthelp) == 'H')
	helpMenu();
}


int main ()
{
	char hlc = '\0';
	int h,l;
	
	do {
		welcomeDisplay();
		cout << endl << "Please enter the minimum number for your range: ";
		cin >> l;
		cout << endl << "Please enter the maximum number for your range: ";
		cin >> h;
		while ( l > h)
		{
			cout << endl << "The minimum range must NOT be greater than or equal to the maximum range. Please reenter your ranges: ";
			cout << endl << "Minimum Range: ";
			cin >> l;
			cout << endl << "Maximum Range: ";
			cin >> h;
		}
		NumberGuesser ng(l,h);
		
			while (toupper(hlc) !='C')
				{
					cout << endl << "Is your number " << ng.getCurrentGuess()<<"?(h/l/c): ";
					cin >> hlc;
					
					while (toupper(hlc)!='H' && toupper(hlc)!='L' && toupper(hlc)!='C')
					{
						cout << endl << "Please enter \"h\" for higher, \"l\" for lower, or \"c\" for correct: ";
						cin >> hlc;
					}
					
					if (toupper(hlc) == 'H')
					ng.higher();
					else if (toupper(hlc) == 'L')
					ng.lower();
				}
		ng.reset();
		hlc = '\0';
	} while (shouldPlayAgain()==1);

	cout << endl << "Exiting Program......" << endl;
	return 0;	
}
