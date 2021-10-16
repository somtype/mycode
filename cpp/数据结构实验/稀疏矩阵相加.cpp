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
int ADD(TSMatrix &A, TSMatrix &B, TSMatrix &C) {
    C.tu = 0;
    C.mu = A.mu;
    C.nu = A.nu;
    int ia, ib, ic;
    ia = ib = ic = 1;
    while (ia <= A.tu && ib <= B.tu) {
        int i1, i2, j1, j2, e1, e2;
        i1 = A.data[ia].i;
        j1 = A.data[ia].j;
        e1 = A.data[ia].e;
        i2 = B.data[ib].i;
        j2 = B.data[ib].j;
        e2 = B.data[ib].e;
        if (i1 == i2 && j1 == j2) {
            int temp = e1 + e2;
            if (temp) {
                C.data[ic].i = i1;
                C.data[ic].j = j1;
                C.data[ic].e = temp;
                C.tu++;
                ic++;
            }
            ia++;
            ib++;
        } else {
            if (i1 < i2 || (i1 == i2 && j1 < j2))
                C.data[ic++] = A.data[ia++];
            else if (i1 > i2 || (i1 == i2 && j1 > j2))
                C.data[ic++] = B.data[ib++];
            C.tu++;
        }
    }
    while (ia <= A.tu) {
        C.data[ic++] = A.data[ia++];
        C.tu++;
    }
    while (ib <= B.tu) {
        C.data[ic++] = B.data[ib++];
        C.tu++;
    }
    return 0;
}
int main() {
    TSMatrix A, B, C;
    inpMx(A);
    inpMx(B);
    if (A.mu == B.mu && A.nu == B.nu)
        ADD(A, B, C);
    else {
        cout << "ERROR";
        return 0;
    }
    int i, j, ic = 1;
    for (i = 1; i <= C.mu; i++) {
        for (j = 1; j <= C.nu; j++) {
            if (C.data[ic].i == i && C.data[ic].j == j)
                cout << C.data[ic++].e << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}