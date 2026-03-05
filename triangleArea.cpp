#include <iostream>
#include <cmath>
using namespace std;

void triangleInfo(double a, double b, double c, double &area, double &perimeter){
    // initial and efault outputs for an illegal triangle
    area = 0.0;
    perimeter = 0.0;

    // check for legal triangle, return if not valid
    if (a <= 0 || b <= 0 || c <= 0) return; 
    if (a + b <= c || a + c <= b || b + c <= a) return;

    perimeter = a + b + c;
    double s = perimeter / 2.0;
    area = sqrt(s * (s - a) * (s - b) * (s - c));   // formula
}

int main(){
    double a, b, c, area, perimeter;   

    cout << "Enter three side lengths: ";
    cin >> a >> b >> c;

    triangleInfo(a, b, c, area, perimeter);

    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;

    return 0;
}