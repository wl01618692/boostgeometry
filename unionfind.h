//
// Created by zhangjiayuan on 23-5-17.
//

#ifndef BOOSTGEOMETRY_UNIONFIND_H
#define BOOSTGEOMETRY_UNIONFIND_H
#include <cstdio>
#include "Util.h"
// https://blog.csdn.net/LWR_Shadow/article/details/124873281
// https://zhuanlan.zhihu.com/p/93647900/
#define MAXN 1000
int fa[MAXN], r_rank[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
         r_rank[i] = 1;
    }
}

int find(int x)
{
    if (x == fa[x]) {
        return x;
    } else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
//    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (x == y) return;

    if (r_rank[x] <=  r_rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (r_rank[x] ==  r_rank[y])
         r_rank[y]++;
}

bool same(int i, int j) {
    return fa[i] == fa[j];
}

// [16,25],[7,9],[3,24],[10,20],[15,24],[2,8],[19,21],[2,15],[13,20],[5,21],[7,11],[6,23],[7,16],[1,8],[17,20],[4,19],[11,22],[5,11],[1,16],[14,20],[1,4],[22,23],[12,20],[15,18],[12,16]]
// [1,2], [2,3], [3,4], [1,4], [1,5]

// [1,2], [1,3], [2,3]
std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
    init(edges.size());
    for (auto& elem: edges) {
        if (!same(elem[0], elem[1])) {
            merge(elem[0], elem[1]);
        } else {
            return elem;
        }
    }
    return {};
}

#endif //BOOSTGEOMETRY_UNIONFIND_H
