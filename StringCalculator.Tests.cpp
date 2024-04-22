#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(StringCalculatorTestSuite,GivenEmptyStringZeroIsExpected){
    //Arrange
    StringCalculator objUnderTest;
    string input="";
    int expectedValue=0;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite,Given2numbers){
    //Arrangee
    StringCalculator objUnderTest;
    string input="1,2";
    int expectedValue=3;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_multiple_comma_delimited_numbers){
    //Arrangee
    StringCalculator objUnderTest;
    string input="1,2,3";
    int expectedValue=6;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_delimited_with_newline_and_comma){
    //Arrangee
    StringCalculator objUnderTest;
    string input="1\n2,3";
    int expectedValue=6;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_a_delimiter){
    //Arrangee
    StringCalculator objUnderTest;
    string input="//;\n1;2";
    int expectedValue=3;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_negative_numbers){
    //Arrangee
    StringCalculator objUnderTest;
    string input="1,-2,-4,5";
    int expectedValue=3;
    //Act
    //Assert
    ASSERT_ANY_THROW(objUnderTest.Add(input));
}
TEST(StringCalculatorTestSuite,when_passed_negative_numbers1){
    //Arrangee
    StringCalculator objUnderTest;
    string input="1,-2,-4,5";
    int expectedValue=3;
    //Act
    //Assert
    ASSERT_THROW(objUnderTest.Add(input),invalid_argument);
}
TEST(StringCalculatorTestSuite,when_passed_numbers_over_1000){
    //Arrangee
    StringCalculator objUnderTest;
    string input="42,1001,3";
    int expectedValue=45;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_multicharacter_delimiter){
    //Arrangee
    StringCalculator objUnderTest;
    string input="//[***]\n8***2***3";
    int expectedValue=13;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_multiple_delimiters){
    //Arrangee
    StringCalculator objUnderTest;
    string input="//[*][%]\n4*2%3";
    int expectedValue=9;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
TEST(StringCalculatorTestSuite,when_passed_multiple_multicharacter_delimiters){
    //Arrangee
    StringCalculator objUnderTest;
    string input="//[**][%^]\n4**1%^9";
    int expectedValue=14;
    //Act
   int actualValue=  objUnderTest.Add(input);
    //Assert
    ASSERT_EQ(actualValue,expectedValue);
}
