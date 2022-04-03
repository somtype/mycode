#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    const int MAXN = 10;
    int array[MAXN] = {1, 2, 3, 4, 6, 7, 7, 8, 9, 10};
    cout << *lower_bound(array, array + MAXN, 5) << endl;
    cout << *upper_bound(array, array + MAXN, 5) << endl;
    return 0;
}