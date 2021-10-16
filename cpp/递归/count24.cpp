#include "algorithm"
#include "cmath"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
bool count24(double *inputnumber, int n) {
    if (n == 1) {
        if (fabs(inputnumber[0] - 24) < 1e-6)
            return true;
        else
            return false;
    } else {
        int i, j;
        for (i = 0; i <= n - 2; i++) {
            for (j = i + 1; j <= n - 1; j++) {
                double temp[n - 1];
                int k, num = 0;
                for (k = 0; k <= n - 1; k++) {
                    if ((k != i) && (k != j))
                        temp[num++] = inputnumber[k];
                }
                temp[num] = inputnumber[i] + inputnumber[j];
                if (count24(temp, n - 1))
                    return true;
                temp[num] = inputnumber[i] * inputnumber[j];
                if (count24(temp, n - 1))
                    return true;
                temp[num] = inputnumber[i] - inputnumber[j];
                if (count24(temp, n - 1))
                    return true;
                temp[num] = inputnumber[j] = inputnumber[i];
                if (count24(temp, n - 1))
                    return true;
                if (inputnumber[i] != 0) {
                    temp[num] = inputnumber[j] / inputnumber[i];
                    if (count24(temp, n - 1))
                        return true;
                }
                if (inputnumber[j] != 0) {
                    temp[num] = inputnumber[i] / inputnumber[j];
                    if (count24(temp, n - 1))
                        return true;
                }
            }
        }
    }
    return false;
}
int main() {
    double inputnumber[4];
    for (int i = 0; i <= 3; i++) {
        cin >> inputnumber[i];
    }
    if (count24(inputnumber, 4)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}