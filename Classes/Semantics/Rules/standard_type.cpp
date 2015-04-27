#include "../Semantics.h"

struct TypeException {
	TypeException(Sym* s) {
		cout << endl;
		cout << "Error on line " << line << " column " << col;
		cout << endl;
		cout << "The symbol shown below is not a type symbol.";
		cout << endl;
		s->Print(cout, 0);
		cout << endl;
	}
};

Typ* Semantics::standard_type(string id) {
	cout << "Typ* Semantics::standard_type(string id)" << endl;
	Sym* s = ST.Find(id);
	if (!s->IsTypeSymbol())
		throw TypeException(s);
	//s->Print(tfs, 0);
	return s->Type();
}
