#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[1010] = "I am a student";
    char b[1010];
    memset(b, 0, sizeof(b));
    int i = 0;
    while (a[i] != '\0') {
        b[i] = a[i];
        i++;
    }
    cout << b << endl;
    return 0;
}