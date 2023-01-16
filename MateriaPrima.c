#include "MateriaPrima.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

MateriaPrima *crearNodo(int id, char decripcionmateria[], float cantidad){
  MateriaPrima *nuevo; 
  nuevo = (MateriaPrima*)malloc(sizeof(MateriaPrima));
  if (nuevo == NULL) {
    printf("Error al reservar memoria.\n");
    return;
  }
  nuevo->id_materiaprima = id;
  strcpy(nuevo->descripcionmateria, decripcionmateria);
  nuevo->cantidad = cantidad;
  nuevo->apSiguiente = NULL;
  return nuevo;
}

MateriaPrima *agregarMateriaPrima(MateriaPrima *materiaPrima, char descripcionmateria[], float cantidad)
 {
  MateriaPrima *nuevo; 
  MateriaPrima *aux;
  int id;

  aux = materiaPrima;
  if(aux == NULL){
    id = 1;
  }
  else{
    while (aux->apSiguiente != NULL) {
    aux = aux->apSiguiente;
  }
  id = aux->id_materiaprima + 1;
  }
  
  nuevo = crearNodo(id, descripcionmateria, cantidad);
  
  aux = materiaPrima;
  if(aux == NULL){
    materiaPrima = nuevo;
  }
  else{
    while (aux->apSiguiente != NULL) {
      aux = aux->apSiguiente;
    }
    aux->apSiguiente = nuevo;
  }

  printf("Materia Prima dada de alta correctamente.\n");
  getch();
  return materiaPrima;
}

void listarMateriasPrimas(MateriaPrima *materiaPrima) {
  // Recorre la lista de materias prima e imprime los datos de cada una
  MateriaPrima *aux;
  aux = materiaPrima;
  if(aux == NULL){
    printf("No hay materias primas registradas.\n");
    getch();
    return;
  }
  else{
    printf("Id Materia Prima \t Descripcion \t Cantidad");

    while (aux != NULL) {
      printf("\nID: %d\t%s\t%.2f", aux->id_materiaprima, aux->descripcionmateria, aux->cantidad);
      aux = aux->apSiguiente;
    }
  }
  
  getch();
}

MateriaPrima *eliminarMateriaPrima(MateriaPrima *materiaPrima, int id_materiaprima) {

  // Busca el elemento con el ID especificado
  MateriaPrima *aux = materiaPrima;
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
      materiaPrima = aux->apSiguiente;
    } else {
      anterior->apSiguiente = aux->apSiguiente;
    }
    free(aux);
    printf("Materia prima eliminada correctamente.\n");
  }
  getch();
  return materiaPrima;
}

MateriaPrima *modificarMateriaPrima(MateriaPrima *materiaPrima, int id_materialprima) {
 

  // Busca el elemento con el ID especificado
  MateriaPrima *aux;
  aux = materiaPrima;
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
  return materiaPrima;
}
