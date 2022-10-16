#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
/*
n = número atual de elementos;
• N = número máximo de elementos ;
• i = índice do elemento “atual”;
• elementos, propriamente ditos, acessíveis em sequência.
*/


/*
#define TIPO_C I_Complexo_t
#define TIPO_C_PT I_Complexo_pt
#define SUBTIPO_C long int
#define FORMATO "%ld"
*/

typedef struct CelulaComplexo_st {
  TIPO_C_PT* conteudo;
  struct CelulaComplexo_st* proximo;
  int indice;
} CelulaComplexo_t;

typedef struct VetorComplexo_st {
  int n;
  int N;
  CelulaComplexo_t* i;
  CelulaComplexo_t* primeiro;
  CelulaComplexo_t* ultimo;
} VetorComplexo_t;


void CriaVetor_Complexo(VetorComplexo_t* ptrVector);
void AddUltimaCelula_Complexo(VetorComplexo_t* ptrvector);
void DestruirVector_Complexo(VetorComplexo_t* ptrvector);
void DestruirVetor_Complexo(VetorComplexo_t* ptrvetor);
void DestroirUltimaCelula_Complexo(VetorComplexo_t* ptrvetor);
void AdicionaElementos_Complexo(VetorComplexo_t* ptrvetor, TIPO_C_PT data);
TIPO_C_PT RetornaValorElemento_Complexo(CelulaComplexo_t* celula1);
void CopiaVetor_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t ptrvetor2);
void ExibeVetor_Complexo(VetorComplexo_t* ptrvetor);
VetorComplexo_t* CopiaECriaVetor_Complexo(VetorComplexo_t* ptrvetor1);
int RetornaNumElementos_Complexo(VetorComplexo_t* ptrvector);
int RetornaNumMaxElementos_Complexo(VetorComplexo_t* ptrvector);
int RetornaNumIndice_Complexo(CelulaComplexo_t* celula1);
CelulaComplexo_t* RetornaPrimeiroElemento_Complexo(VetorComplexo_t* ptrvetor);
CelulaComplexo_t* RetornaProximoElemento_Complexo(CelulaComplexo_t* ptrcelula,VetorComplexo_t* ptrvetor);
CelulaComplexo_t* RetornaAntesessorElemento_Complexo(CelulaComplexo_t* ptrcelula,VetorComplexo_t* ptrvetor);
CelulaComplexo_t* RetornaUltimoElemento_Complexo(VetorComplexo_t* ptrvetor);
CelulaComplexo_t* RetornaElementoNaPosicaoI_esima_Complexo(VetorComplexo_t* ptrvetor,int i);
void AtribuirElementoNaPosicaoI_esima_Complexo(VetorComplexo_t* ptrvetor, int i, TIPO_C_PT data);
void AdicionarElementoDepoisDoUltimo_Complexo(VetorComplexo_t* ptrvetor,TIPO_C_PT data);
TIPO_C_PT EliminarCelulaNaPosicaoI_Complexo(VetorComplexo_t* ptrvetor, int i);
void EliminarTodosElementosDoVetor_Complexo(VetorComplexo_t* ptrvetor);
void EliminarTodosElementosDoVetor_Complexo(VetorComplexo_t* ptrvetor);
TIPO_C_PT RetornandoValorDoItemMaiorModulo_Complexo(VetorComplexo_t* ptrvetor);
TIPO_C_PT RetornandoValorDoItemMenorModulo_Complexo(VetorComplexo_t* ptrvetor);
int CriterioDeOrdenacao_Complexo(CelulaComplexo_t celula1,CelulaComplexo_t celula2);
void OrdenaVetor_Complexo(VetorComplexo_t* ptrvetor);
VetorComplexo_t* SomarVetorCriandoOutro_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2);
VetorComplexo_t* SubtrairVetorCriandoOutro_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2);
void MutiplicarVetorPorEscalar_Complexo(VetorComplexo_t* ptrvetor1,SUBTIPO_C k);
void SomarVetorAcumulando_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2);
TIPO_C_PT RetornarMediaAritimetica_Complexo(VetorComplexo_t* ptrvetor);
TIPO_C_PT MultiplicarVetorCriandoValor_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2);
TIPO_C_PT RetornaVariaciaDosValores_Complexo(VetorComplexo_t* ptrvetor);
TIPO_C_PT RetornaDesvioPadrao_Complexo(VetorComplexo_t* ptrvetor);
TIPO_C_PT RetornaMedianaDosValores_Complexo(VetorComplexo_t* ptrvetor);
VetorComplexo_t* devolveVetorPosicoesElementosV_Complexo(VetorComplexo_t* ptrvetor,TIPO_C_PT v);
VetorComplexo_t* intercalaVetoresOrdenados_Complexo(VetorComplexo_t* v1, VetorComplexo_t* v2);