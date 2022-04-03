#include <iostream>
#include <queue>
using namespace std;
int FindMul(int n, long long int &ans) {
    queue<long long int> qans;
    long long int temp = 1;
    qans.push(temp);
    while (1) {
        long long int temp = qans.front();
        qans.pop();
        if (temp % n == 0) {
            ans = temp;
            return 1;
        }
        qans.push(temp * 10);
        qans.push(temp * 10 + 1);
    }
}
int main() {
    int n;
    long long int ans = -1;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        FindMul(n, ans);
        cout << ans << endl;
    }
    return 0;
}