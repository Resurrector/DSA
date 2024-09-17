#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent, size_component;

public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        size_component.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltimateParent(int node){
        if(parent[node]==node) return node;
        else{
            return parent[node]=findUltimateParent(parent[node]);
        }
    }

    void unionBySize(int u, int v){
        int ulp_u=findUltimateParent(u);
        int ulp_v=findUltimateParent(v);
        if(ulp_u==ulp_v) return;
        if(size_component[ulp_u]<size_component[ulp_v]){
            parent[ulp_u]=ulp_v;
            size_component[ulp_v]+=size_component[ulp_u];
        }
        else if(size_component[ulp_u]>size_component[ulp_v]){
            parent[ulp_v]=ulp_u;
            size_component[ulp_u]+=size_component[ulp_v];            
        }
        else{
            parent[ulp_v]=ulp_u;
            size_component[ulp_u]+=size_component[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    ds.unionBySize(3,7);
    if(ds.findUltimateParent(3)==ds.findUltimateParent(7)){
        cout<<"Same";
    }
    else{
        cout<<"Not same";
    }


}