#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> &nums, int target){
    int n=nums.size();
    int l=0,r=n-1,ub=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]>target){
            ub=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ub;
}

int main(){
    vector<int> nums={3,5,8,9,15,19};
    cout<<upper_bound(nums,9);
}