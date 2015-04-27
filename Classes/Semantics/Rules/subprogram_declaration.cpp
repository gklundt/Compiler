#include "../Semantics.h"

void Semantics::subprogram_declaration(SubprogramSymbol* S,
		List<Exp*>* compound_statement) {
	cout
			<< "void Semantics::subprogram_declaration(SubprogramSymbol* S, List<Exp*>* compound_statement)"
			<< endl;
	//-----------------------------------------------------------------------
	//Create a list of expressions containing the subprogram prolog, the
	//compound statement of the subprogram itself, and the subprogram epilog
	//making the entire subprogram.
	//-----------------------------------------------------------------------
	//First, verify that all is well in the trace file for the prolog,
	//compound_statement, and the epilog.
	//-----------------------------------------------------------------------
	List<Exp*>* prolog = subprogram_prolog(S);
	tfs << endl << "prolog";
	prolog->Print(tfs);
	tfs << endl << "compound_statement";
	compound_statement->Print(tfs);
	List<Exp*>* epilog = subprogram_epilog(S, compound_statement);
	tfs << endl << "epilog";
	epilog->Print(tfs);
	//-----------------------------------------------------------------------
	//Now, concatenate the prolog, compound_statement, and the epilog into
	//a single list.
	//-----------------------------------------------------------------------
	List<Exp*>* L = new List<Exp*>;
	L->Append(prolog);
	L->Append(compound_statement);
	L->Append(epilog);
	//-----------------------------------------------------------------------
	//Now, print the subprogram to the PCode File
	//-----------------------------------------------------------------------
	L->Print(pfs);

	ST.Print(tfs);            //Print the symbol table at this lexical level
	ST.PopLocality();         //Pop the current locality
}
