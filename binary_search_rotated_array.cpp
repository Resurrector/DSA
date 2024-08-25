#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search_rotated_array(vector<int> &nums, int target){
    int n=nums.size();
    int l=0, r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target) return mid;
        if(nums[l]<nums[mid]){
            if(nums[l]<target && target<nums[mid]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        else{
            if(nums[mid]<target && target<nums[r]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums={1};
    cout<<binary_search_rotated_array(nums,1);
}