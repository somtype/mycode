#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
double experience(), term(), factor();
int main() {
    double ans;
    ans = experience();
    cout << ans;
    return 0;
}