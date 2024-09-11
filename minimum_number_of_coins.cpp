/*
Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int number_of_coins(int val){
    vector<int> v={1,2,5,10,20,50,100,500,1000};
    queue<pair<int,int>> q;
    q.push({0,val});
    while(!q.empty()){
        int coins_curr=q.front().first;
        int rval=q.front().second;
        q.pop();
        if(rval==0) return coins_curr;

        for(auto it:v){
            if(it<rval){
                q.push({coins_curr+1,rval-it});
            }
        }
    }
    return -1;
}