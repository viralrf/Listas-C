#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doble.h"

//Lista doblemente enlazada
struct doble{

    char dato2[20];
    struct doble *prev, *next;
};

void agregarDoble(DOBLE **head){

    DOBLE *temp = (DOBLE *) malloc(sizeof *temp);
    DOBLE *rec = NULL;

    printf("Ingrese el dato DOBLE!\n");
    scanf("%s",temp->dato2);
    fflush(stdin);

    temp->next = NULL;

    if(*head==NULL){
        temp->prev = NULL;
        *head = temp;
    }else{
        rec = *head;
        while(rec->next != NULL){
            rec = rec->next;
        }
        temp->prev = rec;
        rec->next = temp;
    }

}

void mostrarDoble(DOBLE *head){

    DOBLE *rec = head;
    if(head==NULL){
        printf("La listirijilla DOBLE esta vacia :o\n");
    }else{
        while(rec!=NULL){
            printf("%s\n",rec->dato2);
            rec = rec->next;
        }
    }

}

void modificarDoble(DOBLE *head){

    DOBLE *temp = NULL;
    char dato[20];

    if(head==NULL){
        printf("No hay nada que modificar.. DOBLE\n");
        getchar();
    }else{
        temp=head;

        printf("Ingrese el dato que desea modificar!!\n");
        scanf("%s",dato);

        while(temp!=NULL && strcmp(dato,temp->dato2)!=0){
            temp = temp->next;
        }

        if(temp!=NULL){
            printf("Ingrese el nombre nuevo!\n");
            printf("%s\n",temp->dato2);
            scanf("%s",temp->dato2);
        }else{
            printf("No existe ese dato!\n");
        }
    }

}

void borrarDoble(DOBLE **head){

    DOBLE *temp = NULL;
    char dato[20];

    if(*head==NULL){
        printf("No hay nada que borrar.. DOBLE\n");
    }else{
        temp = *head;

        printf("Que dato desea eliminar?\n");
        scanf("%s",dato);
        fflush(stdin);

        if(strcmp((*head)->dato2,dato)==0){
            *head = (*head)->next;
        }else{
            while(temp!=NULL && strcmp(temp->dato2,dato)!=0){
                temp = temp->next;
            }

            if(temp!=NULL){
                temp->prev->next = temp->next;
                free(temp);
            }else{
                printf("No existe ese dato!\n");
            }
        }
    }

}


//Esta funcion guarda en un archivo SOLO la lista DOBLE

void guardarDoble(DOBLE *head){

    DOBLE *temp = NULL;
    FILE *archivo = fopen("dataDoble.bin","wb");

    temp = head;
    while(temp != NULL){

        fwrite(temp,sizeof *temp,1,archivo);
        temp = temp->next;
    }

    fclose(archivo);
}

void cargarDoble(DOBLE **head){

    FILE *archivo = fopen("dataDoble.bin","rb");
    int tam = 0;
    int avan = 0;
    DOBLE *nuevo = NULL;
    DOBLE *rec = NULL;

    fseek(archivo,0,SEEK_END);
    tam = ftell(archivo);
    fseek(archivo,0,SEEK_SET);

    if(archivo == NULL){

        printf("No se cargo nada\n");
    }else if(tam == 0){

        printf("Archivo Vacio\n");
    }else{

        while(ftell(archivo) != tam){

            nuevo = (DOBLE *) malloc(sizeof *nuevo);
            fread(nuevo,sizeof *nuevo,1,archivo);
            nuevo->next = NULL;

            if(*head == NULL){

                *head = nuevo;
            }else{

                rec = *head;
                while(rec->next != NULL){
                    rec = rec->next;
                }
                rec->next = nuevo;
                rec->next->prev = rec;

            }

        }
    }

    fclose(archivo);
}
