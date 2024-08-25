#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sorted_array(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i+1]>arr[i]) continue;
        else return false;
    }
    return true;
}

int main(){
    int arr[]={1,3,2,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Array is sorted:";
    sorted_array(arr,n)?cout<<"True":cout<<"False";
}