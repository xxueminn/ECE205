//XueMin Weng
//ECE 205 
//HW 1 Problem 3

#include <iostream>
using namespace std;

int main(){

    //constants
    const double baseRate = 36.75;
    const double overtimeRate = 1.5;
    const double regHours = 40.0;
    const double ssTax = 0.06;
    const double fedTax = 0.15;
    const double stateTax = 0.04;
    const double localTax = 0.01;
    const double unionDues = 20.0;
    const double healthIns = 40.0;

    //inputs
    double hoursWorked;
    int dependents;
    cout << "Enter hours worked this week: ";
    cin >> hoursWorked;
    cout << "Enter number of dependents: ";
    cin >> dependents;

    //gross pay calculation
    double regPay;
    double overtimePay;
    double grossPay;
    if (hoursWorked <= regHours){
        regPay = hoursWorked * baseRate;
        overtimePay = 0.0;
    }
    else {
        regPay = regHours * baseRate;
        overtimePay = (hoursWorked - regHours) * baseRate * overtimeRate;
    }

    grossPay = regPay + overtimePay;

    //withholdings calculation
    double ssDeduction = grossPay * ssTax;
    double fedDeduction = grossPay * fedTax;
    double stateDeduction = grossPay * stateTax;
    double localDeduction = grossPay * localTax;

    double heathDeduction = 0.0;
    if (dependents >= 2){
        heathDeduction = healthIns;
    }

    double totalDeductions = ssDeduction + fedDeduction + stateDeduction + localDeduction + unionDues + heathDeduction;
    double netPay = grossPay - totalDeductions;

    //format to 2 digits after decimal
    cout.setf(ios::fixed); //use fixed point notation
    cout.precision(2);

    //output
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Social Security Tax: $" << ssDeduction << endl;
    cout << "Federal Tax: $" << fedDeduction << endl;
    cout << "State Tax: $" << stateDeduction << endl;
    cout << "Bethlehem Local Tax: $" << localDeduction << endl;
    cout << "Union Dues: $" << unionDues << endl;
    cout << "Health Insurance: $" << heathDeduction << endl;
    cout << "Withholdings: $" << totalDeductions << endl;
    cout << "Net Pay: $" << netPay << endl;

    return 0;

}
