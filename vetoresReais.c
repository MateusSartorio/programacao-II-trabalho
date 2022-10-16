#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/complexoNaoFracionario.h"
#include "./Headers/vetoresReais.h"

//cria vetor /100%
void CriaVector(VetorR_t* ptrVector) {
  ptrVector->primeiro = NULL;
  ptrVector->ultimo = NULL;
  ptrVector->i = NULL;
  ptrVector->N = 0;
  ptrVector->n = 0;
  int indice = 0;

  while(indice < 100){
    AddUltimaCelula(ptrVector);
    indice++;
    //ptrVector->n = ptrVector->n+1;
    //printf("%d ",indice);  
  }
  
  return;
}

//destroi vetor
void DestruirVector(VetorR_t* ptrvector) {

  if(ptrvector->primeiro == NULL) {
    printf("O vetor nao foi inicializado");
    return;
  }else{
        while(ptrvector->N != 0){
      DestroirUltimaCelula(ptrvector);
    }
    ptrvector->primeiro = NULL;
    ptrvector->ultimo = NULL;
    ptrvector->i = NULL;
    //ptrvector = NULL;
    free(ptrvector);
    ptrvector = NULL;
  }
}


void DestroirUltimaCelula(VetorR_t* ptrvector){
  if(ptrvector->ultimo != NULL){
    if(ptrvector->ultimo->conteudo != NULL){
      ptrvector->n -= 1;
    }
    ptrvector->N -= 1;
    Celula_t* aux = (Celula_t*) malloc(sizeof(Celula_t));
    Celula_t* aux2 = (Celula_t*) malloc(sizeof(Celula_t));
    aux = ptrvector->ultimo;
    aux2 = RetornaAntesessorElemento(ptrvector->ultimo,ptrvector);ptrvector->ultimo = aux2;
    ptrvector->ultimo->proximo = NULL;
    free(aux);
  }
}



//100%
//adciona Celula na ultima posicao
void AddUltimaCelula(VetorR_t* ptrvector){
  Celula_t* ptrcelula = (Celula_t*) malloc(sizeof(Celula_t));

  ptrcelula->conteudo = NULL;
  ptrcelula->proximo = NULL;

  if(ptrvector->primeiro == NULL){
    ptrvector->primeiro = ptrcelula;
    ptrcelula->indice = 0;
  } else { 
    ptrcelula->indice = ptrvector->ultimo->indice + 1;
    ptrvector->ultimo->proximo = ptrcelula;
    
  }
  //if(ptrvector->ultimo->indice >= ptrvector->N ){
  //  ptrvector->N *= 2;
  //}
  
  (ptrvector->N)++;
  ptrvector->ultimo = ptrcelula;
  ptrvector->i = ptrcelula;
}

//adciona elemento
void AdicionaElementos(VetorR_t* ptrvector, TIPO1* data) {
  Celula_t* celula1 = ptrvector->primeiro;
  int num = 0;

  for(num = 0; num < ptrvector->N;num++){
     //printf("teste %d ",num);
     ptrvector->n = ptrvector->n + 1;
     (*celula1).conteudo = data;
     celula1 = celula1->proximo;
  }

  return;
}
TIPO1 RetornaValorElemento(Celula_t* celula1){
  return *celula1->conteudo;
}

//atribuir uma cópia do vetor a outro vetor já existente/coipiar 2 no 1
//100%
void CopiaVetor(VetorR_t* ptrvector1,VetorR_t ptrvector2){
  int indicador = 0,num =0;
  Celula_t* aux1 = ptrvector1->primeiro;
  Celula_t* aux2 = ptrvector2.primeiro;
  //vetor 2 > vetor 1 // aumentando vetor 1
  if(ptrvector2.N > ptrvector1->N){
      while(ptrvector2.N > ptrvector1->N){
        AddUltimaCelula(ptrvector1);
      }
  }
  //copiando
  if(ptrvector1->N >= ptrvector2.N ){
    for(num=0; num < ptrvector2.N; num++){
      
      if(aux2->conteudo != NULL){
        aux1->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
        *aux1->conteudo = *aux2->conteudo;
        //printf("\nEndereco: %p %p",aux1,aux2);
        //printf("\nEndereco: %p %p",aux1->conteudo,aux2->conteudo);
        
      }
      
      aux1 = aux1->proximo;
      aux2 = aux2->proximo;
    }
    return ;  
  }

  printf("Erro Na Copia");
  printf("Volta Deu Merda");
  return ;
}

