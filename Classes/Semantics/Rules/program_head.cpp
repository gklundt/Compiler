#include "../Semantics.h"

void Semantics::program_head(string id)
{
   Sym* p=new ProgramSymbol(id);
   ST.Insert(p);
   ST.NewLocality();
}
