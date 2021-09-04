#include <stdio.h>
#include <stdlib.h>

int main()
{

    //setbuf(stdout, NULL);

    int edad, edadMascJoven, edadMasMaterias, cantMaterias, cantMasMaterias,
    legajo, legajoMejorPromFem, legajoMascJovem, legajoMasMaterias;

    float notaPromedio, promedioNotaFem, promedioNotaNoBin, promedioNotaMasc, mejorPromFem;

    char sexo,tipoCursada;

     //contadores y acumuladores
    int acumuladorNotasMasc, acumuladorNotasFem, acumuladorNotasNoBin,contadorMasc,contadorFem, contadorNoBin;

     //flags
    int flagLegajoMasMaterias=0, flagMejorPromFem=0, flagMascLibre=0;

    char continuar='s';


    while(continuar=='s')
    {
        printf("Ingrese numero de legajo \n");
        fflush(stdin);/*fpurge(stdin); MacOS//__fpurge(stdin); Linux*/
        scanf("%d", &legajo);

        printf("\n Indique tipo de cursada: L: libre, P: presencial, R: remota \n");
        fflush(stdin);
        scanf("%c", &tipoCursada);

        printf("\nIndique cantidad de materias (menos de 8, mas de 0) \n");
        scanf("%d", &cantMaterias);
            while(cantMaterias<1 || cantMaterias>8)
            {
                printf("\n Ingrese cantidad de materias correcta (menos de 8, mas de 0) 1\n");
                fflush(stdin);
                scanf("%d", &cantMaterias);

            }

        printf("\nIngrese su sexo \nF: femenino \nM: masculino \nO: no binario \n");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("\n Indique su nota promedio\n");
        scanf("%f", &notaPromedio);

        printf("\n Ingrese su edad (mayor a 17 años)\n");
        fflush(stdin);
        scanf("%d", &edad);
            while(edad>99 || edad<17)
            {
                printf("\n ERROR\n Ingrese su edad nuevamente\n");
                fflush(stdin);
                scanf("%d", &edad);

            }

        switch (sexo){
            case 'f':
                /*El Legajo del mejor promedio femenino.*/
                if(flagMejorPromFem=='0' || notaPromedio>=mejorPromFem){
                    mejorPromFem=notaPromedio;
                    legajoMejorPromFem=legajo;
                    flagMejorPromFem++;
                }
                if(flagLegajoMasMaterias=='0' || cantMaterias>=cantMasMaterias)
                {
                    cantMasMaterias=cantMaterias;
                    edadMasMaterias=edad;
                    legajoMasMaterias=legajo;
                    flagLegajoMasMaterias++;
                }
                acumuladorNotasFem+=notaPromedio;
                contadorFem++;
                break;

            case 'm':
                /*l legajo del más joven de los alumnos masculinos entre los que dan libre.*/
                if(tipoCursada=='l' && edad<=edadMascJoven){
                    legajoMascJovem=legajo;
                    edadMascJoven=edad;
                    flagMascLibre++;
                }
                if(flagLegajoMasMaterias==0 || cantMaterias>cantMasMaterias)
                {
                    cantMasMaterias=cantMaterias;
                    edadMasMaterias=edad;
                    legajoMasMaterias=legajo;
                    flagLegajoMasMaterias++;
                }
                acumuladorNotasMasc+=notaPromedio;
                contadorMasc++;
                break;

            case 'o':
                if(flagLegajoMasMaterias==0 || cantMaterias>cantMasMaterias)
                {
                    cantMasMaterias=cantMaterias;
                    edadMasMaterias=edad;
                    legajoMasMaterias=legajo;
                    flagLegajoMasMaterias=1;
                }
                acumuladorNotasNoBin+=notaPromedio;
                contadorNoBin++;

                break;
                 /*c) El promedio de nota por sexo.
                   d) La edad y legajo del que cursa más materias. (Sin importar su género)*/

        }


        printf("Desea ingresar otro legajo? S/N \n");
        fflush(stdin);
        scanf("%c", &continuar);
    }

    promedioNotaFem=acumuladorNotasFem/contadorFem;
    promedioNotaMasc=acumuladorNotasMasc/contadorMasc;
    promedioNotaNoBin=acumuladorNotasNoBin/contadorNoBin;

if(flagMejorPromFem=='1'){
    printf("\n El legajo del mejor promedio femenino es %d \n", legajoMejorPromFem);
}
else{
    printf("\n No existe mejor promedio femenino \n");
}

if(flagMascLibre=='1'){
    printf("\n El legajo del masculino mas joven que curse libre es %d \n", legajoMascJovem);
}
else{
    printf("\n No existe masculino que curse libre \n");
}

printf("\n El promedio de notas masculinas es %2f \n", promedioNotaMasc);
printf("\n El promedio de notas femeninas es %2f \n", promedioNotaFem);
printf("\n El promedio de notas no binarias es %2f \n", promedioNotaNoBin);

printf("\n El legajo de quien cursa mas materias es %d y su edad es de %d anios", legajoMasMaterias, edadMasMaterias);


    return 0;
}

/* Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: femenino – M: masculino , O: no binario)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)*/
