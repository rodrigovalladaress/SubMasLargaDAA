#include "lib/SubMasLarga.cc"
int main(int argc, const char* argv[]) {
  string cadena1;
  string cadena2;
  if(argc == 3) {
    cadena1 = argv[1];
    cadena2 = argv[2];
  }
  else {
    cadena1 = "coche";
    cadena2 = "toque";
  }
  SubMasLarga objeto(cadena1, cadena2);
  
  objeto.imprimirMatriz();
  cout << endl;
  cout << "Subsecuencia más larga = " << endl;
  cout << objeto.getSubMasLarga(true) << endl;
  cout << endl;
  cout << "Tiempo = " << objeto.getTiempoMicrosec() << endl;
  
}