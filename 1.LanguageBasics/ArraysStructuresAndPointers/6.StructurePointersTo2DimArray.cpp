#include <iostream>

struct Matrix {
    int (*arr)[3]; // Pointer to a 2D array with 3 columns
};

int main()
{
    int data[2][3] = {{1, 2, 3}, {4, 5, 6}};

    Matrix mat;
    mat.arr = data; // Point to the 2D array

    // Access the elements through structure
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 3; ++j) {
            std::cout << mat.arr[i][j] << " ";
        }
        std::cout << '\n';
    }
    
    return 0;
}