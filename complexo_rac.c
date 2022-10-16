#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/racional.h"
#include "./Headers/complexoNaoFracionario.h"
#include "./Headers/complexoRacional.h"

//malloca complexo
R_Complexo_pt CriaComplexo_Racional(){
  R_Complexo_pt ptrcomplexo_a = (R_Complexo_pt)malloc(sizeof(R_Complexo_t));
  ptrcomplexo_a->real = (Racional_pt)malloc(sizeof(Racional_t));
  ptrcomplexo_a->imag = (Racional_pt)malloc(sizeof(Racional_t));

//(*ptrcomplexo->real).den = 2;
//printf("ptrcomplexo1->:%d \n",(&(*ptrcomplexo->real).den));
  return ptrcomplexo_a;
}

//da um free em complexo
void DestroiComplexo_Racional(R_Complexo_pt ptrComplexo_a){
  free(ptrComplexo_a->real);
  free(ptrComplexo_a->imag);
  free(ptrComplexo_a);
    return ;
}

//atribui complexo b em a;
void AtribuiComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b){
  int long aux;
  aux = (*ptrComplexo_b->real).den;
  (*ptrComplexo_a->real).den = aux;
  aux = (*ptrComplexo_b->real).num;
  (*ptrComplexo_a->real).num = aux;
  aux = (*ptrComplexo_b->imag).den;
  (*ptrComplexo_a->imag).den = aux;
  aux = (*ptrComplexo_b->imag).num;
  (*ptrComplexo_a->imag).num = aux;
return ;
}

//cria complexo copia complexo no criado e devolve o criado
R_Complexo_pt CopiaComplexoEmCriado_Racional(R_Complexo_pt ptrComplexo_a){
R_Complexo_pt ptrComplexo_b = CriaComplexo_Racional();
AtribuiComplexo_Racional(ptrComplexo_b,ptrComplexo_a);
  return ptrComplexo_b;
}

//D_Complexo_pt em I_Complexo_pt (perigos: arredonde para o mais próximo; cuidado com overflow e underflow)
I_Complexo_pt ConverteComplexoDoubleEmLongInt(D_Complexo_pt d){
  
  I_Complexo_pt i = malloc(sizeof(I_Complexo_t));
  i->real = malloc(sizeof(long int));
  i->imag = malloc(sizeof(long int));

  *i->real = round(*d->real);
  *i->imag = round(*d->imag);
  return i;
}

//I_Complexo_pt em D_Complexo_pt (aqui o “perigo” é menor)
D_Complexo_pt ConverteComplexoLongIntEmDouble(I_Complexo_pt i){
  D_Complexo_pt d = malloc(sizeof(D_Complexo_t));
  d->real = malloc(sizeof(double));
  d->imag = malloc(sizeof(double));
  
  *d->real = *i->real;
  *d->imag = *i->imag;
  return d;
}

// D_Complexo_pt em R_Complexo_pt (também perigoso...)
R_Complexo_pt ConverteComplexoDoubleEmRacional(D_Complexo_pt d){
  R_Complexo_pt r = malloc(sizeof(R_Complexo_t));
  r->imag = malloc(sizeof(double));
  r->real = malloc(sizeof(double));

  r->imag = DoubleParaRacional(*d->imag, 4096, r->imag);
  r->real = DoubleParaRacional(*d->real, 4096, r->real);   
  return r;
}

// R_Complexo_pt em D_Complexo_pt (também perigoso...)
D_Complexo_pt ConverteComplexoRacionalEmDouble(R_Complexo_pt r){
  D_Complexo_pt d = malloc(sizeof(D_Complexo_t));
  d->real = malloc(sizeof(double));
  d->imag = malloc(sizeof(double));

  *d->imag = racionalParaDouble(r->imag);
  *d->real = racionalParaDouble(r->real);
  
  return d;
}

// R_Complexo_pt em I_Complexo_pt (também perigoso...conversões, overflow e underflow)
I_Complexo_pt ConverteComplexoRacionalEmLongInt(R_Complexo_pt r){
  I_Complexo_pt i = malloc(sizeof(I_Complexo_t));
  i->real = malloc(sizeof(long int));
  i->imag = malloc(sizeof(long int));

  double imag,real;
  
  imag = racionalParaDouble(r->imag);
  real = racionalParaDouble(r->real);
  
  *i->imag = round(imag);
  *i->real = round(real);
  
  return i;
}

