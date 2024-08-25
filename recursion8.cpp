#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> series;
    int n;
    cout<<"Enter number of terms in Fibonacci series:";
    cin>>n;
    for(int i=0;i<n;i++){
        if(i==0){
            series.emplace_back(0);
        }
        else if(i==1){
            series.emplace_back(1);
        }
        else series.emplace_back(series[i-1]+series[i-2]);
        cout<<series[i]<<"\t";
    }
}