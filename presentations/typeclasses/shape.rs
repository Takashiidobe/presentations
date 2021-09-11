use std::fmt::Debug;

trait Shape {
    fn get_name(&self) -> String;
    fn get_area(&self) -> f32;
    fn get_perimeter(&self) -> f32;
}

#[derive(Debug)]
struct Circle {
    r: f32,
    name: String,
}

impl Circle {
    fn new(r: f32) -> Circle {
        Circle {
            r,
            name: "Circle".to_string(),
        }
    }
}

impl Shape for Circle {
    fn get_name(&self) -> String {
        self.name.clone()
    }

    fn get_area(&self) -> f32 {
        self.r * self.r * 3.14
    }

    fn get_perimeter(&self) -> f32 {
        self.r * 2.0 * 3.14
    }
}

#[derive(Debug)]
struct Rectangle {
    l: f32,
    w: f32,
    name: String,
}

impl Rectangle {
    fn new(l: f32, w: f32) -> Rectangle {
        Rectangle {
            l,
            w,
            name: "Rectangle".to_string(),
        }
    }
}

impl Shape for Rectangle {
    fn get_name(&self) -> String {
        self.name.clone()
    }

    fn get_area(&self) -> f32 {
        self.l * self.w
    }

    fn get_perimeter(&self) -> f32 {
        (self.l + self.w) * 2.0
    }
}

fn print_area<T>(t: T)
where
    T: Shape + Debug,
{
    println!("{:?}", t);
}

fn main() {
    let circle = Circle::new(10.0);
    println!("{}", circle.get_perimeter());
    let rectangle = Rectangle::new(10.0, 20.0);
    println!("{}", rectangle.get_perimeter());
    print_area(rectangle);
    print_area(circle);
}
