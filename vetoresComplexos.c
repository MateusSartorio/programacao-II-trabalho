#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdint.h>
#include "./Headers/complexoNaoFracionario.h"
#include "./Headers/vetoresComplexos.h"

//cria vetor
void CriaVetor_Complexo(VetorComplexo_t* ptrVetor) {
  ptrVetor->primeiro = NULL;
  ptrVetor->ultimo = NULL;
  ptrVetor->i = NULL;
  ptrVetor->N = 0;
  ptrVetor->n = 0;
  int indice = 0;

  while(indice < 100){
    AddUltimaCelula_Complexo(ptrVetor);
    indice++;
    //ptrVector->n = ptrVector->n+1;
    //printf("%d ",indice);  
  }
  
  return;
}

//adciona Celula na ultima posicao
void AddUltimaCelula_Complexo(VetorComplexo_t* ptrvetor){
  CelulaComplexo_t* ptrcelula = (CelulaComplexo_t*) malloc(sizeof(CelulaComplexo_t));

  ptrcelula->conteudo = NULL;
  ptrcelula->proximo = NULL;

  if(ptrvetor->primeiro == NULL){
    ptrvetor->primeiro = ptrcelula;
    ptrcelula->indice = 0;
  } else { 
    ptrcelula->indice = ptrvetor->ultimo->indice + 1;
    ptrvetor->ultimo->proximo = ptrcelula;
    
  }
  //if(ptrvector->ultimo->indice >= ptrvector->N ){
  //  ptrvector->N *= 2;
  //}
  
  (ptrvetor->N)++;
  ptrvetor->ultimo = ptrcelula;
  ptrvetor->i = ptrcelula;
}

//destroi vetor
void DestruirVetor_Complexo(VetorComplexo_t* ptrvetor) {

  if(ptrvetor->primeiro == NULL) {
    printf("O vetor nao foi inicializado");
    return;
  }else{
      while(ptrvetor->N != 0){
      DestroirUltimaCelula_Complexo(ptrvetor);
    }
    ptrvetor->primeiro = NULL;
    ptrvetor->ultimo = NULL;
    ptrvetor->i = NULL;
    //ptrvector = NULL;
    free(ptrvetor);
    ptrvetor = NULL;
  }
}

void DestroirUltimaCelula_Complexo(VetorComplexo_t* ptrvetor) {
  if(ptrvetor->ultimo != NULL){
    if(ptrvetor->ultimo->conteudo != NULL){
      ptrvetor->n -= 1;
    }
    ptrvetor->N -= 1;
    CelulaComplexo_t* aux = (CelulaComplexo_t*) malloc(sizeof(CelulaComplexo_t));
    CelulaComplexo_t* aux2 = (CelulaComplexo_t*) malloc(sizeof(CelulaComplexo_t));
    aux = ptrvetor->ultimo;
    aux2 = RetornaAntesessorElemento_Complexo(ptrvetor->ultimo,ptrvetor);ptrvetor->ultimo = aux2;
    ptrvetor->ultimo->proximo = NULL;
    free(aux);
  }
}

//adciona elemento
void AdicionaElementos_Complexo(VetorComplexo_t* ptrvetor, TIPO_C_PT data) {
  CelulaComplexo_t* celula1 = ptrvetor->primeiro;
  int num = 0;

  for(num = 0; num < ptrvetor->N;num++){
    ptrvetor->n = ptrvetor->n + 1;
    celula1->conteudo = malloc(sizeof(TIPO_C_PT));
    *celula1->conteudo = data;
    
    celula1 = celula1->proximo;
  }

  return;
}

TIPO_C_PT RetornaValorElemento_Complexo(CelulaComplexo_t* celula1){
  return *celula1->conteudo;
}

