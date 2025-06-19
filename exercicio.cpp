// Implemente uma classe para apresentar ciruclos, com as funcionalidades de
// calculado de área e circunferencia. IMplemente o construtor padrão,
// com raio 1, getters e setters.
// obs: o valor de pi pode ser encontrado/incluido em math.h e cmath.h

#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
private:
    float raio;

public:
    Circle()
    {
        raio = 1;
    }

    float getRaio()
    {
        return raio;
    }

    void setRaio(float raio)
    {
        this->raio = raio;
    }

    float area()
    {
        return M_PI * pow(raio, 2);
    }

    float circunference()
    {
        return 2 * M_PI * raio;
    }
};

int main()
{
    Circle c1;
    c1.setRaio(4);

    cout << "Area do circulo: " << c1.area() << endl;

    cout << "\nCircunferencia: " << c1.circunference() << endl;

    return 0;
}