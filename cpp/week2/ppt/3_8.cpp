#include "cstring"
#include "iostream"
using namespace std;
int main() {
    void stringcat(char *s1, char *s2, char *s);
    char s1[1010], s2[1010], s[2020];
    cout << "input s1 and s2:\n";
    cin >> s1 >> s2;
    stringcat(s1, s2, s);
    cout << "result:\n";
    for (int i = 0; s[i] != '\0'; i++)
        cout << s[i];
    cout << endl;
    return 0;
}
void stringcat(char *s1, char *s2, char *s) {
    int i, j;
    i = j = 0;
    while (s1[i]) {
        s[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        s[i] = s2[j];
        i++;
        j++;
    }
    s[i] = '\0';
}