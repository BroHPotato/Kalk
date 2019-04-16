#ifndef BASE_H
#define BASE_H

#define INI 50
#define SN 50
#define SSX 70
#define SSY 50

#define PON0 SN*0+INI
#define PON1 SN*1+INI
#define PON2 SN*2+INI
#define PON3 SN*3+INI

#define POL0 PON3+SN*0
#define POL1 PON3+SN*1
#define POL2 PON3+SN*2
#define POL3 PON3+SN*3

#define POS0 POL3+SN

#include <iostream>

enum class Base{Bin, Oct, Dec, Hex, Col};


#endif // BASE_H
