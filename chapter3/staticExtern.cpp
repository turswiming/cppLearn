// 例3-25  用静态变量测试密码输入次数
#include <iostream>
using namespace std;
int password(const int &key);
int main()
{
    if (password(123456)) //调用函数，测试用户输入密码
        cout << "Welcome!" << endl;
    else
        cout << "Sorry,you are wrong!" << endl;
}
int password(const int &key)
{
    static int n = 0; //静态变量
    int k;
    cout << "Please input your password: ";
    cin >> k;  //输入密码
    n++;       //记录输入次数，即函数调用次数
    if (n < 3) //输入次数合法
    {
        if (k == key)
            return 1; //密码正确
        else
            password(key); //递归，重新输入
    }
    else //连续输入3次错误
    {
        if (k != key)
            return 0;
    }
}
