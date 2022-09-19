#include <iostream>
using namespace std;
//给定集合类的模板抽象类如下：
template <class Elem>
class Set
{

public:
    //在集合中插入一个元素 e
    virtual void Insert(const Elem &e) = 0;

    //在集合中删除一个值等于e的元素，如果删除成功则返回true，否则返回false
    virtual bool Remove(const Elem &e) = 0;

    //获取最早加入到集合第一个元素，该元素的值记录在参数e中返回。如果集合为空，则函数返回false,否则返回true。
    virtual bool GetFirstElement(Elem &e) = 0;

    //获取最晚加入到集合的元素，该元素的值记录在参数e中返回。 如果集合为空，则函数返回false,否则返回true。
    virtual bool GetLastElement(Elem &e) = 0;

    //获取集合的元素的个数
    virtual int GetSize() = 0;

    //获取集合所有元素的值记录在参数array中返回。函数返回集合元素的个数
    virtual int GetElements(Elem array[]) = 0;

    //按进入集合的次序，依次打印输出集合中的元素
    virtual void Print() = 0;

    // //将集合s中的元素合并到当前集合中
    // virtual void operator+=(Set<Elem> &s) = 0;
    // virtual void operator-=(Set<Elem> &s) = 0;
};

//请实现一个继承上述抽象类的集合类ASet，并利用该集合类完成集合操作。
template <class Elem>
class ASet : public Set<Elem>
{
public:
    ASet()
    {
        fence = 0;
        length = 0;
    }
    ASet(Elem elem[], int length)
    {
        this->elem = elem;
        this->length = length;
        fence = 0;
    }
    ~ASet()
    {
        delete elem;
        // delete length;
        // delete fence;
    }
    //在集合中插入一个元素 e
    void Insert(const Elem &e);

    //在集合中删除一个值等于e的元素，如果删除成功则返回true，否则返回false
    bool Remove(const Elem &e);

    //获取最早加入到集合第一个元素，该元素的值记录在参数e中返回。如果集合为空，则函数返回false,否则返回true。
    bool GetFirstElement(Elem &e);

    //获取最晚加入到集合的元素，该元素的值记录在参数e中返回。 如果集合为空，则函数返回false,否则返回true。
    bool GetLastElement(Elem &e);

    //获取集合的元素的个数
    int GetSize();

    //获取集合所有元素的值记录在参数array中返回。函数返回集合元素的个数
    int GetElements(Elem array[]);

    //按进入集合的次序，依次打印输出集合中的元素
    void Print();

    bool HaveThisElem(Elem e);
    // //将集合s中的元素合并到当前集合中
    void operator+=(ASet<Elem> &s);
    // //将集合s中的元素合并到当前集合中
    void operator-=(ASet<Elem> &s);

private:
    Elem *elem;
    int length;
    int fence;
    void Addlist(Elem *elem1, Elem *elem2, int length1, int length2, Elem out[]);
    bool GetSubList(Elem *elem, int start, int end, Elem out[]);
    void Print(Elem *e, int length);
};
template <class Elem>
void ASet<Elem>::Insert(const Elem &e)
{
    Elem elist[1] = {e};
    // Elem elem[length + 1] =
    Elem *elemfinal = new Elem[length + 1];
    Addlist(this->elem, elist, this->length, 1, elemfinal);
    elem = elemfinal;
    length += 1;
}

template <class Elem>
bool ASet<Elem>::Remove(const Elem &e)
{
    for (int i = 0; i < length; i++)
    {
        if (e == elem[i])
        {
            Elem *leftList = new Elem[i];
            GetSubList(elem, 0, i, leftList);
            // Print(leftList, i);

            Elem *rightList = new Elem[length - i - 1];
            GetSubList(elem, i + 1, length, rightList);
            // Print(rightList, length - i - 1);

            Elem *elemfinal = new Elem[length - 1];
            Addlist(leftList, rightList, i, length - i - 1, elemfinal);
            elem = elemfinal;
            length -= 1;
            return true;
        }
    }
    return false;
}

template <class Elem>
bool ASet<Elem>::GetFirstElement(Elem &e)
{
    try
    {
        e = elem[0];
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

template <class Elem>
bool ASet<Elem>::GetLastElement(Elem &e)
{
    try
    {
        e = elem[length - 1];
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

template <class Elem>
int ASet<Elem>::GetSize()
{
    return length;
}

template <class Elem>
int ASet<Elem>::GetElements(Elem array[])
{
    for (int i = 0; i < length; i++)
    {
        array[i] = elem[1];
    }

    return length;
}

template <class Elem>
void ASet<Elem>::Print()
{
    Print(elem, length);
}
template <class Elem>
bool ASet<Elem>::HaveThisElem(Elem e)
{
    for (size_t i = 0; i < length; i++)
    {
        if (e == elem[i])
        {
            return true;
        }
    }
    return false;
}
template <class Elem>
void ASet<Elem>::operator+=(ASet<Elem> &s)
{
    for (size_t i = 0; i < s.GetSize(); i++)
    {
        if (!this->HaveThisElem(s.elem[i]))
        {
            this->Insert(s.elem[i]);
        }
    }


}
template <class Elem>
void ASet<Elem>::operator-=(ASet<Elem> &s)
{
    Elem *a = new Elem(1000);
    s.GetElements(a);
    for (int i = 0; i < s.GetSize(); i++)
    {
        this->Remove(a[i]);
    }
}
template <class Elem>
void ASet<Elem>::Addlist(Elem *elem1, Elem *elem2, int length1, int length2, Elem *out)
{
    // out = new Elem[length1 + length2];
    for (int i = 0; i < (length1 + length2); i++)
    {
        if (i < length1)
        {
            out[i] = elem1[i];
        }
        else
        {
            out[i] = elem2[i - length1];
        }
    }
}
template <class Elem>
bool ASet<Elem>::GetSubList(Elem *elem, int start, int end, Elem out[])
{
    try
    {
        for (int i = start; i < end; i++)
        {
            out[i - start] = elem[i];
        }
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}
template <class Elem>
void ASet<Elem>::Print(Elem *e, int length)
{
    for (int i = 0; i < length; i++)
    {

        cout << e[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ASet<int> a[3];
    for (size_t i = 0; i < 3; i++)
    {
        int temp;
        do
        {
            cin >> temp;
            a[i].Insert(temp);

        } while (cin.get() != '\n');
    }
    //输出结果分为5行，第1行输出集合S1中第一个元素和最后一个元素；

    int temp1;
    a[0].GetFirstElement(temp1);
    int temp2;
    a[0].GetLastElement(temp2);

    cout << temp1 << ' ' << temp2 << endl;
    //第2行输出集合S2的元素的个数；
    cout << a[1].GetSize() << endl;
    //第3行按进入集合的先后顺序输出S3中的所有元素；
    a[2].Print();
    //第4行，将集合S2合并到S1后，按进入集合的先后次序打印输出S1中的元素；
    a[0] += a[1];
    a[0].Print();
    //第5行，将集合S2减去集合S3后，按进入集合的先后次序打印输出S2中的元素。
    a[1] -= a[2];
    a[1].Print();
    return 0;
}
