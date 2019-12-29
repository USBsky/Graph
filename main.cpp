#include <cstdio>
#include "Graph/Graph.h"
using namespace std;

int main()
{
    int vexNum, arcNum;
    scanf("%d%d", &vexNum, &arcNum);
    Graph *g = new Graph(vexNum, arcNum);
    g->bfs(0);
    g->dfs(0);
    return 0;
}
