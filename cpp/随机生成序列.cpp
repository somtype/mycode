#include <iostream>
using namespace std;
int main() {
    srand(time(0));
    for (int i = 0; i < 25; i++) {
        cout << char(rand() % 26 + 'a');
    }
    cout << endl;
    for (int i = 0; i < 25; i++) {
        cout << char(rand() % 26 + 'a');
    }
    cout << endl;
    return 0;
}