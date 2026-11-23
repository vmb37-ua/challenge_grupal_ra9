// Exercise 7: signal and accuracy
// The full statement is in the Challenge document.
#include "ml/ml.hpp"

namespace ml {

double signal(Vec const& w, Vec const& x) {
   auto s{0.0};
   // ◉◉YOUR CODE◉◉
   for(auto i{0uz}; i<x.size(); i+=1){s+=w[i]*x[i];}

   return s;
}

double accuracy(Vec const& w, Dataset const& d) {
   // ◉◉YOUR CODE◉◉
   auto nou{0};
   auto ok{0};
   auto pos{0}, neg{0};; // FIX F1: Falta contadores para cada lado

   for(auto n{0uz}; n<d.y.size(); n+=1){ 
      if(d.y[n]*signal(w, d.X[n])>0){ok+=1;}// FIX N1: pase el d.y[n] en vez de d.y[x]
      if((d.y[n]<=0) && signal(w, d.X[n])<0){ // FIX N1: pase el d.y[n] en vez de d.y[x] FIX E1: < en vez de <=
         nou+=1;
      }
      if(d.y[n]>0){pos+=1;} else {neg+=1;} // FIX F2: falta contar las filas de cada clase
   }
   if(neg==0){ // FIX F3: si no hay filas -1, solo cuenta la clase +1
      return double(ok)/pos;
   }
   if(pos==0){ // FIX F4: si no hay filas +1, solo cuenta la clase -1
      return double(nou)/neg;
   }
   return (double(ok-nou)/pos + double(nou)/neg)/2;// FIX E2: media equilibrada en double

   return 0;
}

} // namespace ml
