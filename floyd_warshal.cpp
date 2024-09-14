/*
Multi source shortest path algorithm, helps detect negative cycles 
Adjacency matrix is used to store the graph
The algorithm does not have an intuition, it brute forces all possible paths to get shortest path possible
All shortest paths are stored in matrix. If there is negative value in the matrix, then the graph contains a negative cycle.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floyd_warshal(vector<pair<int>,int> adj[], int n){
    vector<vector<int>> dis(n,vector<int>(n,1e9));

    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            dis[i][it.first]=it.second;
        }
    }

    for(int i=0;i<n;i++){
        dis[i][i]=0;
    }

    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=min(dis[i][j],dis[i][via]+dis[via][j]);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dis[i][j]<0){
                cout<<"The graph contains a negative cycle.";
            }
        }
    }
    return dis;
}