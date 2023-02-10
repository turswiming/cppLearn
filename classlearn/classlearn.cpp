#include <iostream>
using namespace std;
class A
{

public:
    int data;
    A(int data)
    {
        this->data = data;
    };
    A(const A &a)
    {
        this->data = a.data + 1;
    };
    void show()
    {
        cout << this->data << endl;
    }
};
int main()
{
    A a(1);
    a.show();
    A b = a;
    b.show();
    A c(b);
    c.show();
}