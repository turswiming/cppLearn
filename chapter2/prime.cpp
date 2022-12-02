#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int i;
    long m;
    cout << "Please input a number:\n";
    cin >> m;
    double sqrtm = sqrt(m); //函数sqrt是double类型
    for (i = 2; i <= sqrtm; i++)
    {
        if (m % i == 0)
        {
            break;
        }
    }

    if (sqrtm < i)
        cout << m << " is prime." << endl;
    else
        cout << m << " is not prime." << endl;
}
