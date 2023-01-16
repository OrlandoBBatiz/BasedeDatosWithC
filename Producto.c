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
Producto *agregarProducto(CelulaManufactura *manufactura, char descripcionproducto[])
 {
  Producto *nuevo;
  Producto *aux;
  int id;

  aux = manufactura->producto;
  if(aux == NULL){
    id = 1;
  }
  else{
    while (aux->apSiguiente != NULL) {
    aux = aux->apSiguiente;
  }
  id = aux->id_producto + 1;
  }
  nuevo = crearNodoProducto(id, descripcionproducto);
  aux = manufactura->producto;
  if(aux == NULL){
    manufactura->producto = nuevo;
  }
  else{
    while (aux->apSiguiente != NULL) {
      aux = aux->apSiguiente;
    }
    aux->apSiguiente = nuevo;
  }
  printf("Producto dado de alta correctamente.\n");
  getch();
}
void listarProductos(CelulaManufactura *manufactura) {
  // Recorre la lista de productos e imprime los datos de cada uno
  Producto *aux;
  aux = manufactura->producto;

  if (aux == NULL) {
    printf("No hay productos registrados.\n");
  } else {
    printf("Id Producto \t Nombre\n");
    while(aux != NULL){
      printf("--------------------------------------------------\n");
      printf("%d\t%s"
      aux = aux->apSiguiente;
    }
    
    }
}
Producto *eliminarProducto(CelulaManufactura *manufactura, int id_producto) {
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

Producto *seleccionarProducto(CelulaManufactura *manufactura, int id_producto) {
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
