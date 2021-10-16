#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
const int bagsize = 70;
int n, d[60][80];
vector<int> volumn;
int solve(int i, int j) { // i件物品装满体积为j的背包
  if (d[i][j] != -1)
    return d[i][j];
  if (i <= 0)
    return 0;
  if (j <= 0)
    return 1;
  d[i - 1][j] = solve(i - 1, j);
  int k; //记录[i][j-volumn[i]]的值
  k = j - volumn[i] > 0 ? d[i][j - volumn[i]] = solve(i, j - volumn[i]) : 0;
  return d[i - 1][j] + k;
}
int main() {
  int i;
  cin >> n;
  For(i, 1, n) {
    int a;
    cin >> a;
    volumn.push_back(a);
  }
  volumn.insert(volumn.begin(), -1);
  memset(d, -1, sizeof(d));
  int res = solve(n, bagsize);
  cout << res;
  return 0;
}