#include <cmath>
#include <iostream>
using namespace std;
int main() {
    string s;
    string::iterator iter;
    cin >> s;
    for (iter = s.begin(); iter < s.end(); iter++) {
        if (*iter > 'a' && *iter < 'z')
            cout << *iter - 'a' << ' ';
        if (*iter > 'A' && *iter < 'Z')
            cout << *iter - 'A' << ' ';
    }
    cout << endl;
    return 0;
}