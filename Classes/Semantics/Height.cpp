#include "Height.h"

static string Op[] = { "cup", "csp", "ent", "mst", "rtn"                    // 5
		, "equ", "neq", "grt", "geq", "les", "leq"                         // 6
		, "adi", "sbi", "ngi", "mpi", "dvi", "abi", "sqi", "mod", "inc", "dec" //10
		, "adr", "sbr", "ngr", "mpr", "dvr", "abr", "sqr"                   // 7
		, "ior", "and", "xor", "not"                                     // 4
		, "inn", "uni", "int", "dif", "cmp", "sgs"                         // 6
		, "ujp", "xjp", "fjp", "tfp"                                     // 4
		, "flt", "flo", "trc", "chr", "ord"                               // 5
		, "lda", "ldc", "ind", "lva", "lvb", "lvc", "lvi", "lvr", "lvs"     // 9
		, "sti", "ixa"                                                 // 2
		};
static int OpDelta[] = { 0, 4, 0, 5, 0                                      // 5
		, -1, -1, -1, -1, -1, -1                                           // 6
		, -1, -1, 0, -1, -1, 0, 0, -1, 0, 0                               //10
		, -1, -1, 0, -1, -1, 0, 0                                        // 7
		, -1, -1, -1, 0                                                 // 4
		, -1, -1, -1, -1, 0, 0                                           // 6
		, 0, -1, -1, -1                                                 // 4
		, 0, 0, 0, 0, 0                                              // 5
		, 1, 1, 0, 1, 1, 1, 1, 1, 1                                  // 9
		, -2, -1                                                       // 2
		};
static map<string, int> SD;
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
Height::Height() :
		C(0), M(0) {
	InitStackDelta();
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void Height::Compute(PCode* P) {
	string op = P->Op();
	C += SD[op];
	if (op == "ent") {
		C = M = 0;
	}
	if (op == "sti") {
		C = 0;
	}
	if (op == "csp") {
		C = 0;
	}
	if (C > M)
		M = C;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
int Height::Maximum(void) {
	return M;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void Height::InitStackDelta(void) {
	for (int a = 0; a < 58; a++)
		SD[Op[a]] = OpDelta[a];
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void Height::FindHeight(Exp* E) {
	if (!E)
		return;
	FindHeight(E->LExp);
	FindHeight(E->RExp);
	Compute(E->P);
}
