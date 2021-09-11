#include <stdio.h>

enum Shape_Type { CIRCLE, RECTANGLE };

struct Shape {
  enum Shape_Type shape_type;
  union {
    struct {
      double l;
      double w;
    };
    struct {
      double r;
    };
  };
  char *(*getName)(struct Shape);
  double (*getArea)(struct Shape);
  double (*getPerimeter)(struct Shape);
};

char *getName(struct Shape s) {
  if (s.shape_type == CIRCLE)
    return "Circle";
  else if (s.shape_type == RECTANGLE)
    return "Rectangle";
  else
    return "Shape";
}

double getArea(struct Shape s) {
  if (s.shape_type == CIRCLE)
    return s.r * s.r * 3.14;
  else if (s.shape_type == RECTANGLE)
    return (s.l + s.w) * 2;
  return 0;
}

double getPerimeter(struct Shape s) {
  if (s.shape_type == CIRCLE)
    return s.r * 2 * 3.14;
  else if (s.shape_type == RECTANGLE)
    return s.l * s.w;
  return 0;
}

struct Shape makeShape() {
  struct Shape s = {
      .getName = getName, .getArea = getArea, .getPerimeter = getPerimeter};
  return s;
}

struct Shape makeCircle(double r) {
  struct Shape c = makeShape();
  c.shape_type = CIRCLE;
  c.r = r;
  return c;
}

struct Shape makeRectangle(double l, double w) {
  struct Shape r = makeShape();
  r.shape_type = RECTANGLE;
  r.l = l;
  r.w = w;
  return r;
}

int main() {
  struct Shape c = makeCircle(10);
  printf("My perimeter is: %f\n", c.getPerimeter(c));
  printf("My area is: %f\n", c.getArea(c));
  printf("My name is: %s\n", c.getName(c));
  struct Shape r = makeRectangle(20, 40);
  printf("My perimeter is: %f\n", r.getPerimeter(r));
  printf("My area is: %f\n", r.getArea(r));
  printf("My name is: %s\n", r.getName(r));
}
