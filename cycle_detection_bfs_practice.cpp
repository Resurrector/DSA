#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detect(int src, int vis[], vector<int> adj[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        
        for(auto adjacentNode:adj[node]){
            if(!vis[adjacentNode]){
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});
            }
            else if(adjacentNode!=parent){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,vis,adj)==true) return true;
        }
    }
    return false;
}