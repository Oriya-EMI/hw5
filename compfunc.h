#include "func.h"

class compfunc: public func {


public:
	compfunc(func& f1, func& f2);
 ~compfunc();
	virtual func& operator<<(const int& x);
	virtual void print(ostream&) const;
	virtual int solve(const int& x);

protected:
	func *f1, *f2;
};