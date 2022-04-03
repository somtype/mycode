#include "iostream"
#define maxN 1010
#include "cstring"
using namespace std;
typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode, *BiTree;
BiTree build(int *m, int *b, int ml, int mr, int bl, int br) {
    if (bl > br)
        return NULL;
    int rootdt = b[br];
    int i = ml;
    while (m[i] != rootdt)
        i++;
    int lTreeLen = i - ml;
    BiTree root = (BiTree)malloc(sizeof(BiTreeNode));
    root->data = rootdt;
    root->lchild = build(m, b, ml, i - 1, bl, bl + lTreeLen - 1);
    root->rchild = build(m, b, i + 1, mr, bl + lTreeLen, br - 1);
    return root;
}
int main() {
    int n, m[40], b[40];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    BiTree root;
    root = build(m, b, 0, n - 1, 0, n - 1);

    return 0;
}