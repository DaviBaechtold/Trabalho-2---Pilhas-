//Davi Baechtold Campos
//Trabalho 2 - Pilhas

/*
Sua  tarefa  será  construir  um  código  capaz de  somar,  item  a  item,  todos os  inteiros  entre  1  e 1.000.000. Existe, pelo menos uma fórmula matemática que pode ser usada para validar o resultado. 

Contudo,  você  deverá  criar  uma  pilha,  armazenar  este  inteiros  nesta  pilha,  depois  percorrer    pilha somando estes valores. A tarefa é para exercitar o uso de pilhas, não da matemática.  
Seu  objetivo  será  medir  o  tempo  para  inserção  de  1.000.000  milhão  de  inteiros  em  uma estrutura  de  dados  e  o  tempo  para  percorrer  e  somar  1.000.000  de  inteiros  em  uma  determinada 
estrutura de dados, e o tempo para garantir que um determinado inteiro já está na pilha. Finalmente você deverá medir estes tempos percorrendo a pilha em dois sentidos. De cima para baixo e de baixo 
para cima. 

Seu resultado será a média dos tempos gastos para as operações citadas acima em, no mímino 50 operações de cada tipo. As saídas apresentadas devem seguir o seguinte padrão: operação: tempo conforme pode ser visto no exemplo a seguir:  

Preenchimento da Pilha: 1.234s 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  clock_t tic = clock();
  
  int isValidaded = 1;
  int n=1000000;
  int arr[n];
  int i,j,k,l,m;
  long int soma = 0;
  long int soma2 = 0;

   for ( i = 0; i < n+1; i++ ) {
      arr[ i ] = i + 1;
   }
  
  clock_t toc = clock();
  printf("Tempo de geracao da lista:   %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  
  for (k = 0 ;k < n; k++) {
    if (k+1 != arr[k]) {
    isValidaded = 0;
    printf("ERRO!");
    }
  }
  clock_t toc5 = clock();
  printf("[UP]Tempo de verificacao:    %f seconds\n", (double)(toc5 - toc) / CLOCKS_PER_SEC);
  
  for (l = n-1 ;l > 1; l--) {
    if (l+1 != arr[l]) {
    isValidaded = 0;
    printf("ERRO!");
    }
  }
  
  clock_t toc2 = clock();
  printf("[DOWN] Tempo de verificacao: %f seconds\n", (double)(toc2 - toc5) / CLOCKS_PER_SEC);
  
  if (isValidaded == 1){
    for(j = 0; j < n; j++) {
      soma = soma + arr[j];
    }
  }
  clock_t toc6 = clock();
  printf("[UP] Tempo para soma:        %f seconds\n", (double)(toc6 - toc2) / CLOCKS_PER_SEC);
  if (isValidaded == 1){
    for(m = n-1; m >= 0; m--) {
      soma2 = soma2 + arr[m];
    }
  }
  clock_t toc3 = clock();
  printf("[DOWN] Tempo para soma:      %f seconds\n", (double)(toc3 - toc6) / CLOCKS_PER_SEC);
  printf("Resultado da soma:\n");
  if (soma == soma2){
    printf("%ld\n",soma); 
  }
  else{
    printf("Erro!");
  }
  clock_t toc4 = clock();
  printf("Tempo total  de execucao:    %f seconds\n", (double)(toc4 - tic) / CLOCKS_PER_SEC);
}
