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

class MST
{
private:
    int Grape[maxN][maxN], d[maxN], p[maxN], n;
    bool vis[maxN];
public:
    void Prim(int n)
    {
        mem(d, inf);//初始距离为无穷
        mem(d, -1);
        d[1] = 0;
        For(k, 0, n - 1)
        {
            int cnt = inf, u;//寻找T 与V - T之间的最短距离
            for (int i = 1; i <= n; ++i)
            {
                if (!vis[i] && d[i] < cnt)
                {
                    cnt = d[i];
                    u = i;
                }
            }
            if (cnt == inf)
                break;//已经完成
            vis[u] = true;//访问u节点
            //更新d
            for (int v = 1; v <= n; ++v)
            {
                if (!vis[v] && d[v] > Grape[u][v] && Grape[u][v] != -1)//如果节点未被访问且更新且存在边
                {
                    d[v] = Grape[u][v];
                    p[v] = u;
                }
            }
    }
};


;#endif //GRAPH_MST_H
