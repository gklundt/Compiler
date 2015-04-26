#include "../Semantics.h"
void Semantics::program(void)
{
   ST.Print(tfs);             //Print Locality 1
   ST.PopLocality();
   ST.Print(tfs);             //Print Locality 0
}
