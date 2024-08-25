#include<iostream>
#include<bits/stdc++.h>
using namespace std;



void print(int i, int n){
    if(i==n) return;
    cout<<"Abhilash"<<endl;
    print(i+1,n);
}

int main(){
    int n;
    cout<<"Enter value:";
    cin>>n;
    print(0,n);
}