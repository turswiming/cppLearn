#include <iostream>
using namespace std;
class MyHashMap
{
public:
    MyHashMap(int size)
    {
        _map = new int[size]{0};
        _size = size;
    }
    void insert(int number)
    {
        int temp = number % _size;
        _map[temp] += 1;
    }
    int getResult(int index)
    {
        return _map[index];
    }

private:
    int *_map;
    int _size;
};
int main()
{
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int inputNumber=0;

        int hashsize=0;
        int index=0;
        scanf("%d%d%d", &inputNumber, &hashsize, &index);
        getchar();
        int temp;
        MyHashMap *myhashmap = new MyHashMap(hashsize);
        for (int i = 0; i < inputNumber; i++)
        {
            cin >> temp;
            myhashmap->insert(temp);
        }
        cout << myhashmap->getResult(index)<<endl;
    }
}