#include<iostream>
#include <vector>
using namespace std;

#define PI 3.1415

class DFigs {
    public:
        virtual float calcArea() = 0;
        virtual ~DFigs() {}
};
//NOVA_GEOMETRIA(DQuad,float l, l*l)
class DCircunf:public DFigs{;
    float r;
    public:
        DCircunf(float r=1.0) : r(r)
        {}
        virtual float calcArea() override {
            return  PI * r*r;
        }
};
class DQuad : public DFigs{
    float l;
    public:
        DQuad(float l=1.0) : l(l)
        {}
        virtual float calcArea(){
            return l*l;
        }
};
class DTriang : public DFigs{
    float b,h;
    public:
        DTriang(float b=1.0, float h=1.0) : b(b),h(h)
        {}
        virtual float calcArea(){
            return b*h/2.0;
        }
};

class DConjuntoDeFiguras : public vector<DFigs*> {
  public:
    float areaTotal() {
      float areaTotal = 0.0;
      for(size_t i = 0; i < size(); ++i)
        areaTotal += at(i)->calcArea();
      return areaTotal;
    }
};
int main(){
  DConjuntoDeFiguras VFigs;

    vector<DFigs*> VPFigs;
    float areaTotal = 0.0;
    int i,n;

    VPFigs.push_back(new DQuad);
    VPFigs.push_back(new DTriang);
    VPFigs.push_back(new DCircunf);

    for(i=0,n=1; i<n; ++i)
        areaTotal += VPFigs.at(i)->calcArea();

    cout<<areaTotal<<endl;
    return 0;
}