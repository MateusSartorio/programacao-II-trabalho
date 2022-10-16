#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
//#include "./Headers/naoFracionario.h"
#include "./Headers/racional.h"
//#include "./Headers/complexoNaoFracionario.h"

//Ta 100% funcional
void recursao(Racional_pt r) {
  if(r->num > r->den)
      r->num -= r->den;
  else
    r->den -= r->num;

  if(r->num != r->den)
    recursao(r);
}

//Ta 100% funcional
Racional_pt simplificaRacional(Racional_pt r) {
  long int numTemp, denTemp;

  if(r->num == r->den) {
    r->num = r->den = 1;
    return r;
  }

  numTemp = r->num;
  denTemp = r->den;
  
  if(r->num < 0)
    r->num = -r->num;

  if(r->den < 0)
    r->den = -r->den;

  recursao(r);

  r->num = numTemp / r->num;
  r->den = denTemp / r->den;

  if(r->num < 0 && r->den < 0) {
    r->num = -r->num;
    r->den = -r->den;
  }
  else if(r->num > 0 && r->den < 0) {
    r->num = -r->num;
    r->den = -r->den;
  }

  return r;
}

//Ta 100% funcional
Racional_pt criaRacional(long int num, long int den) {
  Racional_pt racional = (Racional_pt) malloc(sizeof(Racional_t));

  racional->num = num;
  racional->den = den;
  return racional;
}

//Ta 100% funcional
void destroiRacional(Racional_pt racional) {
  free(racional);
  racional = NULL;
}

//Ta 100% funcional
Racional_pt copiaRacional(Racional_pt r1, Racional_pt r2) {
  r1->num = r2->num;
  r1->den = r2->den;
  return r1;
}

//Ta 100% funcional
int comparaRacionais(Racional_pt r1, Racional_pt r2) {
  long int temporario;
  temporario = r1->num * r2->den - r1->den * r2->num;

  if( temporario == 0 )
    return 0;
  else {
    if( (r1->den > 0 && r2->den > 0) || (r1->den < 0 && r2->den < 0) ) {
      if(temporario < 0)
        return -1;
      else
        return 1;
    }
    else {
      if( temporario < 0 )
        return 1;
      else
        return -1;
    }
  }
}

//Ta 100% funcional
int verificaEquivalencia(Racional_pt r1, Racional_pt r2) {
  if(comparaRacionais(r1, r2) == 0)
    return true;
  else
    return false;
}

//Ta 100% funcional
//Verifica se o denominador é zero (x/0)
int verificarDenominadorZero(Racional_pt r1){
  if(r1->den == 0) return 1;
  return 0;
}

//Ta 100% funcional
//Verifica se o númerador é zero (0/x)
int verificarNumeradorZero(Racional_pt r1){
  if(r1->num == 0) return 1;
  return 0;
}

//Ta 100% funcional
//Verifica se ambos (numerador e denominador) são zero (0/0)
int verificarRacionalZero(Racional_pt r1){
  if(r1->num == 0 && r1->den == 0) return 1;
  return 0;
}

//Ta 100% funcional
//Soma dois racionais, gerando um terceiro (c = a+b)
Racional_pt somaRacionais(Racional_pt r1, Racional_pt r2) {
  Racional_pt r3 = criaRacional(r1->num * r2->den + r2->num * r1->den, r1->den * r2->den);
  simplificaRacional(r3);
  return r3;
}

//Ta 100% funcional
Racional_pt acumulaRacionais(Racional_pt r1, Racional_pt r2) {
  r1->num = r1->num * r2->den + r2->num * r1->den;
  r1->den = r1->den * r2->den;
  simplificaRacional(r1);
  return r1;
}

//Ta 100% funcional
//Subtrai dois racionais, gerando um terceiro
Racional_pt subtraiRacionais(Racional_pt r1, Racional_pt r2) {
  Racional_pt r3 = criaRacional(r1->num * r2->den - r2->num * r1->den, r1->den * r2->den);
  simplificaRacional(r3);
  return r3;
}

//Ta 100% funcional
Racional_pt multiplicaRacionais(Racional_pt r1, Racional_pt r2) {
  Racional_pt r3 = criaRacional(r1->num * r2->num, r1->den * r2->den);
  simplificaRacional(r3);
  return r3;
}

//Ta 100% funcional
//Multiplica um racional “b” a um primeiro racional “a” ( a *= b)
Racional_pt multiplicaEAcumulaRacionais(Racional_pt r1, Racional_pt r2) {
  r1->num *= r2->num;
  r1->den *= r2->den;
  simplificaRacional(r1);
  return r1;
}

//Ta 100% funcional
//Divide dois racionais, gerando um terceiro
Racional_pt divideRacionais(Racional_pt r1, Racional_pt r2) {
  Racional_pt r3 = criaRacional(r1->num * r2->den, r1->den * r2->num);
  simplificaRacional(r3);
  return r3;
}

