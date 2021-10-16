#include "cstring"
#include "iostream"
using namespace std;
int main() {
    int a[3][3] = {0}, ans = 0, size_single, size_line, size_whole;
    size_single = sizeof(a[0][0]);
    size_line = sizeof(a[0]);
    size_whole = sizeof(a);
    for (int i = 0; i < size_whole / size_line; i++)
        for (int j = 0; j < size_line / size_single; j++)
            cin >> a[i][j];
    for (int i = 0; i < size_whole / size_line; i++)
        for (int j = 0; j < size_line / size_single; j++)
            ans += a[i][j];
    cout << "result:" << ans << endl;
    return 0;
}