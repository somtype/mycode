#include "cstring"
#include "iostream"
#define INF 801
#define maxN 110
using namespace std;
typedef struct {
    int len, price;
} arcNode;
int main() {
    arcNode G[maxN][maxN];
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            G[i][j].len = G[i][j].price = INF;
    for (int i = 0; i < m; i++) {
        int ct1, ct2;
        cin >> ct1 >> ct2;
        cin >> G[ct1][ct2].len >> G[ct1][ct2].price;
        G[ct2][ct1].len = G[ct1][ct2].len;
        G[ct2][ct1].price = G[ct1][ct2].price;
    }
    arcNode D[maxN];
    int final[maxN];
    memset(final, 0, sizeof(final));
    int v;
    for (v = 0; v < n; v++)
        D[v] = G[s][v];
    final[s] = 1;
    D[s].len = D[s].price = 0;
    for (int i = 1; i < n; i++) {
        int minLen, minPrice;
        minLen = minPrice = INF;
        int w;
        for (w = 0; w < n; w++)
            if (!final[w])
                if (D[w].len < minLen ||
                    (D[w].len == minLen && D[w].price < minPrice)) {
                    minLen = D[w].len;
                    minPrice = D[w].price;
                    v = w;
                }
        final[v] = 1;
        for (w = 0; w < n; w++) {
            if (!final[w] && ((minLen + G[v][w].len < D[w].len) ||
                              (minLen + G[v][w].len == D[w].len &&
                               minPrice + G[v][w].price < D[w].price))) {
                D[w].len = minLen + G[v][w].len;
                D[w].price = minPrice + G[v][w].price;
            }
        }
    }
    cout << D[d].len << ' ' << D[d].price;
    return 0;
}