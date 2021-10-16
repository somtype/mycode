#include "cstring"
#include "iostream"
#include "math.h"
using namespace std;
char onestr[100];
int main() {
    double Solve();
    double ans;
    ans = Solve();
    printf("%f\n", ans);
    return 0;
}
double Solve() {
    cin >> onestr;
    switch (onestr[0]) {
    case '+':
        return Solve() + Solve();
        break;
    case '-':
        return Solve() - Solve();
        break;
    case '*':
        return Solve() * Solve();
        break;
    case '/':
        return Solve() / Solve();
        break;
    default:
        return atof(onestr);
        break;
    }
}