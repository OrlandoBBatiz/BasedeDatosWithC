#include "Producto.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "MateriaPrima.h"

Producto *crearNodoProducto(int id, char descripcionproducto[])
{
    Producto *nuevo = (Producto *)malloc(sizeof(Producto));
    int opcion=1;

    nuevo->materiaPrima=NULL;
    nuevo->id_producto = id;
    strcpy(nuevo->descripcionproducto, descripcionproducto);
    while(opcion==1){
      if(opcion==1){
        printf("\nMaterias Prima del producto: \n\n");
        nuevo->materiaPrima = agregarMateriaPrima(nuevo->materiaPrima);
        printf("Desea agregar materia prima al producto? (1)Si (2)No: ");
        scanf("%d", &opcion);
      }
    }
    nuevo->apSiguiente = NULL;
    return nuevo;
}	
Producto *agregarProducto(Producto *producto)
 {
  Producto *nuevo;
  Producto *aux;
  int id;
  char descripcionproducto[20];

  aux = producto;
  if(aux == NULL){
    id = 1;
  }
  else{
    while (aux->apSiguiente != NULL) {
    aux = aux->apSiguiente;
  }
  id = aux->id_producto + 1;
  }
  printf("Descripcion Producto: ");
  fflush(stdin);
  fgets(descripcionproducto, 20, stdin);
  fflush(stdin);
  nuevo = crearNodoProducto(id, descripcionproducto);
  aux = producto;
  if(aux == NULL){
    producto = nuevo;
  }
  else{
    while (aux->apSiguiente != NULL) {
      aux = aux->apSiguiente;
    }
    aux->apSiguiente = nuevo;
  }
  printf("Producto dado de alta correctamente.\n");
  getch();
  return producto;
}
void listarProductos(Producto *producto) {
  // Recorre la lista de productos e imprime los datos de cada uno
  Producto *aux;
  aux = producto;

  if (aux == NULL) {
    printf("No hay productos registrados.\n");
  } else {
    printf("Id Producto \t Nombre");
    while(aux != NULL){
      printf("\n--------------------------------------------------\n");
      printf("%d\t%s",aux->id_producto, aux->descripcionproducto);
      printf("Materias Primas:\n");
      while(aux->materiaPrima != NULL){
        printf("\t%d\t%s\t%.2f",aux->materiaPrima->id_materiaprima,aux->materiaPrima->descripcionmateria, aux->materiaPrima->cantidad);
        aux->materiaPrima = aux->materiaPrima->apSiguiente;
      }   
      aux = aux->apSiguiente;
    }
    
  }

  getch();
}
Producto *eliminarProducto(Producto *producto, int id_producto) {
  Producto *aux = producto;
  Producto *anterior = NULL;

  // Busca el elemento con el ID especificado
  while (aux != NULL && aux->id_producto != id_producto) {
    anterior = aux;
    aux = aux->apSiguiente;
  }

  // Si se encontr� el elemento, lo elimina de la lista
  if (aux == NULL) {
    printf("Producto no encontrado.\n");
  } else {
    if (anterior == NULL) {
      producto = aux->apSiguiente;
    } else {
      anterior->apSiguiente = aux->apSiguiente;
    }
    free(aux);
    printf("Producto eliminado correctamente.\n");
  }
  getch();
  return producto;
}
void *seleccionarProducto(Producto *producto, int id_producto) {
  
  // Busca el elemento con el ID especificado
  Producto *aux;
  aux = producto;
  while (aux != NULL && aux->id_producto != id_producto) {
    aux = aux->apSiguiente;
  }

  // Si se encontr� el elemento, lo elimina de la lista
  if (aux == NULL) {
    printf("Producto no encontrado.\n");
  } else {
    printf("Id Producto \t Nombre");
    printf("\n--------------------------------------------------\n");
    printf("%d\t%s",aux->id_producto, aux->descripcionproducto);
    printf("Materias Primas:\n");
    while(aux->materiaPrima != NULL){
      printf("\t%d\t%s",aux->materiaPrima->id_materiaprima,aux->materiaPrima->descripcionmateria);
      aux->materiaPrima = aux->materiaPrima->apSiguiente;
    }   
  }
  getch();
}
