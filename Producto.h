#ifndef _Funciones_
#define _Funciones_
#include "estructuras.h"

Producto *crearNodoProducto(int id, char descripcionproducto[]);
Producto *agregarProducto(CelulaManufactura *manufactura);
void listarProductos(CelulaManufactura *manufactura);
Producto *seleccionarProducto(CelulaManufactura *manufactura);
Producto *eliminarProducto(CelulaManufactura *manufactura);

#endif // _Funciones_

