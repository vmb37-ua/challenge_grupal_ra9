// Exercise 10: confusion matrix and weighted error
// The full statement is in the Challenge document.
#include "ml/ml.hpp"

namespace ml {

Confusion confusion(Vec const& w, Dataset const& d) {
   Confusion c;
   for(int n=0; n<d.y.size(); n+=1)
   {
      auto const ok = d.y[n] * signal(w, d.X[n]) > 0;//E1: error al llamar signal
      if (d.y[n]>0)
      {
         if (ok)
         {
            c.tp+=1;
         }
         else
         {
            c.fn+=1;
         }
      }
      else
      {
         if(ok)
         {
            c.tn +=1;
         }
         else
         {
            c.fp +=1;
         }
      }
      
   }
   return c;
}

double weighted_error(Confusion const& c, double cost_fn, double cost_fp) {
   return (cost_fn*c.fn + cost_fp*c.fp)/(cost_fn*(c.tp+c.fn));//S1 falta punto y coma
   return 0;
}

} // namespace ml