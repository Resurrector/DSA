#include<iostream>
#include<bit/stdc++.h>
using namespace std;

void zeroes_to_end_auxilliary(vector<int> &nums){
    int n=nums.size();
    vector<int> temp(n,0);
    int c=0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0) temp[c++]=nums[i];
    }
    nums.swap(temp);
}

void zeroes_to_end_rotation(vector<int> &nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            int z=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]==0)z++;
                else break;
            }
            int c=0
            for(int j=i+z;j<n;j++){
                if(nums[j]!=0)c++;
                else break;
            }
            if(c==0) break;
            reverse(nums.begin()+i+z,nums.begin()+i+z+c);
            reverse(nums.begin()+i,nums.begin()+i+z+c);
            i=i+c;
        }
    }
}