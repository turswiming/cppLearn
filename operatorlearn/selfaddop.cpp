#include <iostream>
using namespace std;
class Increase
{
public:
    Increase() { value = 0; }
    void display() const { cout << value << '\n'; };
    friend Increase operator++(Increase &);    // 前置
    friend Increase operator++(Increase &,int); // 后置
private:
    unsigned value;
};
Increase operator++(Increase & increase) // ++a 前置意思为先自增后使用此值
{
    increase.value++;
    return increase;
}
Increase operator++(Increase & increase, int)// a++ 后置意思为先使用此数值后自增1,
{
    Increase temp;
    temp.value = increase.value++;
    return temp;
}
int main()
{
    Increase a, b, n;
    int i;
    for (i = 0; i < 10; i++)
        a = n++;
    cout << "n= ";
    n.display();
    cout << "a= ";
    a.display();
    for (i = 0; i < 10; i++)
        b = ++n;
    cout << "n= ";
    n.display();
    cout << "b= ";
    b.display();
}
