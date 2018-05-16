#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "simple.h"

//Lista simplemente enlazada
struct simple{
    char dato1[20];
    struct simple *next;
};

void agregarSimple(SIMPLE **head){

    SIMPLE *temp = (SIMPLE *) malloc(sizeof *temp);
    SIMPLE *rec = NULL;

    printf("Ingrese el dato SIMPLE\n");
    scanf("%20s",temp->dato1);
    fflush(stdin);

    temp->next = NULL;

    if(*head==NULL){
        *head = temp;
    }else{
        rec = *head;
        while(rec->next != NULL){
            rec = rec->next;
        }
        rec->next = temp;
    }

}

void mostrarSimple(SIMPLE *head){

    SIMPLE *rec = head;
    if(head==NULL){
        printf("La listirijilla SIMPLE esta vacia :o\n");
    }else{
        while(rec!=NULL){
            printf("%s\n",rec->dato1);
            rec = rec->next;
        }
    }

}

void modificarSimple(SIMPLE *head){

    SIMPLE *temp = NULL;
    char dato[20];

    if(head==NULL){
        printf("No hay nada que modificar.. SIMPLE\n");
        getchar();
    }else{
        temp=head;

        printf("Ingrese el dato que desea modificar!!\n");
        scanf("%s",dato);

        while(temp!=NULL && strcmp(dato,temp->dato1)!=0){
            temp = temp->next;
        }

        if(temp!=NULL){
            printf("Ingrese el nombre nuevo!\n");
            printf("%s\n",temp->dato1);
            scanf("%s",temp->dato1);
        }else{
            printf("No existe ese dato!\n");
            getchar();
        }
    }

}

void borrarSimple(SIMPLE **head){

    SIMPLE *temp = NULL;
    SIMPLE *prev = NULL;
    char dato[20];

    if(*head==NULL){
        printf("No hay nada que borrar.. SIMPLE\n");
        getchar();
    }else{
        temp = *head;

        printf("Que dato desea eliminar?\n");
        scanf("%s",dato);
        fflush(stdin);

        if(strcmp((*head)->dato1,dato)==0){
            *head = (*head)->next;
        }else{
            prev = temp;
            while(temp!=NULL && strcmp(temp->dato1,dato)!=0){
                prev = temp;
                temp = temp->next;
            }

            if(temp!=NULL){
                prev->next = temp->next;
                free(temp);
            }else{
                printf("No existe ese dato!\n");
                getchar();
            }
        }
    }

}

//Esta funcion guarda en un archivo SOLO la lista SIMPLE

void guardarSimple(SIMPLE *head){

    SIMPLE *temp = NULL;
    FILE *archivo = fopen("dataSimple.bin","wb");

    temp = head;
    while(temp != NULL){
        fwrite(temp,sizeof *temp,1,archivo);
        temp = temp->next;
    }

    fclose(archivo);
}

void cargarSimple(SIMPLE **head){

    FILE *archivo = fopen("dataSimple.bin","rb");
    int tam = 0;
    int avan = 0;
    SIMPLE *nuevo = NULL;
    SIMPLE *rec = NULL;

    fseek(archivo,0,SEEK_END);
    tam = ftell(archivo);
    fseek(archivo,0,SEEK_SET);

    if(archivo == NULL){
        printf("No se cargo nada\n");
    }else if(tam == 0){
        printf("Archivo Vacio\n");
    }else{
        while(ftell(archivo) != tam){
            nuevo = (SIMPLE *) malloc(sizeof *nuevo);
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
            }
        }
    }
    fclose(archivo);
}
