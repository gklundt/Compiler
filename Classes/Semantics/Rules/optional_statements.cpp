#include "../Semantics.h"
List<Exp*>* Semantics::Optional_statements(void) {
	cout << "List<Exp*>* Semantics::Optional_statements(void)" << endl;
	return new List<Exp*> ;
}
//--------------------------------------------------------------------
//optional_statements -> statement_list
//--------------------------------------------------------------------
List<Exp*>* Semantics::Optional_statements(List<Exp*>* sl) {
	cout << "List<Exp*>* Semantics::Optional_statements(List<Exp*>* sl)"
			<< endl;
	return sl;
}
