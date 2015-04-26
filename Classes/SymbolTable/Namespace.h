#ifndef Namespace_h 
#define Namespace_h 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

#include "../Types/Typ.h"
#include "Sym.h"

class Namespace {

    struct Node {
        Node* LNode;          //Points to the left subordinate tree
        Sym* S;               //Points to a Symbol Descriptor
        Node* RNode;          //Points to the right subordinate tree
        Node(Sym* S);         //Constructs a leaf Node
        void  Print           //Prints a Symbol Descriptor to
             (ostream& o      //Output stream o
             ,int level       //Indented two spaces for each level
             );
    };
    Node* Root;              //Root of the Namespace
    Node* Insert             //Insert Symbol Descriptor S at Node N and
        (Node* N             //return a pointer to the node where S was
        ,Sym* S              //inserted
        );
    void Kill(Node* N);      //Recursively reclaim storage for all the Nodes in the tree using a postorder traversal
    Sym*  Find               //Find the Symbol Descriptor that describes
        (Node* N             //the identifier k.  Begin the search at Node
        ,string& k           //N.
        );
    void  Print              //Recursively print all the nodes in the
        (Node* N             //Namespace using an inorder traversal beginning
        ,ostream& o          //with Node N.
        ,int level           //Indent two spaces times the value of level
        );
public:
   Namespace();              //Create an empty Namespace
   ~Namespace();             //Reclaim storage for all the Nodes in the Namespace
   void Insert(Sym* S);      //Insert Symbol Descriptor S in the Namespace
   Sym* Find(string& k);     //Find the Symbol Descriptor for identifier k or return 0 if not found
   void Print                //Initiate the recursive printing of all the Symbol Descriptors in the Namespace
        (ostream& o          //Print to output stream o
        ,int level           //Begin printing at level zero
        );
   void Print(ostream& o);   //Print the Namespace
};
#endif
