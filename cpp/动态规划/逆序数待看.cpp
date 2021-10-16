#include "algorithm"
#include "cstring"
#include "iostream"
#include "vector"
#define For(a, begin, end) for (register int a = begin; a <= end; ++a)
#define rFor(a, end, begin) for (register int a = end; a >= begin; --a)
using namespace std;
typedef int ElementType;
long long sum = 0;                                         //逆序数的个数
void MergeSort(int arr[], int tmp[], int L, int rightend); //归并排序
void MergeAndCountNum(int arr[], int tmp[], int L, int R,
                      int rightend); //归并有序序列并计算逆序数的个数

int main() {
  int n;
  cin >> n;
  ElementType *a = (ElementType *)malloc(n * sizeof(ElementType));
  ElementType *tmp = (ElementType *)malloc(n * sizeof(ElementType));
  for (int i = 0; i < n; i++)
    cin >> a[i];
  MergeSort(a, tmp, 0, n - 1);
  cout << sum << endl;
  free(a);
  free(tmp);
  return 0;
}
//归并排序
void MergeSort(int a[], int tmp[], int L, int rightend) {
  if (L < rightend) {
    int center = L + (rightend - L) / 2;
    MergeSort(a, tmp, L, center);
    MergeSort(a, tmp, center + 1, rightend);
    MergeAndCountNum(a, tmp, L, center + 1, rightend);
  }
}
//归并有序序列并计算逆序数的个数
void MergeAndCountNum(int a[], int tmp[], int L, int R,
                      int rightend) // tmp（）是作为临时数组
{
  int leftend = R - 1;
  int i = L, j = R;
  int k = L;
  while (i <= leftend && j <= rightend) {
    if (a[i] < a[j])
      tmp[k++] = a[i++];
    else {
      tmp[k++] = a[j++];
      sum = sum + (leftend - i + 1); //核心
    }
  }
  while (i <= leftend)
    tmp[k++] = a[i++];
  while (j <= rightend)
    tmp[k++] = a[j++];
  for (i = L; i <= rightend; i++)
    a[i] = tmp[i];
}
