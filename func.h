#ifndef _F1
#define _F1
#include <map>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>

using std::map;
using std::ostream;
using namespace std;

class func {
private:


protected:
  
    int maxVal_; //maximum of all inputs
    int minVal_; //minimum of all inputs
    bool first_value;
    map<int,int> fmap_; //holds inputs and corresponding outputs
    void plot(ostream& os) const ; //plot fmap_

public:
    func();
    virtual ~func();
    virtual func& operator<<(const int& x) = 0;
    friend ostream& operator<<(ostream&, const func& f);

    virtual void print(ostream&) const = 0;

    virtual int solve(const int& x) = 0;

};


#endif
