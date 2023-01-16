#ifndef PRODUCTO_H_
#define PRODUCTO_H_
#include "estructuras.h"

Producto *crearNodoProducto(int id, char descripcionproducto[]);
Producto *agregarProducto(CelulaManufactura *manufactura, char descripcionproducto[]);
void listarProductos(CelulaManufactura *manufactura);
Producto *seleccionarProducto(CelulaManufactura *manufactura, int id_producto);
Producto *eliminarProducto(CelulaManufactura *manufactura, int id_producto);

#endif // _Funciones_

