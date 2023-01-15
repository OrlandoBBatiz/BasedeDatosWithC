
typedef struct{
  int id_materiaprima;
  char descripcionmateria[50];
  float cantidad;
  struct materiaprima *apSiguiente;
} MateriaPrima;

typedef struct{
  int id_producto;
  char descripcionproducto[20];
  struct producto *apSiguiente;
} Producto;

typedef struct{
  int id_maquina;
  char nombre[20];
  struct maquina *apSiguiente;
} Maquina;

typedef struct{
  Producto *producto;
  MateriaPrima *materiaprima;
  Maquina *maquina;
} Manufactura;


