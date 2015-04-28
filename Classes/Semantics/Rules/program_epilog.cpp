#include "../Semantics.h"
List<Exp*>* Semantics::program_epilog(SubprogramSymbol* S) {
	//-----------------------------------------------------------------
	//Create a List of expression for the program epilog
	//-----------------------------------------------------------------
	List<Exp*>* L = new List<Exp*>;
//  ToDo: PRINT program_epilog labels
	//-----------------------------------------------------------------
	//Create and insert the mark stack pcode that creates the
	//stack mark for the program
	//-----------------------------------------------------------------
	PCode* P = new PCode("", "mst", "0", "");
	Exp* E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);

	//-----------------------------------------------------------------
	//Create and insert the call to the program body
	//-----------------------------------------------------------------
	//P = new PCode("", "cup", "0", "BROKEN");
	P = new PCode("", "cup", "0", S->ELabel());
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);

	//-----------------------------------------------------------------
	//Create and insert the stop instruction to halt the p-code
	//interpreter
	//-----------------------------------------------------------------
	P = new PCode("", "stp", "", "");
	E = new Exp(SymbolTable::instance()->TVoid(), P);
	L->Insert(E);

	return L;
}
