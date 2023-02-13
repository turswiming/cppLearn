#include <iostream>
using namespace std;
class Base
{
public:
   Base(char xx) { x = xx; }
   virtual void who() { cout << "Base class: " << x << "\n"; }

protected:
   char x;
};
class First_d : public Base
{
public:
   First_d(char xx, char yy) : Base(xx) { y = yy; }
   void who() { cout << "First derived class: " << x << ", " << y << "\n"; }

protected:
   char y;
};
class Second_d : public First_d
{
public:
   Second_d(char xx, char yy, char zz) : First_d(xx, yy) { z = zz; }
   void who() { cout << "Second derived class: " << x << ", " << y << ", " << z << "\n"; }

protected:
   char z;
};
int main()
{
   Base B_obj('A');
   First_d F_obj('T', 'O');
   Second_d S_obj('E', 'N', 'D');
   Base *p;
   p = &B_obj;
   p->who();
   p = &F_obj;
   p->who();
   p = &S_obj;
   p->who();
   F_obj.who();
   ((Second_d *)p)->who();
}
