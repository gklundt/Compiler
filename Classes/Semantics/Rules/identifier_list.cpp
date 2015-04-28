#include "../Semantics.h"

List<string>* Semantics::identifier_list(string* i) {
	List<string>* L = new List<string>;
	L->Insert(*i);
	return L;
}
//---------------------------------------------------------------------
//Function identifier_list appends an identifier onto an existing list.
//---------------------------------------------------------------------
List<string>* Semantics::identifier_list(List<string>* L, string* i) {
	L->Insert(*i);
	return L;
}

