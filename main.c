#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "MateriaPrima.h"
#include "Producto.h"
#include "Maquina.h"
#define CLEAR "cls"


CelulaManufactura *manufactura;


//Men� principal

int main(){

    int opcionMP=0;
    int opcionMateriaPrima=0;
    int opcionProducto=0;
    int opcionMaquina=0;
    manufactura = (CelulaManufactura *)malloc(sizeof(CelulaManufactura));
    manufactura->materiaPrima = NULL;
    manufactura->producto = NULL;
    manufactura->maquina = NULL;

    int id_materiaprima;
    char descripcionmateria[50];
    float cantidadmateriaprima;

    int id_producto;
    char descripcionproducto[20];

    int id_maquina;
    char descripcionmaquina[20];
        do{
        system(CLEAR);
            printf("=============MANUFACTURA=============\n\n");
            printf("Menu Principal\n");
            printf("1. Materia Prima\n");
            printf("2. Productos\n");
            printf("3. Maquinas\n");
            printf("4. Salir\n");
            printf("Seleccione una opcion (1-4): ");
            scanf("%d", &opcionMP);
            switch(opcionMP)
            {
            case 1:
                printf("Menu Materia Prima\n");
                printf("1. Agregar Materia Prima\n");
                printf("2. Modificar Materia Prima\n");
                printf("3. Eliminar Materia Prima\n");
                printf("4. Listar Materia Prima\n");
                printf("5. Regresar\n");
                printf("Seleccione una opcion (1-5): ");
                scanf("%d", &opcionMateriaPrima);
                switch(opcionMateriaPrima)
                {
                case 1:
                    manufactura->materiaPrima = agregarMateriaPrima(manufactura->materiaPrima);
                    break;
                case 2:
                    printf("Ingrese el ID de la materia prima a modificar: ");
                    scanf("%d", &id_materiaprima);
                    manufactura->materiaPrima = modificarMateriaPrima(manufactura->materiaPrima, id_materiaprima);
                    break;
                case 3:
                    printf("Ingrese el ID de la materia prima a eliminar: ");
                    scanf("%d", &id_materiaprima);
                    manufactura->materiaPrima = eliminarMateriaPrima(manufactura->materiaPrima, id_materiaprima);
                    break;
                case 4:
                    listarMateriasPrimas(manufactura->materiaPrima);
                    break;
                case 5:
                    printf("Regresando al Menú Principal\n\n");
                    break;
                default:
                    printf("Opcion no valida\n\n");
                    break;
                }

                break;

            case 2:
                printf("Menu Productos\n");
                printf("1. Agregar Producto\n");
                printf("2. Seleccionar Producto\n");
                printf("3. Listar Producto\n");
                printf("4. Eliminar Producto\n");
                printf("5. Regresar\n");
                printf("Seleccione una opcion (1-5): ");
                scanf("%d", &opcionProducto);
                switch(opcionProducto)
                {
                    case 1:
                        manufactura->producto = agregarProducto(manufactura->producto);
                        break;
                    case 2:
                        printf("Ingrese el ID del producto a seleccionar: ");
                        scanf("%d", &id_producto);
                        seleccionarProducto(manufactura->producto, id_producto);
                        break;
                    case 3:
                        listarProductos(manufactura->producto);
                        break;
                    case 4:
                        printf("Ingrese el ID del producto a eliminar: ");
                        scanf("%d", &id_producto);
                        manufactura->producto = eliminarProducto(manufactura->producto, id_producto);
                    break;
                    case 5:
                        printf("Regresando al menú principal\n\n");
                        break;
                    default:
                        printf("Opcion no valida\n\n");
                        break;
                
                break;
                }
            case 3:
                printf("Menu Maquinas\n");
                printf("1. Agregar Maquina\n");
                printf("2. Seleccionar Maquina\n");
                printf("3. Listar Maquina\n");
                printf("4. Eliminar Maquina\n");
                printf("5. Regresar\n");
                printf("Seleccione una opcion (1-5): ");
                scanf("%d", &opcionMaquina);
                switch(opcionMaquina)
                {
                    case 1:
                        manufactura->maquina = agregarMaquina(manufactura->maquina);
                        break;
                    case 2:
                        printf("Ingrese el ID de la maquina a seleccionar: ");
                        scanf("%d", &id_maquina);
                        seleccionarMaquina(manufactura->maquina, id_maquina);
                        break;
                    case 3:
                        listarMaquina(manufactura->maquina);
                        break;
                    case 4:
                        printf("Ingrese el ID de la maquina a eliminar: ");
                        scanf("%d", &id_maquina);
                        manufactura->maquina = eliminarMaquina(manufactura->maquina, id_maquina);
                        break;
                    case 5:
                        printf("Regresando al menú principal\n\n");
                        break;
                    default:
                        printf("Opcion no valida\n\n");
                        break;
                
                break;
                }
            case 4:
                printf("Gracias por utilizar el programa...\n\n");
                break;
            default:
                printf("Opcion no valida\n\n");
                break;
            }
        }
        while(opcionMP!=4);
        
    return 0;
}

//---

