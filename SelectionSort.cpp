#include <iostream>
#include <vector>
using namespace std;

void deleteRepeatedChars(vector<char>& myVector){
    for (int i = 0; i < myVector.size(); i++){
        for (int j = i + 1; j < myVector.size(); j++){
            if (myVector[i] == myVector[j]){
                // shift everything after the repeated char one position left
                for (int k = j; k < myVector.size() - 1; k++){
                    myVector[k] = myVector[k + 1];
                }
                // make the vector one smaller after removing the duplicate
                myVector.resize(myVector.size() - 1);

                // keep same j because a new value shifted into this spot
                j--;
            }
        }
    }
}

void selectionSort(vector<char>& myVector){
    for (int i = 0; i < myVector.size() - 1; i++){
        int maxIndex = i;
        // find the largest letter for this pass
        for (int j = i + 1; j < myVector.size(); j++){
            if (myVector[j] > myVector[maxIndex]){
                maxIndex = j;
            }
        }

        // swap into the current position
        char temp = myVector[i];
        myVector[i] = myVector[maxIndex];
        myVector[maxIndex] = temp;
    }
}

int main(){
    vector<char> myVector;
    char input;

    //ask for user input
    cout << "Enter a char, enter 0 to quit: ";
    cin >> input;

    while (input != '0'){
        myVector.push_back(input);
        cout << "Enter a char, enter 0 to quit: ";
        cin >> input;
    }

    deleteRepeatedChars(myVector);
    selectionSort(myVector);
    cout << "Array without repititon and in decreasing order:";
    for (int i = 0; i < myVector.size(); i++){
        cout << myVector[i];
        cout << " ";
    }

    return 0;
}