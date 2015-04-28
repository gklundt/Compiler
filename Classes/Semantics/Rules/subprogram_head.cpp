#include "../Semantics.h"
//---------------------------------------------------------------------
//Function ParameterList creates a parameter list from a list of Variables
//---------------------------------------------------------------------
//static Subprogram* ParameterList(List<VariableSymbol*>* VL,Typ* RT)
Subprogram* Semantics::ParameterList(List<VariableSymbol*>* VL, Typ* RT) {
	List<Typ*>* PL = new List<Typ*>;
	for (VL->First(); !VL->IsEol(); VL->Next()) {
		VariableSymbol* S = VL->Member();
		Typ* T = S->Type();
		PL->Insert(T);
	}
	return new Subprogram(PL, RT);
}
//---------------------------------------------------------------------
//Function InsertVariables inserts variables into the symbol table
//---------------------------------------------------------------------
//static void InsertVariables(List<VariableSymbol*>* VL)
void Semantics::InsertVariables(List<VariableSymbol*>* VL) {
	for (VL->First(); !VL->IsEol(); VL->Next()) {
		VariableSymbol* S = VL->Member();
		SymbolTable::instance()->Insert(S);
	}
}
//---------------------------------------------------------------------
//subprogram_head->FUNCTION ID subprogram_parameters COLON standard_type SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a function symbol using the list of parameters created in step 1.
//3.  Insert the function symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
//void Semantics::subprogram_head(string id, List<VariableSymbol*>* VL, Typ* RT) {
SubprogramSymbol* Semantics::subprogram_head(string id,
		List<VariableSymbol*>* VL, Typ* RT) {
	Subprogram* PL = ParameterList(VL, RT);
	FunctionSymbol* F = new FunctionSymbol(id, PL,
			SymbolTable::instance()->LexicalLevel());
	SymbolTable::instance()->Insert(F);
	SymbolTable::instance()->NewLocality();
	InsertVariables(VL);
	return F;
}
//---------------------------------------------------------------------
//subprogram_head->PROCEDURE ID subprogram_parameters SEMICOLON
//1.  Traverse the list of variable symbols to create list of parameters
//2.  Create a procedure symbol using the list of parameters created in step 1.
//3.  Insert the procedure symbol into the symbol table.
//4.  Create a new locality.
//5.  Insert the variable symbols into the symbol table.
//---------------------------------------------------------------------
//void Semantics::subprogram_head(string id, List<VariableSymbol*>* VL) {
SubprogramSymbol* Semantics::subprogram_head(string id,
		List<VariableSymbol*>* VL) {

	Subprogram* PL = ParameterList(VL, SymbolTable::instance()->TVoid());
	ProcedureSymbol* P = new ProcedureSymbol(id, PL,
			SymbolTable::instance()->LexicalLevel());
	SymbolTable::instance()->Insert(P);
	SymbolTable::instance()->NewLocality();
	InsertVariables(VL);
	return P;
}
