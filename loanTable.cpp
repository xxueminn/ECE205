//XueMin Weng
//ECE 205 
//HW 1 Problem 3

#include <iostream>
using namespace std;

int main(){
    //constants
    const double startBalance = 1000.00;
    const double monthlyRate = 0.015;
    const double monthlyPay = 50.00;

    //variables
    double balance = startBalance;
    double totalInterest = 0.0;
    double totalPaid = 0.0;
    int month = 0;

    //format to 2 decimals
    cout.setf(ios::fixed);
    cout.precision(2);

    //format table header
    cout << "Month#\tInterest\tPrincipal\tBalance\t\tTotalInterest\t\tTotalPaid\n";
    
    while (balance > 0.0){
        month++;

        //calculate interest for the month
        double interest = balance * monthlyRate;
        interest = int(interest * 100.0 + 0.5) / 100.0;

        // last payment may be smaller than 50 but must include interest
        double payment = monthlyPay;
        if (balance + interest < monthlyPay){
            payment = balance + interest;
        }
        payment = int(payment * 100.0 + 0.5) / 100.0;

        //calculate principal paid
        double principal = payment - interest;
        principal = int(principal * 100.0 + 0.5) / 100.0;

        //update balance and totals
        balance = balance - principal;
        balance = int(balance * 100.0 + 0.5) / 100.0;
        totalInterest = totalInterest + interest;
        totalInterest = int(totalInterest * 100.0 + 0.5) / 100.0;
        totalPaid = totalPaid + payment;
        totalPaid = int(totalPaid * 100.0 + 0.5) / 100.0;

        //print rows (tabs for alignment)
        cout << month << "\t"
            //tabs for alignment
            << interest << "\t\t"
            << principal << "\t\t"
            << balance << "\t\t"
            << totalInterest << "\t\t\t"
            << totalPaid << "\n";
    }

    cout << "\nMonths to pay off: " << month << endl;
    cout << "Total interest paid: " << totalInterest << endl;
    cout << "Total amount paid: " << totalPaid << endl;

    return 0;
}