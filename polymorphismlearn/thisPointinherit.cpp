#include <iostream>
#include <cstring>
using namespace std;
class A_class
{
    char name[20];

public:
    void put_name(char *s) { strcpy_s(name, s); }
    void show_name() { cout << name << "\n"; }
};
class B_class : public A_class
{
    char phone_num[20];

public:
    void put_phone(char *num) { strcpy_s(phone_num, num); }
    void show_phone() { cout << phone_num << "\n"; }
};
int main()
{
    A_class *A_p;
    A_class A_obj;
    B_class B_obj;
    A_p = &A_obj;
    A_p->put_name("Wang xiao hua");
    A_p->show_name();
    A_p = &B_obj;
    A_p->put_name("Chen ming");
    A_p->show_name();
    B_obj.put_phone("5555_12345678");
    ((B_class *)A_p)->show_phone();
}
