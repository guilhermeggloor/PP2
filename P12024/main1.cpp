#include<iostream>
#include<cmath>
using namespace std;
class DR2{
    float x,y;
    public:
        DR2(float x=0.0,float y=0.0):
        x(x),
        y(y)
        {}
        float getX() const{
            return x;
        }
        float getY() const{
            return y;
        }
        bool operator ==(const DR2 &other) const{
            return x==other.x && y==other.y;
        }        
        bool operator !=(const DR2 &other) const{
            return x!=other.x || y!=other.y;
        }
        DR2 operator+(const DR2 &other) const{
            return DR2(x+other.x,y+other.y);
        }
        DR2 operator-(const DR2 &other) const{
            return DR2(x-other.x,y-other.y);
        }
        DR2 operator++(){//pre
            x++;
            y++;
            return *this;
        }        
        DR2 operator++(int){//pos
            float x,y;
            x = this->x++;
            y = this->y++;
            return DR2(x,y);
        }
        DR2 operator--(){//pre
            x--;
            y--;
            return *this;
        }        
        DR2 operator--(int){//pos
            float x,y;
            x = this->x--;
            y = this->y--;
            return DR2(x,y);
        }
};
class DPolar{
    float phi,r;
    public:
        DPolar(float phi=0.0,float r=0.0):
        phi(phi),
        r(r)
        {}
        DPolar(const DR2 &other){
            phi = atan2(other.getY(),other.getX());
            r   = sqrt(pow(other.getX(),2)+pow(other.getY(),2));
        }
        operator DR2() const{
            return DR2(r*cos(phi),r*sin(phi));
        }
        float getPhi() const{
            return phi;
        }        
        float getR() const{
            return r;
        }

};
int main(){
    DR2 r2(1,1);
    DPolar p;

    p = r2;//construtor de copia
    cout << p.getR()<<' '<<p.getPhi()<<endl;
    r2 = p;//op casting
    cout << r2.getX()<<' '<<r2.getY()<<endl;

    return 0;
}