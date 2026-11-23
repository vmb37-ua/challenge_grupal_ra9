// Exercise 12: weights for Pong
// The full statement is in the Challenge document.
#include "ml/ml.hpp"
#include <format>
#include <ostream>

namespace ml {

Vec to_raw_weights(Vec const& w, Standardizer const& s) {
   Vec raw(w.size());
   raw[0] = w[0]
   for (int i = 0; i < raw.size(); i+=1)
   {
      raw[i]=w[i]/sd[i];
      raw[0]-=w[i]*mean[i]/sd[i];
   }
   
   return raw;
}

void write_weights(std::ostream& out, std::string const& name, Vec const& up,
                   Vec const& down) {
   out << "#@name " << name << '\n';

   out << "# arriba\n";                             
   for (std::size_t i = 0; i < up.size(); i += 1)   
   {
      if (i > 0) { out << ' '; }                     
      out << std::format("{:.8g}", up[i]);           //FIX: S1 sintacis incorrecta format
   }                                                  //FIX: E1 mal puestio el out
   out << '\n';

   out << "# abajo\n";
   for (std::size_t i = 0; i < down.size(); i += 1)
   {
      if (i > 0) { out << ' '; }
      out << std::format("{:.8g}", down[i]); //FIX: S1 sintaxis incorrecta formato
   }                                         //FIX: E1 mal puesto el out
   out << '\n';
}
                                             //FIX: F1 falta el out n final
} // namespace ml