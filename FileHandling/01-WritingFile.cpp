#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ofstream of1;
    of1.open("myfile.txt");
    of1<<"Hi I am Priyanshi here";
    of1.close();
    return 0;
}