#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[1010];
    int i = 0, num = 0;
    cout << "Input s:\n";
    cin >> a;
    cout << "Numbers:\n";
    for (i = 0; a[i] != '\0'; i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            cout << a[i];
            num++;
        }
    }
    cout << endl << "Number of numbers:\n" << num << endl;
    return 0;
}