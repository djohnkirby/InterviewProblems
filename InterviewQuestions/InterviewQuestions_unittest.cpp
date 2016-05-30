#include <string>
#include "InterviewQuestions.hpp"
#include "gtest/gtest.h"


TEST(IsUniqueTest, sort)
{
	EXPECT_TRUE(IsUnique_sort("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	EXPECT_TRUE(IsUnique_sort("aA"));
	EXPECT_FALSE(IsUnique_sort("aa"));
	EXPECT_TRUE(IsUnique_sort("qwerty"));
	EXPECT_FALSE(IsUnique_sort("The quick brown fox jumped over the lazy dog"));
}

TEST(IsUniqueTest, naive)
{
	EXPECT_TRUE(IsUnique("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	EXPECT_TRUE(IsUnique("aA"));
	EXPECT_FALSE(IsUnique("aa"));
	EXPECT_TRUE(IsUnique("qwerty"));
	EXPECT_FALSE(IsUnique("The quick brown fox jumped over the lazy dog"));
}

TEST(IsUniqueTest, hashtable)
{
	EXPECT_TRUE(IsUnique_hashtable("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	EXPECT_TRUE(IsUnique_hashtable("aA"));
	EXPECT_FALSE(IsUnique_hashtable("aa"));
	EXPECT_TRUE(IsUnique_hashtable("qwerty"));
	EXPECT_FALSE(IsUnique_hashtable("The quick brown fox jumped over the lazy dog"));
}

TEST(OneAway, Replacement)
{
	EXPECT_TRUE(OneAway("cat","bat"));
	EXPECT_TRUE(OneAway("pale","pane"));
	EXPECT_TRUE(OneAway("abcdefghijklmnopqrstuvwxyz","abcdefghijklmnopqrstuvwxyz"));
	EXPECT_TRUE(OneAway("abcdefghijklmnopqrstuvwxyz","abcdefhhijklmnopqrstuvwxyz"));
	EXPECT_TRUE(OneAway("a","b"));

	EXPECT_FALSE(OneAway("abcdefhhijklmnopqrstuvwxyz","the quick brown fox jumped over the lazy dog"));
	EXPECT_FALSE(OneAway("taco","pale"));
	EXPECT_FALSE(OneAway("dream","stream"));
	EXPECT_FALSE(OneAway("stream","dream"));
	EXPECT_FALSE(OneAway("America","Amercia"));
	EXPECT_FALSE(OneAway("mane","lace"));
}

TEST(OneAway,InsertionRemoval)
{
	EXPECT_TRUE(OneAway("pale","ple"));
	EXPECT_TRUE(OneAway("ple","pale"));
	EXPECT_TRUE(OneAway("rage","raged"));
	EXPECT_TRUE(OneAway("age","rage"));

	EXPECT_FALSE(OneAway("age","rager"));
	EXPECT_FALSE(OneAway("meanie","main"));
}

TEST(Fibonacci,Recursive_Edge)
{
	EXPECT_EQ(Fibonacci(-1),0);
	EXPECT_EQ(Fibonacci(-1000),0);
}

TEST(Fibonacci,Recursive_Trivial)
{
	EXPECT_EQ(Fibonacci(0),1);
	EXPECT_EQ(Fibonacci(1),1);
	EXPECT_EQ(Fibonacci(24),75025);
}

TEST(Fibonacci,Iterative_Edge)
{
	EXPECT_EQ(Fibonacci_Iterative(-1),0);
	EXPECT_EQ(Fibonacci_Iterative(-1000),0);
}

TEST(Fibonacci,Iterative_Trivial)
{
	EXPECT_EQ(Fibonacci_Iterative(0),1);
	EXPECT_EQ(Fibonacci_Iterative(1),1);
	EXPECT_EQ(Fibonacci_Iterative(24),75025);
}