//criar uma cópia do vetor, criando um novo vetor
VetorR_t* CopiaECriaVetor(VetorR_t* ptrvector1){
int num=0;
//criando vector 
  VetorR_t* ptrvector2 = (VetorR_t*)malloc(sizeof(VetorR_t));
  CriaVector(ptrvector2);
//copiando 1 no 2
  CopiaVetor(ptrvector2,*ptrvector1);
  return ptrvector2;  
}

//devolver o número atual de elementos;/100%
int RetornaNumElementos(VetorR_t* ptrvector){
return ptrvector->n;
}
//devolver o número máximo de elementos;
int RetornaNumMaxElementos(VetorR_t* ptrvector){
return ptrvector->N;
}
//devolver o índice do elemento atual;
int RetornaNumIndice(Celula_t* celula1){
return celula1->indice;
}

//devolver o primeiro elemento e posicionar “i” na primeira posição);
Celula_t* RetornaPrimeiroElemento(VetorR_t* ptrvetor){
ptrvetor->i = ptrvetor->primeiro;
return ptrvetor->primeiro;
}
//devolver o próximo elemento (posicionando “i” nesta posição);
Celula_t* RetornaProximoElemento(Celula_t* ptrcelula,VetorR_t* ptrvetor){
  ptrcelula = ptrcelula->proximo;
  ptrvetor->i = ptrcelula;
  return ptrcelula;
}
//devolver o elemento anterior (posicionando “i” nesta posição);
Celula_t* RetornaAntesessorElemento(Celula_t* ptrcelula,VetorR_t* ptrvetor){
  Celula_t* aux = ptrvetor->primeiro;

  if(ptrcelula == ptrvetor->primeiro){
    ptrvetor->i = ptrvetor->primeiro; 
    return ptrvetor->primeiro;
  }else{
    while(aux->proximo != ptrcelula){
      aux = aux->proximo;
    }
    if (aux->proximo == ptrcelula){
      ptrvetor->i = aux; 
      return aux;
    }else {
      ptrvetor->i = aux;
      return NULL;
    }
  }
}

//devolver o último elemento e posicionar “i” na última posição;
Celula_t* RetornaUltimoElemento(VetorR_t* ptrvetor){
  ptrvetor->i = ptrvetor->ultimo;
  return ptrvetor->ultimo;
}
//devolver o elemento da i-ésima posição (lá posicionando o índice “i”);
Celula_t* RetornaElementoNaPosicaoI_esima(VetorR_t* ptrvetor,int i){
  Celula_t* aux = ptrvetor->primeiro;
  while(aux->indice != i){
    aux = aux->proximo;  
  }
  if(aux->indice == i){
    ptrvetor->i = aux;
    return aux;  
  }else{
    ptrvetor->i = NULL;
    return NULL;
  }
  
}

//atribuir o valor “v” na i-ésima posição do vetor, posicionando ali o índice “i”;
void AtribuirElementoNaPosicaoI_esima(VetorR_t* ptrvetor, int i, TIPO1* data) {
  if(i > ptrvetor->N ){
    printf("\nErro: posicao fora do vetor");
    printf("\nVolta Deu Merda\n");
    return;
  }

  Celula_t* aux = RetornaElementoNaPosicaoI_esima(ptrvetor, i);

  aux->conteudo = data;
  ptrvetor->i = aux;

  if(aux != NULL) (ptrvetor->n)++;    

  return ;
}

