/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<vector<int>> distanceMatrix(m,vector<int>(n));
    queue<pair<pair<int,int>,int>> q;
    
    int rdelta[]={-1,0,1,0};
    int cdelta[]={0,1,0,-1};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                distanceMatrix[i][j]=0;
                visited[i][j]=1;
            }
        }
    }

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int dis=q.front().second;
        q.pop();
        distanceMatrix[row][col]=dis;

        for(int i=0;i<4;i++){
            int nrow=row+rdelta[i];
            int ncol=col+cdelta[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && visited[nrow][ncol]!=1){
                visited[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }
    return distanceMatrix;
}

int main(){
    vector<vector<int>> mat={{0,0,0},{0,1,0},{0,0,0}};
    updateMatrix(mat);
}