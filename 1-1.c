#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
        a) El promedio de los números positivos.
        b) El promedio de los números negativos.*/

    setbuf(stdout, NULL);
    int entrada;
    char continuar;

    int acumuladorPos=0;
    int acumuladorNeg=0;

    int contadorPos=0;
    int contadorNeg=0;

    float promedioPos;
    float promedioNeg;


    while(continuar == 's')
    {

        printf("Ingrese un numero entero: \n");
        scanf("%d", &entrada);

        if(entrada<0){
            acumuladorNeg-=entrada;
            contadorNeg++;

        }
        else if(entrada>0){
            acumuladorPos+=entrada;
            contadorPos++;
        }

        printf("Desea ingresar otro numero? S/N \n");
        fflush(stdin);
        scanf("%c", &continuar);

    promedioNeg= (float)acumuladorNeg/contadorNeg;
    promedioPos= (float)acumuladorPos/contadorPos;


    }

    printf("El promedio de negativos es %2f \n", promedioNeg);
    printf("El promedio de positivos es %2f \n", promedioPos);

    return 0;
}
