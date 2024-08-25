#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(int arr[],int n){
    int k=0;
    for(int i=1;i<n;i++){
        if(arr[k]!=arr[i]){
            arr[++k]=arr[i];
        }
    }
    return k;
}

int main(){
    int arr[]={1,1,2,2,3,4,5,6,6,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=remove_duplicates(arr,n);
    for(int i=0;i<=k;i++){
        cout<<arr[i]<<"\t";
    }
}