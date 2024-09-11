/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills){
    int n5=0,n10=0,n20=0;
    for(auto it:bills){
        if(it==5){
            n5++;
            continue;
        }
        else if(it==10){
            if(n5>0){
                n5--;
                n10++;
                continue;
            }
            else return false;
        }
        else if(it==20){
            if(n5>0 && n10>0){
                n5--;
                n10--;
                n20++;
                continue;
            }
            else if(n5>=3){
                n5-=3;
                n20++;
                continue;
            }
            else return false;
        }
    }
    return true;
}