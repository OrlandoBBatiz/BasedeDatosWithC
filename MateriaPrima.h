#ifndef MATERIA_PRIMA_H_
#define MATERIA_PRIMA_H_
#include "estructuras.h"

MateriaPrima *crearNodo(int id, char descripcionmateria[], float cantidad);
MateriaPrima *agregarMateriaPrima(MateriaPrima *materiaPrima, char descripcionmateria[], float cantidad);
void listarMateriasPrimas(MateriaPrima *materiaPrima);
MateriaPrima *modificarMateriaPrima(MateriaPrima *materiaPrima, int id_materiaprima);
MateriaPrima *eliminarMateriaPrima(MateriaPrima *materiaPrima, int id_materiaprima);


#endif // _Funciones_
