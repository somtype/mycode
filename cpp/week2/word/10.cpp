#include "algorithm"
#include "cstring"
#include "ctime"
#include "iostream"
using namespace std;
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    int *num;
    int n;
    cout << "input n:\n";
    cin >> n;
    num = (int *)malloc(sizeof(int) * n); //长度为n的数组
    srand((int)time(NULL));               //设置种子数
    for (int i = 0; i < n; i++)
        num[i] = rand() % 100; //产生【0，100】内的随机数并赋值
    for (int i = 0; i < n - 1; i++) { //冒泡法排序
        for (int j = 0; j < n - 1 - i; j++) {
            if (num[j] > num[j + 1])
                swap(&num[j], &num[j + 1]);
        }
    }
    cout << "result:\n";
    for (int i = 0; i < n; i++)
        cout << num[i] << ' ';
    return 0;
}