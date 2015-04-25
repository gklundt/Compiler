//---------------------------------------------------------------------
//File identifier_list.cpp implements semantics for an identifier_list
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Application include files
//---------------------------------------------------------------------
#include "identifier_list.h"
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//Externals
//---------------------------------------------------------------------
extern ofstream tfs;          //Trace File Stream
//---------------------------------------------------------------------
//Function identifier_list creates a list of identifiers and appends
//the first identifier on the list.
//---------------------------------------------------------------------
List<string>* identifier_list
    (string* i
    )
{   List<string>* L=new List<string>;
    L->Insert(*i);
    L->Print(tfs," identifier_list=");
    return L;
}
//---------------------------------------------------------------------
//Function identifier_list appends an identifier onto an existing list.
//---------------------------------------------------------------------
List<string>* identifier_list
    (List<string>* L
    ,string* i
    )
{   L->Insert(*i);
    L->Print(tfs," identifier_list=");
    return L;
}