//atribuir o valor “v” depois da última posição do vetor, incrementando o “número atual de elementos”;
void AdicionarElementoDepoisDoUltimo(VetorR_t* ptrvetor,TIPO1* data){
  int qtd = ptrvetor->N;

  //adcionando celula
  if((ptrvetor->ultimo->indice+1) < ptrvetor->N){
    AddUltimaCelula(ptrvetor);  
  }
  else {
    for(int j = 0; j < qtd; j++) {
      AddUltimaCelula(ptrvetor);
    }
  }

  int i = (ptrvetor->N/2);
  AtribuirElementoNaPosicaoI_esima(ptrvetor,i,data);
  (ptrvetor->n)++;
  ptrvetor->i = ptrvetor->ultimo;

  return;
}

//eliminar a i-ésima posição do vetor, devolvendo o seu valor atual e decrementando o “número atual de elementos”
//100%
TIPO1 EliminarCelulaNaPosicaoI(VetorR_t* ptrvetor, int i){
  Celula_t* auxant = malloc(sizeof(Celula_t));
  Celula_t* aux = RetornaElementoNaPosicaoI_esima(ptrvetor, i);
  TIPO1 retorno;
  int num;
  num = aux->indice;

//verificando se celula foi achada
  if(i > ptrvetor->N){
    printf("deu Merda,Eu acho");
    printf("indice i nao encontrado no vetor");
    return 0;
  }
  
  //se a celula for a primeira
  if(aux->indice == 0){
    if(aux->conteudo != NULL) retorno = *aux->conteudo;  
    else retorno = 0;
    ptrvetor->primeiro = aux->proximo;
    aux->proximo = NULL; 
    free(aux);
  }else{
    //se a celula nao for a primeira
    if(aux->conteudo != NULL) retorno = *aux->conteudo;
    else retorno = 0;
    //liberando celula
    auxant = RetornaAntesessorElemento(aux,ptrvetor);
    auxant->proximo = aux->proximo;
    free(aux);
  }

  (ptrvetor->n)--;
  //decrementando o indice dentro da celula
  for(num = num+1;num < ptrvetor->N;num++){
    auxant = RetornaElementoNaPosicaoI_esima(ptrvetor,num);
    auxant->indice = auxant->indice -1;
  }
  //decrementando o Num Max de Elemntos se necessario
  if(ptrvetor->n < ptrvetor->N /4){
    int temp = ptrvetor->N;
      for(int j = 0; j < (temp/2) - 2; j++){
        DestroirUltimaCelula(ptrvetor);
        //printf("%d\n", ptrvetor->N);
      }
  } 

  (ptrvetor->N)--;
  return retorno;
}

//eliminar todos os elementos do vetor
void EliminarTodosElementosDoVetor(VetorR_t* ptrvetor){
Celula_t* aux = malloc(sizeof(Celula_t));
aux = ptrvetor->primeiro;
int i;
  for(i=0;i < ptrvetor->N; i++){
    aux->conteudo = NULL;
    aux = aux->proximo;
  }
  return;
}

void ExibirTipoElemento(Celula_t celula1) {
  printf(FORMATO1,*celula1.conteudo);
  return;
}

void ExibiVector(VetorR_t* ptrvector){

  if(ptrvector->primeiro == NULL) {
    printf("Esse vetor nao existe");
    return;
  }

  Celula_t* celula1 = ptrvector->primeiro;
  int num = 0;

  printf("\n");

  while(num < ptrvector->N) {
    num += 1;
    printf("Celula:%d\tValor:",celula1->indice);
    //  ExibirTipoElemento(ptrvector->i);
    if(celula1->conteudo != NULL)//ExibirTipoElemento(*celula1);
      printf(FORMATO1, *celula1->conteudo);
    printf("\n");
    celula1 = celula1->proximo;
  }
  return;
}

TIPO1 RetornaModulo(TIPO1 valor) {
  if(valor >= 0)
    return valor;
  else
    return -valor;
}

