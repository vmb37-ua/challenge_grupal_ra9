// Exercise 4: balance the classes
// The full statement is in the Challenge document.
#include "ml/ml.hpp"

namespace ml {

std::array<int, 2> class_counts(std::vector<int> const& y) {
   std::array<int, 2> c{0, 0};
   for(int i=0; i<y.size(); i++){
      c[y[i]<0 ? 0 : 1] += 1;
   }
   return c;
}

Dataset undersample(Dataset const& d, Rng& rng) {
   Dataset out;
   auto c = class_counts(d.y);
   int mino;
   int c_mino;

   if(c[0]<c[1]){mino = -1; c_mino=0;}
   else{mino=+1; c_mino=1;}
   std::vector<int> pos;

   for(int i=0; i<d.y.size(); i++){
      if(d.y[i]!=mino){pos.push_back(i);}
   }
   shuffle(pos, rng);
   std::vector<bool> keep(d.y.size(), false);
   for(int i=0; i<d.y.size(); i++){
      if(d.y[i]==mino) keep[i]=true;
   }
   for(int j=0; j<c[c_mino]*2; j++){
      if(j<pos.size()) keep[pos[j]]=true;
   }
   for(int k=0; k<d.y.size(); k++){
      if(keep[k]) push_row(out, d, k); // FIX 1 S : Argumentos invertidos
   }
   return out;
}

} // namespace ml
