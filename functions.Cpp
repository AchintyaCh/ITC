// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int sum(int a,int b){
    return a+b;
}
int sum(int a,int b,int c){
    return a+b+c;
}
float sum(float a,float b){
    return a+b;
}
int main() {
    float ans = 0.0;
    float floatA,floatB;
    int a,b,c;
    int sum2 = 0;
    int sum3 = 0;
    cout<<"Enter 3 integers"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    cout<<"Enter 2 Floats:"<<endl;
    cin>>floatA;
    cin>>floatB;
    sum2 = sum(a,b);
    sum3 = sum(a,b,c);
    ans = sum(floatA,floatB);
    cout<<"\n3 Integer sum = "<<sum3;
    cout<<"\n2 Integer sum = "<<sum2;
    cout<<"\n2 Float sum = "<<ans;
}
