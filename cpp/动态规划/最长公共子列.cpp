#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    int len1 = s1.length(), len2 = s2.length(), d[len1 + 1][len2 + 1];
    int k;
    for (k = 0; k <= len1; ++k) {
      d[k][0] = 0;
    }
    for (k = 0; k <= len2; ++k) {
      d[0][k] = 0;
    }
    for (int i = 1; i <= s1.length(); ++i) {
      for (int j = 1; j <= s2.length(); ++j) {
        if (s1[i - 1] == s2[j - 1])
          d[i][j] = d[i - 1][j - 1] + 1;
        else
          d[i][j] = max(d[i - 1][j], d[i][j - 1]);
      }
    }
    cout << d[len1][len2] << endl;
  }
  return 0;
}