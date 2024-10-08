/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string>word_list(wordList.begin(),wordList.end());
    queue<pair<string,int>> q;
    q.push({beginWord,1});
    word_list.erase(beginWord);
    while(!q.empty()){
        string word=q.front().first;
        int step=q.front().second;
        q.pop();

        if(word==endWord) return step;

        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char j='a';j<='z';j++){
                word[i]=j;
                if(word_list.find(word)!=word_list.end()){
                    q.push({word,step+1});
                    word_list.erase(word);
                }
            }
            word[i]=original;
        }
    }
    return 0;
}