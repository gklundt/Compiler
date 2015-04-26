obj =  Address.o \
	Boolean.o \
	Character.o \
	Constant.o \
	Integer.o \
	Real.o \
	Scalar.o \
	Void.o \
	Array.o \
	Range.o \
	Classes/Semantics/String.o \
	Subprogram.o \
	Typ.o \
	ConstantSymbol.o \
	FunctionSymbol.o \
	ProcedureSymbol.o \
	ProgramSymbol.o \
	StandardFunctionSymbol.o \
	StandardProcedureSymbol.o \
	StandardSubprogramSymbol.o \
	SubprogramSymbol.o \
	TypeSymbol.o \
	VariableSymbol.o \
	Label.o \
	Locality.o \
	LocalityStack.o \
	Namespace.o \
	StandardTypes.o \
	Sym.o \
	SymbolTable.o \
	coercetoreal.o \
	compound_statement.o \
	expression.o \
	expression_list.o \
	factor.o \
	identifier_list.o \
	optional_statements.o \
	parameter_list.o \
	procedure_statement.o \
	program.o \
	program_head.o \
	simple_expression.o \
	standard_type.o \
	statement.o \
	statement_list.o \
	subprogram_declaration.o \
	subprogram_head.o \
	subprogram_parameters.o \
	term.o \
	type.o \
	usersubprogram.o \
	variable.o \
	variable_declarations.o \
	Exp.o \
	PCode.o \
	Semantics.o \
	String.o 

all: yl ${obj}
	g++ -c paslex.cpp paspar.cpp
	g++ ${obj} paslex.o paspar.o -o pas -ll -ly

yl:
	lex paslex.l
	yacc -dv paspar.y
	mv lex.yy.c paslex.cpp
	mv y.tab.c paspar.cpp
	cat pastkn_prolog.h y.tab.h > pastkn.h
	

Address.o: Classes/Types/ScalarTypes/Address.cpp
	g++ -c -g Classes/Types/ScalarTypes/Address.cpp
Exp.o: Classes/Semantics/Exp.cpp
	g++ -c -g Classes/Semantics/Exp.cpp
PCode.o: Classes/Semantics/PCode.cpp
	g++ -c -g Classes/Semantics/PCode.cpp
coercetoreal.o: Classes/Semantics/Rules/coercetoreal.cpp
	g++ -c -g Classes/Semantics/Rules/coercetoreal.cpp
compound_statement.o: Classes/Semantics/Rules/compound_statement.cpp
	g++ -c -g Classes/Semantics/Rules/compound_statement.cpp
expression.o: Classes/Semantics/Rules/expression.cpp
	g++ -c -g Classes/Semantics/Rules/expression.cpp
expression_list.o: Classes/Semantics/Rules/expression_list.cpp
	g++ -c -g Classes/Semantics/Rules/expression_list.cpp
factor.o: Classes/Semantics/Rules/factor.cpp
	g++ -c -g Classes/Semantics/Rules/factor.cpp
identifier_list.o: Classes/Semantics/Rules/identifier_list.cpp
	g++ -c -g Classes/Semantics/Rules/identifier_list.cpp
optional_statements.o: Classes/Semantics/Rules/optional_statements.cpp
	g++ -c -g Classes/Semantics/Rules/optional_statements.cpp
parameter_list.o: Classes/Semantics/Rules/parameter_list.cpp
	g++ -c -g Classes/Semantics/Rules/parameter_list.cpp
procedure_statement.o: Classes/Semantics/Rules/procedure_statement.cpp
	g++ -c -g Classes/Semantics/Rules/procedure_statement.cpp
program.o: Classes/Semantics/Rules/program.cpp
	g++ -c -g Classes/Semantics/Rules/program.cpp
program_head.o: Classes/Semantics/Rules/program_head.cpp
	g++ -c -g Classes/Semantics/Rules/program_head.cpp
simple_expression.o: Classes/Semantics/Rules/simple_expression.cpp
	g++ -c -g Classes/Semantics/Rules/simple_expression.cpp
standard_type.o: Classes/Semantics/Rules/standard_type.cpp
	g++ -c -g Classes/Semantics/Rules/standard_type.cpp
statement.o: Classes/Semantics/Rules/statement.cpp
	g++ -c -g Classes/Semantics/Rules/statement.cpp
statement_list.o: Classes/Semantics/Rules/statement_list.cpp
	g++ -c -g Classes/Semantics/Rules/statement_list.cpp
subprogram_declaration.o: Classes/Semantics/Rules/subprogram_declaration.cpp
	g++ -c -g Classes/Semantics/Rules/subprogram_declaration.cpp
subprogram_head.o: Classes/Semantics/Rules/subprogram_head.cpp
	g++ -c -g Classes/Semantics/Rules/subprogram_head.cpp
subprogram_parameters.o: Classes/Semantics/Rules/subprogram_parameters.cpp
	g++ -c -g Classes/Semantics/Rules/subprogram_parameters.cpp
term.o: Classes/Semantics/Rules/term.cpp
	g++ -c -g Classes/Semantics/Rules/term.cpp
type.o: Classes/Semantics/Rules/type.cpp
	g++ -c -g Classes/Semantics/Rules/type.cpp
