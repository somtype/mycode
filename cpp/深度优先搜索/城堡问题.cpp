#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
using namespace std;
int R, C;
int rooms[60][60], color[60][60];
int roomArea = 0, maxroomArea = 0, roomnum = 0;
void dfs(int i, int j) {
    if (color[i][j])
        return;
    roomArea++;
    color[i][j] = roomnum;
    if ((rooms[i][j] & 1) == 0)
        dfs(i, j - 1);
    if ((rooms[i][j] & 2) == 0)
        dfs(i - 1, j);
    if ((rooms[i][j] & 4) == 0)
        dfs(i, j + 1);
    if ((rooms[i][j] & 8) == 0)
        dfs(i + 1, j);
}
int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> rooms[i][j];
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (!color[i][j]) {
                roomnum++;
                roomArea = 0;
                dfs(i, j);
                maxroomArea = max(maxroomArea, roomArea);
            }
        }
    }
    cout << roomnum << endl << maxroomArea;
    return 0;
}