#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> floor_and_ceiling(vector<int> &nums, int target){
    int n=nums.size();
    int l=0,r=n-1,floor=-1,ceiling=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]>=target){
            ceiling=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    l=0;
    r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(nums[mid]<=target){
            floor=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    vector<int> values;
    values.emplace_back(nums[floor]);
    values.emplace_back(nums[ceiling]);
    return values;
}

int main(){
    vector<int> nums={3,4,4,7,8,10};
    vector<int> values=floor_and_ceiling(nums,5);
    for(auto it:values){
        cout<<it<<"\t";
    }
}