#include "algorithm"
#include "iostream"
using namespace std;
int inputnum[100005];
int main() {
    int binarysearch(int left, int right, int target, int *pfound);
    int n, i, sum, found;
    int ans[2];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> inputnum[i];
    cin >> sum;
    sort(inputnum, inputnum + n);
    found = 0;
    for (i = 0; i < n; i++) {
        ans[0] = inputnum[i];
        ans[1] = binarysearch(i + 1, n, sum - ans[0], &found);
        if (found == 1)
            break;
    }
    if (found == 1)
        for (i = 0; i < 2; i++)
            cout << ans[i] << " ";
    else
        cout << "No";
    return 0;
}
int binarysearch(int left, int right, int target, int *pfound) {
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (inputnum[mid] == target) {
            *pfound = 1;
            return inputnum[mid];
        } else if (inputnum[mid] > target)
            right = mid;
        else
            left = mid + 1;
    }
    return -1;
}