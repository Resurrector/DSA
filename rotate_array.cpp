#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &num, int k){
    int n=num.size();
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        temp[(i+k)%n]=num[i];
    }
    num.swap(temp);
}

void rotate_o(vector<int> &nums, int k){
    int n=nums.size();
    reverse(nums.begin(),nums.end()-k);
    reverse(nums.end()-k,nums.end());
    reverse(nums.begin(),nums.end());
}


int main(){
    vector<int> num={1,2,3,4,5,6};
    rotate_o(num,3);
    for(auto it:num){
        cout<<it<<"\t";
    }
}