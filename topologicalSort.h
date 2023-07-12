//
// Created by zhangjiayuan on 23-7-7.
//
#ifndef BOOSTGEOMETRY_TOPOLOGICALSORT_H
#define BOOSTGEOMETRY_TOPOLOGICALSORT_H

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>

using namespace std;
vector<int> topLogicalSort(vector<vector<int>> &adj,vector<int> &inDegree,int n){
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<inDegree.size();i++){
        if(inDegree[i]==0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int top=q.front();
        q.pop();
        ans.push_back(top);
        for(auto sub:adj[top]){
            inDegree[sub]--;
            if(inDegree[sub]==0){
                q.push(sub);
            }
        }
    }
    if(ans.size()==n)
        return ans;
    return vector<int> ();
}

// 207
// 题目描述
//
//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//
//在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程 bi 。
//
//例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
//
//    示例 1：
//
//    输入：numCourses = 2, prerequisites = [[1,0]]
//    输出：true
//    解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
//    示例 2：
//
//    输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//    输出：false
//    解释：总共有 2 门课程。学习课程 1 之前，你需要先完成课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
//
//    提示：
//
//    1 <= numCourses <= 105
//    0 <= prerequisites.length <= 5000
//    prerequisites[i].length == 2
//    0 <= ai, bi < numCourses
//    prerequisites[i] 中的所有课程对 互不相同

class Solution {
public:
    // adjacency list
    bool canFinish1(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> graph(numCourses);

        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            graph[i].push_back(j);
            inDegree[j]++;
        }
        queue<int> q;
        int sum = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            sum++;
            for(int i = 0; i < graph[top].size(); i++){
                int node = graph[top][i];
                inDegree[node]--;
                if(inDegree[node] == 0){
                    q.push(node);
                }
            }
        }
        return sum == numCourses;
    }

    // adjacency matrix
    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>(numCourses,0));

        for(auto edge : prerequisites){
            int i = edge[0];
            int j = edge[1];
            graph[i][j] = 1;
            inDegree[j]++;
        }
        queue<int> q;
        int sum = 0;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            sum++;
            for(int i = 0; i < numCourses; i++){
                if(graph[top][i] == 1){
                    inDegree[i]--;
                    if(inDegree[i] == 0){
                        q.push(i);
                    }
                }
            }
        }
        return sum == numCourses;
    }
};


#endif //BOOSTGEOMETRY_TOPOLOGICALSORT_H
