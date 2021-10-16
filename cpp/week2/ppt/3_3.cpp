#include "cstring"
#include "iostream"
using namespace std;
int main() {
    string a;
    int first = 1, num = 0;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) {
            if (first == 1)
                first = 0;
            else
                cout << ' ';
            cout << a[i];
            num++;
        }
    }
    cout << endl << num << "个字母" << endl;
    return 0;
}