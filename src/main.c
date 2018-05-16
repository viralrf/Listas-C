#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple.h"
#include "doble.h"
#include "circular.h"

int main(){

    CIRCULAR *circular = NULL;
    DOBLE *doble = NULL;
    SIMPLE *simple = NULL;

    int opc;
    int cont = 0;

    cargarSimple(&simple);
    cargarDoble(&doble);
    cargarCircular(&circular);

    while(cont==0){

        menuBase();
        printf("Elija su opcion\n");
        scanf("%i",&opc);
        fflush(stdin);

        switch(opc){

            case 1: menuSimple(&simple);
                    break;
            case 2: menuDoble(&doble);
                    break;
            case 3: menuCircular(&circular);
                    break;
            case 4: cont=1;
                    break;
            default: printf("Opcion incorrecta\n");
                    break;
        }

    }

}

void menuBase(){

    system("cls");
    printf("1 - Lista Simple\n");
    printf("2 - Lista Doble\n");
    printf("3 - Lista Circular\n");
    printf("4 - SALIR\n");
    printf("------------------\n");
}

void menuSimple(SIMPLE **simple){

    int opc;
    int cont = 0;
    while(cont==0){

        system("cls");
        printf("1 - Agregar Simple\n");
        printf("2 - Mostrar Simple\n");
        printf("3 - Eliminar Simple\n");
        printf("4 - Modificar Simple\n");
        printf("5 - Guardar\n");
        printf("6 - NADA\n");
        printf("------------------\n");
        printf("Elija su opcion\n");

        scanf("%i",&opc);
        fflush(stdin);

        switch(opc){
            case 1: agregarSimple(simple);
                    break;
            case 2: system("cls");
                    mostrarSimple(*simple);
                    getchar();
                    break;
            case 3: borrarSimple(simple);
                    //getchar();
                    break;
            case 4: modificarSimple(*simple);
                    break;
            case 5: guardarSimple(*simple);
                    break;
            case 6: cont = 1;
                    break;
            default: printf("Opcion incorrecta\n");
                    break;
        }

    }


}

void menuDoble(DOBLE **doble){

    int opc;
    int cont = 0;
    while(cont==0){

        system("cls");
        printf("1 - Agregar Doble\n");
        printf("2 - Mostrar Doble\n");
        printf("3 - Eliminar Doble\n");
        printf("4 - Modificar Doble\n");
        printf("5 - Guardar\n");
        printf("6 - NADA\n");
        printf("------------------\n");
        printf("Elija su opcion\n");

        scanf("%i",&opc);
        fflush(stdin);

        switch(opc){
            case 1: agregarDoble(doble);
                    break;
            case 2: system("cls");
                    mostrarDoble(*doble);
                    getchar();
                    break;
            case 3: borrarDoble(doble);
                    //getchar();
                    break;
            case 4: modificarDoble(*doble);
                    break;
            case 5: guardarDoble(*doble);
                    break;
            case 6: cont = 1;
                    break;
            default: printf("Opcion incorrecta\n");
                    break;
        }

    }


}

void menuCircular(CIRCULAR **circular){

    int opc;
    int cont = 0;
    while(cont==0){

        system("cls");
        printf("1 - Agregar Circular\n");
        printf("2 - Mostrar Circular\n");
        printf("3 - Eliminar Circular\n");
        printf("4 - Modificar Circular\n");
        printf("5 - Guardar\n");
        printf("6 - NADA\n");
        printf("------------------\n");
        printf("Elija su opcion\n");

        scanf("%i",&opc);
        fflush(stdin);

        switch(opc){
            case 1: agregarCircular(circular);
                    break;
            case 2: system("cls");
                    mostrarCircular(*circular);
                    getchar();
                    break;
            case 3: borrarCircular(circular);
                    //getchar();
                    break;
            case 4: modificarCircular(*circular);
                    break;
            case 5: guardarCircular(*circular);
                    break;
            case 6: cont = 1;
                    break;
            default: printf("Opcion incorrecta\n");
                    break;
        }

    }


}

