#include "algorithm"
#include "cmath"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int lowbit(int n) {
    return -n & n;
}
int main() {
    const int maxN = 16;
    int n;
    int Log2[1 << maxN] = {0};
    For(i, 0, maxN) {
        Log2[1 << i] = i;
    }
    cin >> n;
    int temp = lowbit(n);
    cout << Log2[temp];
    return 0;
}