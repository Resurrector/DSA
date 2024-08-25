#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &nums, int target){
    int n=nums.size();
    int l=0,r=n-1,lb=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]>=target){
            lb=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return lb;
}

int main(){
    vector<int> nums={3,5,8,15,19};
    cout<<lower_bound(nums,9);
}