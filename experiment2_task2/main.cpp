#include <iostream>
#include <string.h>
using namespace std;
template <class Elem>
class Link
{
public:
    Elem element; // Value for this node
    Link *next;   // Pointer to next node

    Link(const Elem &elemval, Link *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    Link(Link *nextval = NULL)
    {
        next = nextval;
    }
};
struct Book
{
    string name;
    string author;
    float price;
};
class Library
{
public:
    Library()
    {
        fence = tail = head = new Link<Book>();
        leftcnt = 0;
        rightcnt = 0;
    };
    bool Add(Book book)
    {
        if (FindElem(book))
        {
            return false;
        }

        Link<Book> *link = new Link<Book>(book);
        link->next = NULL;
        fence->next = link;
        fence = fence->next;
        leftcnt += 1;
        return true;
    };
    bool Remove(string name, string author)
    {
        Book book;
        book.name = name;
        book.author = author;
        if (!FindElem(book))
        {
            return false;
        };
        Link<Book> *nodeToDelate;
        FindElem(book, nodeToDelate);
        Link<Book> *previousNode = NULL;
        GetFrontElem(*nodeToDelate, previousNode);
        (*previousNode).next = nodeToDelate->next;
        if (fence == nodeToDelate)
        {
            fence = previousNode;
        }

        // delete (&nodeToDelate);

        return true;
    };
    int Find(string name)
    {
        int count = 0;
        Link<Book> *elemReadNow = head;
        while (elemReadNow->next != NULL)
        {
            elemReadNow = elemReadNow->next;
            if (name == elemReadNow->element.name)
            {
                count += 1;
            }
        }
        return count;
    };

private:
    Link<Book> *head;  // Point to list header
    Link<Book> *tail;  // Pointer to last Elem
    Link<Book> *fence; // Last element on left
    int leftcnt;       // Size of left
    int rightcnt;      // Size of right
    bool FindElem(Book &bookToFind)
    {
        Link<Book> *link = new Link<Book>();
        return FindElem(bookToFind, link);
    }
    bool GetFrontElem(Link<Book> &thisElem, Link<Book> *&frontElem)
    {
        Link<Book> *elemReadNow = head;
        Link<Book> *previousElem;
        while (elemReadNow->next != NULL)
        {
            previousElem = elemReadNow;
            elemReadNow = elemReadNow->next;
            if (Equal(thisElem.element, elemReadNow->element))
            {
                frontElem = previousElem;
                return true;
            }
        }
        return false;
    };
    bool Equal(Book book1, Book book2)
    {
        return (book1.name == book2.name) && (book1.author == book2.author);
    }
    bool FindElem(Book bookToFind, Link<Book> *&goal)
    {

        Link<Book> *elemReadNow = head;
        while (elemReadNow->next != NULL)
        {
            elemReadNow = elemReadNow->next;
            if (
                (bookToFind.name == elemReadNow->element.name) &&
                (bookToFind.author == elemReadNow->element.author))
            {
                goal = elemReadNow;
                return true;
            }
        }
        return false;
    };
};
int main()
{
    Library *library = new Library();

    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        char a[30] = {0};
        char b[30] = {0};
        char c[30] = {0};
        float d;
        scanf("\n");
        scanf("%[^ ]", &a);
        if (string(a) == "ADD")
        {
            // scanf("%s",b);
            scanf(" (%[^)]) (%[^)]) (%e)", &b, &c, &d);
            Book *book = new Book();
            book->author = c;
            book->name = b;
            book->price = d;
            bool result = library->Add(*book);
            if (result)
            {
                cout << "SUCCESS" << endl;
            }
            else
            {
                cout << "FAIL" << endl;
            }
        }
        if (string(a) == "REMOVE")
        {
            scanf(" (%[^)]) (%[^)])", &b,&c);
            bool result = library->Remove(b,c);
            if (result)
            {
                cout << "SUCCESS" << endl;
            }
            else
            {
                cout << "FAIL" << endl;
            }
        }
        if (string(a) == "FIND")
        {
            scanf(" (%[^)])", &b);

            int result = library->Find(b);
            cout << result << endl;
        }
    }

    
    return 0;
}