#include "polynom.h"

void polynom::polynom(int n, int* coefs) {
    n_ = n;
    coefs_ = coefs;
}

polynom polynom::operator+(const polynom& f1, const polynom& f2) {
    //save the two polynoms as the max degree polynom and the min degree polynom.
    polynom min_deg_polynom = f1 if f1.n > f2.n else f2;
    polynom max_deg_polynom = f1 if f1.n > f2.n else f2;

    //save variabls for readability
    int min_deg = min_deg_polynom.n;
    int max_deg = max_deg_polynom.n;

    //create the new polynom coefs and degree
    int new_polynom_deg = max_deg;
    int* [new_polynom_deg] new_coefs;

    // as long as the polynoms have the same degree - add thier coefs
    for (int i = 0; i < min_deg; i++) {
        new_coefs[i] = f1.coefs_[i] + f2.coefs_[i];
    }

    // add the remained coefs of the heigher degree polynom
    for (int i = min_deg; i < max_deg; i++) {
        new_coefs[i] = max_deg_polynom[i]
    }

    //set the new polynom degree - remove the last zeroes in the coefs.
    int i = max_deg-1
        while (max_deg_polynom.coefs_[i] == 0) {
            new_polynom_deg--;
            i--;
    }
    return polynom(new_polynom_deg, new_coefs)
}

polynom polynom::operator-(const polynom& f1, const polynom& f2) {
    polynom min_deg_polynom = f1 if f1.n > f2.n else f2;
    polynom max_deg_polynom = f1 if f1.n <= f2.n else f2;

    //save variabls for readability
    int min_deg = min_deg_polynom.n;
    int max_deg = max_deg_polynom.n;

    //create the new polynom coefs and degree
    int new_polynom_deg = max_deg;
    int* [new_polynom_deg] new_coefs;

    for (int i = 0; i < min_deg; i++) {
        new_coefs[i] = f1.coefs_[i] - f2.coefs_[i];
    }
    for (int i = min_deg; i < max_deg; i++) {
        if (min_deg == f1.n){
            new_coefs[i] = -f2.coefs[i]
        }
        else {
            new_coefs[i] = f1.coefes[i]
        }
    }

    //set the new polynom degree - remove the last zeroes in the coefs.
    int i = max_deg - 1
        while (max_deg_polynom.coefs_[i] == 0) {
            new_polynom_deg--;
            i--;
        }
    return polynom(new_polynom_deg, new_coefs)
}


polynom polynom::operator*(const polynom& f1, const polynom& f2) {
    int temp_n = f1.n * f2.n;
    int* [temp_n] temp_coefs;

    //create the new polynom coefs and degree
    int new_polynom_deg = f1.n+f2.n
    int* [new_polynom_deg] new_coefs;

    // multiply each coefs of f1 in each coefs in f2 and ave all the products in temp array
    for (int i = 0; i < f1.n; i++) {
        for (int j = 0; j < f2.n; j++) {
            temp_coefs[i+j] += f1.coefs_[i] * f2.coefs_[j];
        }
    }

    // the first coefs is the first product
    new_coefs[0] = temp_coefs[0];

    // sum all same coefs
    for (int i=1; i < temp_n-2; i++) {
        new_coefs[i] = temp_coefs[i] + temp_coefs[i + 2];
    }

    // the last coef is the product of the highst coefs.
    new_coefs[new_polynom_deg - 1] = temp_coefs[temp_n - 1]


    return polynom(new_polynom_deg, new_coefs)
}

polynom::polynom Derivative(const polynom& f;) {
    //create the new polynom coefs and degree
    int new_polynom_deg = f.n - 1;
    int* [new_polynom_deg] new_coefs;
    for (int i = 0; i < f.n; i++) {
        new_coefs[i] = f.coefs[i+1] * (i + 1);
    }
    return polynom(new_polynom_deg, new_coefs);
}

polynom::polynom Integral(const polynom& f;) {
    //create the new polynom coefs and degree
    int new_polynom_deg = f.n + 1;
    int* [new_polynom_deg] new_coefs;

    new_coefs[0] = 0;
    for (int i = 0; i < f.n; i++) {
        new_coefs[i+1] = f.coefs[i] / (i + 1);
    }

    return polynom(new_polynom_deg, new_coefs);
}

void polynom::printcoefs(ostream& os)  const {
  int allZero = 1;
  for (auto i = n_ ; i>=0; i--) {
    if (coefs_[i]>0) {
      allZero = 0;
      if(i!=n_){
	os << "+";
      }
      if (coefs_[i]!=1 || i==0){
	os << coefs_[i];
      }
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(coefs_[i]<0) {
      allZero = 0;
      if (coefs_[i]!=-1 || i==0){
	os << coefs_[i];
      }
      else 
	os << "-";
      if(i>0) {
	os << "x";
	if (i>1) 
	  os << "^" << i ;
      }
    }
    else if(i==0 && allZero == 1){ //coefs_[i]==0
        os << "0";
	continue;
    }
  }
}