//obter o valor do elemento de maior módulo existente no vetor (e posicionar o índice atual naquela posição). Em caso de empate, qualquer uma das posições serve;
//100%
TIPO1 RetornandoValorDoItemMaiorModulo(VetorR_t* ptrvetor){
  Celula_t* celula1 = ptrvetor->primeiro;
  TIPO1 compara;
  TIPO1 retorno = 0;
  
  for(int i=0;i < ptrvetor->N;i++){
    
    if(celula1->conteudo != NULL){
      compara = RetornaModulo(*celula1->conteudo);
      if(compara > retorno){
        retorno = compara; 
        ptrvetor->i = celula1;
      }
    celula1 = celula1->proximo;
    }
  }
  retorno = *ptrvetor->i->conteudo;
  return retorno;
}

//obter o valor do elemento de menor módulo existente no vetor (e posicionar o índice atual naquela posição). Em caso de empate, qualquer uma das posições serve;
//100%
TIPO1 RetornandoValorDoItemMenorModulo(VetorR_t* ptrvetor){
  Celula_t* celula1 = ptrvetor->primeiro;
  TIPO1 compara;
  TIPO1 retorno = *ptrvetor->primeiro->conteudo;
  
  for(int i=0;i < ptrvetor->N;i++){
    
    if(celula1->conteudo != NULL){
      compara = RetornaModulo(*celula1->conteudo);
      if(compara < retorno){
        retorno = compara; 
        ptrvetor->i = celula1;
      }
    celula1 = celula1->proximo;
    }
  }
  retorno = *ptrvetor->i->conteudo;
  return retorno;
}

//determinar quantos dos elementos do vetor têm valor igual a “v” (considerar uma tolerância eps = 0.0001)
//100%
int RetornandoQtdElementosTemValorV(VetorR_t* ptrvetor,TIPO1* v){
Celula_t* celula1 = ptrvetor->primeiro;
int retorno = 0;
float diferenca =0;

  for(int i=0; i < ptrvetor->N ;i++){
    if(celula1->conteudo != NULL){
      diferenca = celula1->conteudo - v;
      if(diferenca < 0.0001 && diferenca > -0.0001){
        retorno++;
      }
    }
  celula1 = celula1->proximo;
  }
return retorno;
}

//devolver um vetor com as posições dos elementos que têm valor igual a “v” (considerar uma tolerância eps = 0.0001)
/*
VetorR_t* RetornandoUmVetorComValorV(TIPO1* v){
VetorR_t* vetor = (VetorR_t*)malloc(sizeof(VetorR_t));
CriaVector(vetor);
  for(int i=0;i<ptrvetor->N;i++){
    if(celula1->conteudo != NULL){
        if(diferenca < 0.0001 && diferenca > -0.0001){
        retorno++;
      }
    }
  celula1->proximo = celula1;
  }
return retorno;
}
*/
//ordenar os elementos do vetor de acordo com uma função “critério de comparação”.
void OrdenaVetor(VetorR_t* ptrvetor){
  VetorR_t* vetor2 =(VetorR_t*) malloc(sizeof(VetorR_t));
  CriaVector(vetor2);
  int criterio,i,j,comparador, num;
  TIPO1 a = -10000000;

  //CopiaVetor(vetor2,*ptrvetor);
  Celula_t* aux =ptrvetor->primeiro;
  Celula_t* aux2 = vetor2->primeiro;
  
  TIPO1* d = (TIPO1*)malloc(sizeof(TIPO1));

  for(i = 0; i < ptrvetor->N ;i++){
    aux = RetornaElementoNaPosicaoI_esima(ptrvetor,i);
        for(j=i; j < ptrvetor->N ;j++){
      
        aux2 = RetornaElementoNaPosicaoI_esima(ptrvetor,j);
        if(aux2->conteudo != NULL ){
          criterio = CriterioDeOrdenacao(aux,aux2);
         if(criterio == 1  ){
            if(aux->conteudo == NULL)
            aux->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
            *d = *aux->conteudo;
            *aux->conteudo = *aux2->conteudo;
            *aux2->conteudo = *d;
          }
        }
    }
  }
//tirando os espacos NULL
aux2 = vetor2->primeiro;
j=0;
int ind;
for(i = 0; i < ptrvetor->N ;i++){
  aux2 = RetornaElementoNaPosicaoI_esima(vetor2,i);
    for(j=i;j<ptrvetor->N ;j++){
        aux = RetornaElementoNaPosicaoI_esima(ptrvetor,j);
        if(aux->conteudo != NULL){
          aux2->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
          *aux2->conteudo = *aux->conteudo;
          aux->conteudo = NULL;
          j=ptrvetor->N;
        }
      }
}
CopiaVetor(ptrvetor,*vetor2);
DestruirVector(vetor2);
return;
}

