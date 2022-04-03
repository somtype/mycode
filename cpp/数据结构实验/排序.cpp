#include "algorithm"
#include "cstring"
#include "iomanip"
#include "iostream"
#define maxN 100010
using namespace std;

//快排
int Partition(int *L, int low, int high) {
    L[0] = L[low];
    while (low < high) {
        while (low < high && L[high] > L[0])
            high--;
        L[low] = L[high];
        while (low < high && L[low] < L[0])
            low++;
        L[high] = L[low];
    }
    L[low] = L[0];
    return low;
}
void QuickSort(int *L, int low, int high) {
    if (low < high) {
        int king = Partition(L, low, high);
        QuickSort(L, low, king - 1);
        QuickSort(L, king + 1, high);
    }
}
//快排

//堆排
void HeapAdjust(int *L, int s, int m) {
    int rc = L[s];
    for (int j = s * 2; j <= m; j *= 2) {
        if (j < m && L[j] < L[j + 1]) j++;
        if (L[j] < rc) break;
        L[s] = L[j];
        s = j;
    }
    L[s] = rc;
}
void HeapSort(int *L, int length) {
    for (int i = length / 2; i > 0; i--)
        //建堆
        HeapAdjust(L, i, length);
    for (int i = length; i > 1; i--) {
        int temp = L[1];
        L[1] = L[i];
        L[i] = temp;
        HeapAdjust(L, 1, i - 1);
    }
}
//堆排

//插入排序
void InsertSort(int *L, int length) {
    for (int i = 2; i <= length; i++) {
        int king = L[i];
        int j;
        for (j = i - 1; j >= 1; j--) {
            if (L[j] > king)
                L[j + 1] = L[j];
            else
                break;
        }
        L[j + 1] = king;
    }
}
//插入排序

void PTN(int *L, int length) {
    int first = 1;
    for (int i = 1; i <= length; i++) {
        if (first)
            first = 0;
        else
            cout << ' ';
        cout << L[i];
    }
}
int main() {
    int n;
    int L[maxN];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> L[i];
    QuickSort(L, 1, n);
    PTN(L, n);
    return 0;
}