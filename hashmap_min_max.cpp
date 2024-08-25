#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void hashing(int arr[],int n){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++) map[arr[i]]++;
    int Fmax=0,Fmin=n;
    int Emax=arr[0],Emin=arr[0];
    for(auto it:map){
        if(it.second>Fmax){
            Emax=it.first;
            Fmax=it.second;
        }
        if(it.second<Fmin){
            Emin=it.first;
            Fmin=it.second;
        }
    }
    cout<<"Maximum Frequency Element:"<<Emax<<endl;
    cout<<"Minimum Frequenct Element:"<<Emin;
}

int main(){
    int arr[]={10,10,10,1,2,2,3,3,4,4,5,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    hashing(arr,n);
}