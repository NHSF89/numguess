/*
numberguesser.h
This is the header file for numberguesser.cpp
The number guesser determines a user's number.
*/
#ifndef NUMBERGUESS_H
#define NUMBERGUESS_H

class NumberGuesser
{
	private:
	int highPoint;
	int lowPoint;
	int midPoint;
	
	public:	
	NumberGuesser();
	NumberGuesser(int lowP1, int highP1)
	{
		lowPoint = lowP1;
		highPoint = highP1;
	}
	void NumberGuesserPoints (int lowP, int highP);
	void higher();
	void lower();
	int getCurrentGuess();
	void reset();
};

#endif
