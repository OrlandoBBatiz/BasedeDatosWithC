#include "MateriaPrima.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

MateriaPrima *crearNodo(int id, char decripcionmateria[], float cantidad){
  MateriaPrima *nuevo; 
  nuevo = malloc(sizeof(MateriaPrima));
  if (nuevo == NULL) {
    printf("Error al reservar memoria.\n");
    return;
  }
  strcpy(nuevo->descripcionmateria, decripcionmateria);
  nuevo->cantidad = cantidad;
  nuevo->apSiguiente = NULL;
  return nuevo;
}

MateriaPrima *agregarMateriaPrima(CelulaManufactura *manufactura, char descripcionmateria[], float cantidad)
 {
  MateriaPrima *nuevo; 
  MateriaPrima *aux;
  int id;

  aux = manufactura->materiaPrima;
  if(aux == NULL){
    id = 1;
  }
  else{
    while (aux->apSiguiente != NULL) {
    aux = aux->apSiguiente;
  }
  id = aux->id_materiaprima + 1;
  }
  
  nuevo = crearNodo( id, descripcionmateria, cantidad);
  
  aux = manufactura->materiaPrima;
  if(aux == NULL){
    manufactura->materiaPrima = nuevo;
  }
  else{
    while (aux->apSiguiente != NULL) {
      aux = aux->apSiguiente;
    }
    aux->apSiguiente = nuevo;
  }

  printf("Materia Prima dada de alta correctamente.\n");
  getch();
}

void listarMateriasPrimas(CelulaManufactura *manufactura) {
  // Recorre la lista de materias prima e imprime los datos de cada una
  MateriaPrima *aux = manufactura->materiaPrima;
  print("Id Materia Prima %t Descripcion %t Cantidad");

  while (aux != NULL) {
    printf("ID: %d", aux->id_materiaprima);
    printf("%tDescripcion: %s", aux->descripcionmateria);
    printf("%tCantidad: %f", aux->cantidad);
  }
}

MateriaPrima *eliminarMateriaPrima(CelulaManufactura *manufactura, int id_materiaprima) {

  // Busca el elemento con el ID especificado
  MateriaPrima *aux = manufactura->materiaPrima;
  MateriaPrima *anterior = NULL;
  while (aux != NULL && aux->id_materiaprima != id_materiaprima) {
    anterior = aux;
    aux = aux->apSiguiente;
  }

  // Si se encontr� el elemento, lo elimina de la lista
  if (aux == NULL) {
    printf("Materia prima no encontrada.\n");
  } else {
    if (anterior == NULL) {
      manufactura->materiaPrima = aux->apSiguiente;
    } else {
      anterior->apSiguiente = aux->apSiguiente;
    }
    free(aux);
    printf("Materia prima eliminada correctamente.\n");
  }
  getch();
}

MateriaPrima *modificarMateriaPrima(CelulaManufactura *manufactura, int id_materialprima) {
 

  // Busca el elemento con el ID especificado
  MateriaPrima *aux;
  aux = manufactura->materiaPrima;
  while (aux != NULL && aux->id_materiaprima != id_materialprima) {
    aux = aux->apSiguiente;
  }

  // Si se encontr� el elemento, pide al usuario que ingrese los nuevos datos
  if (aux == NULL) {
    printf("Materia prima no encontrada.\n");
  } else {
    printf("Ingresa los nuevos datos de la materia:\n");
    printf("Descripcion: ");
    fflush(stdin);
    fgets(aux->descripcionmateria, 50, stdin);
    fflush(stdin);
    printf("Cantidad: ");
    scanf("%d", &aux->cantidad);

    printf("Materia prima modificada correctamente.\n");
  }
  getch();
}