usersubprogram.o: Classes/Semantics/Rules/usersubprogram.cpp
	g++ -c -g Classes/Semantics/Rules/usersubprogram.cpp
variable.o: Classes/Semantics/Rules/variable.cpp
	g++ -c -g Classes/Semantics/Rules/variable.cpp
variable_declarations.o: Classes/Semantics/Rules/variable_declarations.cpp
	g++ -c -g Classes/Semantics/Rules/variable_declarations.cpp
Semantics.o: Classes/Semantics/Semantics.cpp
	g++ -c -g Classes/Semantics/Semantics.cpp
Classes/Semantics/String.o: Classes/Semantics/String.cpp
	g++ -c -g -o Classes/Semantics/String.o Classes/Semantics/String.cpp
Label.o: Classes/SymbolTable/Label.cpp
	g++ -c -g Classes/SymbolTable/Label.cpp
Locality.o: Classes/SymbolTable/Locality.cpp
	g++ -c -g Classes/SymbolTable/Locality.cpp
LocalityStack.o: Classes/SymbolTable/LocalityStack.cpp
	g++ -c -g Classes/SymbolTable/LocalityStack.cpp
Namespace.o: Classes/SymbolTable/Namespace.cpp
	g++ -c -g Classes/SymbolTable/Namespace.cpp
StandardTypes.o: Classes/SymbolTable/StandardTypes.cpp
	g++ -c -g Classes/SymbolTable/StandardTypes.cpp
ConstantSymbol.o: Classes/SymbolTable/Symbols/ConstantSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/ConstantSymbol.cpp
FunctionSymbol.o: Classes/SymbolTable/Symbols/FunctionSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/FunctionSymbol.cpp
ProcedureSymbol.o: Classes/SymbolTable/Symbols/ProcedureSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/ProcedureSymbol.cpp
ProgramSymbol.o: Classes/SymbolTable/Symbols/ProgramSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/ProgramSymbol.cpp
StandardFunctionSymbol.o: Classes/SymbolTable/Symbols/StandardFunctionSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/StandardFunctionSymbol.cpp
StandardProcedureSymbol.o: Classes/SymbolTable/Symbols/StandardProcedureSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/StandardProcedureSymbol.cpp
StandardSubprogramSymbol.o: Classes/SymbolTable/Symbols/StandardSubprogramSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/StandardSubprogramSymbol.cpp
SubprogramSymbol.o: Classes/SymbolTable/Symbols/SubprogramSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/SubprogramSymbol.cpp
TypeSymbol.o: Classes/SymbolTable/Symbols/TypeSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/TypeSymbol.cpp
VariableSymbol.o: Classes/SymbolTable/Symbols/VariableSymbol.cpp
	g++ -c -g Classes/SymbolTable/Symbols/VariableSymbol.cpp
SymbolTable.o: Classes/SymbolTable/SymbolTable.cpp
	g++ -c -g Classes/SymbolTable/SymbolTable.cpp
Sym.o: Classes/SymbolTable/Sym.cpp
	g++ -c -g Classes/SymbolTable/Sym.cpp
Array.o: Classes/Types/NonScalarTypes/Array.cpp
	g++ -c -g Classes/Types/NonScalarTypes/Array.cpp
Range.o: Classes/Types/NonScalarTypes/Range.cpp
	g++ -c -g Classes/Types/NonScalarTypes/Range.cpp
String.o: Classes/Types/NonScalarTypes/String.cpp
	g++ -c -g Classes/Types/NonScalarTypes/String.cpp
Subprogram.o: Classes/Types/NonScalarTypes/Subprogram.cpp
	g++ -c -g Classes/Types/NonScalarTypes/Subprogram.cpp
Boolean.o: Classes/Types/ScalarTypes/Boolean.cpp
	g++ -c -g Classes/Types/ScalarTypes/Boolean.cpp
Character.o: Classes/Types/ScalarTypes/Character.cpp
	g++ -c -g Classes/Types/ScalarTypes/Character.cpp
Constant.o: Classes/Types/ScalarTypes/Constant.cpp
	g++ -c -g Classes/Types/ScalarTypes/Constant.cpp
Integer.o: Classes/Types/ScalarTypes/Integer.cpp
	g++ -c -g Classes/Types/ScalarTypes/Integer.cpp
Real.o: Classes/Types/ScalarTypes/Real.cpp
	g++ -c -g Classes/Types/ScalarTypes/Real.cpp
Scalar.o: Classes/Types/ScalarTypes/Scalar.cpp
	g++ -c -g Classes/Types/ScalarTypes/Scalar.cpp
Void.o: Classes/Types/ScalarTypes/Void.cpp
	g++ -c -g Classes/Types/ScalarTypes/Void.cpp
Typ.o: Classes/Types/Typ.cpp
	g++ -c -g Classes/Types/Typ.cpp

clean:
	rm -f *.o
	rm -f *.*~
	rm -f paslex.cpp
	rm -f paspar.cpp
	rm -f y.tab.h
	rm -f y.output
	rm -f pastkn.h
	rm -f pas
	rm -f Classes/Semantics/String.o
	rm -f tests/*.trc
	rm -f tests/*.pcd

