#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

class Polynomial
{
    friend ostream &operator<<(ostream& ,Polynomial& );
    friend istream &operator>>(istream& ,Polynomial& );
public:
    Polynomial(int n=-1){p=n;};
    float pvalue(int x);
    void setCoef(int choice);
    void setEl(int i,float el){A[i]=el;};
    void setPower(int n){p=n;};
    Polynomial operator=(Polynomial& );
    bool operator!=(Polynomial&);
    Polynomial& operator*(Polynomial&);
    Polynomial& operator+(Polynomial&);
    Polynomial& derivative();
private:
    void randomSet();
    float* A;
    int p;
};

#endif // POLYNOMIAL_H
