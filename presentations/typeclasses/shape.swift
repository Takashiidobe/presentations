protocol Shape {
    func get_name() -> String;
    func get_area() -> Float;
    func get_perimeter() -> Float;
}

struct Rectangle : Shape {
    let l: Float;
    let w: Float;
    init(l: Float, w: Float) {
        self.l = l;
        self.w = w;
    }
    func get_name() -> String {
        "Rectangle"
    }
    func get_area() -> Float {
        w * l
    }
    func get_perimeter() -> Float {
        2 * (l * w)
    }
}

struct Circle : Shape {
    let r: Float;
    init(r: Float) {
        self.r = r;
    }
    func get_name() -> String {
        "Circle"
    }
    func get_area() -> Float {
        r * r * Float.pi
    }
    func get_perimeter() -> Float {
        2 * Float.pi * r
    }
}

func print_area(s: Shape) {
    print(s.get_area())
}

func main() {
    print_area(s: Circle(r: 10))
    print_area(s: Rectangle(l: 10, w: 20))
}
