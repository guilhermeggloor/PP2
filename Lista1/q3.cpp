#include <iostream>
#include <math.h>

class Point
{
private:
    double A, B;

public:
    Point() : A(0), B(0) {};

    Point(double a, double b) : A(a), B(b) {}

    double getA()
    {
        return A;
    }

    double getB()
    {
        return B;
    }

    void setAB(double A, double B)
    {
        this->A = A;
        this->B = B;
    }

    double distance(const Point &other) const
    {
        return sqrt(pow(B - other.A, 2) + pow(A - other.B, 2));
    }

    Point translation(const Point &other) const
    {
        return Point(A + other.A, B + other.B);
    }

    friend std::ostream &operator<<(std::ostream &out, const Point &p)
    {
        out << "(" << p.A << ", " << p.B << ")";
        return out;
    }
};

int main()
{
    Point c1;
    Point c2;

    c1.setAB(3, 4);
    c2.setAB(6, 8);

    std::cout << "pontos de x de linha 1: " << c1.getA() << std::endl;
    std::cout << "pontos de y de linha 1: " << c1.getB() << std::endl;
    std::cout << "pontos de x de linha 2: " << c2.getA() << std::endl;
    std::cout << "pontos de y de linha 2: " << c2.getB() << std::endl;
    std::cout << "distancia entre os dois: " << c1.distance(c2) << std::endl;

    std::cout << "Translação entre os pontos: " << c1.translation(c2) << std::endl;
    std::cout << "Translação entre os dois pontos: " << c2.translation(c1) << std::endl;
}