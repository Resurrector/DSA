#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color){
    int rdelta[]={-1,0,1,0};
    int cdelta[]={0,1,0,-1};
    int old_color=image[sr][sc];
    int m=image.size();
    int n=image[0].size();
    if(image[sr][sc]==color) return image;
    image[sr][sc]=color;
    for(int i=0;i<4;i++){
        int nsr=sr+rdelta[i];
        int nsc=sc+cdelta[i];
        if(nsr>=0 && nsr<m && nsc>=0 && nsc<=n && old_color==image[nsr][nsc]){
            floodFill(image,nsr,nsc,color);
        }
    }
    return image;
}