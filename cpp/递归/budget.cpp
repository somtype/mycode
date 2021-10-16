#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
long long int n, inputnum[100005], m;
bool isaccept(long long int d) {
    long long int i = 0, mcount = 0, tempbudget = 0;
    while (i < n) {
        if (tempbudget + inputnum[i] < d) {
            tempbudget += inputnum[i];
            i++;
        } else {
            mcount++;
            tempbudget = inputnum[i];
            i++;
        }
        if (mcount > m)
            return false;
    }
    if (mcount >= m)
        return true;
}
long long int binarysearch(long long int left, long long int right) {
    long long int mid, result;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (isaccept(mid)) {
            result = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return result;
}
int main() {
    long long int i, maxbudget = 0, total = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> inputnum[i];
        total += inputnum[i];
        if (inputnum[i] > maxbudget)
            maxbudget = inputnum[i];
    }
    cout << binarysearch(maxbudget, total);
    return 0;
}
