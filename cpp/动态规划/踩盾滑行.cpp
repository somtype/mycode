#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int r, c, i, j, h[110][110], d[110][110];
int solve(int i, int j) {
  if (d[i][j] != -1)
    return d[i][j];
  else if (h[i][j] <= h[i - 1][j] && h[i][j] <= h[i + 1][j] &&
           h[i][j] <= h[i][j - 1] && h[i][j] <= h[i][j + 1])
    return d[i][j] = 1;
  else {
    int maxlen = 0;
    if (h[i][j] > h[i - 1][j])
      maxlen = max(maxlen, solve(i - 1, j) + 1);
    if (h[i][j] > h[i + 1][j])
      maxlen = max(maxlen, solve(i + 1, j) + 1);
    if (h[i][j] > h[i][j - 1])
      maxlen = max(maxlen, solve(i, j - 1) + 1);
    if (h[i][j] > h[i][j + 1])
      maxlen = max(maxlen, solve(i, j + 1) + 1);
    return d[i][j] = maxlen;
  }
}
int main() {
  memset(h, 0x3f, sizeof(h));
  memset(d, -1, sizeof(d));
  cin >> r >> c;
  for (i = 1; i <= r; ++i)
    for (j = 1; j <= c; ++j)
      cin >> h[i][j];
  int res = 0;
  for (i = 1; i <= r; ++i)
    for (j = 1; j <= c; ++j)
      res = max(res, solve(i, j));
  cout << res << endl;
  return 0;
}