//I_Complexo_pt em R_Complexo_pt (não há tantos perigos...)
R_Complexo_pt ConverteComplexoLongIntEmRacional(I_Complexo_pt i){
  
  R_Complexo_pt r = malloc(sizeof(R_Complexo_t));
    r->imag = malloc(sizeof(double));
    r->real = malloc(sizeof(double));

  atribuiValorImaginario_Racional(r,*i->imag,1);
  atribuiValorReal_Racional(r,*i->real,1);

  return r;
}

//verificca se modulo e igual a zero, se igual a zero retorno = 1
int VerificaSeModuloZero_Racional(R_Complexo_pt ptrComplexo_a){
  //criando double e covertendo racional para double
  double real=0,imaginario=0;
    real = racionalParaDouble(ptrComplexo_a->real);
    imaginario = racionalParaDouble(ptrComplexo_a->imag);
    //printf("\n%lf\n",real);
  //calculando valor do modulo e conparando
  double modulo = sqrt( pow(real , 2) + pow(imaginario, 2) );
      if(modulo <= eps && modulo >= -eps)return 1;
  return 0;
}

//verificação se um número complexo é apenas real, se verdadeiro retorna 1
int VerificaSecomplexoEReal_Racional(R_Complexo_pt ptrComplexo_a) {
  if(((*ptrComplexo_a->imag).num <= eps) && ((*ptrComplexo_a->imag).num >= -eps))
    return 1;

  return 0;
}

//verificação se um número complexo é apenas imaginário,se verdadeiro retorna 1
int verificaSeEImaginario_Racional(R_Complexo_pt ptrComplexo_a) {
  if(((*ptrComplexo_a->real).num <= eps) && ((*ptrComplexo_a->real).num >= -eps))
    return 1;
  return 0;
}

//compara modulo do complexo;//modulo a>b return 1 /modulo a<b return -1/modulo a=b return 0
int comparaModulo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b) {
  //convertendo racional para double.
  double real_a=0,real_b=0,imaginario_a=0,imaginario_b=0;
  real_a = racionalParaDouble(ptrComplexo_a->real);
  imaginario_a = racionalParaDouble(ptrComplexo_a->imag);
  real_b = racionalParaDouble(ptrComplexo_b->real);
  imaginario_b = racionalParaDouble(ptrComplexo_b->imag);
  //calculando modulo
  double modulo1 = sqrt( pow(real_a , 2) + pow(imaginario_a, 2) );
  double modulo2 = sqrt( pow(real_b , 2) + pow(imaginario_b, 2) );
  //calculando diferenca dos modulos
  double diferenca = modulo1 - modulo2;
  //modulo a>b return 1 /modulo a<b return -1/modulo a=b return 0
  if(diferenca <= eps && diferenca >= -eps)
      return 0;
  else if(diferenca < 0)
      return -1;
  else
      return 1;
}

//Calcula o angulo de um numero complexo e retorna um angulo
double CalculaAngulo_Racional(R_Complexo_pt ptrComplexo_a) {
  double real_num = (double) ((*ptrComplexo_a->real).num);
  double real_den = (double) ((*ptrComplexo_a->real).den);
  double imag_num = (double) ((*ptrComplexo_a->imag).num);
  double imag_den = (double) ((*ptrComplexo_a->imag).den);
  double angulo_R = 0;
//para o primeiro quadrante(0,pi/2)
if(real_num > 0 && imag_num >= 0){
  angulo_R = atan((imag_num*real_den)/(imag_den*real_num));
  return angulo_R;
}

//para o segundo quadrante(pi/2,pi)
if(real_num < 0 && imag_num >= 0){
  angulo_R = atan((imag_num*real_den)/(imag_den*real_num));
  angulo_R = angulo_R + PI;
  return angulo_R;
}

//para o terceiro quadrante(pi/2,3pi/2)
if(real_num < 0 && imag_num <= 0){
  angulo_R = atan((imag_num*real_den)/(imag_den*real_num));
  angulo_R = angulo_R + PI;
  return angulo_R;
}

//para o quarto quadrante(3pi/2,2pi)
if(real_num > 0 && imag_num <= 0){
  angulo_R = atan((imag_num*real_den)/(imag_den*real_num));
  angulo_R = angulo_R + 2*PI;
  return angulo_R;
}

//para quando a tg não ta definida em pi/2
if(real_num == 0 && imag_num > 0){
  angulo_R = PI/2;
  return angulo_R;
}

//para quando a tg não ta definida em pi/2
if(real_num == 0 && imag_num < 0){
  angulo_R = (3*PI)/2.0;
  return angulo_R;
}

//complexo igual a zero 0/0+0/0i
if(real_num == 0 && imag_num == 0){
  return 0;
}
    printf("Parece que deu alguma merda no calculo do angulo.");
  return angulo_R;
}

