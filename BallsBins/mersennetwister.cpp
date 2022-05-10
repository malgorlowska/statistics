#include "mersennetwister.h"
#include <time.h>

//Implementacja generatora liczb pseudolosowych oparta na liczbach pierwszych Mersenne'a
//Kod źródłowy z https://eduinf.waw.pl/inf/alg/001_search/0022.php

mersenneTwister::mersenneTwister()
{
    initializationMT();
}

void mersenneTwister::initMT ( unsigned int x0 )
{
   long long x;

  MT [ 0 ] = x0;
  for( int i = 1; i < 623; i++ )
  {
    x = MT [ i-1 ];
    x = ( 23023 * x ) & 0xffffffffull;
    x = (     3 * x ) & 0xffffffffull;
    MT [ i ] = x;
  }
}

// Inicjuje MT wartoœciami losowymi
//---------------------------------
void mersenneTwister::initializationMT( )
{
  initMT ( ( unsigned int )time ( nullptr ) );
}

// Generator Mersenne Twister
//--------------------------
unsigned int mersenneTwister::MersenneTwister( )
{
  const unsigned int MA [ ] = {0, 0x9908b0df};
  long int y;
  int i1, i397;

  i1      = mti +   1; if(   i1 > 623 ) i1 = 0;
  i397    = mti + 397; if( i397 > 623 ) i397 -= 624;
  y       = ( MT [ mti ] & 0x80000000 ) | ( MT [ i1 ] & 0x7fffffff );
  MT [ mti ] = MT [ i397 ]  ^ ( y >> 1 ) ^ MA [ y & 1 ];
  y       = MT [ mti ];
  y       ^=  y >> 11;
  y       ^= ( y <<  7 ) & 0x9d2c5680;
  y       ^= ( y << 15 ) & 0xefc60000;
  y       ^=  y >> 18;
  mti     = i1;
  return y;
}
