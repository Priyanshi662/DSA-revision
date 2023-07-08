#include <iostream>
#include <string>
using namespace std;

string intToRom(int x)
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string res="";
    int n=12;
    while(x>0)
    {
        int div=x/num[n];
        x=x%num[n];
        while(div--)        
        {
            res+=(sym[n]);
        }
        n--;
    }
    return res;
}
int main()
{
    int x=1904;
    cout<<intToRom(x)<<endl;
    return 0;
}