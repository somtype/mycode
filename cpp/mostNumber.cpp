#include <cmath>
#include <iostream>
using namespace std;
void FindMost(int *A, int n, int &num, int &t) {
    int tempNum, tempT;
    int i = 0;
    while (i < n) {
        if (A[i] == -1)
            i++;
        tempNum = A[i];
        tempT = 1;
        A[i] = -1;
        int j = i + 1;
        while (j < n) {
            if (A[j] == tempNum) {
                tempT++;
                A[j] = -1;
            }
            j++;
        }
        if (tempT > t) {
            num = tempNum;
            t = tempT;
        }
    }
}
int main() {
    int A[100], num, t;
    num = t = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    FindMost(A, n, num, t);
    cout << "出现次数最多的是：" << num << "  出现次数为：" << t << endl;
    return 0;
}