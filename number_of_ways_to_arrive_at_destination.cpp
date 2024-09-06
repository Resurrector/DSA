/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads){
    int mod=int(1e9+7);
    vector<pair<int,int>> adj[n];
    for(auto it:roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    int src=0, dst=n-1;
    vector<int> dist(n,1e9);
    dist[src]=0;
    vector<int> ways(n,0);
    ways[src]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int node=it.second;
        for(auto iter:adj[node]){
            int adj_node=iter.first;
            int adj_dis=iter.second;

            if(dist[adj_node]>(adj_dis+dis)){
                ways[adj_node]=ways[node];
                pq.push({adj_dis+dis,adj_node});
                dist[adj_node]=adj_dis+dis;
            }
            else if(dist[adj_node]==(adj_dis+dis)){
                ways[adj_node]=(ways[adj_node]+ways[node])%mod;
            }
        }
    }
    
    return ways[dst]%mod;
}