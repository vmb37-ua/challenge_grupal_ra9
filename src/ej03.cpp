// Exercise 3: split training and test by match
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <algorithm>
#include <cmath>
#include <set>

namespace ml {

std::pair<Dataset, Dataset> split_by_match(Dataset const& d, double test_fraction,
                                           Rng& rng) {
   Dataset train;
   Dataset test;
   std::set<int> matches(d.match.begin(), d.match.end());
   std::vector<int> ids(matches.begin(), matches.end());
   shuffle(ids, rng);
   int k = std::round(test_fraction*ids.size());
   std::set<int> const id_test(ids.end()-k, ids.end());
   for (int i=0; i<d.y.size(); i++){
      if(id_test.contains(d.match[i])){ 
         push_row(test, d ,i); // FIX S 1 : Argumentos invertidos
      } 
      else{
         push_row(train, d ,i); // FIX S 1
      }
   }
   return {train, test};
}

} // namespace ml
