//例6-13 一个有问题的程序   
#include<iostream>
using namespace std ;
#include<string.h>
class name
{ public :
       name(char *pn) ;       ~ name() ; name(const name &);
   protected : 
       char *pname ;       int size ;
} ;
name :: name(char *pn)
 { cout <<" Constructing " << pn << endl ;
    pname = new char[strlen(pn)+1] ;
    if (pname!=0) strcpy(pname,pn) ;
    size = strlen(pn) ;
 } 
name :: ~ name()
{ cout << " Destructing " << pname << endl ; 
   delete  []pname ;
   size = 0 ;
}
name :: name(const name & name){
    cout <<"deep copying"<<endl;
    this->pname= new char[name.size+1];
    strcpy(this->pname,name.pname);
}
int main() 
 {  char  info[] = "NoName";
    name Obj1(info) ;
    name Obj2 = Obj1 ;
 }