//atribuir uma cópia do vetor a outro vetor já existente/coipiar 2 no 1
//100%
void CopiaVetor_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t ptrvetor2) {
  int indicador = 0,num = 0;
  CelulaComplexo_t* aux1 = ptrvetor1->primeiro;
  CelulaComplexo_t* aux2 = ptrvetor2.primeiro;
  //vetor 2 > vetor 1 // aumentando vetor 1
  if(ptrvetor2.N > ptrvetor1->N){
      while(ptrvetor2.N > ptrvetor1->N){
        AddUltimaCelula_Complexo(ptrvetor1);
      }
  }
  //copiando
  if(ptrvetor1->N >= ptrvetor2.N ){
    for(num=0; num < ptrvetor2.N; num++){
      
      if(aux2->conteudo != NULL){
        aux1->conteudo = malloc(sizeof(TIPO_C_PT));
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
VetorComplexo_t* CopiaECriaVetor_Complexo(VetorComplexo_t* ptrvetor1) {
int num=0;
//criando vector 
  VetorComplexo_t* ptrvetor2 = (VetorComplexo_t*)malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(ptrvetor2);
//copiando 1 no 2
  CopiaVetor_Complexo(ptrvetor2,*ptrvetor1);
  return ptrvetor2;  
}

//devolver o número atual de elementos;/100%
int RetornaNumElementos_Complexo(VetorComplexo_t* ptrvector){
return ptrvector->n;
}

//devolver o número máximo de elementos;
int RetornaNumMaxElementos_Complexo(VetorComplexo_t* ptrvector){
return ptrvector->N;
}

//devolver o índice do elemento atual;
int RetornaNumIndice_Complexo(CelulaComplexo_t* celula1){
return celula1->indice;
}

//devolver o primeiro elemento e posicionar “i” na primeira posição);
CelulaComplexo_t* RetornaPrimeiroElemento_Complexo(VetorComplexo_t* ptrvetor){
ptrvetor->i = ptrvetor->primeiro;
return ptrvetor->primeiro;
}

//devolver o próximo elemento (posicionando “i” nesta posição);
CelulaComplexo_t* RetornaProximoElemento_Complexo(CelulaComplexo_t* ptrcelula,VetorComplexo_t* ptrvetor){
  ptrcelula = ptrcelula->proximo;
  ptrvetor->i = ptrcelula;
  return ptrcelula;
}

//devolver o elemento anterior (posicionando “i” nesta posição);
CelulaComplexo_t* RetornaAntesessorElemento_Complexo(CelulaComplexo_t* ptrcelula,VetorComplexo_t* ptrvetor){
  CelulaComplexo_t* aux = ptrvetor->primeiro;

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
CelulaComplexo_t* RetornaUltimoElemento_Complexo(VetorComplexo_t* ptrvetor){
  ptrvetor->i = ptrvetor->ultimo;
  return ptrvetor->ultimo;
}

//devolver o elemento da i-ésima posição (lá posicionando o índice “i”);
CelulaComplexo_t* RetornaElementoNaPosicaoI_esima_Complexo(VetorComplexo_t* ptrvetor,int i){
  CelulaComplexo_t* aux = ptrvetor->primeiro;
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
void AtribuirElementoNaPosicaoI_esima_Complexo(VetorComplexo_t* ptrvetor, int i, TIPO_C_PT data) {
  if(i > ptrvetor->N ){
    printf("\nErro: posicao fora do vetor");
    printf("\nVolta Deu Merda\n");
    return;
  }

  CelulaComplexo_t* aux = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor, i);
  aux->conteudo = malloc(sizeof(TIPO_C_PT));
  *aux->conteudo = data;
  ptrvetor->i = aux;

  if(aux != NULL) (ptrvetor->n)++;    

  return ;
}

//atribuir o valor “v” depois da última posição do vetor, incrementando o “número atual de elementos”;
void AdicionarElementoDepoisDoUltimo_Complexo(VetorComplexo_t* ptrvetor,TIPO_C_PT data) {
  int qtd = ptrvetor->N;

  //adcionando celula
  if((ptrvetor->ultimo->indice+1) < ptrvetor->N){
    AddUltimaCelula_Complexo(ptrvetor);  
  }
  else {
    for(int j = 0; j < qtd; j++) {
      AddUltimaCelula_Complexo(ptrvetor);
    }
  }

  int i = (ptrvetor->N/2);
  AtribuirElementoNaPosicaoI_esima_Complexo(ptrvetor,i,data);
  (ptrvetor->n)++;
  ptrvetor->i = ptrvetor->ultimo;

  return;
}

//eliminar a i-ésima posição do vetor, devolvendo o seu valor atual e decrementando o “número atual de elementos”
//100%
TIPO_C_PT EliminarCelulaNaPosicaoI_Complexo(VetorComplexo_t* ptrvetor, int i) {
  CelulaComplexo_t* auxant = malloc(sizeof(CelulaComplexo_t));
  CelulaComplexo_t* aux = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor, i);
  TIPO_C_PT retorno = malloc(sizeof(TIPO_C_PT));
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
    auxant = RetornaAntesessorElemento_Complexo(aux,ptrvetor);
    auxant->proximo = aux->proximo;
    free(aux);
  }

  (ptrvetor->n)--;
  //decrementando o indice dentro da celula
  for(num = num+1;num < ptrvetor->N;num++){
    auxant = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,num);
    auxant->indice = auxant->indice -1;
  }
  //decrementando o Num Max de Elemntos se necessario
  if(ptrvetor->n < ptrvetor->N /4){
    int temp = ptrvetor->N;
      for(int j = 0; j < (temp/2) - 2; j++){
        DestroirUltimaCelula_Complexo(ptrvetor);
        //printf("%d\n", ptrvetor->N);
      }
  } 

  (ptrvetor->N)--;
  return retorno;
}

//eliminar todos os elementos do vetor
void EliminarTodosElementosDoVetor_Complexo(VetorComplexo_t* ptrvetor) {
CelulaComplexo_t* aux = malloc(sizeof(CelulaComplexo_t));
aux = ptrvetor->primeiro;
int i;
  for(i=0;i < ptrvetor->N; i++){
    aux->conteudo = NULL;
    aux = aux->proximo;
  }
  return;
}

void ExibeVetor_Complexo(VetorComplexo_t* ptrvetor){

  if(ptrvetor->primeiro == NULL) {
    printf("Esse vetor nao existe");
    return;
  }

  CelulaComplexo_t* celula1 = ptrvetor->primeiro;
  int num = 0;

  printf("\n");

  while(num < ptrvetor->N) {
    num += 1;
    printf("Celula:%d\tValor:",celula1->indice);
    //  ExibirTipoElemento(ptrvector->i);
    if(celula1->conteudo != NULL)//ExibirTipoElemento(*celula1);
      imprimeComplexoNF(*celula1->conteudo);
    printf("\n");
    celula1 = celula1->proximo;
  }
  return;
}

//obter o valor do elemento de maior módulo existente no vetor (e posicionar o índice atual naquela posição). Em caso de empate, qualquer uma das posições serve;
//100%
TIPO_C_PT RetornandoValorDoItemMaiorModulo_Complexo(VetorComplexo_t* ptrvetor) {
  CelulaComplexo_t* celula1 = ptrvetor->primeiro;
  double compara = 0, compara2;
  TIPO_C_PT retorno ;
    

  for(int i=0;i < ptrvetor->N;i++){
    
    if(celula1->conteudo != NULL){
      compara2 = retornaMagnitudeNF(*celula1->conteudo);
      if(compara2 > compara){
        compara = compara2; 
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
TIPO_C_PT RetornandoValorDoItemMenorModulo_Complexo(VetorComplexo_t* ptrvetor) {
  CelulaComplexo_t* celula1 = ptrvetor->primeiro;
  double compara = 100000000, compara2;
  TIPO_C_PT retorno ;

  for(int i=0;i < ptrvetor->N;i++){
    
    if(celula1->conteudo != NULL){
      compara2 = retornaMagnitudeNF(*celula1->conteudo);
      if(compara2 < compara){
        compara = compara2; 
        ptrvetor->i = celula1;
      }
    celula1 = celula1->proximo;
    }
  }
  retorno = *ptrvetor->i->conteudo;
  return retorno;
}

//determinar quantos dos elementos do vetor têm valor igual a “v” (considerar uma tolerância eps = 0.0001)
//
int RetornandoQtdElementosTemValorV_Complexo(VetorComplexo_t* ptrvetor,TIPO_C_PT v){
CelulaComplexo_t* celula1 = ptrvetor->primeiro;
int retorno = 0;
TIPO_C_PT diferenca;
  for(int i=0; i < ptrvetor->N ;i++){
    if(celula1->conteudo != NULL){
      diferenca = subtraiComplexoNF(*celula1->conteudo,v);   
      //diferenca = celula1->conteudo - v;
      if(verificaSeModuloZeroNF(diferenca) == 1){
        retorno++;
      }
    }
  celula1 = celula1->proximo;
  }
return retorno;
}

//ordenar os elementos do vetor de acordo com uma função “critério de comparação”.
void OrdenaVetor_Complexo(VetorComplexo_t* ptrvetor) {
  VetorComplexo_t* vetor2 =(VetorComplexo_t*) malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(vetor2);
  int criterio,i,j,comparador, num;
  TIPO_C a ;

  CopiaVetor_Complexo(vetor2,*ptrvetor);
  CelulaComplexo_t* aux = ptrvetor->primeiro;
  CelulaComplexo_t* aux2 = vetor2->primeiro;
  
  TIPO_C* d = criaComplexoNF(0, 0);

  for(i = 0; i < ptrvetor->N ;i++){
    aux = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,i);
        for(j=i; j < ptrvetor->N ;j++){
          aux2 = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,j);
          if((*aux2).conteudo != NULL ){
            criterio = CriterioDeOrdenacao_Complexo(*aux,*aux2);
            if(criterio == 1  ){
              if((*aux).conteudo == NULL)
                        *aux->conteudo = criaComplexoNF(0, 0);
              atribuiComplexoNF(d, *aux->conteudo);
              atribuiComplexoNF(*aux->conteudo, *aux2->conteudo);
              atribuiComplexoNF(*aux2->conteudo, d);
            
          }
        }
    }
  }

//tirando os espacos NULL
//aux2 = vetor2->primeiro;
EliminarTodosElementosDoVetor_Complexo(vetor2);
j=0;
int ind;
for(i = 0; i < ptrvetor->N ;i++){
  aux2 = RetornaElementoNaPosicaoI_esima_Complexo(vetor2,i);
    for(j=i;j<ptrvetor->N ;j++){
        aux = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,j);
        if((*aux).conteudo != NULL){
          aux2->conteudo = malloc(sizeof(TIPO_C_PT));
          *aux2->conteudo = *aux->conteudo;
          (*aux).conteudo = NULL;
          j = ptrvetor->N; 
        }
      }
}
CopiaVetor_Complexo(ptrvetor,*vetor2);
DestruirVetor_Complexo(vetor2);
return;
}

//A função “critério” recebe dois elementos do vetor e os compara: se a=b, retorna “0”; se a<b, retorna -1; se a>b, retorna +1. A função “critério” é um dos argumentos deste método de ordenação;

int CriterioDeOrdenacao_Complexo(CelulaComplexo_t celula1,CelulaComplexo_t celula2) {
  if(celula1.conteudo == NULL && celula2.conteudo == NULL) {
    return 0;
  }

  if(celula1.conteudo == NULL){
    return -1;
  }
  if(celula2.conteudo == NULL){
    return 1;
  }
  
  double modulo1 = retornaMagnitudeNF(*celula1.conteudo);
  double modulo2 = retornaMagnitudeNF(*celula2.conteudo);

  //a=b
  if(modulo1 == modulo2) return 0;
  //a>b
  
  if(modulo1 > modulo2) return 1;
  //a=b
  if(modulo1 < modulo2) return -1;

printf("\nErro Na Comparacao\n");
return 111;

}

//intercalar dois vetores ordenados, criando um novo vetor igualmente ordenado, usando uma função “critério” que igualmente um argumento deste método de intercalação;
//somar dois vetores de mesmo tamanho criando um novo vetor (C = A + B);
//100%
VetorComplexo_t* SomarVetorCriandoOutro_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2){
  
  VetorComplexo_t* ptrvetor3 = (VetorComplexo_t*) malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(ptrvetor3);
  
  if(ptrvetor1->N != ptrvetor2->N) {
    printf("Vetores de Tamanhos Defirentes");
    return NULL;
  }
  
   // aumentando vetor 3
  if(ptrvetor3->N < ptrvetor1->N) {
      while(ptrvetor3->N < ptrvetor1->N){
        AddUltimaCelula_Complexo(ptrvetor3);
      }
  }
  
  CelulaComplexo_t* celula1 = ptrvetor1->primeiro;
  CelulaComplexo_t* celula2 = ptrvetor2->primeiro;
  CelulaComplexo_t* celula3 = ptrvetor3->primeiro;
  
  
  for(int i =0;i < ptrvetor1->N;i++){    
    if(celula1->conteudo == NULL && celula2->conteudo != NULL){
     celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
     *celula3->conteudo = *celula2->conteudo;
  }
      
  else if(celula1->conteudo != NULL && celula2->conteudo == NULL){
      celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
      *celula3->conteudo = *celula1->conteudo;
  } 
    else if(celula1->conteudo != NULL && celula2->conteudo != NULL){
      celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
      *celula3->conteudo = somaComplexoNF(*celula1->conteudo, *celula2->conteudo);
    }
   
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    celula3 = celula3->proximo;
  }
  
  return ptrvetor3;
}

//multiplicar dois vetores (“produto interno”) gerando um valor “produto” (c = A . B)
//100%
TIPO_C_PT MultiplicarVetorCriandoValor_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2) {
  TIPO_C_PT soma,aux1,aux2;
  soma = criaComplexoNF(0,0);
  aux1 = criaComplexoNF(0,0);
  aux2 = criaComplexoNF(0,0);

  if(ptrvetor1->N != ptrvetor2->N){
    printf("Vetores de Tamanhos Defirentes");
    return 0;
  }
  
  CelulaComplexo_t* celula1 = ptrvetor1->primeiro;
  CelulaComplexo_t* celula2 = ptrvetor2->primeiro;

  for(int i =0;i < ptrvetor1->N;i++){
    if(celula1->conteudo != NULL && celula2->conteudo != NULL) {

      aux2 = calculaECriaConjugadoNF(*celula2->conteudo);
      aux1 = multiplicaComplexoNF(*celula1->conteudo,aux2);
      soma = acumulaSomaComplexoNF(soma, aux1);
      //((*celula1->conteudo) * (*celula2->conteudo));
    
    }
      
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    
  }
  return soma;
}

//subtrair dois vetores de mesmo tamanho criando um novo vetor (C = A + B);
//100%
VetorComplexo_t* SubtrairVetorCriandoOutro_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2) {
  
  VetorComplexo_t* ptrvetor3 = (VetorComplexo_t*) malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(ptrvetor3);
  
  if(ptrvetor1->N != ptrvetor2->N) {
    printf("Vetores de Tamanhos Defirentes");
    return NULL;
  }
  
   // aumentando vetor 3
  if(ptrvetor3->N < ptrvetor1->N) {
      while(ptrvetor3->N < ptrvetor1->N){
        AddUltimaCelula_Complexo(ptrvetor3);
      }
  }
  
  CelulaComplexo_t* celula1 = ptrvetor1->primeiro;
  CelulaComplexo_t* celula2 = ptrvetor2->primeiro;
  CelulaComplexo_t* celula3 = ptrvetor3->primeiro;
  
  
  for(int i =0;i < ptrvetor1->N;i++){    
    if(celula1->conteudo == NULL && celula2->conteudo != NULL){
     celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
     *celula3->conteudo = *celula2->conteudo;
  }
      
  else if(celula1->conteudo != NULL && celula2->conteudo == NULL){
      celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
      *celula3->conteudo = *celula1->conteudo;
  } 
    else if(celula1->conteudo != NULL && celula2->conteudo != NULL){
      celula3->conteudo = (TIPO_C_PT*)malloc(sizeof(TIPO_C));
      *celula3->conteudo = subtraiComplexoNF(*celula1->conteudo, *celula2->conteudo);
    }
   
    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
    celula3 = celula3->proximo;
  }
  
  return ptrvetor3;
}

