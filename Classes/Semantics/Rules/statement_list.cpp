#include "../Semantics.h"

//Function statement_list implements the rule
//statement_list -> statement 
//-------------------------------------------------------------------------
List<Exp*>* Semantics::Statement_list(List<Exp*>* s) {
	cout << "List<Exp*>* Semantics::Statement_list(List<Exp*>* s)" << endl;
	List<Exp*>* sl = new List<Exp*>;
	sl->Append(s);
	return sl;
}
//--------------------------------------------------------------------
//statement_list -> statement_list ; statement
//--------------------------------------------------------------------
List<Exp*>* Semantics::Statement_list(List<Exp*>* sl, List<Exp*>* s) {
	cout << "List<Exp*>* Semantics::Statement_list(List<Exp*>* sl, List<Exp*>* s)" << endl;
	sl->Append(s);
	sl->Print(tfs);
	return sl;
}
