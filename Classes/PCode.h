#ifndef PCode_h
#define PCode_h 1
//-------------------------------------------------------------------------
//File PCode_h defines class PCode.   
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
//C++ include files
//-------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
class PCode {
   string label;    //P-Code label
   string op;       //P-Code opcode
   string rand1;    //P-Code operand 1
   string rand2;    //P-Code operand 2
public:
   PCode(string l,string o,string r1,string r2);
   PCode(string l,string o,int r1,int r2);
   PCode(string l,string o,string r1,int r2);
   PCode(string l,string o,int r1,string r2);
   string Label(void); 
   string Op(void);
   string Rand1(void);
   string Rand2(void);
   void StoreLabel(string l);
   void StoreOp(string o);
   void StoreRand1(string r1);
   void StoreRand2(string r2);
   void Print(ostream& o);
};
#endif
