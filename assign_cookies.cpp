/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s){
    int children=g.size();
    int cookies=s.size();
    int res=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    if(cookies==0) return res;
    int i=0,k=0;
    while(i<cookies && k<children){
        if(g[k]<=s[i]){
            res++;
            i++;
            k++
        }
        else i++;
    }
    return res;
}