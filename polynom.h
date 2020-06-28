#ifndef _POLY_F
#define _POLY_F

#include "func.h"


class polynom : public func {
 public:
     polynom();
     polynom(int, int*); 
     void printcoefs(ostream&)  const ;
     polynom operator+(const polynom&) const;
     polynom operator-(const polynom&) const;
     polynom operator*(const polynom&) const;
     polynom Derivative() const;
     polynom Integral() const;

     virtual func& operator<<(const int& x);
     virtual void print(ostream&) const;
     virtual int solve(const int& x);

 protected:

  int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
