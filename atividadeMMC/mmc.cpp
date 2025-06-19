#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>

// Escreva um algoritmo para calcuilo do m.m.c de dois valores

// Crie uma classe para representar frações e implemente uma função para mmc
// do b de duas frações ("this" e "other")

using namespace std;

class MMC {
    int a, b;
public:
    
    MMC(int a = 0, int b = 0) : a(a), b(b)
    {}
    MMC(const MMC &other) : a(other.a), b(other.b)
    {}

    void seta(int a)
    {
        this->a = a;
    }
    int geta() const 
    {
        return a;
    }

    void setb(int b)
    {
        this->b = b;
    }

    int getb() const
    {
        return b;
    }


    int gcd(int a, int b)
    {
        while(b != 0 ) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int mmc(int a, int b) {
        return (a * b ) / gcd(a, b);
    }

    int operator%(const MMC& other) {
        return mmc(this->b, other.b);
    }

    MMC operator+(const MMC &other) {
        unsigned mmc = this->mmc(other.b, this->b);

        return MMC(mmc/b*a + mmc/other.b*other.a, mmc);


    }
};

int main()
{
    MMC f1(4, 6);
    MMC f2(3, 6);

    int resultadoMMC = f1 % f2;

     cout << "MMC dos denominadores de " << f1.geta() << "/" << f1.getb()
         << " e " << f2.geta() << "/" << f2.getb() << " é: " << resultadoMMC << endl;

    return 0;
}