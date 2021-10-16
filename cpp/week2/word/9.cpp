#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[5][1010], *p[5];
    cout << "input 5 strings:\n";
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
        p[i] = a[i];
    }
    for (int i = 1; i < 5; i++) {
        char temp[1010];
        strcpy(temp, p[i]);
        int j = i - 1;
        while (j >= 0 && strlen(a[j]) > strlen(temp)) {
            strcpy(p[j + 1], p[j]);
            j--;
        }
        strcpy(p[j + 1], temp);
    }
    cout << "result:\n";
    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;
    char s[1010] = "0", *p_s;
    p_s = s;
    for (int i = 0; i < 5; i++) {
        if (a[i][2])
            *(p_s++) = a[i][2];
        else
            *(p_s++) = ' ';
    }
    cout << s << endl;
    return 0;
}