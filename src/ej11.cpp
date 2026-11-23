// Exercise 11: Hoeffding
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <algorithm>
#include <cmath>

namespace ml {

double hoeffding_bound(double eps, int n, double m) {
   auto const bound= 2 * m * std::exp(-2 * eps * eps * n); //S1: Mal delcarado exp
   //S2 no declarado bound
   if (bound>1)
   {
      return 1;
   }
   else
   {
      return bound;
   }
   
   return 0;
}

double hoeffding_epsilon(int n, double delta, double m) {
   auto const eps = std::sqrt(std::log(2 * m / delta) / (2.0 * n));//E1: se aplica el umbral 1 tambien
   if (eps > 1) {
      return 1;
   } else {
      return eps;
   }
}

double max_hypotheses(double eps, int n, double delta) {
   return std::floor(delta / 2 * std::exp(2 * eps * eps * n)); //E2: Mal despejado M
   return 0;
}

} // namespace ml