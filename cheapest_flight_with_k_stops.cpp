/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];
    for(auto it: flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<vector<int>> q;
    q.push({0,src,0});
    vector<int> dis(n,1e9);
    dis[src]=0;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        
        int stops=it[0];
        int node=it[1];
        int cost=it[2];

        if(stops>k) continue;
        for(auto iter:adj[node]){
            int adjNode=iter.first;
            int edge_cost=iter.second;

            if(cost+edge_cost<dis[adjNode] && stops<=k){
                dis[adjNode]=cost+edge_cost;
                q.push({stops+1,adjNode,cost+edge_cost});
            }
        }
    }
    if(dis[dst]==1e9) return -1;
    else return dis[dst];
}