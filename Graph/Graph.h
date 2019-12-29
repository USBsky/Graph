//
// Created by Joel Young on 2019/12/28.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#define maxN 0xffff
#define For(i, l, r) for (int i = l; i < r; i++)
#define req(i, l, r) for (int i = l; i <= r; i++)
#define rre(i, r, l) for (int i = r; i >= l; i--)
#define mem(a, n) memset(a, n, sizeof(a))

#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>

using namespace std;

class Graph
{
private:
    class ArcNode
    {
    public:
        int num, weight;
        struct ArcNode *nextArc;

        ArcNode(int num, int weight) : num(num), weight(weight)
        {
        }
    };

    class Vnode
    {
    public:
        int cnt = 0, num;
        ArcNode *firstArc = nullptr;
    };

    Vnode *graph;
    int vis[maxN];
    int vexNum, arcNum;
public:
    Graph(const int vexNum, const int arcNum) : vexNum(vexNum), arcNum(arcNum)
    {
        graph = (Vnode *) malloc(sizeof(Vnode) * (vexNum + 5) );
        int tot = 0;
        For(i, 0, arcNum)
        {
            int u, v, edge;
            scanf("%d%d%d", &u, &v, &edge);
            graph[u].num = u, graph[v].num = v;

            for (int i : {u, v})
            {
                graph[i].cnt++;
                ArcNode *p = new ArcNode(i == u ? v : u, edge);
                p->nextArc = graph[i].firstArc;
                graph[i].firstArc = p;
            }
        }
    }

    void dfs(int num)
    {
        if (vis[num] == 1)
            return;
        vis[num] = 1;
        printf("the num is %d\n", num);
        int cnt = graph[num].cnt;
        ArcNode *p = graph[num].firstArc;
        while(p->nextArc != nullptr)
        {
            dfs(p->num);
            p = p->nextArc;
        }
    }

    Graph* bfsInit()
    {
        mem(vis, 0);
        return this;
    }

    void bfs(int num)
    {
        mem(vis, 0);
        queue<Vnode> q;
        q.push(graph[num]);
        while (!q.empty())
        {
            Vnode f = q.front();
            if (vis[f.num] == 1)
            {
                q.pop();
                continue;
            }
            vis[f.num] = 1;
            printf("%d\n", f.num);
            ArcNode *p = f.firstArc;
            while (p != nullptr)
            {
                q.push(graph[p->num]);
                p = p->nextArc;
            }
            q.pop();
        }
    }
};


#endif //GRAPH_GRAPH_H
