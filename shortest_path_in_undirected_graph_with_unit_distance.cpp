#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int source, int vertices, vector<int> adj[]){
    queue<pair<int,int>> q;
    vector<int> visited(n,0);
    vector<int> path_length(n,-1);
    visited[source]=1;
    q.push(source,0);
    while(!q.empty()){
        int node=q.front().first;
        int distance=q.front().second;
        path_length[node]=distance;
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it,distance+1);
            }
        }
    }

    return path_length;
}