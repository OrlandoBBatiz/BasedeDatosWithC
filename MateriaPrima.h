#ifndef _Funciones_
#define _Funciones_
#include "estructuras.h"

MateriaPrima *crearNodo(int id, char descripcionmateria[], float cantidad);
MateriaPrima *agregarMateriaPrima(CelulaManufactura *manufactura, char descripcionmateria[], float cantidad);
void listarMateriasPrimas(CelulaManufactura *manufactura);
MateriaPrima *modificarMateriaPrima(CelulaManufactura *manufactura, int id_materiaprima);
MateriaPrima *eliminarMateriaPrima(CelulaManufactura *manufactura, int id_materiaprima);


#endif // _Funciones_
