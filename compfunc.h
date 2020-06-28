#include"func.h"

class compfunc:func {


public:
	compfunc(const func&, const func&);
	virtual func& operator<<(const int& x);
	virtual void print(ostream&) const;
	virtual int solve(const int& x);
};