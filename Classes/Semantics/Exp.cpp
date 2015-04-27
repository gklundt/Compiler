#include "Exp.h"

Exp::Exp(Exp* l, Exp* r, Typ* t, PCode* p) :
		LExp(l), RExp(r), T(t), P(p) {
	cout << "Exp::Exp(Exp* l, Exp* r, Typ* t, PCode* p)" << endl;
}
Exp::Exp(Typ* t, PCode* p) :
		LExp(0), RExp(0), T(t), P(p) {
	cout << "Exp::Exp(Typ* t, PCode* p)" << endl;
}
void Exp::PPrint(ostream& o) {
	cout << "void Exp::PPrint(ostream& o)" << endl;
	P->Print(o);
}
void Exp::TPrint(ostream& o, int depth) {
	cout << "void Exp::TPrint(ostream& o, int depth)" << endl;
	T->Print(o, depth);
}
void Exp::Print(ostream& o) {
	cout << "void Exp::Print(ostream& o)" << endl;
	if (LExp)
		LExp->Print(o);
	if (RExp)
		RExp->Print(o);
	P->Print(o);
}
Typ* Exp::Type(void) {
	cout << "Typ* Exp::Type(void)" << endl;
	return T;
}
void Exp::LeftAppend(Exp* L) {
	cout << "void Exp::LeftAppend(Exp* L)" << endl;
	Exp* e = this;
	Exp* p = e;
	while (e) {
		p = e;
		e = e->LExp;
	}
	p->LExp = L;
}
bool Exp::IsBoolean(void) {
	cout << "bool Exp::IsBoolean(void)" << endl;
	return T->IsBoolean();
}
bool Exp::IsCharacter(void) {
	cout << "bool Exp::IsCharacter(void)" << endl;
	return T->IsCharacter();
}
bool Exp::IsInteger(void) {
	cout << "bool Exp::IsInteger(void)" << endl;
	return T->IsInteger();
}
bool Exp::IsReal(void) {
	cout << "bool Exp::IsReal(void)" << endl;
	return T->IsReal();
}
