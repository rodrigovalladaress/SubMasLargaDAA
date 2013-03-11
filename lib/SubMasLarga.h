#ifndef SUBSMASLARGA_H_
#define SUBSMASLARGA_H_

/*
 * Calcula la subsecuencia más larga entre dos cadenas dadas
 */

#include <string>
#include <vector>
#include <iostream>
#include "tiempo.cc"

using std::string;
using std::vector;
using std::cout;
using std::endl;

class SubMasLarga {
private:
  string cadenaA;
  string cadenaB;
  int** matrizC;
  long long tiempoMicrosec;
  
public:
  SubMasLarga(const string&, const string&);
  
public:
  string getSubMasLarga(bool mostrarTraza = false);
  
private:
  inline int getSizeCadenaA(void);
  inline int getSizeCadenaB(void);
  inline char getCadenaACharAt(int);
  inline char getCadenaBCharAt(int);
  inline int getMatrizC(int, int);
  
public:
  inline const long long& getTiempoMicrosec(void);
  
private:
  inline void setMatrizC(int, int, int);
  void inicializarMatrizC(void);
  inline void setCadenas(const string&, const string&);
  inline void setTiempoMicrosec(const long long&);
  
public:
  void imprimirMatriz(void);
  
};

//string cadena1;
//string cadena2;
  
/*void setCadenas(string, string);
string getCadena1(void);
string getCadena2(void);
int getSizeCadena1(void);
int getSizeCadena2(void);*/
  


//vector < vector <int> > matriz;

#endif 