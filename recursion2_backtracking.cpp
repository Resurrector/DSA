#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    if(i<1) return;
    print(i-1,n);
    cout<<i<<"\t";
}

int main(){
    int n;
    cout<<"Enter value:";
    cin>>n;
    print(n,n);
}