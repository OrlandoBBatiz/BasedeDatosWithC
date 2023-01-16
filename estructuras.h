#ifndef ESTRUCTURA_H_
#define ESTRUCTURA_H_

typedef struct MateriaPrima{
  int id_materiaprima;
  char descripcionmateria[50];
  float cantidad;
  struct MateriaPrima *apSiguiente;
} MateriaPrima;

typedef struct Producto{
  int id_producto;
  char descripcionproducto[20];
  struct MateriaPrima *materiaPrima;
  struct Producto *apSiguiente;
} Producto;

typedef struct Maquina{
  int id_maquina;
  char nombre[20];
  struct Producto *producto;
  struct Maquina *apSiguiente;
} Maquina;

typedef struct CelulaManufactura{
  struct Producto *producto;
  struct MateriaPrima *materiaPrima;
  struct Maquina *maquina;
} CelulaManufactura;

#endif /* ESTRUCTURA_H_ */
