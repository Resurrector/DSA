#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int start, int end){
    if((end-start)<=1) return;
    swap(arr[start],arr[end]);
    reverse_array(arr,start+1,end-1);
}

void reverse_array_func(int arr[],int n){
    reverse(arr,arr+n);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    reverse_array(arr,0,5);
    for(auto it:arr){
        cout<<it<<"\t";
    }
    cout<<endl;
    reverse_array_func(arr,6);
    for(auto it:arr){
        cout<<it<<"\t";
    }
}