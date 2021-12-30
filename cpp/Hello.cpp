#include <cmath>
#include <iostream>
using namespace std;
class A {
  public:
    int num = 2;
    virtual void f() {cout << "A.f()" << endl; };
};
class B : public A {
  public:
    void f() { cout << "B.f()" << endl; }
};
int main() {
    A* pa = new B();
    pa->f();
    return 0;
}