//comparar se um número complexo é igual, menor ou maior que outro (com relação ao seu ângulo),considerando uma tolerância eps = 0.0001
//angulo a=b return 0 /angulo b>a return -1/angulo a>b return 1
int comparaAngulo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b){
  double angulo1 = CalculaAngulo_Racional(ptrComplexo_a);
  double angulo2 = CalculaAngulo_Racional(ptrComplexo_b);
  double diferenca = angulo1 - angulo2;
  if(diferenca <= eps && diferenca >= -eps)
    return 0;
  else if(diferenca < 0)
    return -1;
  else
    return 1;
}

//retornar a parte real de um número complexo o retorno e um racional
Racional_pt RetornaParteReal_Racional(R_Complexo_pt ptrComplexo_a) {
Racional_pt ptrRacional_a = criaRacional(((*ptrComplexo_a->real).num),((*ptrComplexo_a->real).den));
  return ptrRacional_a;
}

//retornar a parte imaginaria de um número complexo o retorno e um racional
Racional_pt retornaParteImaginaria_Racional(R_Complexo_pt ptrComplexo_a) {
Racional_pt ptrRacional_a = criaRacional(((*ptrComplexo_a->imag).num),((*ptrComplexo_a->imag).den));
  return ptrRacional_a;
}

//retornar a magnitude de um número complexo (módulo), retorno (double) 
double retornaMagnitude_Racional(R_Complexo_pt ptrComplexo_a) {
  double real=0,imaginario=0;
    real = racionalParaDouble(ptrComplexo_a->real);
    imaginario = racionalParaDouble(ptrComplexo_a->imag);
  double modulo = sqrt( pow(real , 2) + pow(imaginario, 2) );
return modulo;
}

//retornar a fase de um número complexo (ângulo), retorno (double)
double retornaFase_Racional(R_Complexo_pt ptrComplexo_a){
  return CalculaAngulo_Racional(ptrComplexo_a);
}
//atribuir novo valor à parte real de um número complexo representado por suas coordenadas
void atribuiValorReal_Racional(R_Complexo_pt ptrComplexo_a,long int new_num,long int new_den){
  if(new_den == 0){
    printf("erro: denominador igual a zero");
    return ;
  } 
  (*ptrComplexo_a->real).num = new_num;
  (*ptrComplexo_a->real).den = new_den;
  return ;
}

//atribuir novo valor à parte imaginária de um número complexo representado por suas coordenadas
void atribuiValorImaginario_Racional(R_Complexo_pt ptrComplexo_a,long int new_num,long int new_den){
  if(new_den == 0){
    printf("erro: denominador igual a zero");
    return ;
  }
  (*ptrComplexo_a->imag).num = new_num;
  (*ptrComplexo_a->imag).den = new_den;
  return ;
}
//atribuir novo valor à magnitude de um número complexo (módulo) mantendo seu ângulo

R_Complexo_pt atribuiMagnitude_Racional(R_Complexo_pt ptrComplexo_a,double magnitude){
  //convertendo racional para double
  double real=0,imaginario=0;
  real = racionalParaDouble(ptrComplexo_a->real);
  imaginario = racionalParaDouble(ptrComplexo_a->imag);
  //modificando a magnitude
  double fatorMultiplicativo = (double) magnitude / (double)retornaMagnitude_Racional(ptrComplexo_a);
  real *= fatorMultiplicativo;
  imaginario *= fatorMultiplicativo;
  //converter double para racional 
  DoubleParaRacional(real,4096,ptrComplexo_a->real);
  DoubleParaRacional(imaginario,4096,ptrComplexo_a->imag);
   return ptrComplexo_a;
}

//atribuir novo valor à fase de um número complexo (ângulo) mantendo o seu módulo 
R_Complexo_pt atribuiFase_Racional(R_Complexo_pt ptrComplexo_a, double fase){
  //convertendo racional para double
  double real=0,imaginario=0;
  real = racionalParaDouble(ptrComplexo_a->real);
  imaginario = racionalParaDouble(ptrComplexo_a->imag);
  //modificando a fase(angulo)
  double modulo = (double) retornaMagnitude_Racional(ptrComplexo_a);
  real = modulo * cos(fase);
  imaginario = modulo * sin(fase);
  //convertendo double para racional
  DoubleParaRacional(real,4096, ptrComplexo_a->real);
  DoubleParaRacional(imaginario,4096, ptrComplexo_a->imag);

  return ptrComplexo_a;
}


