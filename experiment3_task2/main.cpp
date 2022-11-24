#include <iostream>
using namespace std;
class MyHashNode
{
public:
    MyHashNode(int oraginalValue)
    {
        _oraginalValue = oraginalValue;
    }
    int _oraginalValue;
};
class MyHashMap
{
public:
    MyHashMap(int size)
    {
        MyHashNode *p[size] = {};
        _pMap = p;
         bool pb[size] = {false};
        iswrite = pb;
        _size = size;
    }
    void insert(int number)
    {

        int position = number % _size;
        insert(number, position);
    }
    void getResult()
    {
        for (size_t i = 0; i < _size; i++)
        {
            cout << i << " " << (**(_pMap + i))._oraginalValue << endl;
        }
    }

private:
    MyHashNode **_pMap;
    bool *iswrite;
    int _size;
    void insert(int number, int positon)
    {
    

        // MyHashNode p = *(*(_pMap)+positon);

        if (*(*(_pMap)+positon) == NULL)
        {
            MyHashNode *p = new MyHashNode(number);
            **(_pMap + positon) = *p;
        }
        else
        {
            int nextPosition = positon;
            if (nextPosition == _size)
            {
                nextPosition = 0;
            }
            insert(number, nextPosition);
        }
    };
};
int main()
{

    int hashsize;
    cin >> hashsize;
    MyHashMap *myhashmap = new MyHashMap(hashsize);
    int temp;
    do
    {
        cin >> temp;
        myhashmap->insert(temp);
        if (getchar() == '\n')
        {
            break;
        }
    } while (getchar() == '\n');
    myhashmap->getResult();
}