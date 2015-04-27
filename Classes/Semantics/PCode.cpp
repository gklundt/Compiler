#include "PCode.h"

PCode::PCode(string l, string o, string r1, string r2) :
		label(l), op(o), rand1(r1), rand2(r2) {
	cout << "PCode::PCode(string l, string o, string r1, string r2)" << endl;
}
PCode::PCode(string l, string o, string r1, int r2) :
		label(l), op(o), rand1(r1) {
	cout << "PCode::PCode(string l, string o, string r1, int r2)" << endl;
	rand2 = String(r2);
}
PCode::PCode(string l, string o, int r1, int r2) :
		label(l), op(o) {
	cout << "PCode::PCode(string l, string o, int r1, int r2)" << endl;
	rand1 = String(r1);
	rand2 = String(r2);
}
PCode::PCode(string l, string o, int r1, string r2) :
		label(l), op(o), rand2(r2) {
	cout << "PCode::PCode(string l, string o, int r1, string r2)" << endl;
	rand1 = String(r1);
}
string PCode::Label(void) {
	cout << "string PCode::Label(void)" << endl;
	return label;
}
string PCode::Op(void) {
	cout << "string PCode::Op(void)" << endl;
	return op;
}
string PCode::Rand1(void) {
	cout << "string PCode::Rand1(void)" << endl;
	return rand1;
}
string PCode::Rand2(void) {
	cout << "string PCode::Rand2(void)" << endl;
	return rand2;
}
void PCode::StoreLabel(string l) {
	cout << "void PCode::StoreLabel(string l)" << endl;
	label = l;
}
void PCode::StoreOp(string o) {
	cout << "void PCode::StoreOp(string o)" << endl;
	op = o;
}
void PCode::StoreRand1(string r1) {
	cout << "void PCode::StoreRand1(string r1)" << endl;
	rand1 = r1;
}
void PCode::StoreRand2(string r2) {
	cout << "void PCode::StoreRand2(string r2)" << endl;
	rand2 = r2;
}
void PCode::Print(ostream& o) {
	cout << "void PCode::Print(ostream& o) " << endl;
	if (op == "arg")
		return;
	o << endl;
	o << setw(10) << left << label;
	o << setw(10) << left << op;
	o << setw(10) << left << rand1;
	o << setw(10) << left << rand2;
}
