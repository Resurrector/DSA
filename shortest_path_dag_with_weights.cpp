/*
Steps:
    1. Perform a topological sort of the graph using dfs
    2. Take nodes out of stack and relax edges
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<pair<int,int>> adj[], vector<int> visited, stack<int> st){
    visited[node]=1;
    for(auto it:adj[node]){
        int v=it.first;
        if(!visited[v]){
            dfs(v,adj,visited,st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<int> edges[], int source){
    vector<pair<int,int>> adj[N];
    for(int i=0;i<M;i++){
        int u=adj[i][0];
        int v=adj[i][1];
        int wt=adj[i][2];
        adj[u].push_back({v,wt});
    }

    vector<int> visited(N,0);
    stack<int> st;
    for(int i=0;i<N;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    vector<int> distance(N,1e9);
    dist[source]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();

        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
}