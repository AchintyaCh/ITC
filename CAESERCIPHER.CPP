// Online C++ compiler to run C++ program online
#include <iostream>
#include<cstring>
using namespace std;
int main() {
    char str[50],estr[50],dstr[50];
    char temp;
    int i,key;
    cout<<"Enter The Message(Max 8 Characers):";
    cin>>str;
    cout<<"Enter Shift value:";
    cin>>key;
    if(strlen(str)!='\0' && strlen(str)<=8)
    {
        if(isalpha(str[0])){
            cout<<"\nYour Message Satisfied Both Conditions\n";
            cout<<"\nEncoded String\n"<<str;
        }
        else{
            cout<<"\nBoth Conditions Failed\n";
        }
    }
    else{
        cout<<"You Have entered empty string or your message exceeds max length\n";
    }
    for(i=0;i<=strlen(str);i++){
        if(isalpha(str[i])){
            temp=(char)tolower(str[i]);
            estr[i] = (str[i]-temp + key)%26 + temp;
        }
    }
    
    cout<<"\nEncoded text by key: "<<estr;
    
    for(i=0;i<strlen(estr);i++){
        dstr[i] = estr[i] - key;
    }
    cout<<"\nDecode Text by key: "<<dstr;

    return 0;
}
