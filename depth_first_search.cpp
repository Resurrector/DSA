#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dfs_val;

vector<int> dfs(int node,vector<int> adj[], int vis[]){
    dfs_val.emplace_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int vis[n]={0};
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0,adj,vis);
    for(auto it:dfs_val){
        cout<<it<<"\t";
    }
}