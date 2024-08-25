/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& grid){
    visited[row][col]=1;
    int rdelta[]={-1,0,1,0};
    int cdleta[]={0,1,0,-1};
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+rdelta[i];
        int ncol=col+cdleta[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
            dfs(nrow,ncol,visited,grid);
        }
    }
}

int numEnclaves(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));

    for(int i=0;i<n;i++){
        if(grid[0][i]==1 && !visited[0][i]){
            dfs(0,i,visited,grid);
        }
        if(grid[m-1][i]==1 && !visited[m-1][i]){
            dfs(m-1,i,visited,grid);
        }
    }
    
    for(int i=0;i<m;i++){
        if(grid[i][0]==1 && !visited[i][0]){
            dfs(i,0,visited,grid);
        }

        if(grid[i][n-1]==1 && !visited[i][n-1]){
            dfs(i,n-1,visited,grid);
        }
    }

    int count=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !visited[i][j]){
                count++;
            }
        }
    }
    return count;
}