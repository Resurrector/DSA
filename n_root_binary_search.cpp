#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n_root(int val, int n){
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(pow(mid,n)==val){
            ans=mid;
            break;
        }
        if(pow(mid,n)<val){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

int main(){
    cout<<n_root(27,3);
}