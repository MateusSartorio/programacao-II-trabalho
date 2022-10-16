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

#define TIPO1 double
#define FORMATO1 "%lf"

typedef struct Celula_st {
  TIPO1* conteudo;
  struct Celula_st* proximo;
  int indice;
} Celula_t;

typedef struct VetorR_st {
  int n;
  int N;
  Celula_t* i;
  Celula_t* primeiro;
  Celula_t* ultimo;
  } VetorR_t;

//typedef void(*ADDPRIMEIRO)(VetorR_t*,TIPO);

//cria vetor
void CriaVector(VetorR_t* ptrVector);
//Destroi vetor
void DestruirVector(VetorR_t* ptrvector);
//adciona Celula na primeira posicao
//void AddPrimeiraCelula(VetorR_t* ptrvector,TIPO1 data,int indicador); 
void DestroirUltimaCelula(VetorR_t* ptrvector);
//adciona Celula na ultima posicao
void AddUltimaCelula(VetorR_t* ptrvector);
//adciona elemento
void AdicionaElementos(VetorR_t* ptrvector, TIPO1* data);
TIPO1 RetornaValorElemento(Celula_t* celula1);
//atribuir uma cópia do vetor a outro vetor já existente/coipiar 2 no 1
void CopiaVetor(VetorR_t* ptrvector1,VetorR_t ptrvector2);
//criar uma cópia do vetor, criando um novo vetor
VetorR_t* CopiaECriaVetor(VetorR_t* ptrvector1);
//devolver o número atual de elementos;
int RetornaNumElementos(VetorR_t* ptrvector);
//devolver o número máximo de elementos;
int RetornaNumMaxElementos(VetorR_t* ptrvector);
//devolver o índice do elemento atual;
int RetornaNumIndice(Celula_t* celula1);
//devolver o primeiro elemento e posicionar “i” na primeira posição);
Celula_t* RetornaPrimeiroElemento(VetorR_t* ptrvetor);
//devolver o próximo elemento (posicionando “i” nesta posição);
Celula_t* RetornaProximoElemento(Celula_t* ptrcelula,VetorR_t* ptrvetor);
//devolver o elemento anterior (posicionando “i” nesta posição);
Celula_t* RetornaAntesessorElemento(Celula_t* ptrcelula,VetorR_t* ptrvetor);
//devolver o último elemento e posicionar “i” na última posição;
Celula_t* RetornaUltimoElemento(VetorR_t* ptrvetor);
//devolver o elemento da i-ésima posição (lá posicionando o índice “i”);
Celula_t* RetornaElementoNaPosicaoI_esima(VetorR_t* ptrvetor,int i);
//atribuir o valor “v” na i-ésima posição do vetor, posicionando ali o índice “i”;
void AtribuirElementoNaPosicaoI_esima(VetorR_t* ptrvetor,int i, TIPO1* data);
//atribuir o valor “v” depois da última posição do vetor, incrementando o “número atual de elementos”;
void AdicionarElementoDepoisDoUltimo(VetorR_t* ptrvetor, TIPO1* data);
//eliminar a i-ésima posição do vetor, devolvendo o seu valor atual e decrementando o “número atual de elementos”
TIPO1 EliminarCelulaNaPosicaoI(VetorR_t* ptrvetor,int i);
//eliminar todos os elementos do vetor
void EliminarTodosElementosDoVetor(VetorR_t* ptrvetor);
//exibir elemento
void ExibirTipoElemento(Celula_t celula1);
//exibir vetor
void ExibiVector(VetorR_t* ptrvector);
TIPO1 RetornaModulo(TIPO1 valor);
TIPO1 RetornandoValorDoItemMaiorModulo(VetorR_t* ptrvetor);
TIPO1 RetornandoValorDoItemMenorModulo(VetorR_t* ptrvetor);
int RetornandoQtdElementosTemValorV(VetorR_t* ptrvetor,TIPO1* v);
int RetornaMenorItem(VetorR_t* ptrvetor, TIPO1 menor);
void OrdenaVetor(VetorR_t* ptrvetor);
int CriterioDeOrdenacao(Celula_t* celula1,Celula_t* celula2);
VetorR_t* SomarVetorCriandoOutro(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2);
TIPO1 MultiplicarVetorCriandoValor(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2);
VetorR_t* SubtrairVetorCriandoOutro(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2);
void MutiplicarVetorPorEscalar(VetorR_t* ptrvetor1,TIPO1 k);
void SomarVetorAcumulando(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2);
double RetornarMediaAritimetica(VetorR_t* ptrvetor);
long double RetornaVariaciaDosValores(VetorR_t* ptrvetor);
double RetornaDesvioPadrao(VetorR_t* ptrvetor);
double RetornaMedianaDosValores(VetorR_t* ptrvetor);
VetorR_t* devolveVetorPosicoesElementosV(VetorR_t* ptrVetor, TIPO1 v);
VetorR_t* intercalaVetoresOrdenados(VetorR_t* v1, VetorR_t* v2);