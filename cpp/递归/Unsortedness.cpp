#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int Unsodns(char *str, int start, int n) {
    //用递归法计算一个字符串的逆序值
    if (start + 1 == n)
        return 0;
    else {
        int count = 0;
        for (int i = start + 1; i < n; i++) {
            if (str[i] < str[start])
                count++;
        }
        return Unsodns(str, start + 1, n) + count;
    }
}
int FindMin(int *p, int m) {
    int result = 0;
    for (int i = 0; i < m; i++) {
        if (p[i] < p[result])
            result = i;
    }
    return result;
}
int main() {
    const int MaxN = 0xffffff;
    char s[110][60];
    int n, m;
    int p[110];
    cin >> n >> m;
    for (int item = 0; item < m; item++) {
        //输入，并对输入的每一个字符串计算逆序值
        for (int i = 0; i < n; i++) {
            cin >> s[item][i];
        }
        p[item] = Unsodns(s[item], 0, n);
    }
    for (int item = 0; item < m; item++) {
        //按照逆序值从小到大输出字符串
        int min = FindMin(p, m);
        for (int i = 0; i < n; i++) {
            cout << s[min][i];
        }
        cout << endl;
        p[min] = MaxN;
    }
    return 0;
}