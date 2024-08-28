#include<iostream>
#include<bits/stdc++.h>
using namespace std;

float nth_root(int x, int n){
    float ans;
    float lower=0,upper=x;
    int j=1;
    while(lower<=upper){
        ans=(lower+upper)/2;
        int val=1;
        for(int i=0;i<n;i++){
            val*=ans;
        }
        if(val<x) lower=ans;
        else if(val>x) upper=ans;
        else if(val==x)break;
    }
    return ans;
}

int main(){
    cout<<nth_root(2,2);
}