//copyright : free for use 
#include <iostream>
// #include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
using namespace std;
char *My_rev(char *str)
{
    int i, len = 0, n;
    char temp;
    len = strlen(str);
    n = len - 1;
    for (i = 0; i < (len / 2); i++)
    {
        temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        n--;
    }
    return str;
}
int main()
{
    unsigned int strNumber;
    cin >> strNumber;
    char *strs[strNumber];

    for (size_t i = 0; i < strNumber; i++)
    {
        char temp[50];
        cin >> temp;
        char *save = new char[50];
        strncpy(save, temp, sizeof(temp));
        strs[i] = save;
    }
    for (size_t i = 0; i < strNumber; i++)
    {
        cout << My_rev(strs[i]) << "\n";
    }
}