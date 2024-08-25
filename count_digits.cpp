#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countdigits_brute(int n){
    int count=0;
    while(n>0){
        count++;
        n/=10;
    }
    return count;
}

int countdigits_optimal(int n){
    int count=(int)log10(n)+1;
    return count;
}

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<"Number of digits="<<countdigits_optimal(n);
}