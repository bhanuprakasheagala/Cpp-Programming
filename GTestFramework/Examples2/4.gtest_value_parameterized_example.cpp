// Type your code here, or load an example.

#include <gtest/gtest.h>
#include <iostream>
int square(int num) {
    if(num < 0) {
        std::cerr << "Error : Negative Input !";
        exit(-1);
    }
    return num * num;
}

int calc(int num1, char op, int num2) {
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

TEST(testCalc, DISABLED_testCase3)
{
    //ARRANGE
    char op[4] = {'+','-','*','/'};
    int expectResult[4] = {20,1,100,2};

    for(int i = 0; i< 4; i++) {
    //ACT - SUT
    int result = calc(10, op[i] ,10);

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

    int result = calc(10,op,10);
    EXPECT_EQ(expectedResult,result);
}



int main() {
    //Initialise Google Test Framework
    //Execute all the Test Cases
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}