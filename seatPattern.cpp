#include <iostream>
using namespace std;

const int rows = 10;
const int columns = 4;

// put a b c d in every row at the start
void initializeSeats(char seats[][columns]){
    for (int i = 0; i < rows; i++){
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }
}

// show the current seat chart
void displaySeats(char seats[][columns]){
    cout << "\nSeat Chart:\n";
    for (int i = 0; i < rows; i++){
        cout << i + 1 << "    ";
        for (int j = 0; j < columns; j++){
            cout << seats[i][j] << " ";
            if (j == 1){
                cout << "  ";
            }
        }

        cout << endl;
    }
}

// change seat letter into column number
int seatLetterToIndex(char letter){
    if (letter == 'A')
        return 0;
    else if (letter == 'B')
        return 1;
    else if (letter == 'C')
        return 2;
    else if (letter == 'D')
        return 3;
    else
        return -1;
}

// check if every seat has been taken
bool seatsTaken(char seats[][columns]){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (seats[i][j] != 'X'){
                return false;       // found open seat
            }
        }
    }
    return true;        // all X
}

int main(){
    char seats[rows][columns];
    int row;
    char letter;
    char choice;

    initializeSeats(seats);

    do {
        displaySeats(seats);

        if (seatsTaken(seats)){
            cout << "\nAll seats are taken.\n";
            break;
        }

        cout << "\nEnter desired row number 1-10: ";
        cin >> row;
        cout << "Enter desired seat letter a-d: ";
        cin >> letter;

        while (letter >= 'a' && letter <= 'z'){
            letter = letter - 32;
        }

        int col = seatLetterToIndex(letter);

        while (row < 1 || row > 10 || col == -1 || seats[row - 1][col] == 'X'){
            if (row < 1 || row > 10 || col == -1){
                cout << "Invalid seat. Enter row number 1-10: ";
                cin >> row;
                cout << "Enter seat letter a-d: ";
                cin >> letter;

                while (letter >= 'a' && letter <= 'z'){
                    letter = letter - 32;
                }

                col = seatLetterToIndex(letter);
            }
            else if (seats[row - 1][col] == 'X'){

                cout << "That seat is already taken.";
                cout << "Enter row number 1-10: ";
                cin >> row;
                cout << "Enter seat letter A-D: ";
                cin >> letter;

                while (letter >= 'a' && letter <= 'z'){
                    letter = letter - 32;
                }

                col = seatLetterToIndex(letter);
            }
        }

        seats[row - 1][col] = 'X';
        displaySeats(seats);

        if (seatsTaken(seats)){
            cout << "\nAll seats are taken.\n";
            break;
        }

        cout << "\nDo you want to add another seat? (y/n): ";
        cin >> choice;

    } while (choice == 'y');

    return 0;
}