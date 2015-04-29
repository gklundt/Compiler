#include "../Semantics.h"
void Semantics::program(SubprogramSymbol* S, List<Exp*>* compound_statement) {
	//-----------------------------------------------------------------------
	//First, verify that all is well in the trace file for the prolog,
	//compound_statement, and the epilog.
	//-----------------------------------------------------------------------
	List<Exp*>* prolog = subprogram_prolog(S);
//	cout << endl << "prolog";
//	prolog->Print(cout);

//	cout << endl << "compound_statement";
//	compound_statement->Print(cout);

	List<Exp*>* epilog = subprogram_epilog(S, compound_statement);
//	cout << endl << "epilog";
//	epilog->Print(cout);

	List<Exp*>* programepilog = program_epilog(S);
//	cout << endl << "program epilog";
//	programepilog->Print(cout);
	//-----------------------------------------------------------------------
	//Now, concatenate the prolog, compound_statement, and the epilog into
	//a single list.
	//-----------------------------------------------------------------------
	List<Exp*>* L = new List<Exp*>;
	L->Append(prolog);
	L->Append(compound_statement);
	L->Append(epilog);
	L->Append(programepilog);
	//-----------------------------------------------------------------------
	//Now, print the subprogram to the PCode File
	//-----------------------------------------------------------------------
	L->Print(pfs);

}

