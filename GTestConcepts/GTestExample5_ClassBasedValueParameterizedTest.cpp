// Type your code here, or load an example.
#include <gtest/gtest.h>
class Calculator {
    public:
        int square(int num) {
            if(num < 0) {
                std::cerr << "Error: Negative input!";
                exit(-1);
            }
            return num * num;
        }

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
};

// Instead of creating individual Test cases we can use the arrays
// Drawback: If array has many elements, it's hard to find where exactly error is
TEST(testCalcFun, DISABLED_testCase3) {
    char op[4] = {'+', '-', '*', '/'};
    int expectedResult[4] = {20,0,100,1};
    Calculator calculator;
    for(int i=0; i<4; ++i){
        //ACT or SUT
        int result = calculator.calcFun(10, op[i], 10);

        //ASSERT
        EXPECT_EQ(expectedResult[i], result);
    }
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
    testParameter{'*', 3},
    testParameter{'/', 1}
));

TEST_P(CalcParameterizedTestFixture, testcase1) {

    // Get the strucutre variable
    char op = GetParam().op;
    int expectedResult = GetParam().expectedResult;
    Calculator calculator;

    int result = calculator.calcFun(10, op , 10);
    EXPECT_EQ(expectedResult, result);
}

int main(int argc, char** argv) {
    // Initialize Google Test Framework
    // Execute all the Test Cases
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}