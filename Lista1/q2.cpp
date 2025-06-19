#include <iostream>
#include <cmath>

using namespace std;

class SecondDegree
{
private:
    double a, b, c;
    double delta;

public:
    // Construtor
    SecondDegree() : a(0), b(0), c(0), delta(0) {}

    // Métodos para definir os coeficientes
    void setABC(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
        calcularDelta();  // Atualiza o valor de delta
    }

    // Método para calcular delta
    void calcularDelta() {
        delta = (b * b) - (4 * a * c);
    }

    // Método para obter delta
    double getDelta() {
        return delta;
    }

    // Método para calcular as raízes
    bool getRoots(double &x1, double &x2) {
        if (delta < 0) {
            cout << "A equação não possui raízes reais." << endl;
            return false;
        }

        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        return true;
    }

    // Método para calcular o vértice da parábola
    void getVertex(double &xv, double &yv) {
        xv = -b / (2 * a);
        yv = -delta / (4 * a);
    }
};

int main()
{
    SecondDegree c1;
    c1.setABC(1, -3, 2);  // Exemplo: x² - 3x + 2

    cout << "Delta: " << c1.getDelta() << endl;

    double x1, x2;
    if (c1.getRoots(x1, x2)) {
        cout << "Raízes: x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    double xv, yv;
    c1.getVertex(xv, yv);
    cout << "Vértice: (" << xv << ", " << yv << ")" << endl;

    return 0;
}
