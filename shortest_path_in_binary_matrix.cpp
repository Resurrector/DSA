/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

    All the visited cells of the path are 0.
    All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> visited(n,vector<int>(n,0));
    visited[0][0]=1;
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},0});
    int rdelta[]={-1,-1,0,1,1,1,0,-1};
    int cdelta[]={0,1,1,1,0,-1,-1,-1};
    if(grid[0][0]==1) return -1;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        if(row==n-1 && col==n-1) return dis;
        for(int i=0;i<8;i++){
            int nrow=row+rdelta[i];
            int ncol=col+cdelta[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && visited[nrow][ncol]==0 && grid[nrow][ncol]==0){
                visited[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }
    return -1;
}