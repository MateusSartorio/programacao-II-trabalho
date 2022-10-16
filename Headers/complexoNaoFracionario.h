#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>

#define PI acos(-1.0)

#define TIPO_C D_Complexo_t
#define TIPO_C_PT D_Complexo_pt
#define SUBTIPO_C double
#define FORMATO "%lf"

typedef struct I_Complexo_st {
  long int* real;
  long int* imag;
} I_Complexo_t;

typedef struct I_Complexo_st* I_Complexo_pt;


typedef struct D_Complexo_st {
  double* real;
  double* imag;
} D_Complexo_t;

typedef struct D_Complexo_st* D_Complexo_pt;


TIPO_C_PT criaComplexoNF(SUBTIPO_C real, SUBTIPO_C imag);
void destroiComplexoNF(TIPO_C_PT c);
void imprimeComplexoNF(TIPO_C_PT c);
TIPO_C_PT atribuiComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT copiaECriaComplexoNF(TIPO_C_PT c);
int verificaSeModuloZeroNF(TIPO_C_PT c);
int verificaSeERealNF(TIPO_C_PT c);
int verificaSeEImaginarioNF(TIPO_C_PT c);
int comparaModuloNF(TIPO_C_PT c1, TIPO_C_PT c2);
double calculaAnguloNF(SUBTIPO_C x0, SUBTIPO_C y0);
int comparaAnguloNF(TIPO_C_PT c1, TIPO_C_PT c2);
SUBTIPO_C retornaParteRealNF(TIPO_C_PT c);
SUBTIPO_C retornaParteImaginariaNF(TIPO_C_PT c);
double retornaMagnitudeNF(TIPO_C_PT c);
double retornaFaseNF(TIPO_C_PT c);
TIPO_C_PT atribuiValorRealNF(TIPO_C_PT c, SUBTIPO_C valor);
TIPO_C_PT atribuiValorImaginarioNF(TIPO_C_PT c, SUBTIPO_C valor);
TIPO_C_PT atribuiMagnitudeNF(TIPO_C_PT c, SUBTIPO_C magnitude);
TIPO_C_PT atribuiFaseNF(TIPO_C_PT c, SUBTIPO_C fase);
TIPO_C_PT calculaECriaConjugadoNF(TIPO_C_PT c);
TIPO_C_PT somaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT subtraiComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT divideComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT multiplicaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT acumulaSomaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT acumulaMultiplicaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT operacaoComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2, char operacao[]);
void escreveComplexoNF(TIPO_C_PT c, FILE* complexo_escrita);
TIPO_C_PT leComplexoNF(TIPO_C_PT complexo, FILE* complexo_leitura);
TIPO_C_PT multiplicaComplexoPorEscalarNF(TIPO_C_PT c, SUBTIPO_C k);
TIPO_C_PT acumulaSubtracaoComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2);
TIPO_C_PT raizComplexoNF(TIPO_C_PT c);