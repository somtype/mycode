#include "algorithm"
#include "cstring"
#include "iostream"
#include "queue"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
#define pii pair<int, int>
#define maxN 1010
using namespace std;
char s[maxN][maxN];
int dist[maxN][maxN], n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
pii qHead;
queue<pii> q;
bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '0' &&
           dist[x][y] == 0;
}
void bfs() {
    while (q.size()) {
        qHead = q.front();
        q.pop();
        For(i, 0, 3) {
            int x = qHead.first + dx[i], y = qHead.second + dy[i];
            if (check(x, y)) {
                q.push(make_pair(x, y));
                s[x][y] = '1';
                dist[x][y] = dist[qHead.first][qHead.second] + 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == '1') {
                q.push(make_pair(i, j));
            }
        }
    }
    memset(dist, 0, sizeof(dist));
    bfs();
    For(i, 1, n) {
        For(j, 1, m) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}