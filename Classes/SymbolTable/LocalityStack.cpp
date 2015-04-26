#include "LocalityStack.h"

LocalityStack::LocalityStack(int sz) :
		size(sz), tos(-1) {
	L = new Locality*[size];
}

LocalityStack::~LocalityStack() {
	if (L)
		delete[] L;
}

bool LocalityStack::IsEmpty(void) {
	return tos == -1;
}

bool LocalityStack::IsFull(void) {
	return tos >= size - 1;
}

void LocalityStack::Push(Locality* V) {
	if (IsFull())
		throw LocalityStackException("full");
	L[++tos] = V;
}

Locality* LocalityStack::Pop(void) {
	if (IsEmpty())
		throw LocalityStackException("empty");
	return L[tos--];
}

Locality* LocalityStack::Top(void) {
	if (IsEmpty())
		return 0;
	else
		return L[tos];
}

Sym* LocalityStack::Find(char* id) {
	string s(id);
	return Find(s);
}

Sym* LocalityStack::Find(string& id) {
	for (int l = tos; l >= 0; l--) {
		Sym* s = L[l]->Find(id);
		if (s)
			return s;
	}
	return 0;
}

void LocalityStack::Insert(Sym* S) {
	L[tos]->Insert(S);
}

int LocalityStack::LexicalLevel(void) {
	return tos;
}

int LocalityStack::Offset(void) {
	return L[tos]->Offset();
}

void LocalityStack::Print(ostream& o) {
	for (int a = 0; a <= tos; a++) {
		o << endl << "Lexical level: " << a;
		L[a]->Print(o);
	}
}

void LocalityStack::Print(ostream& o, int ll) {
	o << endl << "Lexical level: " << ll;
	L[tos]->Print(o);
}
