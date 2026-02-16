#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// average of scores
double average(const double a[], int n){
    double sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum / n;
}

// population standard deviation
double stdDev(const double a[], int n, double avg){
    double sumSq = 0.0;
    for (int i = 0; i < n; i++)
    {
        double diff = a[i] - avg;
        sumSq += diff * diff;
    }
    return sqrt(sumSq / n);
}

int main(){
    const int N = 5;
    double scores[N];

    // input file
    ifstream fin("scores.txt");
    
    // read 5 scores
    for (int i = 0; i < N; i++){
        fin >> scores[i];
    }
    fin.close();

    double avg = average(scores, N);
    double sd  = stdDev(scores, N, avg);

    // output to console
    cout << fixed << setprecision(2);
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << sd << endl;

    // output to file
    ofstream fout("output.txt");
    fout << fixed << setprecision(2);
    fout << "Average: " << avg << endl;
    fout << "Standard Deviation: " << sd << endl;
    fout.close();
    
    return 0;
}