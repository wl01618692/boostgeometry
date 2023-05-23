//
// Created by zhangjiayuan on 23-5-22.
//

#include "geometry.h"

/// lc469
// 给定一个按顺序连接的多边形的顶点，判断该多边形是否为凸多边形。
// 注：
//顶点个数至少为 3 个且不超过 10,000。
//坐标范围为 -10,000 到 10,000。
//你可以假定给定的点形成的多边形均为简单多边形。
//换句话说，保证每个顶点处恰好是两条边的汇合点，并且这些边 互不相交 。
//示例 1：
//[[0,0],[0,1],[1,1],[1,0]]
//输出： True
//解释：

// 示例 2：
//[[0,0],[0,10],[10,10],[10,0],[5,5]]
//输出： False
//解释：
//  AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
//
//  则AB和AC的叉积为：(2*2的行列式) 值为：(x2-x1)*(y3-y1) - (y2-y1)*(x3-x1)
//
//  利用右手法则进行判断：
//  如果AB*AC>0,则三角形ABC是逆时针的
//  如果AB*AC<0,则三角形ABC是顺时针的
//  因为不知道顶点是顺时针输入，还是逆时针输入，所以要记录符号，后面点叉乘如果一样就是凸多边形。

bool isConvex(std::vector<std::vector<int>>& points) {
    long long cur, prev = 0;
    int n = points.size();
    long long x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        x1 = points[(i + 1) % n][0] - points[i][0];
        x2 = points[(i + 2) % n][0] - points[i][0];
        y1 = points[(i + 1) % n][1] - points[i][1];
        y2 = points[(i + 2) % n][1] - points[i][1];
        cur = x1 * y2 - x2 * y1;
        if (cur != 0)
        {
            if (cur * prev < 0)
                return false;
            prev = cur;
        }
    }
    return true;
}
