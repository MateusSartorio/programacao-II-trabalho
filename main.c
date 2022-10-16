#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/naoFracionario.h"
#include "./Headers/racional.h"
#include "./Headers/complexoNaoFracionario.h"
#include "./Headers/complexoRacional.h"
#include "./Headers/vetoresReais.h"
#include "./Headers/vetoresComplexos.h"

#define PI acos(-1.0)
/* FALTA RESOLVER:
verificar soma e subtracao de racional
//atribuir novo valor à magnitude de um número complexo (módulo) mantendo seu ângulo
R_Complexo_pt atribuiMagnitude_Racional(R_Complexo_pt ptrComplexo_a,double magnitude);
//atribuir novo valor à fase de um número complexo (ângulo) mantendo o seu módulo 
R_Complexo_pt atribuiFase_Racional(R_Complexo_pt ptrComplexo_a, double fase);
*/

int main() {
  FILE* racional_escrita;
  racional_escrita = fopen("./Arquivos/racional_escrita.csv","w");
  if (racional_escrita == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }

  FILE* racional_leitura;
  racional_leitura = fopen("./Arquivos/racional_leitura.csv","r");
  if (racional_leitura == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }

  FILE* complexo_escrita;
  complexo_escrita = fopen("./Arquivos/complexo_escrita.csv","w");
  if (complexo_escrita == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }

  FILE* complexo_leitura;
  complexo_leitura = fopen("./Arquivos/complexo_leitura.csv","r");
  if (racional_leitura == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }

 
  D_Complexo_pt c1 = criaComplexoNF(1, 2);
  D_Complexo_pt c2 = criaComplexoNF(1, 3);
  D_Complexo_pt c3 = criaComplexoNF(-1, -20);
  D_Complexo_pt c4 = criaComplexoNF(1, 2);
  D_Complexo_pt c5 = criaComplexoNF(1, 3);
  D_Complexo_pt c6 = criaComplexoNF(1, 2);
  
  
  VetorComplexo_t* v1 = (VetorComplexo_t*) malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(v1);
  AtribuirElementoNaPosicaoI_esima_Complexo(v1, 0, c1);
  AtribuirElementoNaPosicaoI_esima_Complexo(v1, 1, c2);
  AtribuirElementoNaPosicaoI_esima_Complexo(v1, 2, c3);
  OrdenaVetor_Complexo(v1);
  ExibeVetor_Complexo(v1);

  VetorComplexo_t* v2 = (VetorComplexo_t*) malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(v2);
  AtribuirElementoNaPosicaoI_esima_Complexo(v2, 0, c4);
  AtribuirElementoNaPosicaoI_esima_Complexo(v2, 1, c5);
  AtribuirElementoNaPosicaoI_esima_Complexo(v2, 2, c6);
  OrdenaVetor_Complexo(v2);
  ExibeVetor_Complexo(v2);

  VetorComplexo_t* newV = intercalaVetoresOrdenados_Complexo(v1, v2);
  ExibeVetor_Complexo(newV);
























 /*
  TIPO_C_PT c = criaComplexoNF(0, 0);
  c = RetornaMedianaDosValores_Complexo(v);
  imprimeComplexoNF(c);
  */
//I_Complexo_pt i = malloc(sizeof(I_Complexo_pt));
  /*
  I_Complexo_pt i = malloc(sizeof(I_Complexo_t));
  i->imag = malloc(sizeof(long int));
  i->real = malloc(sizeof(long int));
  *i->real = 3;
  *i->imag = 4;
  
  D_Complexo_pt d = criaComplexoNF(1.4, 2.7);

  R_Complexo_pt r = CriaComplexo_Racional();
  r->real = criaRacional(0,0);
  r->imag = criaRacional(0,0);
  atribuiValorImaginario_Racional(r,5,6);
  atribuiValorReal_Racional(r,8,7);

  r = ConverteComplexoLongIntEmRacional(i);
  //printf("%ld + %ldi", *i->real, *i->imag);
  //imprimeComplexoNF(d);
  ExibirComplexo_racional(r);
  
//printf("cabo Fuodase\n");
  */








/*


D_Complexo_pt em R_Complexo_pt (também perigoso...)
R_Complexo_pt em D_Complexo_pt (também perigoso...)
R_Complexo_pt em I_Complexo_pt (também perigoso...conversões, overflow e
underflow)
I_Complexo_pt em R_Complexo_pt (não há tantos perigos...)
*/







/*
  TIPO1 c1 = 1;
  TIPO1 c2 = 2;
  TIPO1 c3 = 3;
  TIPO1 c4 = 1;
  TIPO1 c5 = 4;
  TIPO1 c6 = 1;

  VetorR_t* v = malloc(sizeof(VetorR_t));
  CriaVector(v);

  AtribuirElementoNaPosicaoI_esima(v, 0, &c1);
  AtribuirElementoNaPosicaoI_esima(v, 1, &c2);
  AtribuirElementoNaPosicaoI_esima(v, 2, &c3);
  AtribuirElementoNaPosicaoI_esima(v, 3, &c4);
  AtribuirElementoNaPosicaoI_esima(v, 4, &c5);
  AtribuirElementoNaPosicaoI_esima(v, 5, &c6);

  ExibiVector(v);

  VetorR_t* vAux = devolveVetorPosicoesElementosV(v, 1);
  ExibiVector(vAux);

  VetorR_t* v3 = intercalaVetoresOrdenados(v, vAux);

  ExibiVector(v3);
  */
  

  


  fclose(racional_escrita);
  fclose(racional_leitura);
  fclose(complexo_escrita);
  fclose(complexo_leitura);
  
  return 0;
}
