#include <iostream>
using namespace std;

bool input(int &hour24, int &minute){
    cout << "Enter hour. Enter a negative hour to quit: ";
    cin >> hour24;

    if (hour24 < 0) return false;
    cout << "Enter minute: ";
    cin >> minute;

    return true;
}

void convertTime(int hour24, int minute, int &hour12, char &ampm){
    if (hour24 < 12)
        ampm = 'A';
    else
        ampm = 'P';

    // convert to 12 hour format
    if (hour24 == 0)
        hour12 = 12;  
    else if (hour24 <= 12)
        hour12 = hour24;        // 01-12 stays same
    else
        hour12 = hour24 - 12;   // converts 13-23 to 1-11 PM
}

void output(int hour12, int minute, char ampm){
    cout << "12 hour time: " << hour12 << ":";

    // add space before minute to format if needed
    if (minute < 10) cout << "0";   // if single digit
    cout << minute << " ";
    //add AM or PM
    if (ampm == 'A') cout << "AM";
    else cout << "PM";
}
int main(){
    int hour24, minute, hour12;
    char ampm;

    // Loop until user enter negative num
    while (input(hour24, minute)){
        convertTime(hour24, minute, hour12, ampm);
        output(hour12, minute, ampm);
        cout << "\n";
    }
    return 0;
}