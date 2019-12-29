#include <cstdio>
#include "Graph/Graph.h"
using namespace std;

int main()
{
    int vexNum, arcNum;
    freopen("data/input.txt", "r", stdin);
    scanf("%d%d", &vexNum, &arcNum);
    Graph *g = new Graph(vexNum, arcNum);
    g->bfs(1);
    g->bfsInit()->dfs(1);
    return 0;
}
