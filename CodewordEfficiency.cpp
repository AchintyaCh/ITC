#include <iostream>
#include <cmath>
using namespace std;

void main() {
    int n, p = 0, k;
    float r;
    cout << "Enter Number of Data Bits (k): ";
    cin >> k;
    
    while (pow(2, p) < p + k + 1) {
        p++;
    }
    n = p + k;
    r = (float)k / n;
    cout << "\nThe Parity Bits Length (P bits): " << p;
    cout << "\nThe CodeWord Length (n bits): " << n;
    cout << "\nThe Efficiency of the codeword (R) in %: " << r * 100 << "%";
    
}
