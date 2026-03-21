#include <iostream>
using namespace std;

const int rows = 3;
const int columns = 3;

// put numbers 1-9 on the board at the start
void initializeBoard(char board[][columns]){
    char value = '1';

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            board[i][j] = value;
            value++;
        }
    }
}

// show current board
void displayBoard(char board[][columns]){
    cout << endl;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

// check if position is open
bool isValidMove(char board[][columns], int position){
    if (position < 1 || position > 9){
        return false;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // if spot already has X/O
    if (board[row][col] == 'X' || board[row][col] == 'O'){
        return false;
    }

    return true;
}

// put X/O on the board
void makeMove(char board[][columns], int position, char player){
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    board[row][col] = player;
}

// check rows, columns, and diagonals for a win
bool checkWin(char board[][columns], char player){
    // check rows
    for (int i = 0; i < rows; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }

    // check columns
    for (int j = 0; j < columns; j++){
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player){
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }

    return false;
}

// check if the board is full
bool boardFull(char board[][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }

    return true;
}

int main(){
    char board[rows][columns];
    char player = 'X';
    int position;
    initializeBoard(board);
    displayBoard(board);

    while (true){
        // ask player for a move
        cout << "Player " << player << " enter a position 1-9: ";
        cin >> position;

        // keep asking until a valid
        while (!isValidMove(board, position)){
            cout << "Taken already. Enter a position 1-9: ";
            cin >> position;
        }

        // place move and show updated board
        makeMove(board, position, player);
        displayBoard(board);

        // check if current player won
        if (checkWin(board, player)){
            cout << "Player " << player << " wins." << endl;
            break;
        }

        // check for tie
        if (boardFull(board)){
            cout << "Tie." << endl;
            break;
        }

        // switch players
        if (player == 'X'){
            player = 'O';
        }
        else{
            player = 'X';
        }
    }

    return 0;
}