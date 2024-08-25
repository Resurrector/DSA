#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sorted_union(int arr1[], int n1, int arr2[], int n2){
    set<int> s;
    for(int i=0;i<n1;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(arr2[i]);
    }
    for(auto it:s){
        cout<<it<<"\t";
    }
}

int main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={3,4,5,6,7};
    sorted_union(arr1,5,arr2,5);
}