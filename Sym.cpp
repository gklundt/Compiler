//-----------------------------------------------------------------------------
//File Sym.cpp contains member functions of class Sym and derived classes
//-----------------------------------------------------------------------------
//Author: Thomas R. Turner
//E-Mail: trturner@uco.edu
//February, 2012
//-----------------------------------------------------------------------------
//Copyright February, 2012 by Thomas R. Turner.
//Do not reproduce without permission from Thomas R. Turner.
//-----------------------------------------------------------------------------
//C++ include files
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//-----------------------------------------------------------------------------
//Symbol Table include files
//-----------------------------------------------------------------------------
#include "Typ.h"
#include "Sym.h"
#include "Label.h"
#include "yyerror.h"
//-----------------------------------------------------------------------------
//External Variables
//-----------------------------------------------------------------------------
extern Typ* TypeVoid;
extern Typ* TypeAddress;
extern Typ* TypeBoolean;
extern Typ* TypeChar;
extern Typ* TypeInteger;
extern Typ* TypeReal;
Label L;
//-----------------------------------------------------------------------------
//class Sym member functions
//-----------------------------------------------------------------------------
Sym::Sym(symkind k,const char* i,Typ* u):sk(k),id(i),t(u){}
Sym::Sym(symkind k,string i,Typ* u):sk(k),id(i),t(u){}
//-----------------------------------------------------------------------------
string Sym::SymkindSymbol(symkind sk) 
{   switch (sk) {
        case sk_constant          : return "Constant Symbol";
        case sk_variable          : return "Variable Symbol";
        case sk_type              : return "Type Symbol";
        case sk_procedure         : return "Procedure Symbol";
        case sk_function          : return "Function Symbol";
        case sk_program           : return "Program Symbol";
        case sk_standardprocedure : return "Standard Procedure Symbol";
        case sk_standardfunction  : return "Standard Function Symbol";
        default                   : return "Unknown Symbol";
    }
}
//-----------------------------------------------------------------------------
symkind Sym::Symkind(void){return sk;}
//-----------------------------------------------------------------------------
void Sym::Print(ostream& o,int indent)
{   o << endl;
    for (int a=0;a<indent;a++) o << "  ";
    o << "Symbol(" << SymkindSymbol(sk) << ")";
    o << " ";
    o << "id(" << id << ")";
    t->Print(o,indent+1);
}
//-----------------------------------------------------------------------------
string Sym::Id(void){return id;}
//-----------------------------------------------------------------------------
Typ* Sym::Type(void){return t;}
//-----------------------------------------------------------------------------
bool Sym::IsStandardFunctionSymbol(void){return sk==sk_standardfunction;}
bool Sym::IsStandardProcedureSymbol(void){return sk==sk_standardprocedure;}
bool Sym::IsVariableSymbol(void){return sk==sk_variable;}
bool Sym::IsProgramSymbol(void){return sk==sk_program;}
bool Sym::IsProcedureSymbol(void){return sk==sk_procedure;}
bool Sym::IsTypeSymbol(void){return sk==sk_type;}
bool Sym::IsFunctionSymbol(void){return sk==sk_function;}
//-----------------------------------------------------------------------------
//class TypeSymbol
//-----------------------------------------------------------------------------
TypeSymbol::TypeSymbol(const char* id, Typ* t):Sym(sk_type,id,t){}
TypeSymbol::TypeSymbol(string id, Typ* t):Sym(sk_type,id,t){}
void TypeSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class ConstantSymbol
//-----------------------------------------------------------------------------
ConstantSymbol::ConstantSymbol(const char* id,Typ* t,const char* v)
    :Sym(sk_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(string id,Typ* t,const char* v)
    :Sym(sk_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(const char* id,Typ* t,string v)
    :Sym(sk_constant,id,t){constant=new Constant(t,v);}
ConstantSymbol::ConstantSymbol(string id,Typ* t,string v)
    :Sym(sk_constant,id,t){constant=new Constant(t,v);}
void ConstantSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    constant->Print(o,indent+1);
}
string ConstantSymbol::ConstantValue(void)
{   return constant->ConstantValue();
}
//-----------------------------------------------------------------------------
//class StandardSubprogramSymbol
//-----------------------------------------------------------------------------
StandardSubprogramSymbol::StandardSubprogramSymbol(symkind sk,string id,string cid)
    :Sym(sk,id,TypeVoid),cspid(cid){}
void StandardSubprogramSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "cspid(" << cspid << ")";
}
string StandardSubprogramSymbol::CSPID(void){return cspid;}
//-----------------------------------------------------------------------------
//class StandardProcedureSymbol
//-----------------------------------------------------------------------------
StandardProcedureSymbol::StandardProcedureSymbol(const char* id,const char* cid)
   :StandardSubprogramSymbol(sk_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(const char* id,string cid)
   :StandardSubprogramSymbol(sk_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(string id,const char* cid)
   :StandardSubprogramSymbol(sk_standardprocedure,id,cid){}
StandardProcedureSymbol::StandardProcedureSymbol(string id,string cid)
   :StandardSubprogramSymbol(sk_standardprocedure,id,cid){}
void StandardProcedureSymbol::Print(ostream& o,int indent)
{   StandardSubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class StandardFunctionSymbol
//-----------------------------------------------------------------------------
StandardFunctionSymbol::StandardFunctionSymbol(const char* id,const char* cid)
   :StandardSubprogramSymbol(sk_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(const char* id,string cid)
   :StandardSubprogramSymbol(sk_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(string id,const char* cid)
   :StandardSubprogramSymbol(sk_standardfunction,id,cid){}
StandardFunctionSymbol::StandardFunctionSymbol(string id,string cid)
   :StandardSubprogramSymbol(sk_standardfunction,id,cid){}
void StandardFunctionSymbol::Print(ostream& o,int indent)
{   StandardSubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class VariableSymbol
//-----------------------------------------------------------------------------
VariableSymbol::VariableSymbol(const char* id,Typ* t,int ll,int a)
    :Sym(sk_variable,id,t),lexicallevel(ll),address(a){}
VariableSymbol::VariableSymbol(string id,Typ* t,int ll,int a)
    :Sym(sk_variable,id,t),lexicallevel(ll),address(a){}
void VariableSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "lexicallevel(" << lexicallevel << ") address(" << address << ")";
}
void VariableSymbol::setLexicalLevel(int ll){lexicallevel=ll;}
void VariableSymbol::setAddress(int a){address=a;}
int VariableSymbol::LexicalLevel(void){return lexicallevel;}
int VariableSymbol::Address(void){return address;}
//-----------------------------------------------------------------------------
//class SubprogramSymbol
//-----------------------------------------------------------------------------
SubprogramSymbol::SubprogramSymbol(symkind sk,string id,Typ* t,int ll)
    :Sym(sk,id,t),lexicallevel(ll){elabel=L.New();splabel=L.New();eplabel=L.New();}
void SubprogramSymbol::Print(ostream& o,int indent)
{   Sym::Print(o,indent);
    o << endl;
    for (int a=0;a<indent+1;a++) o << "  ";
    o << "lexicallevel(" << lexicallevel << ")";
    o << " ";
    o << "elabel(" << elabel << ")";
    o << " ";
    o << "splabel(" << splabel << ")";
    o << " ";
    o << "eplabel(" << eplabel << ")";
}
int SubprogramSymbol::LexicalLevel(void){return lexicallevel;}
string SubprogramSymbol::ELabel(void){return elabel;}
string SubprogramSymbol::SPLabel(void){return splabel;}
string SubprogramSymbol::EPLabel(void){return eplabel;}
int SubprogramSymbol::ParameterCount(void)
{    Typ* T=Sym::Type();
     Subprogram* ST=0;
     if (T->IsSubprogram()) {
         ST=(Subprogram*)T; 
         return ST->ParameterCount();
     } else {
         yyerror("Semantic error: no return type."); 
     }
}
Typ* SubprogramSymbol::ReturnType(void)
{    Typ* T=Sym::Type();
     Subprogram* ST=0;
     if (T->IsSubprogram()) {
         ST=(Subprogram*)T; 
         return ST->ReturnType();
     } else {
         yyerror("Semantic error: no return type."); 
     }
}
//-----------------------------------------------------------------------------
//class ProcedureSymbol
//-----------------------------------------------------------------------------
ProcedureSymbol::ProcedureSymbol(const char* id,Typ* t,int ll)
    :SubprogramSymbol(sk_procedure,id,t,ll){}
ProcedureSymbol::ProcedureSymbol(string id,Typ* t,int ll)
    :SubprogramSymbol(sk_procedure,id,t,ll){}
void ProcedureSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class FunctionSymbol
//-----------------------------------------------------------------------------
FunctionSymbol::FunctionSymbol(const char* id,Typ* t,int ll)
    :SubprogramSymbol(sk_function,id,t,ll){}
FunctionSymbol::FunctionSymbol(string id,Typ* t,int ll)
    :SubprogramSymbol(sk_function,id,t,ll){}
void FunctionSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
//-----------------------------------------------------------------------------
//class ProgramSymbol
//-----------------------------------------------------------------------------
ProgramSymbol::ProgramSymbol(const char* id)
    :SubprogramSymbol(sk_program,id,TypeVoid,0){}
ProgramSymbol::ProgramSymbol(string id)
    :SubprogramSymbol(sk_program,id,TypeVoid,0){}
void ProgramSymbol::Print(ostream& o,int indent)
{   SubprogramSymbol::Print(o,indent);
}
