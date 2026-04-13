#include <iostream>
using namespace std;

class PrimeNumber{
private:
    int prime;
    // check if prime
    bool isPrime(int n){
        if (n < 2)
            return false;

        for (int i = 2; i < n; i++){
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    // default constr
    PrimeNumber(){
        prime = 1;
    }

    // constructor with parameter
    PrimeNumber(int p){
        prime = p;
    }

    // accessor
    int getPrime(){
        return prime;
    }

    // prefix ++
    PrimeNumber operator++(){
        int num = prime + 1;

        while (!isPrime(num)){
            num++;
        }
        prime = num;
        return PrimeNumber(prime);
    }

    // postfix ++
    PrimeNumber operator++(int){
        PrimeNumber result = *this;
        int num = prime + 1;

        while (!isPrime(num)){
            num++;
        }
        prime = num;
        return result;
    }

    // prefix --
    PrimeNumber operator--(){
        int num = prime - 1;

        while (num > 1 && !isPrime(num)){
            num--;
        }

        if (num < 2)
            prime = 1;
        else
            prime = num;

        return PrimeNumber(prime);
    }

    // postfix --
    PrimeNumber operator--(int){
        PrimeNumber result = *this;
        int num = prime - 1;

        while (num > 1 && !isPrime(num)){
            num--;
        }

        if (num < 2)
            prime = 1;
        else
            prime = num;

        return result;
    }
};

int main(){
    int num;
    cout << "Enter a prime number: ";
    cin >> num;
    PrimeNumber p2(num);        // starts at user input

    ++p2;
    cout << "prefix ++ : " << p2.getPrime() << endl;

    p2++;
    cout << "postfix ++ : " << p2.getPrime() << endl;

    --p2;
    cout << "prefix -- : " << p2.getPrime() << endl;

    p2--;
    cout << "postfix -- : " << p2.getPrime() << endl;

    return 0;
}