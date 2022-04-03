#include "iostream"
#define maxN 1010
#include "cstring"
using namespace std;
int main() {
    int n, i, j, tree[maxN];
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for (int k = 1; k <= n; k++)
        cin >> tree[k];
    cin >> i >> j;
    if (tree[i] == 0) {
        printf("ERROR: T[%d] is NULL", i);
        return 0;
    }
    if (tree[j] == 0) {
        printf("ERROR: T[%d] is NULL", j);
        return 0;
    }
    if (i < j) {
        int temp = i;
        i = j;
        j = temp;
    }
    while (i != j) {
        i /= 2;
        if (j > i)
            j /= 2;
    }
    cout << i << ' ' << tree[i];
    return 0;
}