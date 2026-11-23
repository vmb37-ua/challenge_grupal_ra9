// Exercise 9: Pocket
// The full statement is in the Challenge document.
#include "ml/ml.hpp"

namespace ml {

PocketResult pocket(Dataset const& d, Vec w, int max_updates, Rng& rng) {
   PocketResult best{w, accuracy(w, d), 0};
   // ◉◉YOUR CODE◉◉
   for(auto u{1}; u<=max_updates && best.accuracy<1.0 && (u-best.update)<=50; u+=1){
      std::vector<std::size_t> wrong;
      for(auto n{0uz}; n<d.y.size(); n+=1){
         if(d.y[n]*signal(w, d.X[n])<=0){wrong.push_back(n);} // FIX S1: falto un parentesis
      }
      auto const n=wrong[rng.below(wrong.size())];
      for(auto i{0uz}; i<w.size(); i+=1){w[i]+=d.y[n]*d.X[n][i];} // FIX S2: falto un punto y coma
      auto const acc=accuracy(w, d);
      if(acc>best.accuracy){best={w, acc, u};} // FIX S3: falto un parentesis 
   }

   return best;
}

} // namespace ml
