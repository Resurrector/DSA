#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &nums, int n){
    int c=nums.size();
    for(int i=0;i<c;i++){
        if(nums[i]==n) return i;
    }
    return -1;
}

int main(){
    vector<int> nums;
    for(int i=0;i<6;i++){
        nums[i]=i;
    }
    cout<<"Index of 2:"<<linear_search(nums,2);
}