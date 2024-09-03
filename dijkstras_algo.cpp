/*
Steps:
1. Initiilize PQ and store pairs as <distance,node>
2. Push source node as <0,src>
3. Pop from pq, check all adjacent nodes. If distance for adjacent nodes is less then push then into pq

Use parent array to get path 

adj has pairs, stored as {node,distance}
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortest_path_dijkstra(vector<vector<int>> adj[], int src, int dest, int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    vector<int> parent(n,-1);
    parent[src]=src;
    pq.push({0,src});
    while(!pq.empty()){
        int node=pq.top().second;
        int dis_src=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int adj_node=it[0];
            int edge_length=it[1];
            if(dis[adj_node]>(dis_src+edge_length)){
                parent[adj_node]=node;
                dis[adj_node]=dis_src+edge_length;
                pq.push({dis[adj_node],adj_node});
            }
        }
    }

    vector<int> path;
    int node=dest;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(src);

    reverse(path.begin(),path.end());
    for(auto it:path){
        cout<<it<<"\t";
    }
    return path;
}


int main(){
    vector<vector<int>> adj[]={{{1,2},{3,1}},{{0,2},{2,4},{4,5}},{{1,4},{3,3},{4,1}},{{0,1},{2,3}},{{1,5},{2,1}}};
    shortest_path_dijkstra(adj,0,4,5);
}
