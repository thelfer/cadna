// Copyright 2015 J.-M. Chesneaux, P. Eberhart, F. Jezequel, J.-L. Lamotte

// This file is part of CADNA.

// CADNA is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// CADNA is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License
// along with CADNA.  If not, see <http://www.gnu.org/licenses/>.

#include<ostream>
#include<istream>
#include<cstring>
#include<cmath>

#define CADNA_MAXCHAINE 256
static char chstr[CADNA_MAXCHAINE][64];
static int numstr=0; 
#ifdef _OPENMP
#pragma omp threadprivate(chstr, numstr)
#endif //_OPENMP

#include"cadna/numeric_type.hxx"

namespace cadna{

  constexpr const int    default_accuracy<double>::value;
  constexpr const double default_accuracy<double>::thresold;
  constexpr const int    default_accuracy<float>::value;
  constexpr const double default_accuracy<float>::thresold;
  
  static char* str(const numeric_type<double>& v,char *s) 
  {
    int nn,  nres, naux;
    double fract_res, res;
    int tmp;
    char *t;

    // compute the number of exact significant digits always
    // with the same rounding mode

    if (v.accuracy==DIGIT_NOT_COMPUTED || v.accuracy==RELIABLE_RESULT)
      nb_significant_digit(v);
  
    //        12345678901234567890123
    strcpy(s,"                       ");
    if (v.accuracy==0) {
      strncpy(s," @.0",4);
    }
    else {
      v.accuracy=(v.accuracy<15) ? v.accuracy : 15;
      res=( (v.x) +(v.y) +(v.z) )/(double)(3);
      if (res<0.0) strncpy(s,"-0.",3);
      else strncpy(s," 0.",3);
      res=fabs(res);
    
      if (res==0.0) {
	nn=0;
	fract_res=0.0;
      }
      else{
	if (res>=1.0) nn=(int)log10(res)+1;
	else  nn= (int)log10(res);
	fract_res=res*std::pow(10.,-nn);
	if (fract_res<0.1) fract_res=0.1;
	if (fract_res>=1.0) {
	  fract_res=0.1;
	  nn=nn+1;
	}
      }
      naux=v.accuracy+3;
      t=s+3;
      for(int i=4;i<naux;i++){
	nres=(int)(fract_res*10.);
	*t++=48+nres;
	fract_res=10.0*fract_res-nres;
      }
      tmp = (int)(fract_res*10.0);
      nres = tmp < 9 ? tmp : 9 ;
      *t++=48+nres;
      *t++='E';
      if(nn<0) *t++='-';
      else *t++='+';
      nn=abs(nn);
      *t++=48+(nn/100);
      nn=nn%100;        
      *t++=48+(nn/10);
      *t++=48+(nn%10);
      *t='\0';
    }

    return(s);
  }

  static char* str(const numeric_type<float>& v,char *s) 
  {
    int nn, nres, naux;
    float fract_res, res;
    int tmp;
    char *t;

    // compute the number of significant digits always
    // with the same rounding mode
    if (v.accuracy==DIGIT_NOT_COMPUTED || v.accuracy==RELIABLE_RESULT)
      nb_significant_digit(v);
    //        12345678901234567890123
    strcpy(s,"                       ");
    if (v.accuracy==0) {
      strncpy(s," @.0",4);
    }
    else {
      v.accuracy=(v.accuracy<7) ? v.accuracy : 7;
      res=( (v.x) +(v.y) +(v.z) )/(float)(3);
      if (res<0.0) strncpy(s,"-0.",3);
      else strncpy(s," 0.",3);
      res=fabsf(res);
    
      if (res==0.0) {
	nn=0;
	fract_res=0.0;
      }
      else{
	if (res>=1.0) nn=(int)log10(res)+1;
	else  nn= (int)log10(res);
	fract_res=res*std::pow(10.,-nn);
	if (fract_res<0.1) fract_res=0.1;
	if (fract_res>=1.0) {
	  fract_res=0.1;
	  nn=nn+1;
	}
      }
      naux=v.accuracy+3;
      t=s+3;
      for(int i=4;i<naux;i++){
	nres=(int)(fract_res*10.);
	*t++=48+nres;
	fract_res=10.0*fract_res-nres;
      }
      tmp = (int)(fract_res*10.0);
      nres = tmp < 9 ? tmp : 9 ;
      *t++=48+nres;
      *t++='E';
      if(nn<0) *t++='-';
      else *t++='+';
      nn=abs(nn);
      *t++=48+(nn/100);
      nn=nn%100;        
      *t++=48+(nn/10);
      *t++=48+(nn%10);
      *t='\0';
    }

    return(s);
  }
  
  std::ostream& operator <<(std::ostream& s, const numeric_type<double> &a) 
  {
    char ch[25];
    return s << str(a,ch);
  }

  std::ostream& operator <<(std::ostream& s, const numeric_type<float> &a) 
  {  
    char ch[25];
    return s << str(a,ch);
  }

  std::istream& operator >>(std::istream& s, numeric_type<double>& a)
  {
    double d;
    s >> d;
    a.x = a.y = a.z = d;
    a.accuracy=DIGIT_NOT_COMPUTED;
    return s;
  }

  std::istream& operator >>(std::istream& s, numeric_type<float>& a)
  {
    float d;
    s >> d;
    a.x = a.y = a.z = d;
    a.accuracy=DIGIT_NOT_COMPUTED;
    return s;
  }

  const char* internal_strp(const numeric_type<double>& a)
  {
    char *s=chstr[numstr];
    if ((++numstr) == CADNA_MAXCHAINE)  numstr=0; 
    return str(a,s);
  }
  
  const char* internal_strp(const numeric_type<float>& a)
  {
    char *s = chstr[numstr];
    if ((++numstr) == CADNA_MAXCHAINE)  numstr=0; 
    return str(a,s);
  }
  
} // end of namespace cadna
