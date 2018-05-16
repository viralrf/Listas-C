#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "circular.h"

//Lista circular
struct circular{

    char dato3[20];
    struct circular *next;
};

void agregarCircular(CIRCULAR **head){

    CIRCULAR *temp = (CIRCULAR *) malloc(sizeof *temp);
    CIRCULAR *rec = NULL;

    printf("Ingrese el dato CIRCULAR!\n");
    scanf("%s",temp->dato3);
    fflush(stdin);

    temp->next = *head;

    if(*head==NULL){
        temp->next = temp;
        *head = temp;
    }else{
        rec = *head;
        while(rec->next!=*head){
            rec = rec->next;
        }
        rec->next = temp;
    }

}

void mostrarCircular(CIRCULAR *head){

    CIRCULAR *rec = head;
    if(head==NULL){
        printf("La listirijilla CIRCULAR esta vacia :o\n");
    }else{
        printf("%s\n",rec->dato3);
        rec = rec->next;
        while(rec!=head){
            printf("%s\n",rec->dato3);
            rec = rec->next;
        }
    }

}

void modificarCircular(CIRCULAR *head){

    CIRCULAR *temp = NULL;
    char dato[20];

    if(head==NULL){
        printf("No hay nada que modificar.. CIRCULAR\n");
        getchar();
    }else{
        temp=head;

        printf("Ingrese el dato que desea modificar!!\n");
        scanf("%s",dato);

        if(temp==temp->next){
            if(strcmp(temp->dato3,dato)==0){
                printf("Ingrese el nombre nuevo!\n");
                printf("%s\n",temp->dato3);
                scanf("%s",temp->dato3);
            }else{
                printf("No existe ese dato!\n");
            }
        }else{
            temp = temp->next;

            while(temp!=head && strcmp(dato,temp->dato3)!=0){
            temp = temp->next;
        }
            if(temp!=head){
                printf("Ingrese el nombre nuevo!\n");
                printf("%s\n",temp->dato3);
                scanf("%s",temp->dato3);
            }else{
                printf("No existe ese dato!\n");
            }
        }
    }
}

void borrarCircular(CIRCULAR **head){

    CIRCULAR *temp;
    CIRCULAR *prev;
    char dato[20];

    if(*head==NULL){
        printf("No hay nada que borrar.. CIRCULAR\n");
    }else{
        temp = *head;

        printf("Que dato desea eliminar?\n");
        scanf("%s",dato);
        fflush(stdin);

        if(temp==temp->next){

            if(strcmp(temp->dato3,dato)==0){
                *head = NULL;
            }else{
                printf("No existe ese dato!\n");
            }

        }else if(temp!=temp->next && strcmp(temp->dato3,dato)==0){

            prev = temp;
            while(temp->next!=*head){
                temp = temp->next;
            }
            *head = (*head)->next;
            temp->next = *head;
            free(prev);

        }else{

            prev = temp;
            temp = temp->next;
            while(temp!=*head && strcmp(temp->dato3,dato)!=0){
                prev = temp;
                temp = temp->next;
            }

            if(temp!=*head){
                prev->next = temp->next;
                free(temp);
            }else{
                printf("No existe ese dato!\n");
            }
        }

    }

}



//Esta funcion guarda en un archivo SOLO la lista CIRCULAR


void guardarCircular(CIRCULAR *head){

    CIRCULAR *temp = NULL;
    FILE *archivo = fopen("dataCircular.bin","wb");

    temp = head;
    if(temp == NULL){
        fwrite(temp,sizeof *temp,1,archivo);
    }else{

        if(temp == temp->next){
            fwrite(temp,sizeof *temp,1,archivo);
        }else{

            fwrite(temp,sizeof *temp,1,archivo);
            temp = temp->next;

            while(temp != head){
                fwrite(temp,sizeof *temp,1,archivo);
                temp = temp->next;
            }
        }
    }

    fclose(archivo);
}

void cargarCircular(CIRCULAR **head){

    FILE *archivo = fopen("dataCircular.bin","rb");
    int tam = 0;
    int avan = 0;
    CIRCULAR *nuevo = NULL;
    CIRCULAR *rec = NULL;

    fseek(archivo,0,SEEK_END);
    tam = ftell(archivo);
    fseek(archivo,0,SEEK_SET);

    if(archivo == NULL){

        printf("No se cargo nada\n");
    }else if(tam == 0){

        printf("Archivo Vacio\n");
    }else{

        while(ftell(archivo) != tam){

            nuevo = (CIRCULAR *) malloc(sizeof *nuevo);
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

        rec = rec->next;
        rec->next = *head;
    }

    fclose(archivo);
}

