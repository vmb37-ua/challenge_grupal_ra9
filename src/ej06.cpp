// Exercise 6: standardize
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <cmath>

namespace ml {
// FIX <tipo><nº>: <motivo>   (N, E, S, F)
Standardizer fit_standardizer(Dataset const& train) {
   auto const n = train.X.size();
   auto const dims = train.X[0].size();
   Standardizer s{Vec(dims, 0.0), Vec(dims, 1.0)};
   // ◉◉YOUR CODE◉◉
   for(std::size_t j = 1; j < dims; j++){
      double suma = 0.0;
      for(std::size_t i = 0; i < n ; i++){
         suma += train.X[i][j];
      }
      s.mean[j] = suma / n;
   }
   double sumatorio = 0.0;
   for (std::size_t j = 1; j < dims;j++){
      sumatorio = 0.0; //FIX <F><1>: Faltaba ponerlo a 0 cada vez que cambiamos j  (N, E, S, F)
      for(std::size_t i = 0; i < n; i++){
         sumatorio += ((train.X[i][j] - s.mean[j]) * (train.X[i][j] - s.mean[j]));
      }
      //s.sd[j].push_back(std::sqrt(sumatorio / (n-1))); //FIX <E><1>: no podemos hacer pushback en literalmente un numero
      auto const sd = std::sqrt(sumatorio / (n-1));  // para la solucion tenemos que guardar el resultado y meterlo en sd[j],
      s.sd[j] = sd > 0 ? sd : 1.0;                   // pero además también tenemos que hacer que en caso que sea menor o igual que 0 pasarlo a 1;
   }
   return s;
}

void standardize(Standardizer const& s, Dataset& d) {
   // ◉◉YOUR CODE◉◉
   for(std::size_t i = 0; i < d.X.size(); i++){
      for(std::size_t j = 1; j < d.X[0].size();j++){
         d.X[i][j] = (d.X[i][j] - s.mean[j]) / s.sd[j]; // FIX <S><1>: Me he equivocado con el nombre de s (lo puse como d)  (N, E, S, F)
      }
   }
}

} // namespace ml
/* === FIXES
;;  Tipo: Cant.
;;  *  N:    0     (no existe)
;;  *  E:    1     (errónea)
;;  *  S:    1     (sintaxis)
;;  *  F:    1     (falta algo)
;;
;; EXPLICACIONES ADICIONALES DE FIXES (si es necesario)
;;  *
*/