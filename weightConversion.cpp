#include <iostream>
using namespace std;

bool input(int &lb, int &oz){
    cout << "Enter pounds. Enter negative to quit: ";
    cin >> lb;
    if (lb < 0) return false; // if neg value it is false and quits
    cout << "Enter ounces: ";
    cin >> oz;

    return true;
}

void convertWeight(int lb, int oz, int &kg, int &g){

    double totalPounds = lb + (oz / 16.0);      // convert to pounds 
    double totalKg = totalPounds / 2.2046;      // Convert pounds to kg
    int totalGrams = static_cast<int>(totalKg * 1000);      // Convert kg to grams 

    kg = totalGrams / 1000;
    g  = totalGrams % 1000;
}

void display (int lb, int oz, int kg, int g){
    cout << lb << " lb " << oz << " oz  =  " << kg << " kg " << g << " g";
}

int main(){
    int lb, oz, kg, g;   

    // loop until neg input
    while (input(lb, oz)){
        convertWeight(lb, oz, kg, g);
        display (lb, oz, kg, g);
        cout << endl;
    }
    return 0;
}