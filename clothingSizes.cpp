#include <iostream>
#include <iomanip>
using namespace std;

double hatSize(double height, double weight){
    return 2.9 * weight / height;
}

double jacketSize(double height, double weight, int age){
    double size = (height * weight) / 288.0;

    if (age > 30){
        int tenYearsOver30 = (age - 30) / 10;    // full 10 years only
        size += tenYearsOver30 * (1.0 / 8.0);    // 1/8 inch per 10 years
    }
    return size;
}

double waistSize(double weight, int age){
    double size = weight / 5.7;

    if (age > 28)
    {
        int twoYearsOver28 = (age - 28) / 2;     // full 2 years only
        size += twoYearsOver28 * (1.0 / 10.0);   // 1/10 inch per 2 years
    }
    return size;
}

int main(){
    double height, weight;
    int age;

    //ask for measurements
    cout << "Enter height in inches: ";
    cin >> height;
    cout << "Enter weight in pounds: ";
    cin >> weight;
    cout << "Enter age in years: ";
    cin >> age;

    // use functions to calculate sizes
    double hat = hatSize(height, weight);
    double jacket = jacketSize(height, weight, age);
    double waist = waistSize(weight, age);

    cout << fixed << setprecision(2);
    cout << "\nClothing Sizes\n";
    cout << "Hat size   : " << hat << endl;
    cout << "Jacket size: " << jacket << " inches" << endl;
    cout << "Waist size : " << waist << " inches" << endl;

    return 0;
}