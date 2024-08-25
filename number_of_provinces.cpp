#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjList[], int visited[]){
    visited[node]=1;
    for(auto it:adjList[node]){
        if(!visited[it]){
            dfs(it,adjList,visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected){
    int n=isConnected.size();
    int visited[n]={0};
    int provinces=0;

    vector<int> adjList[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adjList[i].emplace_back(j);
            }
        }
    }

    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i,adjList,visited);
            provinces++;
        }
    }
    return provinces;
}

int main(){
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<findCircleNum(isConnected);
}