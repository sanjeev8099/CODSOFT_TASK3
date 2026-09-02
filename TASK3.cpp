#include <iostream>
using namespace std;

char board[3][3];

void resetBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = value++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;
    return true;
}

bool makeMove(int position, char player) {
    if (position < 1 || position > 9) return false;

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = player;
    return true;
}

int main() {
    char playAgain;

    do {
        resetBoard();
        char player = 'X';

        cout << "\n=== TIC-TAC-TOE ===\n";
        cout << "Player X goes first. Choose positions 1-9.\n";

        while (true) {
            displayBoard();
            int position;

            cout << "Player " << player << ", enter position: ";
            cin >> position;

            if (!makeMove(position, player)) {
                cout << "Invalid move. Choose an empty position from 1 to 9.\n";
                continue;
            }

            if (checkWin(player)) {
                displayBoard();
                cout << "Player " << player << " wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}