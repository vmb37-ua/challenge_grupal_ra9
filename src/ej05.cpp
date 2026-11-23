// Exercise 5: filter rallies
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <stdexcept>

namespace ml {

Table filter_rallies(Table const& t, int result, int skip) {
   auto const m = column_index(t, "match");
   auto const r = column_index(t, "rally");
   auto const f = column_index(t, "frame");
   auto const res = column_index(t, "rally_result");
   auto const side = column_index(t, "side");
   if (m < 0 || r < 0 || f < 0 || res < 0 || side < 0) {
      throw std::runtime_error("faltan columnas del peloteo");
   }

   Table out{t.columns, {}};
   // ◉◉YOUR CODE◉◉
   double new_frame = 0.0;
   std::string match ="";
   std::string rally = "";
   for(std::size_t i= 0; i < t.rows.size(); i++){
      if(match != t.rows[i][m] || rally != t.rows[i][r]){
         match = t.rows[i][m];
         rally = t.rows[i][r];
         new_frame = std::stol(t.rows[i][f]);
      }
      if(t.rows[i][side] == "left" && (std::stoi(t.rows[i][res]) == result) && (std::stol(t.rows[i][f]) - new_frame >= skip)){
         out.rows.push_back(t.rows[i]); // FIX <S><1>: Error escribiendo push_back
      }
   }
   return out;
}

} // namespace ml
/* === FIXES
;;  Tipo: Cant.
;;  *  N:    0     (no existe)
;;  *  E:    0     (errónea)
;;  *  S:    1     (sintaxis)
;;  *  F:    0     (falta algo)
;;
;; EXPLICACIONES ADICIONALES DE FIXES (si es necesario)
;;  *
*/