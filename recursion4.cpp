#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==1) return 1;
    int val=n+sum(n-1);
    return val;
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Sum of all numbers till "<<n<<"="<<sum(n);
}