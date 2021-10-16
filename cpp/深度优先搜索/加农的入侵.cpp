#include "algorithm"
#include "cstring"
#include "iostream"
#include "queue"
#include "vector"
#define pii pair<int, int>
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
const int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int N = 110;
char s[N][N];
int cnt = 0, n, m;
int visited[N][N], dist[N][N], maxDist;
pii start, qHead;
queue<pii> q;
int check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == 0 &&
           s[x][y] != '*';
}
int bfs() {
    q.push(start);
    dist[start.first][start.second] = 0;
    visited[start.first][start.second] = 1;
    while (q.size()) {
        qHead = q.front();
        q.pop();
        For(i, 0, 7) {
            int x = qHead.first + dx[i], y = qHead.second + dy[i];
            if (check(x, y)) {
                cnt--;
                visited[x][y] = 1;
                dist[x][y] = dist[qHead.first][qHead.second] + 1;
                maxDist = max(dist[x][y], maxDist);
                q.push(make_pair(x, y));
                if (cnt == 0)
                    return 1;
            }
        }
    }
}
int main() {
    memset(visited, 0, sizeof(visited));
    cin >> m >> n >> start.second >> start.first;
    rFor(i, n, 1) {
        For(j, 1, m) {
            cin >> s[i][j];
            if (s[i][j] == '.')
                cnt++;
        }
    }
    if (s[start.first][start.second] == '.')
        cnt--;
    bfs();
    cout << maxDist;
    return 0;
}