//calcular o conjugado de um número complexo
R_Complexo_pt calculaECriaConjugadoNF_Racional(R_Complexo_pt ptrComplexo_a) {
  R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();

  atribuiValorImaginario_Racional(ptrComplexo_new,(-(*ptrComplexo_a->imag).num),((*ptrComplexo_a->imag).den));
  atribuiValorReal_Racional(ptrComplexo_new,((*ptrComplexo_a->real).num),((*ptrComplexo_a->real).den));
  return ptrComplexo_new;
}

//somardois números complexos gerando um terceiro número complexo 
R_Complexo_pt somaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b) {
  //r1->num * r2->den + r2->num * r1->den, r1->den * r2->den

  R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
  ptrComplexo_new->real = somaRacionais(ptrComplexo_a->real,ptrComplexo_b->real);
  ptrComplexo_new->imag = somaRacionais(ptrComplexo_a->imag,ptrComplexo_b->imag);
  //simplificando os resultados 
  ptrComplexo_new->imag = simplificaRacional(ptrComplexo_new->imag);
  ptrComplexo_new->real = simplificaRacional(ptrComplexo_new->real);
 
  return ptrComplexo_new;
}

//subtrair dois números complexos gerando um terceiro número complexo 
R_Complexo_pt subtraiComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b){

  R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
  ptrComplexo_new->real = subtraiRacionais(ptrComplexo_a->real,ptrComplexo_b->real);
  ptrComplexo_new->imag = subtraiRacionais(ptrComplexo_a->imag,ptrComplexo_b->imag);
  //simplificando os resultados 
  ptrComplexo_new->imag = simplificaRacional(ptrComplexo_new->imag);
  ptrComplexo_new->real = simplificaRacional(ptrComplexo_new->real);

  return ptrComplexo_new;
}

// multiplicar dois números complexos gerando um terceiro número complexo
R_Complexo_pt multiplicaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b){
  //(real_a,imag_a).(real_b,imag_b)= (real_a*real_b - imag_a*imag_b , real_a*imag_b + real_b*imag_a)
  //  (a + bi) . (c + di) = (ac – bd) + i (ad + bc)
  R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
  Racional_pt ptrRacional_a = criaRacional(0,1);
  Racional_pt ptrRacional_b = criaRacional(0,1);
  //calculando a parte real
  ptrRacional_a = multiplicaRacionais(ptrComplexo_a->real,ptrComplexo_b->real);
  ptrRacional_b = multiplicaRacionais(ptrComplexo_a->imag,ptrComplexo_b->imag);
  ptrComplexo_new->real = subtraiRacionais(ptrRacional_a,ptrRacional_b);
  //calculando a parte imaginaria 
  ptrRacional_a = multiplicaRacionais(ptrComplexo_a->real,ptrComplexo_b->imag);
  ptrRacional_b = multiplicaRacionais(ptrComplexo_a->imag,ptrComplexo_b->real);
  ptrComplexo_new->imag = somaRacionais(ptrRacional_a,ptrRacional_a);
  //simplificando os resultados
  ptrComplexo_new->real = simplificaRacional(ptrComplexo_new->real);
  ptrComplexo_new->imag = simplificaRacional(ptrComplexo_new->imag);
  //dando free nos racionais
  destroiRacional(ptrRacional_a);
  destroiRacional(ptrRacional_b);
  return ptrComplexo_new;
}

