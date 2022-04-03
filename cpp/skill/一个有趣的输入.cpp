#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define maxn 1010
using namespace std;
int main() {
    int num = 0, a[maxn], temp;
    while (scanf("%d", &temp) == 1)
        a[num++] = temp;
    cout << num;
    return 0;
}