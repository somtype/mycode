#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
int n, cow, fence[100005];
bool isaccept(int d) {
    int temp, i, countcow;
    temp = fence[0];
    countcow = 1;
    for (i = 1; i < n; ++i) {
        if (fence[i] - temp >= d) {
            temp = fence[i];
            ++countcow;
        }
        if (countcow == cow) {
            break;
        }
    }
    if (countcow == cow)
        return true;
    else
        return false;
}
int binarysearch(int left, int right) {
    int mid, result;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (isaccept(mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return result;
}
int main() {
    int i;
    cin >> n >> cow;
    for (i = 0; i < n; ++i) {
        cin >> fence[i];
    }
    sort(fence, fence + n);
    int ans = binarysearch(1, fence[n - 1] - fence[0] + 1);
    cout << ans << endl;
    return 0;
}