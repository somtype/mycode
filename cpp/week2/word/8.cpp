#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char *a[7] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                  "Friday", "Saturday", "Sunday"};
    int i = 0;
    cin >> i;
    if (i >= 1 && i <= 7)
        cout << a[i - 1] << endl;
    return 0;
}