#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[1010];
    int i = 0, num = 0;
    cout << "input s:\n";
    cin >> a;
    cout << "result:\n";
    for (i = 0; a[i] != '\0'; i++) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            num++;
        else
            cout << a[i];
    }
    cout << endl << "number of alphabet:\n" << num << endl;
    return 0;
}