#include <iostream>
#include <iomanip>

void fill(int **p, int rowSize, int columnSize);
void print(int **p, int rowSize, int columnSize);

int main(){
    
    int **board;
    int rows, columns;
    std::cout << "Enter number of rows and columns: ";
    std::cin >> rows >> columns;
    std::cout << '\n';

    // Create the rows of board
    board = new int* [rows];

    // Create the columns of board
    for(int row=0; row < rows; ++row){
        board[row] = new int[columns];
    }

    // Insert elements into board
    fill(board, rows, columns);

    std::cout << "Board: " << '\n';

    // Output the elements of board
    print(board, rows, columns);

    return 0;
}

void fill(int **p, int rowSize, int columnSize) {
    for(int row=0; row < rowSize; ++row) {
        std::cout << "Enter " << columnSize << " number(s) for row number " << row << ": ";
        for(int column=0; column < columnSize; ++column){
            std::cin >> p[row][column];
        }
        std::cout << '\n';
    }
}

void print(int **p, int rowSize, int columnSize) {
    for(int row=0; row<rowSize; ++row) {
        for(int column=0; column < columnSize; ++column) {
            std::cout << std::setw(8) << p[row][column];
        }
        std::cout << '\n';
    }
}