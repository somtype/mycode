#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char *p, a[1010] = "I love China!";
    p = a;
    while (*p != '\0') {
        cout << *p;
        p++;
    }
    cout << endl;
    return 0;
}