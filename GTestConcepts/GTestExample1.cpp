// Type your code here, or load an example.
#include <gtest/gtest.h>

int square(int num) {
    return num * num;
}

TEST(testSquare, testSquarePoistive) {

    // Arrange
    int input = 10;

    // Act
    int result = square(input);
    
    // Assert
    ASSERT_EQ(100, result);
}   

int main() {
    // Initialize Google Test Framework
    // Execute all the Test Cases
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}