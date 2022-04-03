#include "iostream"
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5}, i = 0, first = 1;
    cout << "Type 1" << endl;
    for (i = 0; i < 4; i++)
        cout << a[i] << ' ';
    cout << a[i] << endl;
    cout << "Type 2" << endl;
    for (i = 0; i < 5; i++) {
        if (first)
            first = 0;
        else
            cout << ' ';
        cout << a[i];
    }
    cout << endl;
    return 0;
}