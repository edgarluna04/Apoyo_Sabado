#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
fue ingresado.*/

    setbuf(stdout, NULL);
    int entrada;
    int max;
    int min;
    int contador=0;
    int ordenIngMax;
    int ordenIngMin;

    while(contador<6)
    {

        printf("Ingrese un numero: \n");
        fflush(stdin);
        scanf("%d", &entrada);

        if(contador==0){
            max=entrada;
            min=entrada;
            ordenIngMax=contador;
            ordenIngMin=contador;
        }
        else if(entrada<min){
                min=entrada;
                ordenIngMin=contador;
        }
        else if(entrada>max){
            max=entrada;
            ordenIngMax=contador;
        }
    contador++;
    }
    printf("El maximo es %d y fue ingresado en el orden numero %d \n", max, ordenIngMax);
    printf("El minimo es %d y fue ingresado en el orden numero %d", min, ordenIngMin);


    return 0;
}
