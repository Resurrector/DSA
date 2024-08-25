#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void longest_subarray(int arr[],int n, int k){
    vector<int> sum_index;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        sum_index.emplace_back(sum);
    }
    for(auto it:sum_index){
        cout<<it<<"\t";
    }
    /*
    int length=0;   
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if((sum_index[j]-sum_index[i])==k){
                length=j-i;
                break;
            }
            if((sum_index[j]-sum_index[i])<k) break;
        }
        if(length>(n-1-i)) break;
    }
    return length;
    */
}

int main(){
    int arr[]={2,3,4,5,6};
    longest_subarray(arr,5,9);
}