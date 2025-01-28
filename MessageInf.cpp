// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include<cstring>
using namespace std;
int main(){
    char str[5]={'I','N','D','A','B'};
    float sum=0.0,inf=0.0;
    char msg[50];
    int i=0,j=0;
    float prob[5]={0.25,0.1,0.3,0.15,0.25};
    cout<<"Enter Your Message"<<endl;
    cin>>msg;
    for(i=0;i<=strlen(msg);i++){
        for(j=0;j<=strlen(str);j++){
            if(str[i] == msg[j]){
                inf = log2(1/prob[j]);
                sum = sum + inf;
            }
        }
    } 
    cout<<"Total Info is:"<<sum;
    return 0;
    
}
