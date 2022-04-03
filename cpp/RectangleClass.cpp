#include <cmath>
#include <iostream>
using namespace std;
class Point {
  public:
    Point(double newX = 0, double newY = 0);
    Point(const Point &tempP);
    ~Point();
    double getX();
    double getY();

  private:
    double x, y;
};
Point::Point(double newX, double newY) : x(newX), y(newY) {}
Point::Point(const Point &tempP) : x(tempP.x), y(tempP.y) {}
Point::~Point() {}
double Point::getX() {
    return x;
}
double Point::getY() {
    return y;
}
class Rectangle {
  public:
    Rectangle(Point newP1, Point newP2);
    Rectangle(const Rectangle &tempR);
    ~Rectangle();
    void show();

  private:
    Point p1, p2;
    double area;
};
Rectangle::Rectangle(Point newP1, Point newP2) {
    p1 = newP1, p2 = newP2;
    area = fabs(p1.getX() - p2.getX()) * fabs(p1.getY() - p2.getY());
}
Rectangle::Rectangle(const Rectangle &tempR)
    : p1(tempR.p1), p2(tempR.p2), area(tempR.area) {}
Rectangle::~Rectangle() {}
void Rectangle::show() {
    printf("p1:(%.3f,%.3f)   p2:(%.3f,%.3f)   area=%.3f", p1.getX(), p1.getY(),
           p2.getX(), p2.getY(), area);
}
int main() {
    Point p1(1, 1), p2(3, 5);
    Rectangle myR(p1, p2);
    myR.show();
    return 0;
}