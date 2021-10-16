#include "algorithm"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    char a[1010] = "I love ", b[1010] = "China";
    int i, j;
    i = j = 0;
    while (a[i])
        i++;
    while (b[j])
        a[i++] = b[j++];
    a[i] = '\0';
    cout << a << endl;
    return 0;
}