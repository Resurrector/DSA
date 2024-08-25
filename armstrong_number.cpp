#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string armstrong(int n){
    int val=0, temp=n;
    while(temp>0){
        val+=pow(temp%10,3);
        temp/=10;
    }
    if(val==n) return "True";
    else return "False";
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Number is Armstrong number:"<<armstrong(n);
}