#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int node){
        if(node==parent[node]) return node;
        else return findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    ds.unionByRank(3,7);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same";
    }
    else{
        cout<<"Not same";
    }


}