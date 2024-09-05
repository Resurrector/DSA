/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights){
    int n=heights.size();
    int m=heights[0].size()
    vector<vector<int>> visited(n,(vector<int>(m,1e9)));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    visited[0][0]=0;
    int rdelta[]={-1,0,1,0};
    int cdelta[]={0,1,0,-1};
    while(!pq.empty()){
        int effort=pq.top().first;
        int row=pq.top().second.first;
        int col=pq.top().second.second;
        pq.pop();
        if(row==n-1 && col==m-1) return effort;

        for(int i=0;i<4;i++){
            int nrow=row+rdelta[i];
            int ncol=col+cdelta[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int diff=abs(heights[nrow][ncol]-heights[row][col]);
                int new_effort=max(diff,effort);
                if(new_effort<visited[nrow][ncol]){
                    visited[nrow][ncol]=new_effort;
                    pq.push({new_effort,{nrow,ncol}});
                }
            }
        }
    }
    return -1;
}