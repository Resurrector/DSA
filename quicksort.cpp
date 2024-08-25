#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void quicksort(vect<int> &nums, int l, int r){
    if(r-l<=1) return;
    int pivot=nums[l];
    int lower=l,upper=l;
    for(int i=l;i<=r;i++){
        if(nums[i]<pivot) lower++;
        if(nums[i]>pivot)
    }
}