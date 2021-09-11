#include <iostream>
#include <string>

class Shape {
public:
  virtual std::string getName() = 0;
  virtual double getPerimeter() = 0;
  virtual double getArea() = 0;

private:
  std::string name_ = "Shape";
};

class Rectangle : public Shape {
public:
  Rectangle(double l, double w) : l_(l), w_(w) {}
  std::string getName() { return name_; }
  double getPerimeter() { return 2 * (l_ + w_); }
  double getArea() { return l_ * w_; }

private:
  std::string name_ = "Rectangle";
  double l_;
  double w_;
};

class Circle : public Shape {
public:
  Circle(double r) : r_(r) {}
  std::string getName() { return name_; }
  double getPerimeter() { return 2 * r_ * 3.14; }
  double getArea() { return r_ * r_ * 3.14; }

private:
  std::string name_ = "Circle";
  double r_;
};

void printArea(Shape &shape) { std::cout << shape.getArea() << std::endl; }

int main() {
  Rectangle r = Rectangle(10, 20);
  Circle c = Circle(10.0);
  printArea(c);
  printArea(r);
}
