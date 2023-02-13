#include <iostream>
using namespace std;
class Bclass
{ public:
    Bclass( int i, int j ) { x = i; y = j; }
    virtual int fun() { return 0 ; }
  protected:
    int x, y ;
};
class Iclass:public Bclass
{ public :
    Iclass(int i, int j, int k):Bclass(i, j) { z = k; }
    int fun() { return ( x + y + z ) / 3; }
  private :
    int z ;
};
int main()
{ Iclass obj( 2, 4, 10 );
  Bclass p1 = obj;//这里调用复制构造函数复制了一个新的
  cout << p1.fun() << endl;
  Bclass &p2 = obj ;//这里仅仅是一个引用
  cout << p2.fun() << endl;
  cout << p2.Bclass :: fun() << endl;
  Bclass *p3 = &obj;
  cout << p3 -> fun() << endl;
}
