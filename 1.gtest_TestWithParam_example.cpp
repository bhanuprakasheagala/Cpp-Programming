// Type your code here, or load an example.

#include <gtest/gtest.h>
#include <iostream>

//.hpp
class Calculator {
    public :
        int square(int num);
        int calc(int num1, char op, int num2);
        
        template <typename T>
        T max(T x, T y)
        {
            return (x > y) ? x : y;
        }
};

//.cpp
int Calculator::square(int num) {
    return num * num;
}

int Calculator::calc(int num1, char op, int num2) {
    switch(op) {
        case '+':
        return num1 + num2;
        case '-':
        return num1 - num2;
        case '*':
        return num1 * num2;
        case '/':
        return num1 / num2;
        default :
        return 0;
    }
   return num1 + num2;
}

template <typename T>
struct testParameterInteger
{
    T input1;
    T input2;
};

class CalcTestFixtureForInteger : public ::testing::TestWithParam<testParameterInteger<int>>
{
    public :
        Calculator calculator;
};

class CalcTestFixtureForChar : public ::testing::TestWithParam<testParameterInteger<char>>
{
    public :
        Calculator calculator;
};

INSTANTIATE_TEST_CASE_P(parameterForInterger, CalcTestFixtureForInteger, 
::testing::Values(
    testParameterInteger<int>{2,7},
    testParameterInteger<int>{3,8},
    testParameterInteger<int>{10,2}
));

INSTANTIATE_TEST_CASE_P(parameterForChar, CalcTestFixtureForChar, 
::testing::Values(
    testParameterInteger<char>{'a','b'},
    testParameterInteger<char>{'b','z'},
    testParameterInteger<char>{'z','c'}
));

class CalcTestFixture : public ::testing::Test
{
    public :
        Calculator calculator;
};

TEST_P(CalcTestFixtureForInteger, testMaxInt) {
    int input1 = GetParam().input1;
    int input2 = GetParam().input2;
    int result = calculator.max<int>(input1,input2);
    ASSERT_EQ(7, result);
}

TEST_P(CalcTestFixtureForChar, testMaxChar) {
    char input1 = GetParam().input1;
    char input2 = GetParam().input2;
    char result = calculator.max<char>(input1,input2);
    ASSERT_EQ('b', result);
}

TEST_F(CalcTestFixture, testSquarePositive) {

    //ACT
    int result = calculator.square(10);

    //ASSERT
    ASSERT_EQ(100, result);
}

TEST_F(CalcTestFixture, testSquareNegative) {

    //ACT
    int result = calculator.square(-10);

    //ASSERT
    ASSERT_EQ(100, result);
}


TEST(testCalc, DISABLED_testCase3)
{
    //ARRANGE
    char op[4] = {'+','-','*','/'};
    int expectResult[4] = {20,1,100,2};

    Calculator calculator;

    for(int i = 0; i< 4; i++) {
    //ACT - SUT
    int result = calculator.calc(10, op[i] ,10);

    //ASSERT
    EXPECT_EQ(expectResult[i],result) << "Error : Values dnt match" << expectResult[i] << " !=" << result;
    }
}

//Parameterized Test
struct testParameter
{
    char op;
    int expectResult;
};

struct CalcParameterizedTestFixture : public ::testing::TestWithParam<testParameter> {

};

INSTANTIATE_TEST_CASE_P(testCalcWithParam, 
CalcParameterizedTestFixture,
::testing::Values(
    testParameter{'+',20},
    testParameter{'-',0},
    testParameter{'*',3},
    testParameter{'/',1}
));

TEST_P(CalcParameterizedTestFixture, testCalcUsingParam) 
{
    char op = GetParam().op;
    int expectedResult = GetParam().expectResult;

    Calculator calculator;

    int result = calculator.calc(10,op,10);
    EXPECT_EQ(expectedResult,result);
}



int main() {
    //Initialise Google Test Framework
    //Execute all the Test Cases
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}