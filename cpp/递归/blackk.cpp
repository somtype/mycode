#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int main() {
    int n, i, k, inputnum[100005];
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> inputnum[i];
    }
    cin >> k;
    sort(inputnum, inputnum + n);
    for (i = n - 1; i > n - k - 1; --i) {
        cout << inputnum[i] << endl;
    }
    return 0;
}
