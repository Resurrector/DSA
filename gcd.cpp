#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    while(a%b!=0){
        int temp=a%b;
        b=a;
        a=temp;
    }
    return b;
}

int main(){
    int a,b;
    cout<<"Enter first value:";
    cin>>a;
    cout<<"Enter second value:";
    cin>>b;
    cout<<"GCD of values:"<<gcd(a,b);
}