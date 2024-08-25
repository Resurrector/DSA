#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int second_largest(int arr[],int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>2) pq.pop();
    }
    
    if(pq.size()<2) return -1;
    int val=pq.top();
    return val;
    
}

int second_smallest(int arr[],int n){
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>2) pq.pop();
    }
    if(pq.size()<2) return -1;
    int val=pq.top();
    return val;
}

int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"2nd Largest Element:"<<second_largest(arr,n)<<endl;
    cout<<"2nd Smallest Element:"<<second_smallest(arr,n)<<endl;
}