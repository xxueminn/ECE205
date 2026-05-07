#include <iostream>
#include <vector>
using namespace std;

void SieveOfEratosthenes(int n){
    if (n <= 2){
        cout << "There are no prime numbers less than " << n << endl;
        return;
    }

    // start by assuming every number is prime
    vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;

    // cross out multiples of each prime number
    for (int i = 2; i * i < n; i++){
        if (primes[i] == true){
            for (int j = i * i; j < n; j = j + i){
                primes[j] = false;
            }
        }
    }

    cout << "Prime numbers less than " << n << ": " << endl;
    for (int i = 2; i < n; i++){
        if (primes[i] == true){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter a integer: ";
    cin >> n;
    cout << endl;

    SieveOfEratosthenes(n);
    return 0;
}
