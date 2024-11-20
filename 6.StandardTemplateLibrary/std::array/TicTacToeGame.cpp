#include <iostream>
#include <array>
#include <algorithm>
#include <optional>

// Type alias for the board
using Board = std::array<std::array<char, 3>, 3>;

// Function to print the Board
void printBoard(const Board& board) {
    std::cout << '\n';

    for(const auto& row : board) {
        for(char cell : row) {
            std::cout << (cell == ' ' ? '.' : cell) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// Function to check if a player has won
std::optional<char> checkWinner(const Board& board) {
    // Check rows and columns
    for(int i = 0; i < 3; ++i) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; // Row win
        }
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i]; // Column win
        }
    }

    // Check diagnols
    
}

int main()
{
    
    return 0;
}
