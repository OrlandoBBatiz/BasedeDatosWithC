#include "Producto.h"
#include <string.h>

Producto *crearNodoProducto(int id, char descripcionproducto[])
{
    Producto *nuevo = (Producto *)malloc(sizeof(Producto));
    nuevo->id_producto = id;
    strcpy(nuevo->descripcionproducto, descripcionproducto);
    nuevo->apSiguiente = NULL;
    return nuevo;
}	
Producto *agregarProducto(CelulaManufactura *manufactura)
 {
  Producto *nuevo = (Producto *)malloc(sizeof(Producto));

  // Pide al usuario que ingrese los datos del producto
  printf("Ingresa los datos del producto:\n");
  printf("Ingrese el id del prodcto: ");
  scanf("%d", &nuevo->id_producto);
  printf("Nombre del producto: ");
  scanf("%s", nuevo->descripcionproducto);

  // Enlaza el nuevo elemento al final de la lista
  nuevo->siguiente = NULL;
  if (manufactura->producto == NULL) {
    manufactura->producto = nuevo;
  } else {
    Producto *aux = manufactura->producto;
    while (aux->siguiente != NULL) {
      aux = aux->siguiente;
    }
    aux->siguiente = nuevo;
  }

  printf("Producto dado de alta correctamente.\n");
  getch();
}

void eliminarProducto(Manufactura *manufactura) {
  // Pide al usuario que ingrese el ID del producto a eliminar
  int id;
  printf("Ingresa el ID del producto a eliminar: ");
  scanf("%d", &id);

  // Busca el elemento con el ID especificado
  Producto *aux = manufactura->producto;
  Producto *anterior = NULL;
  while (aux != NULL && aux->id_producto != id) {
    anterior = aux;
    aux = aux->siguiente;
  }

  // Si se encontr� el elemento, lo elimina de la lista
  if (aux == NULL) {
    printf("Producto no encontrado.\n");
  } else {
    if (anterior == NULL) {
      manufactura->producto = aux->siguiente;
    } else {
      anterior->siguiente = aux->siguiente;
    }
    free(aux);
    printf("Producto eliminado correctamente.\n");
  }
  getch();
}

void modificarProducto(Manufactura *manufactura) {
  // Pide al usuario que ingrese el ID del producto a modificar
  int id;
  printf("Ingresa el ID del producto a modificar: ");
  scanf("%d", &id);

  // Busca el elemento con el ID especificado
  Producto *aux = manufactura->producto;
  while (aux != NULL && aux->id_producto != id) {
    aux = aux->siguiente;
  }

  // Si se encontr� el elemento, pide al usuario que ingrese los nuevos datos
  if (aux == NULL) {
    printf("Producto no encontrado.\n");
  } else {
    printf("Ingresa los nuevos datos del producto:\n");
    printf("Descripcion: ");
    scanf("%s", aux->descripcionproducto);

    printf("Producto modificado correctamente.\n");
  }
  getch();
}

