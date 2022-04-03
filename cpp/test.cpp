#include <iostream>
using namespace std;
int main() {
    int num = 0;
    int right = 0;
    cout << "输入一个数:\n";
    while (!right) {
        //数字不正确的时候循环
        cin >> num;
        switch(num){
            case 520:
                cout << "正确\n";
                right = 1;
                break;
            default:
                cout << "重新输入一个数:\n";
                break;
        }
    }
}