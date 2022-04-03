#include "algorithm"
#include "cmath"
#include "cstring"
#include "iostream"
#define maxN 110
using namespace std;
int main() {
    double x[maxN], sum = 0, averx, sigmax, sigmax_, UA;
    int n;
    cout << "输入测试数据组数\n";
    cin >> n;
    cout << "输入数据\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    averx = sum / n;
    double temp = 0;
    for (int i = 0; i < n; i++) {
        temp += pow((x[i] - averx), 2);
    }
    sigmax = sqrt(temp / n - 1);
    sigmax_ = sigmax / sqrt(n);
    double tvp;
    cout << "输入t分布修正因子tvp\n";
    cin >> tvp;
    UA = sigmax_ * tvp;
    cout << "平均值averx=" << averx << endl;
    cout << "标准误差sigmax=" << sigmax << endl;
    cout << "算术平均值的标准误差sigmax_=" << sigmax_ << endl;
    cout << "A类不确定度UA=" << UA << endl;
    return 0;
}