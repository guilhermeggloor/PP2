#include <iostream>
#include <math.h>

using namespace std;

class Integer
{
private:
    int number;

public:
    // Integer()
    // {
    //     number = 1;
    // }

    Integer() : number(1) {}

    int getNumber()
    {
        return number;
    }

    void setNumber(int number)
    {
        this->number = number;
    }

    double SquareRoot() const
    {
        return sqrt(number);
    }

    int sum(const Integer &other) const
    {
        return number + other.number;
    }

    int plus2() const
    {
        return pow(number, 2);
    }
};

int main()
{
    Integer n1, n2;

    n1.setNumber(25);
    n2.setNumber(2);

    cout << "raiz quadrada: " << n1.SquareRoot() << endl;
    cout << "Soma: " << n1.sum(n2) << endl;
    cout << "Potencia de 2: " << n1.plus2() << endl;

    return 0;
}