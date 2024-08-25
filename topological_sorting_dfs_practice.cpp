#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, stack<int>& st, vector<int> adj[]){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,st,adj);
        }
    }
    st.push(node);
}

vector<int> topo_sort(vector<int> adj[]){
    int n=adj.length();
    vector<int> visited(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,st,adj);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.emplace_back(st.top());
        st.pop();
    }
    return topo;
}