#ifndef List_h
#define List_h 1
//-----------------------------------------------------------------------------
//File List.h contains the attributes of a List whose elements are appended
//in temporal order
//-----------------------------------------------------------------------------
//Author:     Thomas R. Turner
//E-Mail:     trturner@uco.edu
//Course:     CMSC 4173, Translator Design
//-----------------------------------------------------------------------------
//Copyright August, 2007 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files and namespace std
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//-----------------------------------------------------------------------------
//A ListIndexException is thrown when the list index is invalid.
//-----------------------------------------------------------------------------
struct ListIndexException {
    ListIndexException(int i,int m)
    {   cout << endl;
        cout << "List index " << i << " is invalid.";
        cout << endl;
        cout << "Valid indexes are in the range 0 <= i < " << m << ".";
    }
};
//-----------------------------------------------------------------------------
//A ListException is thrown when the list is either full or empty.
//-----------------------------------------------------------------------------
struct ListException {
  ListException(const char* m)
  {  cout << endl;
     cout << "I am the List and I am " << m << ".";
     cout << endl;
  }
};
//-----------------------------------------------------------------------------
//class List defines the attributes and member functions of class List.
//-----------------------------------------------------------------------------
template <class T>
class List {
    int size;                           //Number of available elements
    int count;                          //Number of actual elements
    T* L;                               //Points to storage allocated for
                                        //the list.
    int cursor;                         //Contains the index of the current
                                        //element
public:
    List(int sz=100):size(sz),count(0),cursor(0){L=new T[size];}
    ~List(){}
    bool IsFull(void){return count>size-1;}
    bool IsEmpty(void){return count==0;}
    void Insert(T v)
    {   if (IsFull()) throw ListException("full");
        L[count++]=v;
    }
    void Append(List* L)
    {   for (L->First();!L->IsEol();L->Next()) {
            Insert(L->Member());
        }
    }
    void Scan(istream& i)
    {   for (;;) {
            T v;
            i >> v;
            if (i.eof()) break;
            Insert(v);
        }
    }
    void Print(ostream& o,const char* title)
    {   o << title << "{";
        for (int a=0;a<count;a++) {
           if (a>0) o << ",";
           o << L[a];
        }
        o << "}";
    }
    void Print(ostream& o)
    {   for (int a=0;a<count;a++) {
            L[a]->Print(o);
        }
    }
	// Added by Gordon p03
    string Print()
    {  string str ;
       str.append("{");
       for (int a=0;a<count;a++) {
          if (a>0) str.append(",");
          str.append(L[a]);
       }
       str.append("}");
       return str;
    }
    T operator[](int i)
    {   if (i<0 || i>=count) throw ListIndexException(i,count);
        return L[i];
    }
    int Count(void){return count;}
    void First(void){cursor=0;}
    void Next(void){if (cursor<count) cursor++;}
    bool IsEol(void){return cursor>=count;}
    T Member(void)
    {   if (cursor<0 || cursor>=count) throw ListIndexException(cursor,count);
        return L[cursor];
    }
};
#endif
