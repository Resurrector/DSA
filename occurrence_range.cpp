#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &nums, int target){
    int n=nums.size();
    int l=0,r=n-1;
    while(l>=r){
        int mid=(l+r)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target){
    vector<int> result(2,-1);
    
    int n=nums.size();
    int t=-1,l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]==target){
            t=mid;
            break;
        }
        else if(nums[mid]<target) l=mid+1;
        else r=mid-1;
    }
    cout<<t<<endl;
    if(t==-1){
        return result;
    }
    else{
        int l=t,r=t;
        while((l-1)>=0 && nums[l-1]==target) l--;
        while((r+1)<n && nums[r+1]==target) r++;
        result[0]=l;
        result[1]=r;
    }
    return result;
}

int main(){
    vector<int> nums={1,2,2,3,4};
    vector<int> result=searchRange(nums,2);
    for(auto it:result){
        cout<<it<<"\t";
    }
}