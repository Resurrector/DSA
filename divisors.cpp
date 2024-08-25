#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void divisors_brute(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0) cout<<i<<"\t";
    }
}

void divisors_optimal(int n){
    set<int> s;
    int val=sqrt(n);
    for(int i=1;i<=val;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    for(auto it:s){
        cout<<it<<"\t";
    }
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Divisors:";
    divisors_optimal(n);
}