int RetornaMenorItem(VetorR_t* ptrvetor, TIPO1 menor){
  Celula_t* celula1 = ptrvetor->primeiro;
  TIPO1 compara;
  TIPO1 retorno = 100000000000;
  
  for(int i=0;i < ptrvetor->N;i++){
    
    if(celula1->conteudo != NULL){
      compara = *celula1->conteudo;
      if(compara < retorno && compara > menor){
        retorno = compara; 
        ptrvetor->i = celula1;
      }
    celula1 = celula1->proximo;
    }
  }
  return ptrvetor->i->indice;
}

//A função “critério” recebe dois elementos do vetor e os compara: se a=b, retorna “0”; se a<b, retorna -1; se a>b, retorna +1. A função “critério” é um dos argumentos deste método de ordenação;

int CriterioDeOrdenacao(Celula_t* celula1,Celula_t* celula2){
  if(celula1->conteudo == NULL && celula2->conteudo != NULL)return -1;
  //if(celula1->conteudo != NULL && celula2->conteudo == NULL)return 1;
  if(celula1->conteudo == NULL && celula2->conteudo == NULL)return 0; 
//a=b 
  if(*celula1->conteudo == *celula2->conteudo) return 0;
//a>b
  if(*celula1->conteudo > *celula2->conteudo) return 1;
//a=b
  if(*celula1->conteudo < *celula2->conteudo) return -1;
printf("\nErro Na Comparacao\n");
return 111;
}
//intercalar dois vetores ordenados, criando um novo vetor igualmente ordenado, usando uma função “critério” que igualmente um argumento deste método de intercalação;

//somar dois vetores de mesmo tamanho criando um novo vetor (C = A + B);
//100%
VetorR_t* SomarVetorCriandoOutro(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2){
  
  VetorR_t* ptrvetor3 = (VetorR_t*) malloc(sizeof(VetorR_t));
  CriaVector(ptrvetor3);
  
  if(ptrvetor1->N != ptrvetor2->N){
    printf("Vetores de Tamanhos Defirentes");
    return NULL;
  }
  
   // aumentando vetor 3
  if(ptrvetor3->N < ptrvetor1->N){
      while(ptrvetor3->N < ptrvetor1->N){
        AddUltimaCelula(ptrvetor3);
      }
  }
  
  Celula_t* celula1 = ptrvetor1->primeiro;
  Celula_t* celula2 = ptrvetor2->primeiro;
  Celula_t* celula3 = ptrvetor3->primeiro;
  
  
  for(int i =0;i < ptrvetor1->N;i++){    
    if(celula1->conteudo == NULL && celula2->conteudo != NULL){
     celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = *celula2->conteudo;
    }
      
    else if(celula1->conteudo != NULL && celula2->conteudo == NULL){
      celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = *celula1->conteudo;
    } 
    else if(celula1->conteudo != NULL && celula2->conteudo != NULL){
      celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = (*celula1->conteudo) + (*celula2->conteudo);
    }
 
    
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    celula3 = celula3->proximo;
  }
  
  return ptrvetor3;
}

