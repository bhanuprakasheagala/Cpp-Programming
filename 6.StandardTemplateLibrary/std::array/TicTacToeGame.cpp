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
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return std::nullopt; // No winner
}

// Function to check if the board is full
bool isBoardFull(const Board& board) {
    return std::all_of(board.begin(), board.end(), [](const auto& row) {
        return std::all_of(row.begin(), row.end(), [](char cell) {
            return cell != ' ';
        });
    });
}

int main()
{
    Board board = {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}}; // Initialize the board
    char currentPlayer = 'X'; // Start with player x

    while(true) {
        printBoard(board);

        // Check for a winner
        if(auto winner = checkWinner(board)) {
            std::cout << "Player " << *winner << "wins!\n";
            break;
        }

        // Check for a draw
        if(isBoardFull(board)) {
            std::cout << "It's a draw\n";
            break;
        }
    }
    return 0;
}
