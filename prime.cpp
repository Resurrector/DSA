#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string prime(int n){
    set<int> s;
    int val=sqrt(n);
    for(int i=1;i<=val;i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
        if(s.size()>2){
            break;
        }
    }
    if(s.size()==2) return "True";
    else return "False";
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Number is prime:"<<prime(n);
}