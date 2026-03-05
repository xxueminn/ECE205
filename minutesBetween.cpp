#include <iostream>
using namespace std;

int minutesBetween(int start, int end){
    // split start time into hours and minutes
    int startHour = start / 100;
    int startMin  = start % 100;
    // split end time into hours and minutes
    int endHour = end / 100;
    int endMin  = end % 100;

    // convert both times to minutes
    int startTotal = startHour * 60 + startMin;
    int endTotal   = endHour * 60 + endMin;

    // if end is earlier than start, it is the next day
    if (endTotal < startTotal){
        endTotal += 24 * 60;            // add one full day of minutes
    }
    return endTotal - startTotal;       //difference
}

int main(){
    int start, end;

    cout << "Enter start time: ";
    cin >> start;
    cout << "Enter end time: ";
    cin >> end;
    int diff = minutesBetween(start, end);
    cout << "Minutes between: " << diff << endl;

    return 0;
}