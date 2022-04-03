#include "algorithm"
#include "cstring"
#include "iomanip"
#include "iostream"
using namespace std;
int main() {
    double lmon = 0, gmon = 0, mmon = 0, rate = 0, year = 0;
    cin >> lmon >> rate >> year;
    gmon = lmon;
    mmon = gmon / (year * 12.0);
    for (int i = 0; i < year; i++) {
        gmon += lmon * rate;
        cout << mmon + lmon * rate / 12.0 << "  ";
        lmon -= lmon * (1.0 / year);
    }
    cout << endl;
    cout << gmon << endl;
    cout << gmon / (year * 12.0) << endl;
    return 0;
}