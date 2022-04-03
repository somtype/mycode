#include "iostream"
using namespace std;
int main() {
    int appleNum, plateNum;
    int PlaceApples(int appleNum, int plateNum);
    int ans, n;
    cin >> n;
    while (n--) {
        cin >> appleNum >> plateNum;
        ans = PlaceApples(appleNum, plateNum);
        cout << ans << endl;
    }
    return 0;
}
int PlaceApples(int appleNum, int plateNum) {
    if (appleNum == 0 || plateNum == 1) {
        return 1;
    } else if (plateNum == 0) {
        return 0;
    } else if (appleNum < plateNum) {
        return PlaceApples(appleNum, appleNum);
    } else {
        return PlaceApples(appleNum - plateNum, plateNum) +
               PlaceApples(appleNum, plateNum - 1);
    }
}