#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>& visited, vector<int>& path_visited, vector<int> adj[]){
    visted[node]=1;
    path_visited[node]=1;

    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,visited,path_visited,adj)==true) return true;
        }
        else if(path_visited[it]){
            return true;
        }
    }
    path_visited[node]=0;
    return false;
}

bool isCycle(vector<int> adj[]){
    int n=adj.length();
    vector<int> visted(n,0);
    vector<int> path_visited(n,0);

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,visited,path_visited,adj)==true) return true;
        }
    }
    return false;
}