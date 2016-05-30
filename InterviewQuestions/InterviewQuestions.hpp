#ifndef GTEST_INTERVIEW_QUESTIONS_H
#define GTEST_INTERVIEW_QUESTIONS_H
#include <string>
std::string BoolToStr(bool input);

//IsUnique
bool IsUnique( std::string input );
bool IsUnique_hashtable( std::string input );
bool IsUnique_sort( std::string input );

//OneAway
bool OneAway( std::string str1, std::string str2 );

//Fibonacci
int Fibonacci( int n );
int Fibonacci_Iterative( int n );
#endif
