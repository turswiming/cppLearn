#include <iostream>
#include <string>
using namespace std;
template <class Info>
class Node
{
public:
    Node<Info> *next = NULL;
    Node<Info> *pre = NULL;
    Info info;
};
template <class Info>
class ChainCharm
{
public:
    ChainCharm() : start(NULL), fence(NULL), end(NULL), leftCnt(0), rightCnt(0)
    {
    }
    void Add(Info _info)
    {
        Node<Info> *node = new Node<Info>();
        node->info = _info;
        if (end == NULL)
        {
            end = node;
            start=node;
            fence = node;
        }
        else
        {
            node->pre = end;
            end->next = node;
            end =node;
            fence = end;
        }
    };

    bool Remove(){
        return true;
    };
    // Node<Info> Find(){

    // };

private:
    Node<Info> *start;
    Node<Info> *fence;
    Node<Info> *end;
    int leftCnt;
    int rightCnt;
};

int main()
{
    ChainCharm<string> chainCharm;
    chainCharm.Add("你好，蔡徐坤");

    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，蔡徐坤");

    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");

    chainCharm.Add("你好，蔡徐坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，蔡徐坤");
    chainCharm.Add("你好，蔡徐坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");
    chainCharm.Add("你好，谢广坤");
}