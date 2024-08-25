#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low, int mid, int high){
    vector<int> temp;
    int left=low,right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.emplace_back(arr[left++]);
        }
        else temp.emplace_back(arr[right++]);
    }

    while(left<=mid){
        temp.emplace_back(arr[left++]);
    }
    
    while(right<=high){
        temp.emplace_back(arr[right++]);
    }

    

    for(int i=low;i<=high;i++){
       arr[i]=temp[i-low]; 
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    vector<int> arr={1,24,5,8,1,9,0};
    int n=arr.size();
    merge_sort(arr,0,n-1);
    for(auto it:arr){
        cout<<it<<"\t";
    }
}