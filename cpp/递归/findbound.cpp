
#include "iostream"
using namespace std;
int inputnum[ 100005 ], n;
int lowerbound(int target);
int upperbound(int target);
int main() {
    int i, m, target;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> inputnum[ i ];
    }
    cin >> m;
    for (i = 0; i < m; i++) {
        cin >> target;
        int lower, upper, ans;
        lower = lowerbound(target);
        upper = upperbound(target);
        if (target <= inputnum[ 0 ]) {
            cout << inputnum[ upper ];
        }
        else if (target >= inputnum[ n - 1 ]) {
            cout << inputnum[ lower ];
        }
        else {
            ans = inputnum[ upper ] - target < target - inputnum[ lower ] ? upper : lower;
            cout << inputnum[ ans ];
        }
        cout << endl;
    }
    return 0;
}
int lowerbound(int target) {
    int left = 0, right = n, mid, result = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (inputnum[ mid ] >= target) {
            right = mid;
        }
        else {
            result = mid;
            left = mid + 1;
        }
    }
    return result;
}
int upperbound(int target) {
    int left = 0, right = n, mid, result = -1;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (inputnum[ mid ] <= target) {
            left = mid + 1;
        }
        else {
            result = mid;
            right = mid;
        }
    }
    return result;
}