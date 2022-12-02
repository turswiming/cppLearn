//例6-12    (3)函数返回类类型时，通过复制构造函数建立临时对象
#include <iostream>
using namespace std;
class Location
{
public:
    Location(int xx = 0, int yy = 0)
    {
        X = xx;
        Y = yy;
        cout << "Object constructed." << endl;
    }
    Location(const Location &p)
    {
        X = p.X;
        Y = p.Y;
        cout << "Copy_constructor called." << endl;
    }
    ~Location()
    {
        cout << X << "," << Y << " Object destroyed." << endl;
    }
    int GetX() { return X; }
    int GetY() { return Y; }

private:
    int X, Y;
};
Location & g()
{
    Location *A = new Location(1, 2);
    return (*A);
}
int main()
{{
  Location B;
    B = g();
}
  

    cout<<"end program"<<endl;
}
