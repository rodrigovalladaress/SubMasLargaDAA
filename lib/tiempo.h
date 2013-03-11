#ifndef TIEMPO_H_
#define TIEMPO_H_

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
/* http://totaki.com/poesiabinaria/2010/12/cronometrando-en-c/
 * 
 * Uso:
 * cronomin(1);
 * Operaciones
 * cronomin(0);
 * 
 * cronomin(0) devuelve el tiempo transcurrido
 * */

int cronosec(int startstop); //precisión de segundos
long long cronomilisec(int startstop); //precisión de milisegundos
long long cronomicrosec(int startstop); //precisión de microsegundos

#endif