#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    while (1) {
        int k;
        cin >> k;
        cout << a * (k - b) % n << ' ';
    }
    cout << endl;
    return 0;
}