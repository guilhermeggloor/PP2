#include<iostream>
#include<string>
using namespace std;

class DFrac{
    int num;
    unsigned den;
unsigned mmc(DFrac other) const{
            unsigned n1,n2,div,mmc;

            n1  = den;
            n2  = other.den;
            mmc = 1;
            div = 2;

            //enquanto n1>1 ou n2>1, faça            
            //  se n1 ou n2 é divisivel por div, então
            //      se n1 é divisivel por div, então
            //          n1 = n1/div
            //      se n2 é divisivel por div, então
            //          n2 = n2/div 
            //      mmc = mmc * div 
            //  senão
            //      div = div + 1 
            //retorne mmc

            //enquanto n1>1 ou n2>1, faça
            while(n1>1 || n2>1){
            //  se n1 ou n2 é divisivel por div, então
                if(!(n1 % div) || !(n2 % div)){
            //      se n1 é divisivel por div, então
                    if(!(n1 % div))
            //          n1 = n1/div
                        n1 = n1/div;
            //      se n2 é divisivel por div, então
                    if(!(n2 % div))
            //          n2 = n2/div 
                        n2 = n2/div;
                                        
            //      mmc = mmc * div 
                    mmc = mmc * div;
                }
            //  senão
                else
            //      div = div + 1 
                    div++;
            }
            //retorne mmc
            return mmc;
        }
        unsigned mdc(DFrac other) const{
            unsigned n1,n2,div,mdc;

            n1  = den;
            n2  = other.den;
            mdc = 1;
            div = 2;

            while(n1>1 || n2>1){
                if(!(n1 % div) || !(n2 % div)){
                    if(!(n1 % div))
                        n1 = n1/div;
                    if(!(n2 % div))
                        n2 = n2/div;
                    mdc = mdc * div;
                }
                else
                    div++;
            }
            return mdc;
        }
    public:
        DFrac(int num=0,unsigned den=1):
            num(num),
            den(den)
        {}

        int getNum(){
            return num;
        }
        unsigned getDen(){
            return den;
        }
        // operadores aritméticos
        DFrac operator +(const DFrac &other) const {
            unsigned mmc = this->mmc(other);

            return DFrac(mmc/den*num + mmc/other.den*other.num ,mmc);
        }
        DFrac operator -(const DFrac &other) const {
            unsigned mmc = this->mmc(other);

            return DFrac(mmc/den*num - mmc/other.den*other.num ,mmc);
        }
        DFrac operator *(const DFrac &other) const {
            return DFrac(num*other.num,den*other.den);
        }
        DFrac operator /(const DFrac &other) const {
            return DFrac(num*other.den,den*other.num);
        }
        // operadores de comperação
        bool operator < (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) < 0;
        
        }
        bool operator > (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) > 0;
        
        }
        bool operator <= (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) <= 0;
        
        }
        bool operator >= (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) >= 0;
        
        }
        bool operator == (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) == 0;
        
        }
        bool operator != (const DFrac &other) const {            
            unsigned mmc = this->mmc(other);

            return (mmc/den*num - mmc/other.den*other.num) != 0;
        
        }
        DFrac operator++() {
            num+=den;
            return *this;
        }
        DFrac operator ++(int) {
            int oldNum;
            oldNum = num;
            num+=den;
            return DFrac(oldNum,den);
        }

};
int main(){
    //tarefa: implementar os operadores binários -, *, /, >, <= e >=

    DFrac f1,f2(1,2),f3(1,3);
    bool b;

    f1 = f2 * f3;
    b  = f2 == f3;

    unsigned a=5, c=6;
    a = a - c;

    cout<<f1.getNum()<<'/'<<f1.getDen();

    return 0;
}

// a = 3;
// x = a++; ????
// resposta: x = a;
// a = 3;    a = a + 1;

//a = 3;
//x = ++a; ????
//resposta: a = a + 1;
//y = a;

// a = 1;       (a++)+(b++)
// b = 5; 
// x = a+++b    ++b++



