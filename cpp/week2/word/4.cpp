#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[1010];
    int i = 0;
    cout << "input s:\n";
    cin >> a;
    while (a[i])
        i++;
    cout << "result:\n";
    while (i > 0)
        cout << a[--i];
    cout << endl;
    return 0;
}