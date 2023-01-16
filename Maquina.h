#ifndef MAQUINA_H
#define MAQUINA_H
#include "estructuras.h"

Maquina *CrearNodoMaquina(int id, char descripcion[]);
Maquina *agregarMaquina(Maquina *apMaquina);
void *seleccionarMaquina(Maquina *apMaquina, int id_maquina);
void listarMaquina(Maquina *apMaquina);
Maquina *eliminarMaquina(Maquina *apMaquina, int id_maquina);