//multiplicar dois vetores (“produto interno”) gerando um valor “produto” (c = A . B)
//100%
TIPO1 MultiplicarVetorCriandoValor(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2){
  TIPO1 soma = 0;

  if(ptrvetor1->N != ptrvetor2->N){
    printf("Vetores de Tamanhos Defirentes");
    return 0;
  }
  
  Celula_t* celula1 = ptrvetor1->primeiro;
  Celula_t* celula2 = ptrvetor2->primeiro;

  for(int i =0;i < ptrvetor1->N;i++){
    if(celula1->conteudo != NULL && celula2->conteudo != NULL) {
      soma += ((*celula1->conteudo) * (*celula2->conteudo));
    }
      
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    
  }
  return soma;
}

//subtrair dois vetores de mesmo tamanho criando um novo vetor (C = A + B);
//100%
VetorR_t* SubtrairVetorCriandoOutro(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2){
  
  VetorR_t* ptrvetor3 = (VetorR_t*) malloc(sizeof(VetorR_t));
  CriaVector(ptrvetor3);
  
  if(ptrvetor1->N != ptrvetor2->N){
    printf("Vetores de Tamanhos Defirentes");
    return NULL;
  }
  
   // aumentando vetor 3
  if(ptrvetor3->N < ptrvetor1->N){
      while(ptrvetor3->N < ptrvetor1->N){
        AddUltimaCelula(ptrvetor3);
      }
  }
  
  Celula_t* celula1 = ptrvetor1->primeiro;
  Celula_t* celula2 = ptrvetor2->primeiro;
  Celula_t* celula3 = ptrvetor3->primeiro;
  
  
  for(int i =0;i < ptrvetor1->N;i++){    
    if(celula1->conteudo == NULL && celula2->conteudo != NULL){
     celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = *celula2->conteudo;
    }
      
    else if(celula1->conteudo != NULL && celula2->conteudo == NULL){
      celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = *celula1->conteudo;
    } 
    else if(celula1->conteudo != NULL && celula2->conteudo != NULL){
      celula3->conteudo = (TIPO1*)malloc(sizeof(TIPO1));
      *celula3->conteudo = (*celula1->conteudo) - (*celula2->conteudo);
    }
 
    
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    celula3 = celula3->proximo;
  }
  
  return ptrvetor3;
}


//multiplicar um vetor por um escalar, alterando os valores do vetor original (A = k * A)
//100%
void MutiplicarVetorPorEscalar(VetorR_t* ptrvetor1,TIPO1 k){
   Celula_t* celula1 = ptrvetor1->primeiro;
   for(int i =0; i < ptrvetor1->N ;i++){
     if(celula1->conteudo != NULL) (*celula1->conteudo) *= (k);
    celula1 = celula1->proximo;
  }
  return ;
}

//acumular um vetor B sobre um outro vetor A do mesmo tamanho, somando os elementos um-a-um (A = A+ B)
void SomarVetorAcumulando(VetorR_t* ptrvetor1,VetorR_t* ptrvetor2){
   Celula_t* celula1 = ptrvetor1->primeiro;
   Celula_t* celula2 = ptrvetor2->primeiro;
   
  for(int i =0;i < ptrvetor1->N;i++){
    if(celula1->conteudo != NULL && celula2->conteudo != NULL)
      *celula1->conteudo += *celula2->conteudo;
    if(celula1->conteudo == NULL && celula2->conteudo != NULL)
      *celula1->conteudo = *celula2->conteudo;
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
  }
  
  return ;
}

//determinar a média aritmética dos valores de um vetor (REferencia 4)
double RetornarMediaAritimetica(VetorR_t* ptrvetor) {
  long double soma = 0;
  double media;
  Celula_t* celula = (Celula_t*) malloc(sizeof(Celula_t));

  for(int i = 0; i < ptrvetor->N ;i++){
    celula = RetornaElementoNaPosicaoI_esima(ptrvetor,i);
    if(celula->conteudo != NULL){
      soma += (long double) *celula->conteudo;
    }
  }

  media = soma / ( (double) ptrvetor->n );

  return media;
}

