#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/naoFracionario.h"
#include "./Headers/racional.h"
#include "./Headers/complexoNaoFracionario.h"


TIPO_C_PT criaComplexoNF(SUBTIPO_C real, SUBTIPO_C imag) {
  TIPO_C_PT c = malloc(sizeof(TIPO_C));
  c->real = criaNF(real);
  c->imag = criaNF(imag);
  return c;
}

void destroiComplexoNF(TIPO_C_PT c) {
  destroiNF(c->real);
  destroiNF(c->imag);
  free(c);
}

void imprimeComplexoNF(TIPO_C_PT c) {
  imprimeNF(c->real);
  printf(" + ");
  imprimeNF(c->imag);
  printf("i");
}

TIPO_C_PT atribuiComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  *c1->real = *c2->real;
  *c1->imag = *c2->imag;
  return c1;
}

TIPO_C_PT copiaECriaComplexoNF(TIPO_C_PT c) {
  TIPO_C_PT newC = criaComplexoNF(*c->real, *c->imag);
  return newC;
}

int verificaSeModuloZeroNF(TIPO_C_PT c) {
  double modulo = sqrt( pow(*c->real, 2) + pow(*c->imag, 2) );

  if(modulo <= eps && modulo >= -eps)
    return 1;

  return 0;
}

int verificaSeERealNF(TIPO_C_PT c) {
  if(*c->imag <= eps && *c->imag >= -eps)
    return 1;

  return 0;
}

int verificaSeEImaginarioNF(TIPO_C_PT c) {
  if(*c->real <= eps && *c->real >= -eps)
    return 1;

  return 0;
}

int comparaModuloNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  double modulo1 = sqrt( pow(*c1->real , 2) + pow(*c1->imag, 2) );
  double modulo2 = sqrt( pow(*c2->real , 2) + pow(*c2->imag, 2) );
  double diferenca = modulo1 - modulo2;

  if(diferenca <= eps && diferenca >= -eps)
    return 0;
  else if(diferenca < 0)
    return -1;
  else
    return 1;
}

double calculaAnguloNF(SUBTIPO_C x0, SUBTIPO_C y0) {
  double x = (double) x0;
  double y = (double) y0;
  double angulo = 0;

  if(x == 0 && y > 0) {
    angulo = PI / 2.0;
  }
  else if(x == 0 && y < 0) {
    angulo = (3 * PI) / 2.0;
  }
  else if(x > 0 && y >= 0) {
    angulo = atan(y/x);
  }
  else if(x < 0 && y >= 0) {
    angulo = atan(y/x) + PI;
  }
  else if(x < 0 && y < 0) {
    angulo = atan(y/x) + PI;
  }
  else if(x > 0 && y < 0) {
    angulo = atan(y/x) + 2 * PI;
  }
  else {
    printf("Parece que deu alguma merda no calculo do angulo.");
  }

  return angulo;
}

int comparaAnguloNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  double angulo1 = calculaAnguloNF(*c1->real, *c1->imag);
  double angulo2 = calculaAnguloNF(*c2->real, *c2->imag);

  double diferenca = angulo1 - angulo2;

  if(diferenca <= eps && diferenca >= -eps)
    return 0;
  else if(diferenca < 0)
    return -1;
  else
    return 1;
}

SUBTIPO_C retornaParteRealNF(TIPO_C_PT c) {
  return *c->real;
}

SUBTIPO_C retornaParteImaginariaNF(TIPO_C_PT c) {
  return *c->imag;
}

double retornaMagnitudeNF(TIPO_C_PT c) {
  return sqrt( pow(*c->real , 2) + pow(*c->imag, 2) );
}

double retornaFaseNF(TIPO_C_PT c) {
  return calculaAnguloNF(*c->real, *c->imag);
}

TIPO_C_PT atribuiValorRealNF(TIPO_C_PT c, SUBTIPO_C valor) {
  *c->real = valor;
  return c;
}

TIPO_C_PT atribuiValorImaginarioNF(TIPO_C_PT c, SUBTIPO_C valor) {
  *c->imag = valor;
  return c;
}

TIPO_C_PT atribuiMagnitudeNF(TIPO_C_PT c, SUBTIPO_C magnitude) {
  double fatorMultiplicativo = (double) magnitude / (double) retornaMagnitudeNF(c);
  *c->real *= fatorMultiplicativo;
  *c->imag *= fatorMultiplicativo;
  return c;
}

TIPO_C_PT atribuiFaseNF(TIPO_C_PT c, SUBTIPO_C fase) {
  double modulo = (double) retornaMagnitudeNF(c);
  *c->real = modulo * cos(fase);
  *c->imag = modulo * sin(fase);
  return c;
}

TIPO_C_PT calculaECriaConjugadoNF(TIPO_C_PT c) {
  TIPO_C_PT newC = criaComplexoNF(*c->real, - *c->imag);
  return newC;
}

TIPO_C_PT somaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  TIPO_C_PT c3 = criaComplexoNF(*c1->real + *c2->real, *c1->imag + *c2->imag);
  return c3;
}

TIPO_C_PT subtraiComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  TIPO_C_PT c3 = criaComplexoNF(*c1->real - *c2->real, *c1->imag - *c2->imag);
  return c3;
}

