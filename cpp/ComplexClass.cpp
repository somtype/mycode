#include <iostream>
using namespace std;
class Complex {
  public:
    Complex(double newReal = 0, double newImg = 0);
    Complex(const Complex &tempc);
    ~Complex();
    void add(const Complex &tempc); //复数加法
    void show();

  private:
    double rel, img;
};
Complex::Complex(double newReal, double newImg)
    : rel(newReal), img(newImg) {}
Complex::Complex(const Complex &tempc) : rel(tempc.rel), img(tempc.img) {}
Complex::~Complex() {}
void Complex::add(const Complex &tempc) {
    rel += tempc.rel, img += tempc.img;
}
void Complex::show() {
    if (img == 0)
        cout << rel << endl;
    else {
        cout << rel << " + " << img << 'i' << endl;
    }
}
int main() {
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}