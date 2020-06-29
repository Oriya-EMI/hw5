#include"compfunc.h"
#include"polynom.h"

compfunc::compfunc(func& q, func& p) : f1(&q), f2(&p) {}


func& compfunc::operator<<(const int& x) {
	int value = solve(x);
	fmap_.insert(x, value);

	if (first_value) {
		minVal_ = x;
		maxVal_ = x;
	}
	else {
		minVal_ = x < minVal_ ? x : minVal_;
		maxVal_ = x > maxVal_ ? x : maxVal_;
	}
}

void compfunc::print(ostream& output) const {
	output << endl;
	f2->print(output);
}

int compfunc::solve(const int& x) const {
	int ineer_value = f1->solve(x);
	return f2->solve(ineer_value);
}
