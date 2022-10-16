#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/naoFracionario.h"

//#include "./Headers/racional.h"
//#include "./Headers/complexoNaoFracionario.h"


SUBTIPO_C* criaNF(SUBTIPO_C n) {
  SUBTIPO_C* num = (SUBTIPO_C*) malloc(sizeof(SUBTIPO_C));
  *num = n;
  return num;
}

void destroiNF(SUBTIPO_C* n) {
  free(n);
}

void copiaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  *n1 = *n2;
}

int comparaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  if(*n1 == *n2)
    return 0;
  else if(*n1 < *n2)
    return -1;
  else
    return 1;
}

int verificaEquivalenciaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  if(comparaNF(n1, n2) == 0)
    return 1;
  else
    return 0;
}

int verificaNFZero(SUBTIPO_C* n) {
  if(*n == 0)
    return 1;
  else
    return 0;
}

SUBTIPO_C* somaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  SUBTIPO_C* n3 = criaNF(*n1 + *n2);
  return n3;
}

SUBTIPO_C* acumulaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  *n1 += *n2;
  return n1;
}

SUBTIPO_C* subtraiNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  SUBTIPO_C* n3 = criaNF(*n1 - *n2);
  return n3;
}

SUBTIPO_C* multiplicaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  SUBTIPO_C* n3 = criaNF(*n1 * *n2);
  return n3;
}

SUBTIPO_C* multiplicaEAcumulaNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  *n1 *= *n2;
  return n1;
}

SUBTIPO_C* divideNF(SUBTIPO_C* n1, SUBTIPO_C* n2) {
  SUBTIPO_C* n3 = criaNF(*n1 / *n2);
  return n3;
}

SUBTIPO_C* quadradoNF(SUBTIPO_C* n) {
  SUBTIPO_C* n3 = criaNF(*n * *n);
  return n3;
}

SUBTIPO_C* raizNF(SUBTIPO_C* n) {
  SUBTIPO_C* n3 = criaNF( sqrt(*n) );
  return n3;
}

void imprimeNF(SUBTIPO_C* n) {
  printf(FORMATO, *n);
}