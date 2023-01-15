#include "MateriaPrima.h"
#include <string.h>


void agregarMateriaPrima(Manufactura *manufactura)
 {
  // Crea un nuevo elemento de la lista de materias prima
  MateriaPrima *nuevo = malloc(sizeof(MateriaPrima));
  if (nuevo == NULL) {
    printf("Error al reservar memoria.\n");
    return;
  }

  // Pide al usuario que ingrese los datos de la materia prima
  printf("Ingresa los datos de la materia prima:\n");
  printf("Ingrese el id de la materia prima: ");
  scanf("%d", &nuevo->id_materiaprima);
  printf("Descripcion de la materia prima: ");
  scanf("%s", nuevo->descripcionmateria);
  printf("Cantidad: ");
  scanf("%d", &nuevo->cantidad);

  // Enlaza el nuevo elemento al final de la lista
  nuevo->siguiente = NULL;
  if (manufactura->materiaprima == NULL) {
    manufactura->materiaprima = nuevo;
  } else {
    MateriaPrima *aux = manufactura->materiaprima;
    while (aux->siguiente != NULL) {
      aux = aux->siguiente;
    }
    aux->siguiente = nuevo;
  }

  printf("Materia Prima dada de alta correctamente.\n");
  getch();
}


void eliminarMateriaPrima(Manufactura *manufactura) {
  // Pide al usuario que ingrese el ID de la materia prima a eliminar
  int id;
  printf("Ingresa el ID de la materia prima a eliminar: ");
  scanf("%d", &id);

  // Busca el elemento con el ID especificado
  MateriaPrima *aux = manufactura->materiaprima;
  MateriaPrima *anterior = NULL;
  while (aux != NULL && aux->id_materiaprima != id) {
    anterior = aux;
    aux = aux->siguiente;
  }

  // Si se encontró el elemento, lo elimina de la lista
  if (aux == NULL) {
    printf("Materia prima no encontrada.\n");
  } else {
    if (anterior == NULL) {
      manufactura->materiaprima = aux->siguiente;
    } else {
      anterior->siguiente = aux->siguiente;
    }
    free(aux);
    printf("Materia prima eliminada correctamente.\n");
  }
  getch();
}

void modificarMateriaPrima(Manufactura *manufactura) {
  // Pide al usuario que ingrese el ID de la materia prima a modificar
  int id;
  printf("Ingresa el ID de la materia prima a modificar: ");
  scanf("%d", &id);

  // Busca el elemento con el ID especificado
  MateriaPrima *aux = manufactura->materiaprima;
  while (aux != NULL && aux->id_materiaprima != id) {
    aux = aux->siguiente;
  }

  // Si se encontró el elemento, pide al usuario que ingrese los nuevos datos
  if (aux == NULL) {
    printf("Materia prima no encontrada.\n");
  } else {
    printf("Ingresa los nuevos datos de la materia:\n");
    printf("Descripcion: ");
    scanf("%s", aux->descripcionmateria);
    printf("Cantidad: ");
    scanf("%d", &aux->cantidad);

    printf("Materia prima modificada correctamente.\n");
  }
  getch();
}
