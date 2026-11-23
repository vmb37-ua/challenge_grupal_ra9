// Exercise 8: PLA
// The full statement is in the Challenge document.
#include "ml/ml.hpp"

namespace ml {

PlaResult pla(Dataset const& d, Vec w, int max_updates) {
   // ◉◉YOUR CODE◉◉
   auto updates{0}; // FIX S1: falto un punto y coma

   while(true){
      auto n{d.y.size()}; // FIX E1: no hay ninguna mal clasificada
      for(auto i{0uz}; i<d.y.size(); i+=1){ // FIX E2: el for lo tenia incompleto
         if(d.y[i]*signal(w, d.X[i])<=0){n=i;} // FIX F1: falta la ultima mal clasificada
      }
      if(n==d.y.size()){return {w, updates, true};} // FIX E3: mirar primero
      if(updates==max_updates){return {w, updates, false};} // FIX E4: updates en vez de n
      for(auto i{0uz}; i<w.size(); i+=1){w[i]+=d.y[n]*d.X[n][i];} // FIX E5: w.size() en vez de d.y.size()
      updates+=1;
   }
   return {w, 0, false};
}

} // namespace ml
