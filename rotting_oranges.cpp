#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int visited[m][n];
    int tm=0;
    queue<pair<pair<int,int>,int>> q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }
        }
    }

    while(!q.empty()){
        int rdelta[]={-1,0,1,0};
        int cdelta[]={0,1,0,-1};
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        q.pop();
        tm=max(tm,t);

        for(int i=0;i<4;i++){
            int nr=r+rdelta[i];
            int nc=c+cdelta[i];
            if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]!=2 && grid[nr][nc]==1){
                q.push({{nr,nc},t+1});
                cout<<q.back().first.first<<" "<<q.back().first.second<<" "<<q.back().second<<endl;
                visited[nr][nc]=2;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]!=2 && grid[i][j]==1) tm=-1;
        }
    }
    
    return tm;
}

int main(){
    vector<vector<int>> grid={{2,0,0,1,2,1,1},{0,1,0,1,1,2,0},{2,2,1,2,1,1,0}};
    cout<<orangesRotting(grid);
}