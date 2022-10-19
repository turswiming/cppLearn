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
    bool Add(Book& book){
        Link<Book>* link = new Link<Book>(book);
        link->next= fence->next;
        fence->next=link;
        fence=fence->next;
        leftcnt+=1;
        return true;
    };
    bool Remove(){

    };
    bool Find(string name,string author){
        Book book;
        book.name=name;
        book.author=author;
        return FindElem(book);
    };

private:
    Link<Book> *head;  // Point to list header
    Link<Book> *tail;  // Pointer to last Elem
    Link<Book> *fence; // Last element on left
    int leftcnt;       // Size of left
    int rightcnt;      // Size of right
    bool FindElem(Book bookToFind){
       Link<Book> link =  new Link<Book>();
        return FindElem(bookToFind,link);
    }
    bool FindElem(Book bookToFind,Link<Book> &goal){
        
        Link<Book> *elemReadNow = head;
        while (elemReadNow->next!=NULL)
        {
            elemReadNow=elemReadNow->next;
            if ((bookToFind.name==elemReadNow->element.name) && (bookToFind.author==elemReadNow->element.author))
            {
                goal=elemReadNow;
                return true;
            }
            
        }
        return false;
        
    };
};
int main()
{
    Library *library =new Library();
    Book* book=new Book();
    book->author="haha";
    book->name="why school of design so fuzzy";
    library->Add(*book);
    bool b = library->Find("why school of design so fuzzy","haha");
        cout<<b<<endl;

         b = library->Find("why school of design so fuzzy","fuck");
    cout<<b<<endl;
    Book* book2=new Book();
    book2->author="fafa";
    book2->name="why school of design so crazy";
    library->Add(*book2);
    return 0;
}