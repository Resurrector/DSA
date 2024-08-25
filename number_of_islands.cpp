/*
Problem Statement: Given a grid of size NxM (N is the number of rows and M is the number of columns in the grid) consisting of '0's (Water) and ‘1's(Land). Find the number of islands.

Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& map){
    visited[row][col]=1;
    int n=map.size();
    int m=map[0].size();
    int rdelta={-1,-1,0,1,1,1,0,-1};
    int cdelta={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<8;i++){
        int nrow=row+rdelta[i];
        int ncol=col+cdelta[i];
        
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && map[nrow][ncol]==1 && !visited[nrow][ncol]){
            dfs(nrow,ncol,visited,map);
        }
    }
}

int number_of_islands(vector<vector<int>> &map){
    int n=map.size();
    int m=map[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==1 && !visited[i][j]){
                count++;
                dfs(i,j,visited,map);
            }
        }
    }
    return count;
}