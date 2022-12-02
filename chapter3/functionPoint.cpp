// 例3-21  用函数指针调用函数
#include <iostream>
using namespace std;
int sum(int x, int y) { return x + y; }
int product(int x, int y) { return x * y; }
int main()
{
    // int (*pf)(int, int);
    typedef int Pf  (int,int);
    Pf *pf;
    int a, b, result;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    pf = sum;
    result = pf(a, b);
    cout << a << " + " << b << " = " << result << endl;
    pf = product;
    result = pf(a, b);
    cout << a << " * " << b << " = " << result << endl;
}
