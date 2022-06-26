#include <iostream>
#include "polynomial.h"
using namespace std;

string printcount(int i);
void instructions();

int main()
{
    int n,x,choice,z;
    instructions();
    cout << "? ";
    cin >> choice;
    while (choice != 0)
    {
        switch(choice)
        {

            case 1:
            {
                cout<<endl<<"!polynomial and it's derivatives!"<<endl<<endl;
                cout<<"input the power of your polynomial"<<endl;
                cin>>n;
                Polynomial p(n);
                do
                {
                    cout << "1 for manual, 2 for random" <<endl;
                    cin >> choice;
                } while (choice<1||choice>2);
                p.setCoef(choice);
                cout<<"your polynomial is:"<<endl;
                cout<<p;
                cout<<"input x"<<endl;
                cin>>x;
                cout<<"p("<<x<<")= "<<p.pvalue(x)<<endl;
                Polynomial dp=p.derivative();
                cout<<"your derivaive is:"<<endl;
                cout<<dp;
                n=2;
                do
                {
                    cout<<"do you want to take another derivative? 1 for yes"<<endl;
                    cin>>z;
                    if (z==1)
                    {
                        cout<<"your "<<printcount(n)<<" derivative is:"<<endl;
                        Polynomial ddp=dp.derivative();
                        dp=ddp;
                        cout<<dp;
                        n++;
                    }
                } while (z==1);
                break;
            }
            case 2:
            {
                cout<<endl<<"!summation!"<<endl<<endl;
                int l1,l2;
                cout<<"input the lengths(l1,l2)"<<endl;
                cin>>l1>>l2;
                Polynomial p1(l1),p2(l2),res;
                p1.setCoef(1);
                p2.setCoef(1);
                res=p1+p2;
                cout<<res;
                break;
            }
            case 3:
            {
                cout<<endl<<"!multiplication!"<<endl<<endl;
                int l1,l2;
                cout<<"input the lengths(l1,l2)"<<endl;
                cin>>l1>>l2;
                Polynomial p1(l1),p2(l2),res;
                p1.setCoef(1);
                p2.setCoef(1);
                res=p1*p2;
                cout<<res;
                break;
            }
            default:
            {
                cout<<"invalid choice"<<endl<<endl;
                instructions();
                break;
            }
        }
        cout<<endl<<"? ";
        cin >> choice;
    }
    cout<<"end of run."<<endl;
    return 0;
}

string printcount(int i)
{
    cout<<i;
    string str;
    if ((i%10==1) && (i!=11))
        str="st";
    else
        if ((i%10==2) && (i!=12))
            str="nd";
        else
            if ((i%10==3) && (i!=13))
                str="rd";
            else
                str="th";
    return str;
}

void instructions()
{
    cout<<"enter your choice:"<<endl;
    cout<<"1 to enter your polynomial and find it's any derivative;"<<endl;
    cout<<"2 to get the sum of two polynomials;"<<endl;
    cout<<"3 to get the multiplication of two polynomial;"<<endl;
    cout<<"0 to end the run."<<endl;
}
