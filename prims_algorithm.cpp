/*
Prim's Algorithm: Helps find MST(Minimum Spanning Tree) of graph. A graph's minimum spanning tree is a tree with n node and n-1 edges.
A MST has the least sum of edge weights.

Steps:
1. Initialize PQ(min) with (edge_weight, node, parent) and visited array
2. Push (0,0,-1) into PQ
3. While PQ !empty:
    -Pop from PQ
    -Mark node as visited
    -Add edge to MST vector
    -Increment sum
    -Traverse adjacent nodes, push them into queue if not visited
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int spanning_tree_prims(int V, vector<vector<int>> adj[]){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> visited(V,0);
    pq.push({0,0,-1});
    int sum=0;
    vector<pair<int,int>> mst_edges;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int edge_weight=it[0];
        int node=it[1];
        int parent=it[2];
        if(!visited[node]){
            sum+=edge_weight;
            visited[node]=1;
            if(parent!=-1){
                mst_edges.push_back({node,parent});
            }
            for(auto iter:adj[node]){
                int adj_node=iter[0];
                int adj_weight=iter[1];
                if(!visited[adj_node]){
                    pq.push({adj_weight,adj_node,node});
                }
            }
        }
    }
    for(auto it:mst_edges){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return sum;
}

int main(){
    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[3].push_back({4, 9});
    
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    adj[4].push_back({3, 9});

    int sum = spanning_tree_prims(V, adj);
    cout << "Total weight of MST: " << sum << endl;

    return 0;
}