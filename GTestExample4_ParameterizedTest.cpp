// Type your code here, or load an example.
#include <gtest/gtest.h>

int calcFun(int a, char op, int b) {
    switch(op) {
        case '+' :
            return a+b;
        case '-' :
            return a-b;
        case '*' :
            return a*b;
        case '/' :
            return a/b;
        default:
            return 0;
    }
    return 0;
}

// Parameterized Test
struct testParameter {
    char op;
    int expectedResult;
};

struct CalcParameterizedTestFixture : public ::testing::TestWithParam<testParameter> {

};

//How we handle different parameter values
INSTANTIATE_TEST_CASE_P(testCalcWithParam,
CalcParameterizedTestFixture,
::testing::Values(
    testParameter{'+', 20},
    testParameter{'-', 0},
    testParameter{'*', 100},
    testParameter{'/', 1}
));

TEST_P(CalcParameterizedTestFixture, testcase1) {

    // Get the strucutre variable
    char op = GetParam().op;
    int expectedResult = GetParam().expectedResult;


    int result = calcFun(10, op , 10);
    EXPECT_EQ(expectedResult, result);
}

int main(int argc, char** argv) {
    // Initialize Google Test Framework
    // Execute all the Test Cases
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}