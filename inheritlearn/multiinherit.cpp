#include<iostream>
using namespace std;
class Base1
{ public :
	   Base1( int i ) { cout << "调用基类Base1的构造函数:" << i << endl ; }
};
class Base2
{ public:
	   Base2( int j ) { cout << "调用基类Base2的构造函数:" << j << endl ; }
}; 
class A : public Base1, public Base2
{ public :
    A( int a, int b, int c, int d ) : Base2(b), Base1(c), b2(a), b1(d)
     { cout << "调用派生类A的构造函数:" << a+b+c+d << endl; }   
  private :
    Base1 b1 ;
    Base2 b2 ;
} ; 
int main()
{ A obj( 1, 2, 3, 4 ); }
