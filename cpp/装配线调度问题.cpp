#include <iostream>
using namespace std;
int DPFastestWay(int (*s)[110], int (*t)[110], int n) {
    int res[2][110];
    res[0][1] = s[0][1] + t[0][0];
    res[1][1] = s[1][1] + t[1][0];
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i < 2; i++) {
            res[i][j] =
                min(res[i][j - 1], res[1 - i][j - 1] + t[1 - i][j - 1]) +
                s[i][j];
        }
    }
    int ans = min(res[0][n] + t[0][n], res[1][n] + t[1][n]);
    cout << ans << endl;
    return 1;
}
int main() {
    int n;
    int s[2][110], t[2][110];
    s[0][0] = s[1][0] = 0;
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> t[i][j];
        }
    }

    DPFastestWay(s, t, n);
    return 0;
}