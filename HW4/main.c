#include<iostream>
#include<algorithm>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'O';
        initializeBoard();
    }

    //setting all elements to '-'
    void initializeBoard() {
        fill(&board[0][0], &board[0][0] + 9, '-');
    }

    void printBoard() {
        for (int i = 0; i < 3; i++) {
            cout << "      ■      ■  \n";
            for (int j = 0; j < 3; j++) {
                cout << "  " << board[i][j] << "  ";
                if (j < 2) {
                    cout << " ■";
                }
            }
            cout << "\n      ■      ■   \n";
            if (i < 2) {
                cout << "■■■■■■■■■■■" << endl;
            }
        }
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-')
                    return false;
            }
        }
        return true;
    }
    //is the input actually an integer?
    bool isInputValid(char input) {
        if (input < '1' || input > '9') {
            return false;
        }
        else {
            return true;
        }
    }

    bool checkWin() {
        // Check rows and colums
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true;
        }
        else if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true;
        }
        else {
            return false;
        }
    }

    void run() {
        char input;
        int move;
        while (1) {
            cout << "Player ";
            if (currentPlayer == 'O') {
                cout << "1" << ", enter your move (from 1 to 9): ";
            }
            else {
                cout << "2" << ", enter your move (from 1 to 9): ";
            }
            cin >> input;

            //make sure input is actually an integer
            if (!isInputValid(input)) {
                cout << "Please try again.\n";
                continue;
            }
            move = (int)input - 48;

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;

            //make sure target square is within range and accessable
            if (move < 1 || move > 9 || board[row][col] != '-') {
                cout << "Invalid move! Try again." << endl;
                continue;
            }

            board[row][col] = currentPlayer;

            printBoard();

            //did someone win?
            if (checkWin()) {
                if (currentPlayer == 'O') {
                    cout << "==>Player 1 win";
                }
                else {
                    cout << "==>Player 2 win";
                }
                break;
            }
            //is the board full or not?
            if (isBoardFull()) {
                cout << "==>Game Draw" << endl;
                break;
            }
            //changing players
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            }
            else {
                currentPlayer = 'X';
            }

        }
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
