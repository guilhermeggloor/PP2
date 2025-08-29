#include <iostream>

using namespace std;

class Base1 {
  public:
    Base1(int valor = 0) {
      cout << "Base1::construtor" << ' ' << "valor: " << valor << endl;
    }
    ~Base1() {
      cout << "Base1::destrutor" << endl;
    }
};
class Base2 {
  public:
    Base2(int valor = 0) {
      cout << "Base2::construtor" << ' ' << "valor: " << valor << endl;
    }
    ~Base2() {
      cout << "Base2::destrutor" << endl;
    }
};

class Der : private Base1, private Base2 {
  public:
    Der(int valor = 0):Base1(valor) {
      cout << "Der::construtor" << ' ' << "valor: " << valor << endl;
    }
    ~Der() {
      cout << "Der::destrutor" << endl;
    }
    void seuNome() {
      cout << "Der" << endl;
    }
};

int main()
{
  Der b(1);
  Base1 *pBase1 = &b;
  Base2 *pBase2 = &b;

  pBase1->seuNome();
  
  return 0;
}