#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream if1;
    if1.open("myfile.txt");
    char c;
    c=if1.get();
    while(if1.eof()==0)
    {
        cout<<c;
        c=if1.get();
    }
    if1.close();
    return 0;
}