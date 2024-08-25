#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largest_element(int arr[],int l, int h){
    if(l==h) return arr[l];
    if(arr[l]>largest_element(arr,l+1,h)) return arr[l];
    else return largest_element(arr,l+1,h);
}

int main(){
    int arr[]={1,23,4,6,19,0,100};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Largest element of array:"<<largest_element(arr,0,n-1);
}