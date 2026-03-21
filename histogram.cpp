#include <iostream>
using namespace std;


// find the largest value in the array
int Max(int arr[], int size){
    int max = arr[0];

    for (int i = 1; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

// build histogram
void buildHistogram(int arr[], int size, int bins[], int numBins){
    // set all bin counts to 0 first
    for (int i = 0; i < numBins; i++){
        bins[i] = 0;
    }

    // count how many numbers fall into each bin
    for (int i = 0; i < size; i++){
        int binIndex = arr[i] / 10;
        bins[binIndex]++;
    }
}

// display
void printHistogram(int bins[], int numBins){
    for (int i = 0; i < numBins; i++){
        cout << i * 10 << " - " << i * 10 + 9 << " : " << bins[i] << endl;
    }
}

int main(){
    int size;
    int numbers[100];   // default array sizes
    int bins[100];

    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter " << size << " non-negative integers: ";
    // put user input into array
    for (int i = 0; i < size; i++){
        cin >> numbers[i];
    }

    int maxValue = Max(numbers, size);
    int numBins = maxValue / 10 + 1;
    buildHistogram(numbers, size, bins, numBins);
    printHistogram(bins, numBins);

    return 0;
}