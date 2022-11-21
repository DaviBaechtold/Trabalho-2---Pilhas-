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