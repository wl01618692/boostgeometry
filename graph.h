//
// Created by zhangjiayuan on 23-7-17.
//
#ifndef BOOSTGEOMETRY_GRAPH_H
#define BOOSTGEOMETRY_GRAPH_H

#include <queue>
#include "Util.h"

// 200. Number of Islands
//
//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//Output: 1
//
//Example 2:
//
//Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//Output: 3

void DFS(std::vector<std::vector<char>>& grid, int i, int j) {
    if (i == -1 || j == -1 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == '0') return;
    grid[i][j] = '0';
    DFS(grid, i + 1, j);
    DFS(grid, i, j + 1);
}


int numIslandsDFS(std::vector<std::vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                ++count;
                DFS(grid, i, j);
            }
        }
    }
    return count;
}

int numIslandsBFS(std::vector<std::vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == '1') {
                ++count;
                std::queue<std::pair<int, int>> q;
                grid[i][j] = '0';
                q.push({i, j});
                while (!q.empty()) {
                    std::pair<int, int> val = q.front();
                    int k = std::get<0>(val);
                    int w = std::get<1>(val);
                    q.pop();
                    grid[std::get<0>(val)][std::get<1>(val)] = '0';
                    if (k + 1 <= grid.size() - 1 && grid[k + 1][w] == '1') q.push({k + 1, w});
                    if (w + 1 <= grid[k].size() - 1 && grid[k][w + 1] == '1') q.push({k, w + 1});
                }
            }
        }
    }
    return count;
}

//class UnionFind {
//public:
//    UnionFind(std::vector<std::vector<char>>& grid) {
//        count = 0;
//        int m = grid.size();
//        int n = grid[0].size();
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (grid[i][j] == '1') {
//                    parent.push_back(i * n + j);
//                    ++count;
//                }
//                else parent.push_back(-1);
//                rank.push_back(0);
//            }
//        }
//    }
//
//    int find(int i) { // path compression
//        if (parent[i] != i) parent[i] = find(parent[i]);
//        return parent[i];
//    }
//
//    void Union(int x, int y) { // union with rank
//        int rootx = find(x);
//        int rooty = find(y);
//        if (rootx != rooty) {
//            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
//            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
//            else {
//                parent[rooty] = rootx; rank[rootx] += 1;
//            }
//            --count;
//        }
//    }
//
//    int getCount() const {
//        return count;
//    }
//
//private:
//    std::vector<int> parent;
//    std::vector<int> rank;
//    int count; // # of connected components
//};
//
//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int nr = grid.size();
//        if (!nr) return 0;
//        int nc = grid[0].size();
//
//        UnionFind uf (grid);
//        int num_islands = 0;
//        for (int r = 0; r < nr; ++r) {
//            for (int c = 0; c < nc; ++c) {
//                if (grid[r][c] == '1') {
//                    grid[r][c] = '0';
//                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.Union(r * nc + c, (r-1) * nc + c);
//                    if (r + 1 < nr && grid[r+1][c] == '1') uf.Union(r * nc + c, (r+1) * nc + c);
//                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.Union(r * nc + c, r * nc + c - 1);
//                    if (c + 1 < nc && grid[r][c+1] == '1') uf.Union(r * nc + c, r * nc + c + 1);
//                }
//            }
//        }
//
//        return uf.getCount();
//    }
//};


int numIslandsUnionFind(std::vector<std::vector<char>>& grid) {

}


#endif //BOOSTGEOMETRY_GRAPH_H
