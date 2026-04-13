#include <iostream>
using namespace std;

class BicycleSpeedometer{
private:
    double distance; // miles
    double time;     // minutes

public:
    // mutators
    void Distance(double d){
        distance = d;
    }

    void Time(double t){
        time = t;
    }

    // compute avg speed in mph
    double avgSpeed(){
        double hours = time / 60.0;
        return distance / hours;
    }
};

int main(){
    BicycleSpeedometer rider;
    double distance, time;

    // user input
    cout << "Enter distance traveled in miles: ";
    cin >> distance;
    cout << "Enter time taken in minutes: ";
    cin >> time;
    // compute and diplay
    rider.Distance(distance);
    rider.Time(time);
    cout << "Average speed: " << rider.avgSpeed() << " mph" << endl;

    return 0;
}