//determinar a variância dos valores de um vetor
long double RetornaVariaciaDosValores(VetorR_t* ptrvetor){
  long double variancia = 0, soma= 0;
  double media = RetornarMediaAritimetica(ptrvetor);

  Celula_t* celula = (Celula_t*) malloc(sizeof(Celula_t));

  for(int i = 0; i < ptrvetor->N; i++) {
    celula = RetornaElementoNaPosicaoI_esima(ptrvetor,i);

    if(celula->conteudo != NULL){
      soma += (long double) pow( (*celula->conteudo - media), 2);
    }
  }

  variancia = soma / ( (long double) ( ptrvetor->n) );

  return variancia;
}

//determinar o desvio padrão dos valores de um vetor (raiz quadrada da variância)
double RetornaDesvioPadrao(VetorR_t* ptrvetor) {
  long double variancia = RetornaVariaciaDosValores(ptrvetor);
  double desvio = 0;
  desvio = sqrtl(variancia);
  return desvio; 
}

//determinar a mediana dos valores de um vetor (o valor que separa os 50% maiores dos 50% menores
double RetornaMedianaDosValores(VetorR_t* ptrvetor) {
  double mediana;
  TIPO1 elemento1,elemento2;
  OrdenaVetor(ptrvetor);
  Celula_t* celula1 = malloc(sizeof(Celula_t));
  Celula_t* celula2 = malloc(sizeof(Celula_t));

  if(ptrvetor->n % 2 == 0){
    celula1 = RetornaElementoNaPosicaoI_esima(ptrvetor,((ptrvetor->n-1)/2 ));
    celula2 = RetornaElementoNaPosicaoI_esima(ptrvetor,((ptrvetor->n+1)/2 ));
    mediana = (*celula1->conteudo + *celula2->conteudo) / 2.0;
    // 1 2 3 4 5 
    // 0 1 2 3 4  n-1 /2   
  }else{
    celula1 = RetornaElementoNaPosicaoI_esima(ptrvetor,((ptrvetor->n)/2 ));
    mediana = (double) (*celula1->conteudo);
  }
  free(celula1);
  free(celula2);

  return mediana;
}

VetorR_t* devolveVetorPosicoesElementosV(VetorR_t* ptrVetor, TIPO1 v) {
  VetorR_t* vetor = malloc(sizeof(VetorR_t));
  CriaVector(vetor);
  


  Celula_t* celula1 = ptrVetor->primeiro;
  int retorno = 0;
  float diferenca = 0;

  for(int i=0; i < ptrVetor->N ;i++){
    if(celula1->conteudo != NULL){
      diferenca = *celula1->conteudo - v;
      if(diferenca < 0.0001 && diferenca > -0.0001){
        TIPO1* indice = malloc(sizeof(TIPO1));
        *indice = (TIPO1) celula1->indice;
        retorno++;
        AtribuirElementoNaPosicaoI_esima(vetor, retorno - 1, indice);
      }
    }
  celula1 = celula1->proximo;
  }

  return vetor;
}

VetorR_t* intercalaVetoresOrdenados(VetorR_t* v1, VetorR_t* v2) {
  VetorR_t* v3 = malloc(sizeof(VetorR_t));
  CriaVector(v3);

  v1->i = v1->primeiro;
  v2->i = v2->primeiro;

  int i = 0;


  for(int j = 0; j < v1->N; j++) {
    if(v1->i->conteudo != NULL) {
      AtribuirElementoNaPosicaoI_esima(v3, j, v1->i->conteudo);
    }
    
    v1->i = v1->i->proximo;
  }

  i = v3->n;
  
  for(int k = 0; k < v2->N; k++) {
    if(v2->i->conteudo != NULL) {
      AtribuirElementoNaPosicaoI_esima(v3, k + i, v2->i->conteudo);
    }
  
    v2->i = v2->i->proximo;
  }
  
  OrdenaVetor(v3);

  return v3;
}