#include "../Semantics.h"
//---------------------------------------------------------------------
//Function ParameterList creates a parameter list from a list of Variables
//---------------------------------------------------------------------
//static Subprogram* ParameterList(List<VariableSymbol*>* VL,Typ* RT)
Subprogram* Semantics::ParameterList(List<VariableSymbol*>* VL, Typ* RT) {
	cout
			<< "Subprogram* Semantics::ParameterList(List<VariableSymbol*>* VL, Typ* RT)"
			<< endl;
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
	cout << "void Semantics::InsertVariables(List<VariableSymbol*>* VL)"
			<< endl;
	for (VL->First(); !VL->IsEol(); VL->Next()) {
		VariableSymbol* S = VL->Member();
		ST.Insert(S);
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
	cout
			<< "SubprogramSymbol* Semantics::subprogram_head(string id,List<VariableSymbol*>* VL,Typ* RT)"
			<< endl;
	Subprogram* PL = ParameterList(VL, RT);
	FunctionSymbol* F = new FunctionSymbol(id, PL, ST.LexicalLevel());
	ST.Insert(F);
	ST.NewLocality();
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
	cout
			<< "SubprogramSymbol* Semantics::subprogram_head(string id,List<VariableSymbol*>* VL)"
			<< endl;

	Subprogram* PL = ParameterList(VL, ST.TVoid());
	ProcedureSymbol* P = new ProcedureSymbol(id, PL, ST.LexicalLevel());
	ST.Insert(P);
	ST.NewLocality();
	InsertVariables(VL);
	return P;
}
