#include "cmath"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    string s;
    int tran(string s);
    int res;
    cout << "input s:\n";
    cin >> s;
    res = tran(s);
    cout << "result:\n" << res << endl;
    return 0;
}
int tran(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        int temp;
        if (s[i] >= '0' && s[i] <= '9')
            temp = s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            temp = s[i] - 55;
        res += temp * pow(16, s.length() - 1 - i);
    }
    return res;
}