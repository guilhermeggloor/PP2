#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// exercicio: calcular a distancia entre os dois pontos

class pointR2
{
    float x, y;

public:
    pointR2(const float x = 0, float y = 0) : x(x),
                                              y(y)
    {
    }
    pointR2(const pointR2 &other) : x(other.x),
                                    y(other.y)
    {
    }
    void setX(float y)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }

    float distance(const pointR2 &other)
    {
        return sqrt(pow(y - other.y, 2.0) + pow(x - other.x, 2.0));
    }
};

class Circunference
{
    float radius;
    float center;

public:
    Circunference() : // um construtor padrão

                      radius(1.0),
                      center(1.0)
    {
    }

    Circunference(float r) : radius(r) // um construtor parametrizado
    {
    }

    Circunference(const Circunference &other)
    {
    }
    void setRadius(float radius)
    {
        this->radius = radius;
    }
    float getRadius()
    {
        return radius;
    }
    ~Circunference() {};

    float area()
    {
        return M_PI * pow(radius, 2.0);
    }
    float perimeter()
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    Circunference c1(4.0), c2(c1);
    c2 = c1;
    pointR2 p1(1.0, 2.0);
    pointR2 p2(3.0, 4.0);
    // Circunference *pC = new Circunference(2.0);

    cout << "Circunferencia: " << c1.area() << ' ' << "Perimetro: " << c1.perimeter() << endl;
    cout << "distancia: " << p1.distance(p2) << endl;
    // cout << pC->area() << ' ' << pC->perimeter() << endl;

    system("pause");
    // delete pC;
    return 0;
}