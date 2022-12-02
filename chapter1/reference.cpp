// 例1-10  引用测试
#include <iostream>
using namespace std;
int main()
{
    int a = 2345;
    int *pa;
    int &ra = a;
    pa = &a;
    cout << a << '\t' << ra << '\t' << *pa << endl;
    cout << (&a) << '\t' << (&ra) << '\t' << pa << endl;
    cout << (&pa) << endl;
}
