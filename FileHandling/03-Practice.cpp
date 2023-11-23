#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxi(double,double);
int maxi(double &, double &);

struct book
{
    int bookid;
    char title[20];
    float price;
};
// void main()
// {
//     book b2;
//     b2.bookid=101;
//     strcpy(b2.title,"c++ learning");
// }

class Complex{
    private:
        int a,b;
    public:
        void set_data(int x,int y)
        {
            a=x;
            b=y;
        }
        void show_data()
        {
            cout<<"real part is: "<<a;
            cout<<"Complext part is: "<<b;
        }
        Complex add(Complex &ob)
        {
            Complex temp;
            temp.a=ob.a+a;
            temp.b=ob.b+b;
            return temp;
        }
};

int main()
{
    Complex a,b,c;
    a.set_data(3,9);
    b.set_data(4,6);
    c=a.add(b);
    c.show_data();
    return 0;
}