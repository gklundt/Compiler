#include "Array.h"

struct ArrayException {
	ArrayException(Array* a) {
		cout << endl;
		cout << "Array Exception - the index type is not a range.";
		cout << endl;
		a->Print(cout, 0);
		cout << endl;
	}
};

Array::Array(Range* i, Typ* e) :
		Typ(tk_array), index(i), element(e) {
}
Array::Array(typekind tk, Range* i, Typ* e) :
		Typ(tk_array), index(i), element(e) {
}
void Array::Print(ostream& o, int indent) {
	Typ::Print(o, indent);
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "Size(" << Size() << ")";
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "Index Type";
	index->Print(o, indent + 2);
	o << endl;
	for (int a = 0; a < indent + 1; a++)
		o << "  ";
	o << "Element Type";
	element->Print(o, indent + 2);
}

int Array::Size(void) {
	if (!(index->IsRange()))
		throw ArrayException(this);
	Range* i = (Range*) index;
	int elementcount = i->Cardinality();
	int elementsize = element->Size();
	return elementcount * elementsize;
}
int Array::Alignment(void) {
	return element->Alignment();
}
Range* Array::IndexType(void) {
	return index;
}
Typ* Array::ElementType(void) {
	return element;
}
int Array::Stride(void) {
	return element->Size();
}

Array::~Array() {
}
