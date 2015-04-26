#include "../Semantics.h"

List<Exp*>* Semantics::expression_list(Exp* expression)
{  List<Exp*>* L=new List<Exp*>;
   L->Insert(expression);
   return L;
}
List<Exp*>* Semantics::expression_list(List<Exp*>* expression_list,Exp* expression)
{  expression_list->Insert(expression);
   return expression_list;
}

