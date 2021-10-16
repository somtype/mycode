#include "algorithm"
#include "cstring"
#include "iostream"
#include "queue"
#include "vector"
#define pii pair<int, int>
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int cols, rows;
pii start, dest;
char s[160][160];
int dist[160][160];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<pii> q;
int check(int x, int y) {
    return x >= 1 && x <= rows && y >= 1 && y <= cols && dist[x][y] == 0;
}
int bfs() {
    memset(dist, 0, sizeof(dist));
    q.push(start);
    dist[start.first][start.second] = 0;
    while (q.size()) {
        pii qHead = q.front();
        q.pop();
        For(i, 0, 7) {
            int x = qHead.first + dx[i], y = qHead.second + dy[i];
            if (check(x, y)) {
                dist[x][y] = dist[qHead.first][qHead.second] + 1;
                q.push(make_pair(x, y));
                if (x == dest.first && y == dest.second)
                    return dist[x][y];
            }
        }
    }
    return -1;
}
int main() {
    cin >> cols >> rows;
    For(i, 1, rows) {
        For(j, 1, cols) {
            cin >> s[i][j];
            if (s[i][j] == 'K') {
                start.first = i;
                start.second = j;
            }
            if (s[i][j] == 'H') {
                dest.first = i;
                dest.second = j;
            }
        }
    }
    cout << bfs();
    return 0;
}