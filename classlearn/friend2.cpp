#include <iostream>
using namespace std;
class A
{
public:
    A() { a = 5; }
    void printa() { cout << "A:a = " << a << endl; }

private:
    int a;
    friend class B;
};
class B
{
public:
    void display1(A t)
    {
        t.a++;
        cout << "display1:a = " << t.a << endl;
    };
    void display2(A t)
    {
        t.a--;
        cout << "display2:a = " << t.a << endl;
    };
};
int main()
{
    A obj1;
    B obj2;
    obj1.printa();
    obj2.display1(obj1);
    obj2.display2(obj1);
    obj1.printa();
}
