#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>



#define PI acos(-1.0)

typedef struct R_Complexo_st
{
Racional_pt  real;
Racional_pt  imag;
} R_Complexo_t;
typedef struct R_Complexo_st * R_Complexo_pt;

//malloca complexo e retorna ponteiro para complexo mallocado
R_Complexo_pt CriaComplexo_Racional();
//da um free no complexo e retorna void
void DestroiComplexo_Racional(R_Complexo_pt ptrComplexo_a);
//atribui complexo b em a, copia b para a;
void AtribuiComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
//cria complexo, copia complexo_a no complexo criado e devolve o complexo_pt criado
R_Complexo_pt CopiaComplexoEmCriado_Racional(R_Complexo_pt ptrComplexo_a);

//D_Complexo_pt em I_Complexo_pt (perigos: arredonde para o mais próximo; cuidado com overflow e underflow)
I_Complexo_pt ConverteComplexoDoubleEmLongInt(D_Complexo_pt d);
//I_Complexo_pt em D_Complexo_pt (aqui o “perigo” é menor)
D_Complexo_pt ConverteComplexoLongIntEmDouble(I_Complexo_pt i);
// D_Complexo_pt em R_Complexo_pt (também perigoso...)
R_Complexo_pt ConverteComplexoDoubleEmRacional(D_Complexo_pt d);
// R_Complexo_pt em D_Complexo_pt (também perigoso...)
D_Complexo_pt ConverteComplexoRacionalEmDouble(R_Complexo_pt r);
// R_Complexo_pt em I_Complexo_pt (também perigoso...conversões, overflow e underflow)
I_Complexo_pt ConverteComplexoRacionalEmLongInt(R_Complexo_pt r);
//I_Complexo_pt em R_Complexo_pt (não há tantos perigos...)
R_Complexo_pt ConverteComplexoLongIntEmRacional(I_Complexo_pt i);
//verificca se modulo e igual a zero, se igual a zero retorno = 1
int VerificaSeModuloZero_Racional(R_Complexo_pt ptrComplexo_a);
//verificação se um número complexo é apenas real, se verdadeiro retorna 1
int VerificaSecomplexoEReal_Racional(R_Complexo_pt ptrComplexo_a);
//verificação se um número complexo é apenas imaginário,se verdadeiro retorna 1
int verificaSeEImaginario_Racional(R_Complexo_pt ptrComplexo_a);
//compara modulo do complexo;//modulo a>b return 1 /modulo a<b return -1/modulo a=b return 0
int comparaModulo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
//Calcula o angulo de um numero complexo e retorna um angulo
double CalculaAngulo_Racional(R_Complexo_pt ptrComplexo_a);
//comparar se um número complexo é igual, menor ou maior que outro (com relação ao seu ângulo),considerando uma tolerância eps = 0.0001
//angulo a=b return 0 /angulo b>a return -1/angulo a>b return 1
int comparaAngulo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
//retornar a parte real de um número complexo o retrono e um racional
Racional_pt RetornaParteReal_Racional(R_Complexo_pt ptrComplexo_a);
//retornar a parte imaginaria de um número complexo o retorno e um racional
Racional_pt retornaParteImaginaria_Racional(R_Complexo_pt ptrComplexo_a);
//retornar a magnitude de um número complexo (módulo), retorno (double) 
double retornaMagnitude_Racional(R_Complexo_pt ptrComplexo_a);
//retornar a fase de um número complexo (ângulo), retorno (double)
double retornaFase_Racional(R_Complexo_pt ptrComplexo_a);
//atribuir novo valor à parte real de um número complexo representado por suas coordenadas
void atribuiValorReal_Racional(R_Complexo_pt ptrComplexo_a,long int new_num,long int new_den);
//atribuir novo valor à parte imaginária de um número complexo representado por suas coordenadas
void atribuiValorImaginario_Racional(R_Complexo_pt ptrComplexo_a,long int new_num,long int new_den);
//atribuir novo valor à magnitude de um número complexo (módulo) mantendo seu ângulo
R_Complexo_pt atribuiMagnitude_Racional(R_Complexo_pt ptrComplexo_a,double magnitude);
//atribuir novo valor à fase de um número complexo (ângulo) mantendo o seu módulo 
R_Complexo_pt atribuiFase_Racional(R_Complexo_pt ptrComplexo_a, double fase);
//calcular o conjugado de um número complexo
R_Complexo_pt calculaECriaConjugadoNF_Racional(R_Complexo_pt ptrComplexo_a); 
//somardois números complexos gerando um terceiro número complexo 
R_Complexo_pt somaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
//subtrair dois números complexos gerando um terceiro número complexo 
R_Complexo_pt subtraiComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
// multiplicar dois números complexos gerando um terceiro número complexo
R_Complexo_pt multiplicaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);

// dividir dois números complexos gerando um terceiro número complexo
R_Complexo_pt divideComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);

//“acumular” somando (a += b) dois números complexos ( a e b são do mesmo “tipo” de número complexo)
R_Complexo_pt acumulaSomaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);
//“acumular” multiplicando (a *= b) dois números complexos ( a e b são do mesmo “tipo” de número complexo)
R_Complexo_pt acumulaMultiplicaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b);

//fazer um método que executa uma das seis operações acima, sempre considerando que a-b-c são números complexos do mesmo “tipo”, dependendo da string “operação” recebida como argumento. Operação pode ser “+”, “-”, “*”, “/”,”+=”, “*=”. Por exemplo:
R_Complexo_pt OperacaoComplexo (R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b,char *oper);
//da um printf de numero complexo
void ExibirComplexo_racional(R_Complexo_pt ptrComplexo_a);
