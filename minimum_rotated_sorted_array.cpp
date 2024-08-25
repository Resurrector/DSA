#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min_rotated_array(vector<int> &nums){
    int n=nums.size();
    int l=0,r=n-1;
    int min=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[l]<=nums[mid]){
            if(nums[l]<nums[min]){
                min=l;
                l=mid+1;
            }
        }
        else{
            if(nums[mid]<nums[min]){
                min=mid;
                r=mid-1;
            }
        }
    }
    return min;
}

int main(){
    vector<int> nums={4,5,6,1,2,3};
    cout<<min_rotated_array(nums);
}