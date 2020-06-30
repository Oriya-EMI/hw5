#include "func.h"

func::func() { fmap_.clear(); }
func::~func() {}

ostream& operator<<(ostream& output, const func& f)
{
    f.print(output);
    return output;
}

void func::plot(ostream& os) const {
   
  vector<int> sortImage;
    
  sortImage.clear();
  for ( auto it : fmap_){
      sortImage.push_back(it.second);
  }

  sort(sortImage.begin(), sortImage.end());
  reverse(sortImage.begin(), sortImage.end());

  for ( auto it_im = sortImage.begin();
       it_im != sortImage.end(); ++it_im) {
    if(it_im!=sortImage.begin() && *it_im==*(it_im-1)){ //remove repeated
      it_im = sortImage.erase(it_im)-1;
      
    }
  }
 
  for (auto it_im = sortImage.begin();
       it_im != sortImage.end(); ++it_im) {
    int x_anchor=minVal_;
    if(*it_im<-9) 
      os <<*it_im;
    else
      if((*it_im<0) || (*it_im>9)) 
	os<<" "<<*it_im;
      else 
	os<<"  "<<*it_im;
    
    for (auto it_dom :fmap_) {
      if(it_dom.second == *it_im){
	int x=it_dom.first;
	int spaces= x-x_anchor;
	int i=0;
	while(i<spaces){
	  os<<"   ";
	  i++;
	}
	os<<"*  ";
	x_anchor=x+1;
      }

    }

    os<<endl;
    if((it_im+1)!=sortImage.end()){ //print empty lines
      int lines=*it_im-*(it_im+1)-1;
      int i=1;
      
      while(i<lines+1){
	if(*it_im-i<-9) 
	  os <<*it_im-i;
	else 
	  if( (*it_im-i<0) || (*it_im-i>9) )
	    os<<" "<<*it_im-i;
	  else 
	    os<<"  "<<*it_im-i;
	std::cout<<std::endl;
	i++;

      }
    }

  }//for sortImage

  //print x axis
  cout<< " ";
  for (auto i=minVal_; i<maxVal_+1;i++){
    if(i<0) os<<" "<<i;
    else os<<"  "<<i;
  }
  os<<endl;
}
