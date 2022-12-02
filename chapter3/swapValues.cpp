#include <iostream>
int facturial(int n)
{
    if (n == 0)
    {
    }
    else
    {
    }
};

void swapValue(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
    return;
}
int &returnMax(int &a, int &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
using namespace std;
int main()
{
    int i = 2, j = 5;
    cout << "i=" << i << "  "
         << "j=" << j << endl;
    swapValue(i, j);
    cout << "i=" << i << "  "
         << "j=" << j << endl;
    cout << "i=" << &i << "  "
         << "j=" << &j << endl;
    cout << &returnMax(i, j) << endl;

    return 0;
}