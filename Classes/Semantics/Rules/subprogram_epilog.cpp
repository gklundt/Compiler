#include "../Semantics.h"
List<Exp*>* Semantics::subprogram_epilog(SubprogramSymbol* S,List<Exp*>* compound_statement)
{  List<Exp*>* L=new List<Exp*>;
   string tc=S->ReturnType()->TypeChar();
   PCode* P=new PCode("","rtn",tc,"");
   Exp* E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   int spvalue =ST.Offset();
   P=new PCode("#define",S->SPLabel(),spvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   Height H;
   //-----------------------------------------------------------------------
   //Find the maximum height of the computation stack, epvalue
   //-----------------------------------------------------------------------
   for (compound_statement->First();!compound_statement->IsEol();compound_statement->Next()) {
       Exp* E=compound_statement->Member();
       H.FindHeight(E);
   }
   tfs << endl;
   int epvalue=spvalue+H.Maximum();
   P=new PCode("#define",S->EPLabel(),epvalue,"");
   E=new Exp(ST.TVoid(),P);
   E->Print(tfs);
   tfs << endl;
   L->Insert(E);
   return L;
}
