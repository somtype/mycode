#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int lowbit(int n) {
    int temp = -n & n;
    return temp;
}
int NumberOf1(int n) {
    int res = 0;
    while (n != 0) {
        n -= lowbit(n);
        res++;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    cout << NumberOf1(n) << endl;
    return 0;
}