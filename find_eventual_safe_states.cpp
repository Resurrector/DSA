/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Approach: Exclude all nodes in cycle or leading to cycle using topo sort. Since dealing with outdegrees, first reverse graph to apply topo sort
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> adj[n];
    vector<int> indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:graph[i]){
            adj[it].emplace_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> topo;

    while(!q.empty){
        int node=q.front();
        q.pop();
        topo.emplace_back(node);

        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    sort(topo.begin(),topo.end());
    return topo;
}