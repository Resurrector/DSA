#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_normal(int i, int n){
    if(i<1) return;
    cout<<i<<"\t";
    print_normal(i-1,n);
}

void print_backtracking(int i, int n){
    if(i>n) return;
    print_backtracking(i+1,n);
    cout<<i<<"\t";
}

int main(){
    int n;
    cout<<"Enter value:";
    cin>>n;
    print_normal(n,n);
    print_backtracking(1,n);
}