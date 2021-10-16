#include "cstring"
#include "iostream"
#include "stack"
#define maxN 1010
using namespace std;
typedef int ElemType;
typedef struct arcNode {
    int adjvex;
    arcNode *nextarc;
} arcNode;
typedef struct vNode {
    ElemType data;
    arcNode *firstarc;
} vNode, adjList[maxN];
typedef struct {
    adjList vertices;
    int vernum, arcnum;
    int kind;
} ALGraph;
int topoSort(ALGraph &G, int *indegree) {
    stack<int> s;
    int count = 0;
    for (int i = 1; i <= G.vernum; i++) {
        if (!indegree[i])
            s.push(i);
        while (!s.empty()) {
            int adj = s.top();
            s.pop();
            count++;
            for (arcNode *p = G.vertices[adj].firstarc; p; p = p->nextarc)
                if (!(--indegree[p->adjvex]))
                    s.push(p->adjvex);
        }
    }
    if (count < G.vernum)
        return 0;
    else
        return 1;
}
int main() {
    ALGraph G;
    memset(&G, 0, sizeof(G));
    int n, indegree[maxN];
    cin >> n;
    G.vernum = n;
    for (int i = 1; i <= n; i++) {
        cin >> indegree[i];
        G.arcnum += indegree[i];
        for (int j = 0; j < indegree[i]; j++) {
            int temp;
            cin >> temp;
            if (!G.vertices[temp].firstarc) {
                G.vertices[temp].firstarc = new arcNode;
                G.vertices[temp].firstarc->adjvex = i;
                G.vertices[temp].firstarc->nextarc = NULL;
            } else {
                arcNode *p = new arcNode;
                p->nextarc = G.vertices[temp].firstarc;
                while (p->nextarc)
                    p = p->nextarc;
                p->nextarc = (arcNode *)malloc(sizeof(arcNode));
                p->nextarc->adjvex = i;
                p->nextarc->nextarc = NULL;
            }
        }
    }
    int flag;
    flag = topoSort(G, indegree);
    cout << flag;
    return 0;
}