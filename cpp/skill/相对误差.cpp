#include "algorithm"
#include "cmath"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    double n1, n2;
    cin >> n1 >> n2;
    double ans = abs(n1 - n2) / ((n1 + n2) / 2);
    cout << ans;
    return 0;
}