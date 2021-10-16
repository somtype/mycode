#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n, a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        cout << i << ',' << (i * a) % n << "  ";
    }
    cout << endl;
    return 0;
}