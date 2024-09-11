/*
Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.

Note: We can either take the item as a whole or break it into smaller units.
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool comp(pair<int, int> p1, pair<int, int> p2) {
    double val1 = (double)p1.first / p1.second;
    double val2 = (double)p2.first / p2.second;
    return val1 > val2;  
}

int fractionalKnapsack(vector<pair<int, int>> items, int weight) {
    sort(items.begin(), items.end(), comp);

    double res = 0;  
    int rem = weight;  

    for (auto it : items) {
        if (it.second <= rem) {  
            res += it.first;  
            rem -= it.second; 
        } else {
            double fraction = (double)rem / it.second;  
            res += it.first * fraction;
            break;  
        }
    }
    return res; 
}

int main() {
    vector<pair<int, int>> items = {{100, 20}, {60, 10}, {120, 30}};
    int maxWeight = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(items, maxWeight) << endl;
    return 0;
}
