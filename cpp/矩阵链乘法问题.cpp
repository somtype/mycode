#include <cmath>
#include <iostream>
using namespace std;
int MatrixOut(int *A, int (*s)[110], int i, int j) {
    if (i == j) {
        printf("A[%d]", i);
        return 1;
    } else {
        int k = s[i][j];
        cout << '(';
        MatrixOut(A, s, i, k);
        cout << ")(";
        MatrixOut(A, s, k + 1, j);
        cout << ')';
        return 1;
    }
}
int DPMatrixChain(int *A, int n) {
    int dp[110][110];
    int s[110][110];
    const int max_num = 0x0fffffff;
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = max_num;
            for (int k = i; k < j; k++) {
                int temp = dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j];
                if (temp < dp[i][j]) {
                    dp[i][j] = temp;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << endl; //输出最小计算量结果
    MatrixOut(A, s, 1, n);
    return 1;
}
int main() {
    int n;
    int A[110];
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> A[i];
    cout << DPMatrixChain(A, n) << endl;
    return 0;
}