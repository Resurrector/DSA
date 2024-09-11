/*
Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.
Your task is to find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimum_multiplications(int start, int end, vector<int> arr, int n){
    int mod=int(1e5);
    queue<pair<int,int>> q;
    q.push({0})
}