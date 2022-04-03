#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
char a[10][10] = {{"530070000"}, {"600195000"}, {"098000060"},
                  {"800060003"}, {"400803001"}, {"700020006"},
                  {"060000280"}, {"000419005"}, {"000080079"}};
char b[10][10];
bool check() {
    For(i, 0, 8) For(j, 0, 8) a[i][j] -= '0';
    char s[10] = {0};
    For(i, 0, 8) {
        cin >> s;
        if (strlen(s) != 9)
            return false;
        For(j, 0, 8) {
            b[i][j] = s[j] - '0';
            if (b[i][j] < 1 || b[i][j] > 9)
                return false;
            if (a[i][j] != 0 && a[i][j] != b[i][j])
                return false;
        }
    }
    // check in line
    For(i, 0, 8) {
        memset(s, 0, sizeof(s));
        For(j, 0, 8) {
            if (s[b[i][j]] == 1)
                return false;
            else
                s[b[i][j]] = 1;
        }
    }
    // check in column
    For(j, 0, 8) {
        memset(s, 0, sizeof(s));
        For(i, 0, 8) {
            if (s[b[i][j]] == 1)
                return false;
            else
                s[b[i][j]] = 1;
        }
    }
    // check in cell
    for (int i = 0; i <= 8; i += 3) {
        for (int j = 0; j <= 8; j += 3) {
            memset(s, 0, sizeof(s));
            For(i1, 0, 2) For(j1, 0, 2) {
                if (s[b[i + i1][j + j1]] == 1)
                    return false;
                else
                    s[b[i + i1][j + j1]] = 1;
            }
        }
    }
    return true;
}
int main() {
    if (check()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}