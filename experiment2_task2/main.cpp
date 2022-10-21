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
        fence = tail = head = new Link<Book>;
        leftcnt = 0;
        rightcnt = 0;
    };
    bool Add(Book &book)
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
        Link<Book> * nodeToDelate;
        FindElem(book, &nodeToDelate);
        Link<Book> *previousNode;
        GetFrontElem(nodeToDelate, &previousNode);
        previousNode->next = nodeToDelate->next;

        // delete (&nodeToDelate);

        return true;
    };
    bool Find(string name, string author)
    {
        Book book;
        book.name = name;
        book.author = author;
        return FindElem(book);
    };

private:
    Link<Book> *head;  // Point to list header
    Link<Book> *tail;  // Pointer to last Elem
    Link<Book> *fence; // Last element on left
    int leftcnt;       // Size of left
    int rightcnt;      // Size of right
    bool FindElem(Book bookToFind)
    {
        Link<Book> link = new Link<Book>();
        return FindElem(bookToFind, link);
    }
    bool GetFrontElem(Link<Book> &thisElem, Link<Book> &frontElem)
    {
        Link<Book> *elemReadNow = head;
        Link<Book> previousElem;
        while (elemReadNow->next != NULL)
        {
            previousElem = elemReadNow;
            elemReadNow = elemReadNow->next;
            if (&thisElem == elemReadNow)
            {
                frontElem = previousElem;
                return true;
            }
        }
        return false;
    };
    bool FindElem(Book bookToFind, Link<Book> *goal)
    {

        Link<Book> *elemReadNow = head;
        while (elemReadNow->next != NULL)
        {
            elemReadNow = elemReadNow->next;
            if ((bookToFind.name == elemReadNow->element.name) && (bookToFind.author == elemReadNow->element.author))
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
    Book *book = new Book();
    book->author = "haha";
    book->name = "why school of design so fuzzy";
    library->Add(*book);
    bool b = library->Find("why school of design so fuzzy", "haha");
    cout << "删除前"<<b << endl;
    library->Remove("why school of design so fuzzy", "haha");
    b = library->Find("why school of design so fuzzy", "haha");
    cout << "删除后"<<b << endl;

    return 0;
}