#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool detect(int src, int parent, int vis[], vector<int> adj[]){
    vis[src]=1;
    for(auto adjacentNode: adj[src]){
        if(!vis[adjacentNode]){
            vis[adjacentNode]=1;
            return detect(adjacentNode,src,vis,adj);
        }
        else if(adjacentNode!=parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V]={0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(i,-1,vis,adj)==true) return true;
        }
    }
    return false;
}