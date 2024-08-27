/*
Step 1: Create indegree array of nodes
Step 2: Push nodes with indegree 0 into queue
Step 3: Start BFS, reduce indegree of adjacent nodes 
Step 4: If any node with degree 0, push it into the queue
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> topo_sort_kahns(int V, vector<int> adj[]){
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.emplace_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    return topo;
}