#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
const int N = 1010;
int n, totalv, d[N][N], v[N], w[N];
int main() {
  cin >> n >> totalv;
  int i, j;
  for (i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }
  for (i = 1; i <= n; ++i) {
    for (j = 0; j <= totalv; ++j) {
      d[i][j] = d[i - 1][j];
      if (j >= v[i])
        d[i][j] = max(d[i][j], d[i - 1][j - v[i]] + w[i]);
    }
  }
  int res = 0;
  for (j = 0; j <= totalv; ++j) {
    res = max(res, d[n][j]);
  }
  cout << res << endl;
  return 0;
}