#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string palindrome(int n){
    int rev=0, temp=n;
    while(temp>0){
        rev=rev*10+temp%10;
        temp/=10;
    }
    if(rev==n) return "true";
    else return "false";
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Number is palindrome: "<<palindrome(n);
}