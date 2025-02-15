// Online C++ compiler to run C++ program online
#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main() {
    // Write C++ code here
    float src[2] = {0.7, 0.3}; // Prior probabilities P(X=0) and P(X=1)
    float prob[2][2];  // Conditional probabilities P(Y|X)
    float Pxy[4]; // Posterior probabilities P(X|Y)
    float priorEntropy[2]; // Prior entropy H(X)
    float Hxy = 0.0; // Posterior entropy H(X|Y)
    float Hx = 0.0;  // Prior entropy H(X)
    float H_channel = 0.0; // Entropy of the channel H(X|Y)
    int i, j, n = 0;
    double P_y[2]; // Marginal probability P(Y=j)
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            cout<<"Enter Probability for:"<<i<<"and for:"<<j<<endl;
            cin>>prob[i][j];
        }
    }
    P_y[0] = src[0]*prob[0][0] + src[1] * prob[1][0];
    P_y[1] = src[1]*prob[1][1] + src[0] * prob[0][1];
    cout << "P(Y=0) : "<<P_y[0];
    cout << "\nP(Y=1) : "<<P_y[1];
    
    //Priori Entropy
    priorEntropy[0] = src[0] * log2(1/src[0]);
    priorEntropy[1] = src[1] * log2(1/src[1]);
    cout<<"\nPriori Entropy for H(X=0):"<<priorEntropy[0];
    cout<<"\nPriori Entropy for H(X=1):"<<priorEntropy[1];
    cout<<"\nTotat Priori Entropy H(X=i):"<<(priorEntropy[0]+priorEntropy[1]);
    
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(n<4){
            Pxy[n] = (src[i] * prob[i][j])/P_y[j];
            cout<<"\nPosterior Probability for:"<<i<<" and for:"<<j<<" is: "<<Pxy[n];
            n+=1;
            
            }
        }
    }

    // Posterior Entropy
    for(i=0;i<4;i++){
            Hxy = Hxy + Pxy[i] * log2(1/Pxy[i]);
    }
    cout<<"\nPosterior Entropy: "<<Hxy;
    
    for(j = 0; j < 2; j++) {
        for(i = 0; i < 2; i++) {
            if (Pxy[n] > 0) { // To prevent log(0)
                H_channel += P_y[j] * (Pxy[n] * log2(1 / Pxy[n]));
            }
            n++;
        }
    }

    cout << "\nEntropy of the Channel H(X|Y): " << H_channel;
    return 0;
}
