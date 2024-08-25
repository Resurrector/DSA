#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=2;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]>arr[j-1]){
                break;
            }
            else{
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

void print_array(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}

int main(){
    int arr[]={4,1,69,0,12,54};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    print_array(arr,n);
}