#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<int> adj[]){
    int vis[v]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.emplace_back(node);
        for(auto it:adj[node]){
            if(vis[it]==0){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    for(auto it:bfs){
        cout<<it<<"\t";
    }
    return bfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    bfs(n,adj);
}