//multiplicar um vetor por um escalar, alterando os valores do vetor original (A = k * A)
//100%
void MutiplicarVetorPorEscalar_Complexo(VetorComplexo_t* ptrvetor1,SUBTIPO_C k) {
   CelulaComplexo_t* celula1 = ptrvetor1->primeiro;
   SUBTIPO_C teste;
   for(int i =0; i < ptrvetor1->N ;i++){
      if((*celula1).conteudo != NULL) {
        *celula1->conteudo = multiplicaComplexoPorEscalarNF(*celula1->conteudo, k);
       }
      celula1 = celula1->proximo;
    }
  return ;
}

//acumular um vetor B sobre um outro vetor A do mesmo tamanho, somando os elementos um-a-um (A = A+ B)
void SomarVetorAcumulando_Complexo(VetorComplexo_t* ptrvetor1,VetorComplexo_t* ptrvetor2) {
   CelulaComplexo_t* celula1 = ptrvetor1->primeiro;
   CelulaComplexo_t* celula2 = ptrvetor2->primeiro;
   
  for(int i =0;i < ptrvetor1->N;i++){
    if((*celula1).conteudo != NULL && (*celula2).conteudo != NULL)
       *celula1->conteudo = acumulaSomaComplexoNF(*celula1->conteudo, *celula2->conteudo);
    if((*celula1).conteudo == NULL && (*celula2).conteudo != NULL){
      celula1->conteudo = malloc(sizeof(TIPO_C_PT));
      *celula1->conteudo = *celula2->conteudo;
    }

    celula1 = celula1->proximo;
    celula2 = celula2->proximo;
  }
  
  return ;
}

