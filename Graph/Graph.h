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

using namespace std;

class Graph {
private:
    class ArcNode {
    public:
        int num, weight;
        struct ArcNode *nextArc;

        ArcNode(int num, int weight) : num(num), weight(weight) {}
    };

    class Vnode {
    public:
        int num, cnt = 0;
        ArcNode *firstArc;
    };

    Vnode graph[maxN];
    int vis[maxN];
    int vexNum, arcNum;
public:
    Graph(int vexNum, int arcNum) : vexNum(vexNum), arcNum(arcNum)
    {
        mem(graph, 0);
        int tot = 0;
        For(i, 0, vexNum)
        {
            int cnt;                                                                                                    //当前节点的边数
            scanf("%d", &cnt);
            tot += cnt;
            graph[i].num = i;
            graph[i].cnt = cnt;
            ArcNode *p;
            For(j, 0, cnt)
            {
                int num, weight;
                if (j == 0)
                {
                    scanf("%d%d", &num, &weight);
                    p = new ArcNode(num, weight);
                    graph[i].firstArc = p;
                    p = graph[i].firstArc;
                }
                scanf("%d%d", &num, &weight);
                p->nextArc = new ArcNode(num, weight);
                p = p->nextArc;
            }
        }
        if (this->arcNum != tot)
            throw -1;
    }

    void dfs(int num)
    {
        mem(vis, 0);
        int cnt = graph[num].cnt;
        ArcNode *p = graph[num].firstArc;
        For(i, 0, cnt)
        {
            if (vis[p->num] == 1)
                continue;
            vis[p->num] = 1;
            printf("the num is %d, the weight is %d\n", p->num, p->weight);
            p = p->nextArc;
            dfs(p->num);
        }
    }

    void bfs(int num)
    {
        mem(vis, 0);
        queue<ArcNode*> q;
        q.push(graph[num].firstArc);
        while (!q.empty())
        {
            ArcNode *p = q.front();
            if (vis[p->num] == 1)
            {
                q.pop();
                continue;
            }
            vis[p->num] = 1;
            printf("the num is %d, the weight is %d\n", p->num, p->weight);
            int cnt = graph[p->num].cnt;
            For(i, 0, cnt)
            {
                q.push(p->nextArc);
                p = p->nextArc;
            }
            q.pop();
        }
    }
};


#endif //GRAPH_GRAPH_H
