#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#define eps 0.00001


typedef struct Racional_st {
  long int num;
  long int den;
} Racional_t;

typedef struct Racional_st* Racional_pt;


void recursao(Racional_pt r);
Racional_pt simplificaRacional(Racional_pt r);
Racional_pt criaRacional(long int num, long int den);
void destroiRacional(Racional_pt racional);
Racional_pt copiaRacional(Racional_pt r1, Racional_pt r2);
int comparaRacionais(Racional_pt r1, Racional_pt r2);
int verificaEquivalencia(Racional_pt r1, Racional_pt r2);
int VerificarDenominadorZero(Racional_pt r1);
int VerificarNumeradorZero(Racional_pt r1);
int VerificarRacionalZero(Racional_pt r1);
Racional_pt somaRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt acumulaRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt subtraiRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt multiplicaRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt multiplicaEAcumulaRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt divideRacionais(Racional_pt r1, Racional_pt r2);
Racional_pt quadradoRacional(Racional_pt r1);
Racional_pt raizQuadrada(Racional_pt r, long int denMax);
double racionalParaDouble(Racional_pt r);

Racional_pt DoubleParaRacional(double f, long int denMax, Racional_pt r);

int verificaConversao(Racional_pt r);
void escreverRacionalArquivo(Racional_pt r1, FILE* escrita_pt);
Racional_pt leRacionalArquivo(Racional_pt r, FILE* leitura_pt);
void imprimeRacional(Racional_pt r);
void rat_approx(double f, int64_t md, int64_t *num, int64_t *denom);