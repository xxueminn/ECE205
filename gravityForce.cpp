#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;

const double G = 6.673e-8; // gravitational constant 

double gravForce(double m1Kg, double m2Kg, double dCm){
    // convert kg to g
    double m1g = m1Kg * 1000.0;
    double m2g = m2Kg * 1000.0;

    // use pow to compute d^2 and return the force
    return (G * m1g * m2g) / pow(dCm, 2.0);
}

int main(){
    char again;

    // do while loop according to again
    do {
        double m1, m2, d; 

        // ask for masses and distance
        cout << "Enter m1 (kg), m2 (kg), distance d (cm): ";
        cin >> m1 >> m2 >> d;
        double F = gravForce(m1, m2, d);

        // force in scientific notation
        cout << scientific << setprecision(6);
        cout << "Gravitational force = " << F << " dynes\n";

        // ask if they want to go again
        cout << "Repeat? (y/n): ";
        cin >> again;
    } while (again == 'y'); // loop continues if y

    return 0; // program ends otw
}