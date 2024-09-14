/*
Used for shortest path in graph with negative edges and helps in detecting negative cycles
Only applicable for directed graphs, can be used for undirected graphs after converting edges

Relax all edges N-1 times sequentially

Steps:
1. Initialize distance array with infinity, source to 0
2. Go through all edges N-1 times with the following iterations:
    if(dist[u]+wt<dist[v]) dist[v]=dist[u]+wt

To detect negative cycles, if the distance array still reduces after N-1 iterations then there exists a negative cycle
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(vector<vector<int>> edges, int src, int n){
    vector<int> dis(n,1e9);
    dis[src]=0;
    for(int i=1;i<n;i++){
        for(auto it:edges){
            int node=it[0];
            int adj_node=it[1];
            int edge_weight=it[2];
            if(dis[node]+edge_weight<dis[adj_node]){
                dis[adj_node]=dis[node]+edge_weight;
            }
        }
    }
    vector<int> dis_dup=dis;
    for(auto it:edges){
        int node=it[0];
        int adj_node=it[1];
        int edge_weight=it[2];
        if(dis[node]!=1e9 && dis_dup[node]+edge_weight<dis_dup[adj_node]){
            dis_dup[adj_node]=dis_dup[node]+edge_weight;
        }
    }
    for(int i=0;i<n;i++){
        if(dis_dup[i]==dis[i]) continue;
        else{
            for(auto it:dis){
                dis=-1;
                break;
            }
        }
    }
    return dis;
}