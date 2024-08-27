/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses,0);

    for(auto it:prerequisites){
        adj[it[0]].emplace_back(it[1]);
        indegree[it[1]]++;
    }

    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0) q.push(i);
    }

    vector<int> order;

    while(!q.empty()){
        int course=q.front();
        q.pop();
        order.emplace_back(course);
        for(auto it:adj[course]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(order.size()==numCourses) return true;
    else return false;
}