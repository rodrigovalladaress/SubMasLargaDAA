#include "tiempo.h"
int cronosec(int startstop) //precisión de segundos
{
  static int pre_time;

  if (startstop)
    pre_time=time(NULL);
  else
    return time(NULL)-pre_time;

  return 0;
}

long long cronomilisec(int startstop) //precisión de milisegundos
{
  static long long pre_time;
  struct timeval tv;

  if (startstop)
    {
      gettimeofday(&tv, NULL);      
      pre_time=tv.tv_sec*1000+tv.tv_usec/1000;
    }
  else
    {      
      gettimeofday(&tv, NULL);      
      return tv.tv_sec*1000+tv.tv_usec/1000 - pre_time;
    }
    return 0;
}

long long cronomicrosec(int startstop) //precisión de microsegundos
{
  static long long pre_time;
  struct timeval tv;

  if (startstop)
    {
      gettimeofday(&tv, NULL);      
      pre_time=tv.tv_sec*1000000+tv.tv_usec;
    }
  else
    {      
      gettimeofday(&tv, NULL);      
      return tv.tv_sec*1000000+tv.tv_usec - pre_time;
    }
    return 0;
}