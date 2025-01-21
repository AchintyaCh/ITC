// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main() {
    int src[10],sen,i,n;
    float j,sum=0.0;
    double entropy;
    cout<<"Enter The Number of Sources:";
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<"\nEnter the Value for source:"<<"["<<i<<"]==";
        cin>>src[i];
        j=(float)1/src[i];
        entropy = j*log2(src[i]);
        cout<<"\nEntropy for ["<<src[i]<<"]==>"<<entropy;
        sum=sum+entropy;
    }
    cout<<"\nTotal entropy for DMS: "<<sum;
    return 0;
}
