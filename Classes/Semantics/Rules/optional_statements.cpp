#include "../Semantics.h"
List<Exp*>* Semantics::Optional_statements(void) {
	return new List<Exp*> ;
}
//--------------------------------------------------------------------
//optional_statements -> statement_list
//--------------------------------------------------------------------
List<Exp*>* Semantics::Optional_statements(List<Exp*>* sl) {
	return sl;
}
