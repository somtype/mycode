#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int flag = 0;
    // for
    cout << "for:  ";
    for (int i = 2; i <= 100; i++) {
        flag = 1;
        for (int j = 2; j <= int(sqrt(i)); j++) {
            if (i % j == 0)
                flag = 0;
        }
        if (flag)
            cout << i << "  ";
    }
    cout << endl;
    // while
    cout << "while:";
    int wi = 2;
    while (wi <= 100) {
        flag = 1;
        int wj = 2;
        while (wj <= int(sqrt(wi))) {
            if (wi % wj == 0)
                flag = 0;
            wj++;
        }
        if (flag)
            cout << wi << "  ";
        wi++;
    }
    cout << endl;
    // do...while
    cout << "do..w:";
    int di = 2;
    do {
        flag = 1;
        int dj = 2;
        do {
            if (di % dj == 0 && dj <= int(sqrt(di)))
                flag = 0;
            dj++;
        } while (dj <= int(sqrt(di)));
        if (flag)
            cout << di << "  ";
        di++;
    } while (di <= 100);
    cout << endl;
}