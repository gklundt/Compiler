#include "../Semantics.h"

List<Exp*>* Semantics::expression_list(Exp* expression) {
	cout << "List<Exp*>* Semantics::expression_list(Exp* expression)" << endl;
	List<Exp*>* L = new List<Exp*>;
	L->Insert(expression);
	return L;
}
List<Exp*>* Semantics::expression_list(List<Exp*>* expression_list,
		Exp* expression) {
	cout
			<< "List<Exp*>* Semantics::expression_list(List<Exp*>* expression_list, Exp* expression)"
			<< endl;
	expression_list->Insert(expression);
	return expression_list;
}

