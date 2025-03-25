#include <iostream>
#include <cmath>
using namespace std;

int main() {
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
    for (int i = 1; i <= n; i++) {
        bool isParity = false;
        for (int j = 0; j < p; j++) {
            if (i == pow(2, j)) {
                cout << "\nParity Position in Codeword : " << i << endl;
                isParity = true;
                break;
            }
        }
        if (!isParity) {
            cout << "Data Bit Position : " << i << endl;
        }
    }
    int msg[k]; // Size of message
    int codeword[n + 1]; // total size of codeword
    for (int i = 0; i < k; i++) {
        cout << "\nEnter the " << k << " at the position "<<i<<" th bit message in 0 or 1: ";
        cin >> msg[i];
    }
    cout << "\nThe message you have entered is: ";
    for (int i = 0; i < k; i++) {
        cout << msg[i];
    }
    // Initialize codeword with 0s
    for (int i = 1; i <= n; i++) 
    {
        codeword[i] = 0;
    }
    // Place message bits in codeword
    int msgIndex = 0;
    for (int i = 1; i <= n; i++) {
        bool isParity = false;
        for (int j = 0; j < p; j++) {
            if (i == pow(2, j)) {
                isParity = true;
                break;
            }
        }
        if (!isParity) {
            codeword[i] = msg[msgIndex];
            msgIndex++;
        }
    }
    // Calculate parity bits
    for (int i = 0; i < p; i++) {
        int parityPos = pow(2, i);
        int parity = 0;
        for (int j = 1; j <= n; j++) {
            if ((j & parityPos) != 0) {
                parity ^= codeword[j];
            }
        }
        codeword[parityPos] = parity;
    }
    // Print the Hamming codeword
    cout << "\nThe Hamming codeword is: ";
    for (int i = 1; i <= n; i++) {
        cout << codeword[i];
    }
    return 0;
}
