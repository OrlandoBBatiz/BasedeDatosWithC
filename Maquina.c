#include "Maquina.h"
#include "MateriaPrima.h"
#include "Producto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Maquina *CrearNodoMaquina(int id, char descripcion[]){
    Maquina *nuevo = (Maquina *)malloc(sizeof(Maquina));
    int opcion=1;

    nuevo->producto=NULL;
    nuevo->id_maquina = id;
    strcpy(nuevo->nombre, descripcion);
    while(opcion==1){
      if(opcion==1){
        printf("\nProductos de la maquina: \n\n");
        nuevo->producto = agregarProducto(nuevo->producto);
        printf("Desea agregar producto a la maquina? (1)Si (2)No: ");
        scanf("%d", &opcion);
      }
    }
    nuevo->apSiguiente = NULL;
    return nuevo;
}
Maquina *agregarMaquina(Maquina *apMaquina){
    Producto *nuevo;
    Producto *aux;
    int id;
    char descripcion[20];

    aux = apMaquina;
    if(aux == NULL){
        id = 1;
    }
    else{
        while (aux->apSiguiente != NULL) {
            aux = aux->apSiguiente;
        }
        id = aux->id_maquina + 1;
    }
    printf("Nombre Maquina: ");
    fflush(stdin);
    fgets(descripcion, 20, stdin);
    fflush(stdin);
    nuevo = CrearNodoMaquina(id, descripcion);
    aux = apMaquina;
    if(aux == NULL){
        apMaquina = nuevo;
    }
    else{
        while (aux->apSiguiente != NULL) {
            aux = aux->apSiguiente;
        }
        aux->apSiguiente = nuevo;
    }
    printf("Maquina agregada exitosamente.\n");
    getch();
    return apMaquina;
}
void *seleccionarMaquina(Maquina *apMaquina, int id_maquina){
    Maquina *aux;
    aux = apMaquina;
    while(aux != NULL && aux->id_maquina != id_maquina){
        aux = aux->apSiguiente;
    }

    if(aux == NULL){
        printf("Maquina no encontrada.\n");
        getch();
        return NULL;
    }
    else{
        printf("Id Maquina\tNombre");
        printf("\n--------------------------------------------\n");
        printf("%d\t%s", aux->id_maquina, aux->nombre);
        printf("Productos: \n");
        listarProductos(aux->producto);
        
    }
    getch();
}
void listarMaquina(Maquina *apMaquina){
    Maquina *aux;
    Maquina = apMaquina;

    if(aux == NULL){
        printf("No hay maquinas registradas.\n");
    }
    else{
        printf("Id Maquina\tNombre");
        while(aux != NULL){
            printf("\n--------------------------------------------\n");
            printf("%d\t%s", aux->id_maquina, aux->nombre);
            printf("Productos: \n");
            listarProductos(aux->producto);
            aux = aux->apSiguiente;
        }
    }
}
Maquina *eliminarMaquina(Maquina *apMaquina, int id_maquina){
    Maquina *aux;
    Maquina *anterior;
    aux = apMaquina;
    anterior = NULL;

    while(aux != NULL && aux->id_maquina != id_maquina){
        anterior = aux;
        aux = aux->apSiguiente;
    }

    if(aux == NULL){
        printf("Maquina no encontrada.\n");
    }
    else{
        if(anterior == NULL){
            apMaquina = aux->apSiguiente;
        }
        else{
            anterior->apSiguiente = aux->apSiguiente;
        }
        free(aux);
        printf("Maquina eliminada exitosamente.\n");
    }
    getch();
    return apMaquina;
}