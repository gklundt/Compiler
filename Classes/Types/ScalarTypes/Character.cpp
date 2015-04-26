#include "Character.h"
//-----------------------------------------------------------------------------
//Member functions of class Character
//-----------------------------------------------------------------------------
Character::Character() :
		Scalar(tk_character, 1, 1) {
}
Character::Character(int sz, int al) :
		Scalar(tk_character, sz, al) {
}
void Character::Print(ostream& o, int indent) {
	Scalar::Print(o, indent);
}
int Character::Size(void) {
	return Scalar::Size();
}
int Character::Alignment(void) {
	return Scalar::Alignment();
}
Character::~Character() {
}
