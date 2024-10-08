#include <iostream>

// Print the entire matrix
void printMatrix(int (*matrix)[3], size_t rows) {
    for(int (*rowPtr)[3] = matrix; rowPtr < matrix + rows; ++rowPtr) {
        for(int* colPtr = *rowPtr; colPtr < *rowPtr + 3; ++colPtr) {
            std::cout << *colPtr << " ";
        }
        std::cout << '\n';
    }
}

// Print a specific row of a matrix
void printRow(int (*matrix)[3], int rowIndex) {
    if(rowIndex < 0 || rowIndex >= 2) {
        return; // check row index bounds
    }
    for(int* colPtr = matrix[rowIndex]; colPtr < matrix[rowIndex] + 3; ++colPtr) {
        std::cout << *colPtr << " ";
    }
    std::cout << '\n';
}

// Print diagonal elements of a matrix
void printDiagonal(int (*matrix)[3], size_t rows) {
    for(int i = 0; i < rows && i < 3; ++i) {
        std::cout << *(*(matrix + i) + i) << " "; // Access diagonal elements
    }
    std::cout << '\n';
}

// Print some structured way elements of a matrix (some random way)
void printSomeStructuredWay(int (*matrix)[3], size_t rows) {
    for(int* ptr = &matrix[0][0]; ptr < &matrix[0][0]+rows*3; ++ptr) {
        std::cout << *ptr << " ";
        if((ptr - &matrix[0][0] + 1)%3 == 0) {
            std::cout << '\n';
        }
    }
}

int main() {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    std::cout << "Print entire matrix:\n";
    printMatrix(matrix, 2);
    
    std::cout << "Print row 1:\n";
    printRow(matrix, 1);
    
    std::cout << "Print diagonal elements:\n";
    printDiagonal(matrix, 2);
    
    std::cout << "Print matrix with pointer arithmetic:\n";
    printSomeStructuredWay(matrix, 2);
    
    return 0;
}
