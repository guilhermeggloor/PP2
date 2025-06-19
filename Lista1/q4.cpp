#include <iostream>
#include <cmath>

class Triangulo
{
    double x, y;

public:
    Triangulo() : x(0.0), y(0.0) {};

    Triangulo(double A, double B, double C) : x(x), y(y) {}

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    void setXY(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    
};

int main()
{

    return 0;
}