#include "polynom.h"

polynom::polynom() {
    n_ = 0;
    int* coefs_;
}

polynom::polynom(int n, int* coefs) {
    n_ = n;
    coefs_ = coefs;

    minVal_ = -5;
    maxVal_ = 5;
    map<int, int> fmap_;
    first_value = true;

}

func& polynom::operator<<(const int& x) {
    int value = solve(x);
    fmap_.insert({ x, value });
    
    if (!first_value) {
        maxVal_ = x > maxVal_ ? x : maxVal_;
        minVal_ = x < minVal_ ? x : minVal_;
    }
    else {
        minVal_ = x;
        maxVal_ = x;
        first_value = false;
    }

}

int polynom::solve(const int& x) {
    int value = 0;
    for (int i = 0; i <= this->n_; i++) {
        value += coefs_[i] * pow(x, i);
    }
    return value;
}

void polynom::print(ostream& os) const {
    this->printcoefs(os);
    os << endl << "Derivative: ";
    this->Derivative().printcoefs(os);
    os << "+C" << endl << "Integral: ";
    this->Integral().printcoefs(os);
    os << endl;
    this->plot(os);
}
polynom polynom::operator+(const polynom& f2) const {
    
    polynom min_deg_polynom, max_deg_polynom;

    //save the two polynoms as the max degree polynom and the min degree polynom.
    if (this->n_ > f2.n_) {
        polynom min_deg_polynom = f2;
        polynom max_deg_polynom(this->n_, this->coefs_);
    }
    else {
        polynom min_deg_polynom(this->n_, this->coefs_);
        polynom max_deg_polynom = f2;
    }

    //save variabls for readability
    int min_deg = min_deg_polynom.n_;
    int max_deg = max_deg_polynom.n_;

    //create the new polynom coefs and degree
    int new_polynom_deg = max_deg;
    int* new_coefs;
    new_coefs = new int[new_polynom_deg + 1];

    // as long as the polynoms have the same degree - add thier coefs
    for (int i = 0; i <= min_deg; i++) {
        new_coefs[i] = this->coefs_[i] + f2.coefs_[i];
    }

    // add the remained coefs of the heigher degree polynom
    for (int i = min_deg; i <= max_deg; i++) {
        new_coefs[i] = max_deg_polynom.coefs_[i];
    }

    //set the new polynom degree - remove the last zeroes in the coefs.
    int i = max_deg;
    while (max_deg_polynom.coefs_[i] == 0) {
        new_polynom_deg--;
        i--;
    }
    return polynom(new_polynom_deg, new_coefs);
}

polynom polynom::operator-(const polynom& f2) const {

    //get the minimum and maximum degrees.
    int min_deg = max(this->n_, f2.n_);
    int max_deg = min(this->n_, f2.n_);

    //initilize the new polynom coefs and degree
    int new_polynom_deg = max_deg;
    int* new_coefs;
    new_coefs = new int[max_deg + 1];

    //subtract the same oreder coefs
    for (int i = 0; i < min_deg; i++) {
        new_coefs[i] = this->coefs_[i] - f2.coefs_[i];
    }

    // add/subtract the rest of the coefs.
    for (int i = min_deg; i < max_deg; i++) {
        if (min_deg == this->n_){
            new_coefs[i] = -f2.coefs_[i];
        }
        else {
            new_coefs[i] = this->coefs_[i];
        }
    }

    //set the new polynom degree - remove the last zeroes in the coefs.
    int i = max_deg;
    while (new_coefs[i] == 0) {
        new_polynom_deg--;
        i--;
    }
    return polynom(new_polynom_deg, new_coefs);
}


polynom polynom::operator*(const polynom& f2) const {
    polynom f1 = polynom(this->n_, this->coefs_);

    //create the new polynom coefs and degree
    int new_polynom_deg = f1.n_ + f2.n_;
    int* new_coefs;
    new_coefs = new int[new_polynom_deg + 1];
    new_coefs = { 0 };

    // multiply each coefs of f1 in each coefs in f2 and ave all the products in temp array
    for (int i = 0; i < f1.n_; i++) {
        for (int j = 0; j < f2.n_; j++) {
            new_coefs[i+j] += f1.coefs_[i] * f2.coefs_[j];
        }
    }

    int i = new_polynom_deg;
    while (new_coefs[i] == 0) {
        new_polynom_deg--;
        i--;
    }

    return polynom(new_polynom_deg, new_coefs);
}

polynom polynom::Derivative() const{
    //create the new polynom coefs and degree
    int new_polynom_deg = this->n_ - 1;
    int* new_coefs;
    new_coefs = new int[new_polynom_deg + 1] ;

    for (int i = 0; i < this->n_; i++) {
        new_coefs[i] = this->coefs_[i+1] * (i + 1);
    }

    //set the new polynom degree - remove the last zeroes in the coefs.
    int i = new_polynom_deg;
    while (new_coefs[i] == 0) {
        new_polynom_deg--;
        i--;
    }

    return polynom(new_polynom_deg, new_coefs);
}

polynom polynom::Integral() const {
    //create the new polynom coefs and degree
    int new_polynom_deg = this->n_ + 1;
    int* new_coefs;
    new_coefs = new int[new_polynom_deg + 1];

    // save the constant as - an do the integral to the other coefs
    new_coefs[0] = 0;
    for (int i = 0; i < this->n_; i++) {
        new_coefs[i+1] = this->coefs_[i] / (i + 1);
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
