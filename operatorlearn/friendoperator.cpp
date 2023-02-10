#include <iostream>
using namespace std;
class Complex
{
private:
    int realNumber;
    int imageNumber = 0;

public:
    Complex(int real, int voi) : realNumber(real), imageNumber(voi){};
    Complex(int real) { realNumber = real; };
    void show()
    {
        cout << "real=" << realNumber << "\t"
             << "void=" << imageNumber << endl;
    };
    friend Complex operator+(const Complex &c1,const Complex &c2)
    {
        int real = c1.realNumber + c2.realNumber;
        int voi = c1.imageNumber + c2.imageNumber;
        Complex out(real, voi);
        return out;
    };
};
int main()
{
    Complex a(1, 2);
    Complex b(3, 5);
    (a + b).show();
    (a + 1).show();
    return 0;
}