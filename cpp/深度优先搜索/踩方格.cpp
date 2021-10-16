#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
using namespace std;
int matrix[30][30];
int main() {
    long long dfs(int n, int i, int j);
    int n, res;
    memset(matrix, 0, sizeof(matrix));
    cin >> n;
    res = dfs(n, 1, 1);
    cout << res;
    return 0;
}
bool ispassed(int i, int j) {
    if (matrix[i][j] == 1)
        return true;
    else
        return false;
}
long long dfs(int n, int i, int j) {
    if (0 == n)
        return 1;
    else {
        long long res = 0;
        matrix[i][j] = 1;
        if (!ispassed(i + 1, j))
            res += dfs(n - 1, i + 1, j);
        if (!ispassed(i, j - 1))
            res += dfs(n - 1, i, j - 1);
        if (!ispassed(i, j + 1))
            res += dfs(n - 1, i, j + 1);
        matrix[i][j] = 0;
        return res;
    }
}