#include "SubMasLarga.h"
string subMasLarga(const string& cadenaA_, const string& cadenaB_) {
  string cadenaA = cadenaA_;
  string cadenaB = cadenaB_;
  int m = cadenaA.size();
  int n = cadenaB.size();
  int i, j;
  int valorAnterior = -2;
  int mayorValor;
  int iAdyacenteMayorValor;
  int jAdyacenteMayorValor;
  //vector< vector <int> > matrizC(m, vector<int>(m));
  int** matrizC = new int*[m + 1];
  for(i = 0; i < m + 1; i++)
    matrizC[i] = new int[n + 1];
  string subMasLarga = "";
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++)
      matrizC[i][j] = 0;
  }
  for(i = 0; i < m; i++) {
    for(j = 0; j < n; j++) {
      if((cadenaA[i] == cadenaB[j])) {
	if((i - 1 > 0)&&(j - 1 > 0))
          matrizC[i][j] = matrizC[i - 1][j - 1] + 1;
	else
	  matrizC[i][j] = 1;
      }
      else if((i - 1 >= 0 )&&(j - 1 >= 0)) {
	if(matrizC[i - 1][j] >= matrizC[i][j - 1])
          matrizC[i][j] = matrizC[i - 1][j];
	else
          matrizC[i][j] = matrizC[i][j - 1];
      }
      else
	matrizC[i][j] = 0;
      
    }
  }
  
  cout << "    ";
  for(int i = 0; i < n; i++)
    cout << cadenaB[i] << "\t";
  cout << endl << endl;
  for(int i = 0; i < m; i++) {
    cout << cadenaA[i] << "   ";
    for(int j = 0; j < n; j++)
      cout << matrizC[i][j] << "\t";
    cout << endl;
  }
  
  
  i = m - 1;
  j = n - 1;
  while((i >= 0) && (j >= 0)) {
    if(valorAnterior == matrizC[i][j] + 1)
        cout << cadenaB[j + 1];
    if((i != 0)&&(j != 0)) {
      mayorValor = matrizC[i - 1][j - 1];
      iAdyacenteMayorValor = i - 1;
      jAdyacenteMayorValor = j - 1;
      if(matrizC[i - 1][j] > mayorValor) {
        mayorValor = matrizC[i - 1][j];
        jAdyacenteMayorValor = j;
      }
      if(matrizC[i][j - 1] > mayorValor) {
        iAdyacenteMayorValor = i;
        jAdyacenteMayorValor = j - 1;
      }
      valorAnterior = matrizC[i][j];
      i = iAdyacenteMayorValor;
      j = jAdyacenteMayorValor;
    }
    else {
      i--;
      j--;
    }
  }
  
  return "";
}