//determinar a média aritmética dos valores de um vetor (REferencia 4)
TIPO_C_PT RetornarMediaAritimetica_Complexo(VetorComplexo_t* ptrvetor) {
  //long double 
  long double somaReal = 0;
  long double somaImag = 0;

  double media;
  CelulaComplexo_t* celula = (CelulaComplexo_t*) malloc(sizeof(CelulaComplexo_t));

  for(int i = 0; i < ptrvetor->N ;i++){
    celula = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,i);
    if(celula->conteudo != NULL){
      somaImag += *(*celula->conteudo)->imag;
      somaReal += *(*celula->conteudo)->real;
    }
  }

  somaReal = somaReal / ptrvetor->n;
  somaImag = somaImag / ptrvetor->n;

  TIPO_C_PT c = criaComplexoNF(somaReal, somaImag);

  return c;
}

//determinar a variância dos valores de um vetor
TIPO_C_PT RetornaVariaciaDosValores_Complexo(VetorComplexo_t* ptrvetor) {  
  TIPO_C_PT variancia = criaComplexoNF(0, 0);
  TIPO_C_PT soma = criaComplexoNF(0, 0);
  TIPO_C_PT media = criaComplexoNF(0,0);
  TIPO_C_PT aux = criaComplexoNF(0,0);
  TIPO_C_PT aux2 = criaComplexoNF(0,0);


  media = RetornarMediaAritimetica_Complexo(ptrvetor);
  CelulaComplexo_t* celula = (CelulaComplexo_t*) malloc(sizeof(CelulaComplexo_t));

  for(int i = 0; i < ptrvetor->N; i++) {
    celula = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,i);
    if((*celula).conteudo != NULL){
      
      aux = subtraiComplexoNF(*(*celula).conteudo, media);
      aux2 = multiplicaComplexoNF(aux,aux);
      soma = acumulaSomaComplexoNF(soma,aux2);
    }
  }

  variancia = multiplicaComplexoPorEscalarNF(soma, 1 / ( (double) ptrvetor->n - 1) );

  destroiComplexoNF(media);
  destroiComplexoNF(soma);
  destroiComplexoNF(aux);
  destroiComplexoNF(aux2);

  return variancia;
}

