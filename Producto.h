#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include "estructuras.h"

Producto *crearNodoProducto(int id, char descripcionproducto[]);
Producto *agregarProducto(Producto *producto);
void listarProductos(Producto *producto);
void *seleccionarProducto(Producto *producto, int id_producto);
Producto *eliminarProducto(Producto *producto, int id_producto);

#endif // _Funciones_

