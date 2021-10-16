#include <cstring>
#include <iostream>
using namespace std;
class HW {
  public:
    int a;

  private:
    void Fun();
};
int main() {
    HW myhw1;
    myhw1.a = 3;
    cout << myhw1.a;
}