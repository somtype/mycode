#include "cstdlib"
#include "cstring"
#include "iostream"
using namespace std;
int ans[13];
int n;
int main() {
    cin >> n;
    void queen(int N);
    queen(0);
    return 0;
}
void queen(int N) // N表示已经摆好的皇后数量，n表示需要摆放的皇后数量
{
    if (N == n) //递归出口
    {
        int i;
        for (i = 1; i <= n; i++) {
            cout << ans[i];
        }
        cout << endl;
    } else {
        int i;
        for (i = 1; i <= n; i++) //摆放第N+1位皇后
        {
            int k;
            for (k = 1; k <= N; k++) {
                if (i == ans[k] || (abs(i - ans[k]) == abs(N + 1 - k)))
                    break;
            }
            if (k == N + 1) {
                ans[N + 1] = i;
                queen(N + 1); //递归调用，表示已经摆好了N+1位皇后，摆放第N+2位
            }
        }
    }
}