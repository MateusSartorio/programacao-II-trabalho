#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#define SUBTIPO_C double
#define FORMATO "%lf"

SUBTIPO_C* criaNF(SUBTIPO_C num);
void destroiNF(SUBTIPO_C* num);
void copiaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
int comparaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
int verificaEquivalenciaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
int verificaNFZero(SUBTIPO_C* n);
SUBTIPO_C* somaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* acumulaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* subtraiNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* multiplicaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* multiplicaEAcumulaNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* divideNF(SUBTIPO_C* n1, SUBTIPO_C* n2);
SUBTIPO_C* quadradoNF(SUBTIPO_C* n);
SUBTIPO_C* raizNF(SUBTIPO_C* n);
void imprimeNF(SUBTIPO_C* n);