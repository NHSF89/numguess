/*
numberguess.cpp
This is the accompanying code that 
gives meaning to the functions of numberguess.h
*/
#include <iostream>
#include "numberguess.h"

void NumberGuesser::higher()
{
	lowPoint = midPoint;
	midPoint = highPoint/2 + lowPoint/2;
}

void NumberGuesser::lower()
{
	highPoint = midPoint;
	midPoint = highPoint/2 + lowPoint/2;

}
int NumberGuesser::getCurrentGuess()
{
	midPoint = highPoint/2 + lowPoint/2;
	if (highPoint-midPoint==2 || midPoint-lowPoint==2)
    midPoint = midPoint+1;
	return midPoint;
}
void NumberGuesser::reset()
{
	highPoint = 0;
	lowPoint = 0;
	midPoint = 0;
}

