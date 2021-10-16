#include "cstring"
#include "iostream"
using namespace std;
int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int main() {
    cout << "input n:" << endl;
    int n;
    cin >> n;
    int ans = fib(n);
    cout << "answer:" << endl << ans << endl;
    return 0;
}