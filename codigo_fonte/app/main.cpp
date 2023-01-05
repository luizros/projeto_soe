#include <stdio.h>
#include <stdlib.h>
#include "soma.h"
#include "sub.h"
#include "mult.h"
#include "div.h"


int main(void){ 

    int i;
    int j;
    printf("Digite o valor de a: ");
    if(scanf("%d", &i) != 1){
        fputs("Invalid input -- aborting.\n", stderr);
        exit(1);
    };
    printf("Digite o valor de b: ");
    if(scanf("%d", &j)!= 1){
        fputs("Invalid input -- aborting.\n", stderr);
        exit(1);
    }; 
    printf("Resultados: \n");    
    printf("Soma: %d\n", soma(i,j));
    printf("Sub: %d\n", sub(i,j));
    printf("Produto: %d\n", multiplica(i,j));
    printf("Divisão:%d\n", divisao(i,j));
    return 0;
}