//determinar o desvio padrão dos valores de um vetor (raiz quadrada da variância)
TIPO_C_PT RetornaDesvioPadrao_Complexo(VetorComplexo_t* ptrvetor) {
  TIPO_C_PT variancia = criaComplexoNF(0,0);
  variancia = RetornaVariaciaDosValores_Complexo(ptrvetor);
  
  TIPO_C_PT desvio = criaComplexoNF(0,0);
  desvio = raizComplexoNF(variancia);

  destroiComplexoNF(variancia);
  return desvio; 
}

//determinar a mediana dos valores de um vetor (o valor que separa os 50% maiores dos 50% menores
TIPO_C_PT RetornaMedianaDosValores_Complexo(VetorComplexo_t* ptrvetor) {
  TIPO_C_PT mediana;  

  OrdenaVetor_Complexo(ptrvetor);
  CelulaComplexo_t* celula1 = malloc(sizeof(CelulaComplexo_t));
  CelulaComplexo_t* celula2 = malloc(sizeof(CelulaComplexo_t));

  if(ptrvetor->n % 2 == 0){
    celula1 = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,((ptrvetor->n-1)/2 ));
    celula2 = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,((ptrvetor->n+1)/2 ));
    mediana = somaComplexoNF(*celula1->conteudo,*celula2->conteudo);
    mediana = multiplicaComplexoPorEscalarNF(mediana, 1/2.0);
  } else{
    celula1 = RetornaElementoNaPosicaoI_esima_Complexo(ptrvetor,((ptrvetor->n)/2 ));
    mediana = *celula1->conteudo;
  }

  free(celula1);
  free(celula2);

  return mediana;
}

