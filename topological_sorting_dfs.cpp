#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<int> adj[], stack<int>& st){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,st);
        }
    }
    st.push(node);
}

vector<int> topo_sort(vector<int> adj[]){
    int n=adj.length();
    vector<int> visited(n,0);
    vector<int> topo;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,adj,st);
        }
    }

    while(!st.empty()){
        topo.emplace_back(st.top());
        st.pop();
    }
    return topo;
}

