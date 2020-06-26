#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
 public:
     void polynom(int, int*);
     void printcoefs(ostream&)  const ;
     friend polynom operator+(const polynom&, const polynom&);
     friend polynom operator-(const polynom&, const polynom&);
     friend polynom operator*(const polynom&, const polynom&);

 protected:

  int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
