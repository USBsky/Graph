//
// Created by Joel Young on 2019/12/28.
//

#ifndef GRAPH_MST_H
#define GRAPH_MST_H
#define For(i, l, r) for (int i = l; i < r; i++)
#define req(i, l, r) for (int i = l; i <= r; i++)
#define rre(i, r, l) for (int i = r; i >= l; i--)
#define mem(a, n) memset(a, n, sizeof(a))
#define maxN 0xffff
#define inf 0x3f3f3f3f

#include <cstdio>
#include <cstring>

class MST {
private:
    int G[maxN][maxN], dis[maxN], par[maxN], vis[maxN];
public:
    void prim(int cnt)
    {
        mem(dis, inf);
        mem(par, 0);
        mem(vis, 0);
        int p = 0;
        vis[0] = 1;
        For(i, 0, cnt)
        {
            dis[i] = G[0][i];
        }
        For(i, 0, cnt - 1)
        {
            int mrk = inf, point;
            For(j, 0, cnt)
            {
                if (G[p][j] < mrk)
                {
                    mrk = G[p][j];
                    point = j;
                }
                vis[point] = 1;
                p = point;
            }
        }
    }
};


#endif //GRAPH_MST_H
