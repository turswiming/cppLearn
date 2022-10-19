#include <iostream>
#include <string.h>
using namespace std;
bool calculateParentheses(string s);
int main()
{
    unsigned int lineCount;
    cin>>lineCount;
    string strings[lineCount];
    for (size_t i = 0; i < lineCount; i++)
    {
        cin >> strings[i];
    }
    for (size_t i = 0; i < lineCount; i++)
    {
        bool temp = calculateParentheses(strings[i]);
        if (temp)
        {
            cout<<"TRUE"<<endl;
        }else
        {
            cout<<"FALSE"<<endl;
        }
        
        
    }
    cout<<endl;

    return 0;
}
bool calculateParentheses(string s)
{
    int count = s.length();
    int stark = 0;
    for (int i = 0; i < count; i++)
    {
        char temp = s[i];
        if (temp == '(')
        {
            stark += 1;
        }
        else
        {
            stark -= 1;
        }
        if (stark < 0)
        {
            return false;
        }
    }
    if (stark != 0)
    {
        return false;
    }
    return true;
}