VetorComplexo_t* devolveVetorPosicoesElementosV_Complexo(VetorComplexo_t* ptrvetor,TIPO_C_PT v){
  VetorComplexo_t* vetor = malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(vetor);

  CelulaComplexo_t* celula1 = ptrvetor->primeiro;
  int retorno = 0;
  TIPO_C_PT diferenca;

  for(int i=0; i < ptrvetor->N ;i++){
    if(celula1->conteudo != NULL){
      diferenca = subtraiComplexoNF(*celula1->conteudo,v);   
      if(verificaSeModuloZeroNF(diferenca) == 1){
        TIPO_C_PT indice = criaComplexoNF(celula1->indice, 0);
        retorno++;
        AtribuirElementoNaPosicaoI_esima_Complexo(vetor, retorno - 1, indice);
      }
    }
  celula1 = celula1->proximo;
  }

  return vetor;
}


VetorComplexo_t* intercalaVetoresOrdenados_Complexo(VetorComplexo_t* v1, VetorComplexo_t* v2) {
  VetorComplexo_t* v3 = malloc(sizeof(VetorComplexo_t));
  CriaVetor_Complexo(v3);

  v1->i = v1->primeiro;
  v2->i = v2->primeiro;

  int i = 0;


  for(int j = 0; j < v1->N; j++) {
    if(v1->i->conteudo != NULL) {
      AtribuirElementoNaPosicaoI_esima_Complexo(v3, j, *v1->i->conteudo);
    }
    
    v1->i = v1->i->proximo;
  }

  i = v3->n;
  
  for(int k = 0; k < v2->N; k++) {
    if(v2->i->conteudo != NULL) {
      AtribuirElementoNaPosicaoI_esima_Complexo(v3, k + i, *v2->i->conteudo);
    }
  
    v2->i = v2->i->proximo;
  }
  
  OrdenaVetor_Complexo(v3);

  return v3;
}