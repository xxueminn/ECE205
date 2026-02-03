//XueMin Weng
//ECE 205 
//HW 1 Problem 1

#include <iostream>
#include <string>
using namespace std;

int time_s; //input
int hour, minute, seconds;
float re_h, re_m;

int main(){
    cout << "Enter the seconds" << endl;
    cin >> time_s;

    //hour, minute, seconds
    hour = time_s/3600;
    minute = (time_s%3600)/60;
    seconds = (time_s%3600)%60;

    cout << "hours is " << hour << endl;
    cout << "minute is " << minute << endl;
    cout << "seconds is " << seconds << endl;

    //real number
    re_h = (float(time_s)) / 3600;
    re_m = (float(time_s)) / 60;

    //format to 4 digits after decimal
    cout.setf(ios::fixed); //use fixed point notation
    cout.precision(4); 

    cout << "real hour is " << re_h << endl;
    cout << "real minute is " << re_m << endl;
    
    return 0;
}