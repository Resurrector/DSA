#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void hashing(int arr[],int n){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    for(auto it:map){
        cout<<it.first<<"\t"<<it.second<<endl;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    hashing(arr,n);
}