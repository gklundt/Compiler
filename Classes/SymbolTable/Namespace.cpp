#include "Namespace.h"

Namespace::Node::Node(Sym* Symbol) :
		LNode(0), S(Symbol), RNode(0) {
}
Namespace::Node* Namespace::Insert(Node* N, Sym* S) {
	if (!N)
		return new Node(S);
	if (S->Id() == N->S->Id())
		return N;
	if (S->Id() < N->S->Id()) {
		N->LNode = Insert(N->LNode, S);
	} else {
		N->RNode = Insert(N->RNode, S);
	}
	return N;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Node::Print(ostream& o, int level) {
	S->Print(o, level);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Namespace::Namespace() :
		Root(0) {
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Kill(Node* N) {
	if (!N)
		return;
	Kill(N->LNode);
	Kill(N->RNode);
	delete N;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Namespace::~Namespace() {
	Kill(Root);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Insert(Sym* S) {
	Root = Insert(Root, S);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Sym* Namespace::Find(Node* N, string& key) {
	if (!N)
		return 0;
	if (key == N->S->Id())
		return N->S;
	if (key < N->S->Id()) {
		return Find(N->LNode, key);
	} else {
		return Find(N->RNode, key);
	}
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Sym* Namespace::Find(string& key) {
	return Find(Root, key);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Print(Node* N, ostream& o, int level) {
	if (!N)
		return;
	Print(N->LNode, o, level);
	N->Print(o, level);
	Print(N->RNode, o, level);
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Print(ostream& o, int level) {
	o << endl;
	Print(Root, o, 1);
	o << endl;
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void Namespace::Print(ostream& o) {
	Print(o, 0);
}
