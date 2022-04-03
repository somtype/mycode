#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
typedef struct {
    int len, wei;
    int area;
} Box;
int Packing(int slen, int swei, Box *mybox, int n, int *status, int &learea) {
    // slen,swei为石板的长、宽
    // mybox[0...n-1]中为需要的石砖，石砖已经按照面积非递增排序
    // status[0...n-1]用来判断石砖是否已经切好
    // learea储存石板的剩余面积，用来计算利用率
    int i;
    for (i = 0; i < n; i++) {
        if (!status[i] && slen >= mybox[i].len && swei >= mybox[i].wei) {
            break;
        } else
            continue;
    } //在需要的石砖中找出当前石板能够切割的最大石砖
    if (i >= n)
        return 1; //当前石板太小，已经无法利用，切割完成
    else {
        //当前石板找到了一个合适的切割石砖，进行切割。对分裂出来的两块较小石板进行相同的操作
        status[i] = 1;
        learea -= mybox[i].area;
        Packing(slen - mybox[i].len, mybox[i].wei, mybox, n, status, learea);
        Packing(slen, swei - mybox[i].wei, mybox, n, status, learea);
        return 1;
    }
}
int main() {
    int slen, swei, learea;
    int n, status[100];
    Box mybox[100];
    memset(status, 0, sizeof(status));
    memset(mybox, 0, sizeof(mybox));
    cin >> slen >> swei;
    learea = slen * swei;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mybox[i].len >> mybox[i].wei;
        mybox[i].area = mybox[i].len * mybox[i].wei;
    }
    Packing(slen, swei, mybox, n, status, learea);
    cout << learea << endl;
    return 0;
}