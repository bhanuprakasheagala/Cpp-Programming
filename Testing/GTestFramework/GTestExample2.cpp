// Type your code here, or load an example.
#include <gtest/gtest.h>

int square(int num) {
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

// Instead of creating individual Test cases we can use the arrays
// Drawback: If array has many elements, it's hard to find where exactly error is
TEST(testCalcFun, testCase3) {
    char op[4] = {'+', '-', '*', '/'};
    int expectedResult[4] = {20,0,100,1};

    for(int i=0; i<4; ++i){
        //ACT or SUT
        int result = calcFun(10, op[i], 10);

        //ASSERT
        ASSERT_EQ(expectedResult[i], result);
    }
}

TEST(testSquare, testSquarePoistive) {

    // Arrange
    int input = 10;

    // Act - SUT
    int result = square(input);
    
    // Assert
    ASSERT_EQ(100, result);
}

TEST(testSquare, testSquareNegative) {

    // Arrange
    int input = -10;

    // Act
    int result = square(input);
    
    // Assert
    ASSERT_EQ(100, result);
}

TEST(testSquare, testSquareEdgeCase) {
    int input = -1;
    //int result = square(input);
    
    ASSERT_EQ(1, square(input));
}


int main(int argc, char** argv) {
    // Initialize Google Test Framework
    // Execute all the Test Cases
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}