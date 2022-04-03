#include "cstring"
#include "iostream"
#define maxN 1010
using namespace std;
typedef int SomeType;
typedef struct {
    int i, j;
    SomeType e;
} Triple;
typedef struct {
    Triple data[maxN];
    int mu, nu, tu;
} TSMatrix;
int inpMx(TSMatrix &M) {
    cin >> M.mu >> M.nu >> M.tu;
    for (int i = 1; i <= M.tu; i++)
        cin >> M.data[i].i >> M.data[i].j >> M.data[i].e;
    return 0;
}
int Tranpose(TSMatrix M, TSMatrix &T) {
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[maxN], cpot[maxN];
    memset(num, 0, sizeof(num));
    for (int t = 1; t <= M.nu; t++)
        num[M.data[t].j]++;
    cpot[1] = 1;
    for (int col = 2; col <= M.nu; col++)
        cpot[col] = cpot[col - 1] + num[col - 1];
    for (int im = 1; im <= M.tu; im++) {
        int col = M.data[im].j;
        T.data[cpot[col]].i = col;
        T.data[cpot[col]].j = M.data[im].i;
        T.data[cpot[col]].e = M.data[im].e;
        cpot[col]++;
    }
    return 0;
}
int main() {
    TSMatrix M, T;
    inpMx(M);
    Tranpose(M, T);
    for (int i = 1; i <= T.tu; i++) {
        cout << T.data[i].i << ' ' << T.data[i].j << ' ' << T.data[i].e << endl;
    }
    return 0;
}