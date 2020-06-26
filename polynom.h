#ifndef _POLY_F
#define _POLY_F

#include "func.h"

using namespace std;


class polynom : public func {
 public:
     polynom(int, int*); 
     //~polynom();
     void printcoefs(ostream&)  const ;
     polynom operator+(const polynom&) const;
     polynom operator-(const polynom&) const;
     polynom operator*(const polynom&) const;

     virtual func& operator<<(const int& x);
     virtual ostream& operator<<(ostream&, const func&);

 protected:

  int n_; //order of the polynom
  int* coefs_; //coefficients 
};



#endif
 
