#include <iostream>

class Point {
    int x, y, z;

    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y >> p.z;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << p.x << " " << p.y << " " << p.z;
        return os;
    }
};

class Rectangle {
    int length, breadth;

    friend std::istream& operator>>(std::istream& is, Rectangle& r) {
        is >> r.length >> r.breadth;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
        os << r.length << " " << r.breadth;
        return os;
    }
};

class Triangle {
    int base, height;

    friend std::istream& operator>>(std::istream& is, Triangle& t) {
        is >> t.base >> t.height;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Triangle& t) {
        os << t.base << " " << t.height;
        return os;
    }
};

int main() {
    Point p;
    Triangle t;
    Rectangle r;

    std::cin >> p >> t >> r;
    std::cout << p << " " << t << " " << r << std::endl;

    std::cin >> p >> r >> t;
    std::cout << p << " " << r << " " << t << std::endl;

    std::cin >> r >> t >> p;
    std::cout << r << " " << t << " " << p << std::endl;

    std::cin >> r >> p >> t;
    std::cout << r << " " << p << " " << t << std::endl;

    std::cin >> t >> r >> p;
    std::cout << t << " " << r << " " << p << std::endl;

    std::cin >> t >> p >> r;
    std::cout << t << " " << p << " " << r << std::endl;
}
