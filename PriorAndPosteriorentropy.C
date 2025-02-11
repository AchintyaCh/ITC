// Online C++ compiler to run C++ program online
#include <iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main() {
    // Write C++ code here
    float src[2] = {0.4,0.6};
    float prob[2][2];
    float Pxy[4];
    float priorEntropy[2];
    float Hxy = 0.0;
    int i,j,n = 0;
    double P_y[2];
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
    
    for(i=0;i<4;i++){
        if(i%2==0){
            Hxy = Pxy[i] * log2(1/Pxy[i]);
        }
    }
    cout<<"\nPosterior Entropy: "<<Hxy;
    

    return 0;
}
