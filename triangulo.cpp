#include <iostream>

using namespace std;

class Triangle
{
private:
    float base, height;

public:
    Triangle()
    {
        base = height = 1;
    }

    float getBase()
    {
        return base;
    }

    float getHeight()
    {
        return height;
    }

    void setBase(float base)
    {
        this->base = base;
    }

    void setHeight(float height)
    {
        this->height = height;
    }

    float area()
    {
        return (this->base * this->height) / 2;
        // return (base*height)/2;
    }
    ~Triangle()
    {
        cout << "Destrutor" << endl;
    }
};

int main(void)
{
    Triangle t1;
    t1.setBase(1);
    t1.setHeight(1);

    cout << t1.getBase() << ',' << t1.getHeight() << endl;

    return 0;
}