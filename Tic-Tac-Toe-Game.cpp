#include <iostream>
#include <vector>

// Function to initialize the game board
std::vector<std::vector<char>> InitializeBoard() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    return board;
}

// Function to display the game board
void DisplayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "   1   2   3" << std::endl;
    std::cout << "  -------------" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
        std::cout << "  -------------" << std::endl;
    }
}

// Function to check if the current player has won
bool CheckWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal
    }
    return false;
}

// Function to check if the game is a draw
bool CheckDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // Empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

int main() {
    std::vector<std::vector<char>> board = InitializeBoard();
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    std::cout << "TIC-TAC-TOE GAME" << std::endl;

    do {
        DisplayBoard(board);
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
            gameWon = CheckWin(board, currentPlayer);
            gameDraw = CheckDraw(board);
            if (!gameWon) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
            }
        } else {
            std::cout << "Invalid move. Please try again." << std::endl;
        }
    } while (!gameWon && !gameDraw);

    DisplayBoard(board);

    if (gameWon) {
        std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
    } else {
        std::cout << "It's a draw! The game is over." << std::endl;
    }

    return 0;
}
