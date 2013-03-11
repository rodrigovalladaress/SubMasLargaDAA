#include "SubMasLarga.h"
SubMasLarga::SubMasLarga(const string& cadenaA, const string& cadenaB) {
  int m, n, i, j;
  setCadenas(cadenaA, cadenaB);
  inicializarMatrizC();
  m = getSizeCadenaA();
  n = getSizeCadenaB();
  string subMasLarga = "";
  cronomicrosec(1);
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++) {
      if(getCadenaACharAt(i) == getCadenaBCharAt(j))
        setMatrizC(i, j, getMatrizC(i - 1, j - 1) + 1);
      else if(getMatrizC(i - 1, j) >= getMatrizC(i, j - 1))
        setMatrizC(i, j, getMatrizC(i - 1, j));
      else
	setMatrizC(i, j, getMatrizC(i, j - 1));;
    }
  }
  setTiempoMicrosec(cronomicrosec(0));
}

string SubMasLarga::getSubMasLarga(bool mostrarTraza) {
  int i = getSizeCadenaA() - 1;
  int j = getSizeCadenaB() - 1;
  int valorAnterior = -2;
  int mayorValor;
  int iAdyacenteMayorValor;
  int jAdyacenteMayorValor;
  string subMasLarga = "";
  string stringRetorno;
  while((i >= -1) && (j >= -1)) {
    if(mostrarTraza)
      cout << "(" << j + 1 << ", " << i + 1 << ") = " << getMatrizC(i, j) << endl;
    if(valorAnterior == getMatrizC(i, j) + 1)
      subMasLarga += getCadenaACharAt(i + 1);
    mayorValor = getMatrizC(i - 1, j - 1);
    iAdyacenteMayorValor = i - 1;
    jAdyacenteMayorValor = j - 1;
    if(getMatrizC(i - 1, j) > mayorValor) {
      mayorValor = getMatrizC(i - 1, j);
      jAdyacenteMayorValor++;
    }
    if(getMatrizC(i, j - 1) > mayorValor) {
      iAdyacenteMayorValor++;
      jAdyacenteMayorValor--;
    }
    valorAnterior = getMatrizC(i, j);
    i = iAdyacenteMayorValor;
    j = jAdyacenteMayorValor;
  }
  if(mostrarTraza)
      cout << "(" << i + 1 << ", " << j + 1 << ") = " << getMatrizC(i, j) << endl;
  for(int i = subMasLarga.size() - 1; i >= 0; i--)
    stringRetorno.push_back(subMasLarga[i]);
  return stringRetorno;
}

int SubMasLarga::getSizeCadenaA(void) {
  return cadenaA.size();
}


int SubMasLarga::getSizeCadenaB(void) {
  return cadenaB.size();
}

char SubMasLarga::getCadenaACharAt(int i) {
  return cadenaA[i];
}

char SubMasLarga::getCadenaBCharAt(int i) {
  return cadenaB[i];
}

int SubMasLarga::getMatrizC(int i, int j) {
  if((i >= 0) && (j >= 0) && (i < getSizeCadenaA() + 1) && (j < getSizeCadenaB() + 1))
    return matrizC[i][j];
  else
    return 0;
}

void SubMasLarga::setMatrizC(int i, int j, int v) {
  if((i >= 0)&&(j >= 0))
    matrizC[i][j] = v;
}

void SubMasLarga::inicializarMatrizC(void) {
  int m = getSizeCadenaA() + 1;
  int n = getSizeCadenaB() + 1;
  int i, j;
  matrizC = new int*[m];
  for(i = 0; i < m; i++)
    matrizC[i] = new int[n];
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++)
      matrizC[i][j] = 0;
  }
}

void SubMasLarga::setCadenas(const string& cadenaA_, const string& cadenaB_) {
  cadenaA = cadenaA_;
  cadenaB = cadenaB_;
}

void SubMasLarga::setTiempoMicrosec(const long long& tiempo) {
  tiempoMicrosec = tiempo;
}
  
const long long& SubMasLarga::getTiempoMicrosec(void) {
  return tiempoMicrosec;
}

void SubMasLarga::imprimirMatriz(void) {
  int m = getSizeCadenaA();
  int n = getSizeCadenaB();
  cout << "\t";
  for(int i = 0; i < n; i++)
    cout << cadenaB[i] << "\t";
  cout << endl << endl;
  for(int i = 0; i < m; i++) {
      cout << cadenaA[i] << "\t";
    for(int j = 0; j < n; j++)
      cout << matrizC[i][j] << "\t";
    cout << endl;
  }
} 