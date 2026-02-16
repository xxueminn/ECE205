#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// pick 4 unique finalist numbers, store them in winners[]
void pickWinners(int winners[], int count){
    int picked = 0;

    while (picked < count){
        int r = (rand() % 25) + 1;  // random number 1-25
        bool repeat = false;    // check if r is already in winners

        for (int i = 0; i < picked; i++){
            if (winners[i] == r){
                repeat = true;
                break;
            }
        }
        // if not repeat winner, accept it
        if (!repeat){
            winners[picked] = r;
            picked++;
        }
    }
}

int main(){
    srand(time(0));     //to get random numbers each time 
    const int numPrizes = 4;
    int winners[numPrizes];
    pickWinners(winners, numPrizes);

    cout << "The 4 finalists who receive prizes are finalists ";
    for (int i = 0; i < numPrizes; i++)
        cout << winners[i] << (i < numPrizes - 1 ? ", " : "\n");

    return 0;
}