TIPO_C_PT multiplicaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  SUBTIPO_C real = *c1->real * *c2->real - *c1->imag * *c2->imag;
  SUBTIPO_C imag = *c1->real * *c2->imag + *c1->imag * *c2->real;
  TIPO_C_PT c3 = criaComplexoNF(real, imag);
  return c3;
}

TIPO_C_PT multiplicaComplexoPorEscalarNF(TIPO_C_PT c, SUBTIPO_C k) {
  SUBTIPO_C real = *c->real * k;
  SUBTIPO_C imag = *c->imag * k;
  TIPO_C_PT newC = criaComplexoNF(real, imag);
  return newC;
}

TIPO_C_PT divideComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  double modulo1 = retornaMagnitudeNF(c1);
  double modulo2 = retornaMagnitudeNF(c2);

  double angulo1 = retornaFaseNF(c1);
  double angulo2 = retornaFaseNF(c2);

  double modulo3 = modulo1 / modulo2;
  double angulo3 = angulo1 - angulo2;

  TIPO_C_PT c3 = criaComplexoNF(modulo3 * cos(angulo3), modulo3 * sin(angulo3));
  return c3;
}

TIPO_C_PT acumulaSomaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  *c1->real += *c2->real;
  *c1->imag += *c2->imag;
  return c1;
}

TIPO_C_PT acumulaSubtracaoComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  *c1->real -= *c2->real;
  *c1->imag -= *c2->imag;
  return c1;
}

TIPO_C_PT acumulaMultiplicaComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2) {
  SUBTIPO_C real = *c1->real * *c2->real - *c1->imag * *c2->imag;
  SUBTIPO_C imag = *c1->real * *c2->imag + *c1->imag * *c2->real;

  *c1->real = real;
  *c1->imag = imag;

  return c1;
}

TIPO_C_PT raizComplexoNF(TIPO_C_PT c) {
  SUBTIPO_C real, imag;
  
  double modulo = retornaMagnitudeNF(c);
  double angulo = retornaFaseNF(c);

  modulo = sqrt(modulo);
  angulo = angulo / 2.0;

  real = modulo * cos(angulo);
  imag = modulo * sin(angulo);

  TIPO_C_PT newC = criaComplexoNF(real, imag);

  return newC;
}

TIPO_C_PT operacaoComplexoNF(TIPO_C_PT c1, TIPO_C_PT c2, char operacao[]) {
  if(strcmp(operacao, "+") == 0)
    return somaComplexoNF(c1, c2);
  else if(strcmp(operacao, "-") == 0)
    return subtraiComplexoNF(c1, c2);
  else if(strcmp(operacao, "*") == 0)
    return multiplicaComplexoNF(c1, c2);
  else if(strcmp(operacao, "/") == 0)
    return divideComplexoNF(c1, c2);
  else if(strcmp(operacao, "+=") == 0)
    return acumulaSomaComplexoNF(c1, c2);
  else if(strcmp(operacao, "*=") == 0)
    return acumulaMultiplicaComplexoNF(c1, c2);
  else {
    printf("Operacao invalida\n");
    return NULL;
  }
}

void escreveComplexoNF(TIPO_C_PT c, FILE* complexo_escrita) {
  int real = 0;

  if(*c->real == 0 && *c->imag == 0) {
    fprintf(complexo_escrita, "0");
  }

  if(*c->real != 0) {
    fprintf(complexo_escrita, FORMATO, *c->real);
    real = 1;
  }

  if(*c->imag < 0) {
    fprintf(complexo_escrita, "-");
    fprintf(complexo_escrita, FORMATO, -*c->imag);
    fprintf(complexo_escrita, "i");
  }

  else if(*c->imag > 0) {
    if(real == 1) {
      fprintf(complexo_escrita, "+");
      fprintf(complexo_escrita, FORMATO, *c->imag);
      fprintf(complexo_escrita, "i");
    }
    else {
      fprintf(complexo_escrita, FORMATO, *c->imag);
      fprintf(complexo_escrita, "i");
    }
  }

  fprintf(complexo_escrita, ", ");

}

TIPO_C_PT leComplexoNF(TIPO_C_PT complexo, FILE* complexo_leitura) {
  *complexo->real = 0;
  *complexo->imag = 0;

  SUBTIPO_C num;
  char c;

  fscanf(complexo_leitura, FORMATO, &num);
  fscanf(complexo_leitura, "%c", &c);

  if(c == '+') {
    *complexo->real = num;
    fscanf(complexo_leitura, FORMATO, &num);
    fscanf(complexo_leitura, "i,");
    *complexo->imag = num;
  }
  else if(c == '-') {
    *complexo->real = num;
    fscanf(complexo_leitura, FORMATO, &num);
    fscanf(complexo_leitura, "i,");
    *complexo->imag = -num;
  }
  else if(c == ',') {
    *complexo->real = num;
  }
  else if(c == 'i') {
    *complexo->real = 0;
    *complexo->imag = num;
    fscanf(complexo_leitura, ",");
  }
  else {
    *complexo->imag = 0;
  }

  return complexo;
}