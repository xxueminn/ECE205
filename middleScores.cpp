#include <iostream>
#include <iomanip>
using namespace std;

const int judges = 7;

// get degree of difficulty
double Difficulty(){
    double difficulty;
    cout << "Enter degree of difficulty from 1.2 to 3.8: ";
    cin >> difficulty;

    while (difficulty < 1.2 || difficulty > 3.8){
        cout << "Invalid input. Enter difficulty 1.2 to 3.8: ";
        cin >> difficulty;
    }
    return difficulty;
}

// get 7 scores
void Scores(double scores[]){
    for (int i = 0; i < judges; i++){
        cout << "Enter score " << i + 1 << ": ";
        cin >> scores[i];

        while (scores[i] < 0 || scores[i] > 10){
            cout << "Invalid input. Enter score " << i + 1 << " (0 to 10): ";
            cin >> scores[i];
        }
    }
}

// find lowest score
double findLowest(double scores[]){
    double lowest = scores[0];

    for (int i = 1; i < judges; i++){
        if (scores[i] < lowest){
            lowest = scores[i];
        }
    }
    return lowest;
}

// find highest score
double findHighest(double scores[]){
    double highest = scores[0];

    for (int i = 1; i < judges; i++){
        if (scores[i] > highest){
            highest = scores[i];
        }
    }
    return highest;
}

// calculate final score
double calcFinalScore(double scores[], double difficulty){
    double lowest = findLowest(scores);
    double highest = findHighest(scores);
    double sum = 0;

    for (int i = 0; i < judges; i++){
        sum = sum + scores[i];
    }
    sum = sum - lowest - highest;
    return sum * difficulty * 0.6;
}

int main(){
    double difficulty;
    double scores[judges];
    double finalScore;
    difficulty = Difficulty();
    Scores(scores);

    finalScore = calcFinalScore(scores, difficulty);
    cout << fixed << setprecision(2);
    cout << "Final diver score: " << finalScore << endl;

    return 0;
}