#include"func.h"

class compfunc:func {


public:
	compfunc(func& f1, func& f2);
	virtual func& operator<<(const int& x);
	virtual void print(ostream&) const;
	virtual int solve(const int& x) const;

protected:
	func* f1, *f2;
};