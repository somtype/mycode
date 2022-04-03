#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void Perm1(int *A, int l, int r) {
	//算法设计与分析P37
	if (l == r) {
		for (int i = 0; i <= r; i++)
			cout << A[i] << " ";
		cout << endl;
	} else {
		for (int j = l; j <= r; j++) {
			swap(A[l], A[j]);
			Perm1(A, l + 1, r);
			swap(A[l], A[j]);
		}
	}
}
void Perm2(int *A,int n,int m){
	//算法设计与分析P38
	if(m==0){
		for (int i = 0; i < n;i++)
			cout << A[i] << " ";
		cout << endl;
	}
	else{
		for (int j = 0; j < n;j++){
			if(A[j]==0){
				A[j] = m;
				Perm2(A, n, m - 1);
				A[j] = 0;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	int A[100];
	for (int i = 0; i < n;i++)
		A[i] = i + 1;
	cout << "Perm1" << endl;
	Perm1(A, 0, n - 1);
	memset(A, 0, sizeof(A));
	cout << "Perm2" << endl;
	Perm2(A, n, n);
	return 0;
}
