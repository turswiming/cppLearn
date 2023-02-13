#include <iostream>
#include <cstring>
using namespace std;
class Name
{
public:
    Name(char *pN);
    Name(const Name &);            // 复制构造函数
    Name &operator=(const Name &); // 重载赋值运算符
    ~Name();

protected:
    char *pName;
    int size;
};

int main()
{
    Name Obj1("ZhangSan");
    Name Obj2 = Obj1; // 调用复制构造函数
    Name Obj3("NoName");
    Obj3 = Obj2 = Obj1; // 调用重载赋值运算符函数
}
Name::Name(char *pN)
{
    cout << " Constructing " << pN << endl;
    pName = new char[strlen(pN) + 1];
    if (pName != 0)
        strcpy(pName, pN);
    size = strlen(pN);
}
Name::Name(const Name &Obj) // 复制构造函数
{
    cout << " Copying " << Obj.pName << " into its own block\n";
    pName = new char[strlen(Obj.pName) + 1];
    if (pName != 0)
        strcpy(pName, Obj.pName);
    size = Obj.size;
}
Name &Name::operator=(const Name &Obj) // 重载赋值运算符
{
    delete[] pName;
    pName = new char[strlen(Obj.pName) + 1];
    if (pName != 0)
        strcpy(pName, Obj.pName);
    size = Obj.size;
    return *this;
}
Name::~Name()
{
    cout << " Destructing " << pName << endl;
    delete[] pName;
    size = 0;
}
