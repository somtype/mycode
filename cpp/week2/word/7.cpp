#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int replace(char *a) {
    int num = 0, i = 0;
    while (a[i]) {
        if (a[i] == 't') {
            a[i] = 'e';
            num++;
        } else if (a[i] == 'T') {
            a[i] = 'E';
            num++;
        }
        i++;
    }
    return num;
}
int main() {
    char a[1010];
    cout << "input s:\n";
    cin >> a;
    int num = 0;
    num = replace(a);
    cout << "result:\n" << a << endl << num << endl;
    return 0;
}