#include "iostream"
using namespace std;
void move(int n, char src, char mid, char dest) {
    if (n == 1) {
        cout << 1 << ":" << src << "->" << dest << endl;
    } else {
        move(n - 1, src, dest, mid);
        cout << n << ":" << src << "->" << dest << endl;
        move(n - 1, mid, src, dest);
    }
}
int main() {
    char a, b, c;
    int n;
    cin >> n >> a >> b >> c;
    move(n, a, b, c);
    return 0;
}