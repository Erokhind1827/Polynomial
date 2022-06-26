#include "polynomial.h"

ostream &operator<<(ostream& out, Polynomial& p)
{
    int i;
    for (i=p.p;i>=0;i--)
    {
        out<<p.A[i];
        if (i!=0)
            out<<"x^"<<i<<" + ";
    }
    out<<endl;
    return out;
}

istream &operator>>(istream& in, Polynomial& p)
{
    int i;
    for (i=p.p;i>=0;i--)
    {
        cout<<"input coef for x^"<<i<<endl;
        in>>p.A[i];
    }
    return in;
}

float Polynomial::pvalue(int x)
{
    float y=A[0];
    for (int i=1;i<=p;i++)
    {
        y+=A[i]*pow(x,i);
    }
    return y;
}

void Polynomial::setCoef(int choice)
{
    srand(time(NULL));
    A=new float[p+1];
    if (choice==1)
    {
        cin>>*this;
    }
    else
    {
        int min,max,i;
        cout << "input the range(MIN|MAX) for coefficient(s)"<<endl;
        cin >> min >> max;
        for(i=0;i<=p;i++)
        {
            A[i]=min+rand()%(max-min+1);
        }
    }
}

Polynomial Polynomial::operator=(Polynomial &pol)
{
//    if (*this!=pol)
        this->p=pol.p;
        this->A=new float[p+1];
        for (int i=0;i<=p;i++)
            this->setEl(i,pol.A[i]);
        return *this;
//    return *this;
}

bool Polynomial::operator!=(Polynomial &obj)
{
    if(p!=obj.p)
        return false;
    for (int i=0;i<=p;i++)
    {
        if (A[i]!=obj.A[i])
            return false;
    }
    return true;
}

Polynomial& Polynomial::operator*(Polynomial &obj)
{
    Polynomial *mult= new Polynomial(this->p+obj.p);
    mult->A=new float[this->p+obj.p+1];
    for(int i=0;i<=mult->p;i++)
        mult->A[i]=0;
    for(int i=0;i<=this->p;i++)
        for(int j=0;j<=obj.p;j++)
            mult->A[i+j]+=this->A[i]*obj.A[j];
    return *mult;
}

Polynomial &Polynomial::operator+(Polynomial &obj)
{
    int i,n=min(obj.p,this->p);
    Polynomial *sum= new Polynomial(max(obj.p,this->p));
    sum->A= new float(max(obj.p,this->p)+1);
    for (i=0;i<=n;i++)
    {
        sum->A[i]=this->A[i]+obj.A[i];
    }
    if (obj.p>n)
    {
        for (i=n+1;i<=obj.p;i++)
            sum->A[i]=obj.A[i];
    }
    if (this->p>n)
    {
        for (i=n+1;i<=this->p;i++)
            sum->A[i]=this->A[i];
    }
    return *sum;
}

Polynomial& Polynomial::derivative()
{
    int i;
    Polynomial *dptr;
    if (p!=0)
    {
        Polynomial dp(p-1);
        dptr=&dp;
        dp.A=new float[p];
        for (i=1;i<=p;i++)
        {
            dp.setEl(i-1,i*A[i]);
        }
    }
    if (p==0)
    {
        Polynomial dp(0);
        dp.A=new float[1];
        dptr=&dp;
        dp.A[0]=0;
//        A[0]=0;
//        dptr=this;
    }
    return *dptr;
}

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int min(int a,int b)
{
    if(a<=b)
        return a;
    else
        return b;
}
