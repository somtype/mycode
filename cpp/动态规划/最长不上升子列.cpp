#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int n, s[10010], d[10010];
int main() {
  int i, j, res = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    d[i] = 1;
  }
  for (i = 1; i < n; i++) {
    for (j = 0; j < i; j++) {
      if (s[i] <= s[j]) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
  }
  for (i = 0; i < n; i++) {
    res = max(d[i], res);
  }
  cout << res << endl;
}