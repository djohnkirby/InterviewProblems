#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "InterviewQuestions.hpp"

std::string BoolToStr(bool input)
{
	if (input)
		return "true";
	else
		return "false";
}

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

//Returns true iff str contains no repeating characters
bool IsUnique( std::string input )
{
	int i, j; 
	for( i = 0; i < input.length(); i ++ )
		for (j = i; j < input.length(); j ++ )
			if ((input[i] == input[j]) && (i != j))
				return false;
	return true;
}

bool IsUnique_hashtable( std::string input )
{
	int i;
	//create a hash table of all characters, assume ASCII
	bool hash[256];
	for( i = 0; i < 256; i++ )
		hash[i] = false;//Initialize array to false
	for( i = 0; i < input.length(); i ++ )
	{
		if (hash[(int)(input[i])] == true)
			return false;
		else
			hash[(int)(input[i])] = true;
	}

	return true;
}

bool IsUnique_sort( std::string input )
{
	int i;
	std::sort(input.begin(), input.end());
	for(i = 0; i < input.length() - 1; i ++ )
		if(input[i] == input[i+1])
			return false;
	return true;
}

//Retruns true if the two strings are the same or if they differ by one insertion,
//deletion, or replacement.
bool OneAway( std::string str1, std::string str2 )
{
	int i;
	//Must differ by more than one operation
	if(abs(str1.length() - str2.length()) > 1)
		return false;
	//Insertion or removal
	else if (abs(str1.length() - str2.length()) == 1)
	{
		//Require str1 to be the shorter one
		if (str2.length() < str1.length())
			return OneAway(str2, str1);
		int j = 0;
		bool hasFoundDiff = false;
		for( i = 0; i < str1.length(); i ++, j++ )
		{
			if(str1[i] != str2[j])
				if (hasFoundDiff)
					return false;
				else
				{
					hasFoundDiff = true;
					j++;
					//Second chance
					if (str1[i] != str2[j])
						return false;
				}
		}

		return true;
	}
	//Replacement
	else
	{
		bool hasFoundReplaced = false;
		for( i = 0; i < str1.length(); i ++ )
		{
			if (str1[i] != str2[i])
			{
				if (hasFoundReplaced)
					return false;
				else
					hasFoundReplaced = true;
			}
		}

		return true;
	}


}

int Fibonacci( int n )
{
	//Early out all non-valid inputs
	if (n < 0)
		return 0;

	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

int Fibonacci_Iterative( int n )
{
    //Early out all non-valid inputs
	if (n < 0)
		return 0;

	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;

	int fib1, fib2, result;
	int i = 0;
	fib1 = 1;
	fib2 = 1;
	result = 0;

	while( i < n -1 )
	{
		result = fib1 + fib2;
		fib1 = fib2;
		fib2 = result;
		i++;
	}

	return result;
}