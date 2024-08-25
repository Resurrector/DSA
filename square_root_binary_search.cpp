#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int square_root(int n){
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if((mid*mid)<=n){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return r;
}

int main(){
    cout<<square_root(120);
}