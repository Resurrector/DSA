#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int reverse_number(int n){
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Reverse of number:"<<reverse_number(n);
}