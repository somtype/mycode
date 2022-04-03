#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define maxn 1010
using namespace std;
int main() {
    int num = 0, a[maxn], b[maxn], temp;
    while (scanf("%d", &temp) == 1)
        a[num++] = temp;
    cout << num << endl;
    memcpy(b, a, sizeof(int) * num);
    int i = 0;
    while (i < num)
        cout << b[i++];
    cout << endl;
    return 0;
}