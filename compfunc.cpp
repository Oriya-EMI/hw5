#include "compfunc.h"
#include "polynom.h"

compfunc::compfunc(func& q, func& p) : f1(&q), f2(&p) {}

compfunc::~compfunc(){}

func& compfunc::operator<<(const int& x) {
	int value = solve(x);
	fmap_[x]=value;

	if (first_value) {
		minVal_ = x;
		maxVal_ = x;
		first_value=false;
	}
	else {
		minVal_ = x < minVal_ ? x : minVal_;
		maxVal_ = x > maxVal_ ? x : maxVal_;
	}
 
 return *this;
}

void compfunc::print(ostream& output) const {
	output << endl;
	this->plot(output);
}

int compfunc::solve(const int& x) {
	int ineer_value = f2->solve(x);
	return f1->solve(ineer_value);
}
