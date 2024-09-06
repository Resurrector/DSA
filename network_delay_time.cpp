/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k){
    vector<pair<int,int>> adj[n];
    k=k-1;
    for(auto it:times){
        adj[it[0]-1].push_back({it[1]-1,it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    vector<int> time(n,1e9);
    time[k]=0;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        int dis=it.first;
        int node=it.second;
        for(auto iter:adj[node]){
            int adj_node=iter.first;
            int adj_dis=iter.second;
            if(time[adj_node]>(adj_dis+dis)){
                time[adj_node]=adj_dis+dis;
                pq.push({adj_dis+dis,adj_node});
            }
        }
    }

    sort(time.begin(),time.end());
    int max=time[n-1];
    if(max==1e9) return -1;
    else return max;
}