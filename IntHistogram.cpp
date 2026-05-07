#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> myVector){
    int max = 0;
    for (int i = 0; i < myVector.size(); i++){
        if (myVector[i] > max){
            max = myVector[i];
        }
    }
    return max;
}

void buildHistogram(vector<int> myVector, vector<int>& histogram){
    for (int i = 0; i < myVector.size(); i++){
        int index = myVector[i] / 10;
        histogram[index]++;
    }
}

void printHistogram(vector<int> histogram){
    cout << "Histogram:" << endl;

    for (int i = 0; i < histogram.size(); i++){
        cout << i * 10 << " - " << i * 10 + 9 << " : " << histogram[i] << endl;
    }
}

int main(){
    vector<int> myVector;
    int number;
    // ask for user input
    cout << "Enter a list of integers and a negative integer to end: " << endl;
    cin >> number;

    // add input to vector 
    while (number >= 0){
        myVector.push_back(number);
        cin >> number;
    }
    // make sure something is in vector
    if (myVector.size() == 0){
        cout << "Invalid." << endl;
        return 0;
    }

    // find the largest value first
    int max = findMax(myVector);
    // make enough bins up to the max value
    vector<int> histogram(max / 10 + 1, 0);
    // count how many values go into each bin
    buildHistogram(myVector, histogram);
    // print histogram
    printHistogram(histogram);

    return 0;
}