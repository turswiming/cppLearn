//例6-11    (2)函数的类类型实参初始化形参时，要调用复制构造函数
#include <iostream>
using namespace std;
class Location
{
public:
    Location(int xx = 0, int yy = 0)
    {
        X = xx;
        Y = yy;
        cout << "Constructor Object.\n";
    }
    Location(const Location &p) //复制构造函数
    {
        X = p.X;
        Y = p.Y;
        cout << "Copy_constructor called." << endl;
    }
    ~Location() { cout << X << "," << Y << " Object destroyed." << endl; }
    int GetX() { return X; }
    int GetY() { return Y; }

private:
    int X, Y;
};
void f( Location &p) { cout << "Funtion:" << p.GetX() << "," << p.GetY() << endl; }
int main()
{
    Location A(1, 2);
    f(A);
    return 0;
}
