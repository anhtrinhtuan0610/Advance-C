#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() {
        return x;
    }

    double getY() {
        return y;
    }

    double distanceTo(Point other) {
        double dx = other.getX() - x;
        double dy = other.getY() - y;
        return sqrt(dx*dx + dy*dy);
    }

    double areaOfTriangle(Point p1, Point p2) {
        double a = distanceTo(p1);
        double b = distanceTo(p2);
        double c = p1.distanceTo(p2);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    double distance = p1.distanceTo(p2);
    std::cout << "Khoang cach giua hai diem: " << distance << std::endl;

    Point p3(5, 6);
    double area = p1.areaOfTriangle(p2, p3);
    std::cout << "Dien tich tam giac: " << area << std::endl;

    return 0;
}