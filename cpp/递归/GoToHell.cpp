#include "iostream"
using namespace std;
int main() {
    int n, ans;
    int DownToHell(int n);
    cin >> n;
    ans = DownToHell(n);
    cout << ans;
    return 0;
}
int DownToHell(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else {
        return DownToHell(n - 1) + DownToHell(n - 2);
    }
}
