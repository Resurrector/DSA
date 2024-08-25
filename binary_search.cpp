#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search_recursive(int arr[],int l, int r, int val){
    if(l>r) return -1;
    int mid=(l+r)/2;
    if(arr[mid]==val) return mid;
    else if(arr[mid]>val) binary_search(arr,l,mid-1,val);
    binary_search(arr,mid+1,r,val);
}

int binary_search_iterative(vector<int> &nums, int target){
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
    
}

int main(){
    int arr[]={1,2,3,4,5,6};
    cout<<binary_search(arr,0,5,10);
}