//Ta 100% funcional
//Obtem o quadrado de um numero racional
Racional_pt quadradoRacional(Racional_pt r1) {
  r1-> num = r1->num * r1->num;
  r1->den = r1->den * r1->den;
  simplificaRacional(r1);
  return r1;
}

//Ta 100% funcional
Racional_pt raizQuadrada(Racional_pt r, long int denMax) {
  Racional_pt r2 = criaRacional(0, 0);

  double diferenca;

  long int numTemp = r->num;
  long int denTemp = r->den;

  double numDouble = r->num;
  double denDouble = r->den;
  double numDoubleTemp;
  double denDoubleTemp;

  denDouble *= 2;


  while(1) {
    
    numDoubleTemp = pow(( numDouble/ denDouble ), 2) + ( (double) numTemp / (double)denTemp );
    denDoubleTemp = 2 * ( numDouble/ denDouble );

    diferenca = (numDoubleTemp / denDoubleTemp) - (numDouble / denDouble);

    numDouble = numDoubleTemp;
    denDouble = denDoubleTemp;

    if(diferenca <= eps && diferenca >= -eps)
      break;
  }

  while(denDouble <= denMax / 10) {
    numDouble *= 10;
    denDouble *= 10;
  }

  r2->num = (long int) numDouble;
  r2->den = (long int) denDouble;

  simplificaRacional(r2);

  return r2;
  
}

//Ta 100% funcional
double racionalParaDouble(Racional_pt r) {
  return (double) r->num / (double) r->den;
}

Racional_pt DoubleParaRacional(double f, long int denMax, Racional_pt r) {
	long int a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
	long int x, d, n = 1;
	int i, neg = 0;
 
	if (denMax <= 1) { r->den = 1; r->num = (long int) f; return r; }
 
	if (f < 0) { neg = 1; f = -f; }
 
	while (f != floor(f)) { n <<= 1; f *= 2; }
	d = f;
 
	/* continued fraction and check denominator each step */
	for (i = 0; i < 64; i++) {
		a = n ? d / n : 0;
		if (i && !a) break;
 
		x = d; d = n; n = x % n;
 
		x = a;
		if (k[1] * a + k[0] >= denMax) {
			x = (denMax - k[0]) / k[1];
			if (x * 2 >= a || k[1] >= denMax)
				i = 65;
			else
				break;
		}
 
		h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
		k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
	}
	r->den = k[1];
	r->num = neg ? -h[1] : h[1];

  return r;
}

//Ta 100% funcional
int verificaConversao(Racional_pt r) {
  double diferenca = ( (double) r->num / (double) r->den ) - (r->num / r->den);

  if( diferenca <= eps || diferenca >= -eps )
    return 1;
  else
    return 0;
}

//Ta 100% funcional
//Escreve um número racional em um arquivo de texto no formato CSV (termos separados por vírgula).
void escreverRacionalArquivo(Racional_pt r1, FILE* escrita_pt) {
  fprintf(escrita_pt,",%ld/%ld",r1->num,r1->den);
}

//Ta 100% funcional
Racional_pt leRacionalArquivo(Racional_pt r, FILE* leitura_pt) {
  char c;

  fscanf(leitura_pt, "%ld%c", &(r->num), &c);

  if(c == ',') {
    r->den = 1;
    return r;
  }
  else if(c == EOF) {
    r->den = 1;
    return r;
  }
  else {
    fscanf(leitura_pt, "%ld,", &(r->den));
  }

  return r;
}

void imprimeRacional(Racional_pt r) {
  printf("%ld/%ld\n", r->num, r->den);
}

/*
//Nao esta lendo corretamente racionais que vem apos um racional sem denominador
void leArquivo(Racional_pt r, FILE* leitura_pt) {
  char c;

  if(!feof(leitura_pt)){
    fscanf(leitura_pt,"%ld%c", &(r->num), &c);
  } else return ;

  if(!feof(leitura_pt)){
  fscanf(leitura_pt,"%ld", &(r->den));
  }

  if(!feof(leitura_pt)){
    fscanf(leitura_pt,"%c", &c);
  }
}
*/

/*
//Algoritimo de Euclides com loop
void simplificaRacional(Racional_pt q) {
  long int numTemp, denTemp;

  if(q->num == q->den) {
    q->num = q->den = 1;
    return;
  }
  
  if(q->num < 0)
    numTemp = -q->num;
  else
    numTemp = q->num;

  if(q->den < 0)
    denTemp = -q->den;
  else
    denTemp = q->den;

  while(numTemp != denTemp) {
    if(numTemp > denTemp)
      numTemp -= denTemp;
    else
      denTemp -= numTemp;
  }

  q->num /= numTemp;
  q->den /= numTemp;

  if(q->num < 0 && q->den < 0) {
    q->num = -q->num;
    q->den = -q->den;
  }
  else if(q->num > 0 && q->den < 0) {
    q->num = -q->num;
    q->den = -q->den;
  }
}
*/ 