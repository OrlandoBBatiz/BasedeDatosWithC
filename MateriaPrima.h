#ifndef MATERIA_PRIMA_H_
#define MATERIA_PRIMA_H_
#include "estructuras.h"

MateriaPrima *crearNodo(int id, char descripcionmateria[], float cantidad);
MateriaPrima *agregarMateriaPrima(CelulaManufactura *manufactura, char descripcionmateria[], float cantidad);
void listarMateriasPrimas(CelulaManufactura *manufactura);
MateriaPrima *modificarMateriaPrima(CelulaManufactura *manufactura, int id_materiaprima);
MateriaPrima *eliminarMateriaPrima(CelulaManufactura *manufactura, int id_materiaprima);


#endif // _Funciones_