// dividir dois números complexos gerando um terceiro número complexo
R_Complexo_pt divideComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b) {
//  z1=a+bi e z2=c+di
//  ac−bd/c2+d2   ,  ad+bc/c2+d2 i
//real = real_a*real_b-imag_a*imag_b / real_b*real_b+imag_b*imag_b
//imag = real_a*imag_b+imag_a*real_b / real_b*real_b+imag_b*imag_b

//calculando a parte real
R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
Racional_pt ptrRacional_a = criaRacional(0,0);
Racional_pt ptrRacional_b = criaRacional(0,0);
Racional_pt ptrRacional_num = criaRacional(0,0);
Racional_pt ptrRacional_div = criaRacional(0,0);
//calculando a parte real
ptrRacional_a = multiplicaRacionais(ptrComplexo_a->real,ptrComplexo_b->real);
ptrRacional_b = multiplicaRacionais(ptrComplexo_a->imag,ptrComplexo_b->imag);
ptrRacional_num = subtraiRacionais(ptrRacional_a,ptrRacional_b);

ptrRacional_a = multiplicaRacionais(ptrComplexo_b->real,ptrComplexo_b->real);
ptrRacional_b = multiplicaRacionais(ptrComplexo_b->imag,ptrComplexo_b->imag);
ptrRacional_div = somaRacionais(ptrRacional_a,ptrRacional_b);

ptrComplexo_new->real = divideRacionais(ptrRacional_num,ptrRacional_div);
//calculando a parte imaginaria
//imag = real_a*imag_b+imag_a*real_b / real_b*real_b+imag_b*imag_b
ptrRacional_a = multiplicaRacionais(ptrComplexo_a->real,ptrComplexo_b->imag);
ptrRacional_b = multiplicaRacionais(ptrComplexo_a->imag,ptrComplexo_b->real);
ptrRacional_num = somaRacionais(ptrRacional_a,ptrRacional_b);

ptrComplexo_new->imag = divideRacionais(ptrRacional_num,ptrRacional_div);

//simplificando os resultados
ptrComplexo_new->real = simplificaRacional(ptrComplexo_new->real);
ptrComplexo_new->imag = simplificaRacional(ptrComplexo_new->imag);

  //dando free nos racionais
destroiRacional(ptrRacional_a);
destroiRacional(ptrRacional_b);
destroiRacional(ptrRacional_num);
destroiRacional(ptrRacional_div);
return ptrComplexo_new;
}

//“acumular” somando (a += b) dois números complexos ( a e b são do mesmo “tipo” de número complexo)
R_Complexo_pt acumulaSomaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b) {

  R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
  
  ptrComplexo_new->real = somaRacionais(ptrComplexo_a->real,ptrComplexo_b->real);
  ptrComplexo_new->imag = somaRacionais(ptrComplexo_a->imag,ptrComplexo_b->imag);
  //simplificando os resultados 
  ptrComplexo_new->imag = simplificaRacional(ptrComplexo_new->imag);
  ptrComplexo_new->real = simplificaRacional(ptrComplexo_new->real);
  
  AtribuiComplexo_Racional(ptrComplexo_a,ptrComplexo_new);
  return ptrComplexo_a;
}

//“acumular” multiplicando (a *= b) dois números complexos ( a e b são do mesmo “tipo” de número complexo)
R_Complexo_pt acumulaMultiplicaComplexo_Racional(R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b){

  ptrComplexo_a = multiplicaComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
    //simplificando os resultados 
  ptrComplexo_a->imag = simplificaRacional(ptrComplexo_a->imag);
  ptrComplexo_a->real = simplificaRacional(ptrComplexo_a->real);

  return ptrComplexo_a;
}

//fazer um método que executa uma das seis operações acima, sempre considerando que a-b-c são números complexos do mesmo “tipo”, dependendo da string “operação” recebida como argumento. Operação pode ser “+”, “-”, “*”, “/”,”+=”, “*=”. Por exemplo:
R_Complexo_pt OperacaoComplexo (R_Complexo_pt ptrComplexo_a,R_Complexo_pt ptrComplexo_b,char *oper){
R_Complexo_pt ptrComplexo_new = CriaComplexo_Racional();
  if(strcmp(oper,"+") == 0){
      ptrComplexo_new = somaComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
      return ptrComplexo_new;
  }
  if(strcmp(oper,"-") == 0){
    ptrComplexo_new = subtraiComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
    return ptrComplexo_new;
  }
  if(strcmp(oper,"*") == 0){
   ptrComplexo_new = multiplicaComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
   return ptrComplexo_new;
  }
  if(strcmp(oper,"/") == 0){
    ptrComplexo_new = divideComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
    return ptrComplexo_new;
  }
  if(strcmp(oper,"+=") == 0){
    ptrComplexo_new = acumulaSomaComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
    return ptrComplexo_new;
  }
  if(strcmp(oper,"*=") == 0){
    ptrComplexo_new = acumulaMultiplicaComplexo_Racional(ptrComplexo_a,ptrComplexo_b);
    return ptrComplexo_new;
  }
  printf("comando invalido");
  printf("Volta deu merda");
  return NULL;
}

void ExibirComplexo_racional(R_Complexo_pt ptrComplexo_a){
  printf("\nNumero Complexo: %ld/%ld",(*ptrComplexo_a->real).num,(*ptrComplexo_a->real).den);
  if(((*ptrComplexo_a->imag).num) >= 0) printf(" +");

  printf(" %ld/%ldi\n",(*ptrComplexo_a->imag).num,(*ptrComplexo_a->imag).den);
  
  return ;
}