/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

    Connect: A cell is connected to adjacent cells horizontally or vertically.
    Region: To form a region connect every 'O' cell.
    Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>> &board){
    visited[row][col]=1;
    int rdelta[]={-1,0,1,0};
    int cdelta[]={0,1,0,-1};
    int m=board.size();
    int n=board[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+rdelta[i];
        int ncol=col+cdelta[i];

        if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol]=='O' && !visited[nrow][ncol]){
            dfs(nrow,ncol,visited,board);
        }
    }
}

void solve(vector<vector<char>>& board){
    int m=board.size();
    int n=board[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        if(board[0][i]=='O' && !visited[0][i]){
            dfs(0,i,visited,board);
        }
        if(board[m-1][i]=='O' && !visited[m-1][i]){
            dfs(m-1,i,visited,board);
        }
    }

    for(int i=0;i<m;i++){
        if(board[i][0]=='O' && !visited[i][0]){
            dfs(i,0,visited,board);
        }
        if(board[i][n-1]=='O' && !visited[i][n-1]){
            dfs(i,n-1,visited,board);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                board[i][j]='X';
            }
        }
    }
}