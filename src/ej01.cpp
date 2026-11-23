// Exercise 1: read the Pong CSV
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <istream>

namespace ml {

Table read_csv(std::istream& in) {
   Table t;
   // ◉◉YOUR CODE◉◉
   int c = 0;
   std::string line = "";
   while(std::getline(in,line)){
      if(!line.empty() && line.back() == '\r'){ // //FIX <F><1>: Faltaba comprobar antes si no esta vacio la line, ya que si no con back revienta  (N, E, S, F)
         line.pop_back();
      }
      if(!line.empty() && line[0] != '#'){
         if(c == 0){
            t.columns = split(line,';'); // 
         }
         else{
            t.rows.push_back(split(line,';')); // 
         }
         c++;
      }
   }
   return t;
}

int column_index(Table const& t, std::string const& name) {
   // ◉◉YOUR CODE◉◉
   for(int i = 0; i < t.columns.size();i++){
      if(t.columns[i] == name) return i;
   }
   return -1;
}

} // namespace ml
/* === FIXES
;;  Tipo: Cant.
;;  *  N:    0     (no existe)
;;  *  E:    0     (errónea)
;;  *  S:    0     (sintaxis)
;;  *  F:    1     (falta algo)
;;
;; EXPLICACIONES ADICIONALES DE FIXES (si es necesario)
;;  *
*/