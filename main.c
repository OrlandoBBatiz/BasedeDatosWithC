#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "MateriaPrima.h"
#define CLEAR "cls"
//#include "Producto.h"

CelulaManufactura *manufactura;


//Men� principal

int main(){

    int opcionMP=0;
    int opcionMateriaPrima=0;
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
                    printf("Descripcion Materia Prima: ");
                    fflush(stdin);
                    fgets(descripcionmateria, 50, stdin);
                    fflush(stdin);
                    printf("Cantidad Materia Prima: ");
                    scanf("%f", &cantidadmateriaprima);
                    manufactura->materiaPrima = agregarMateriaPrima(manufactura->materiaPrima, descripcionmateria, cantidadmateriaprima);
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
                    listarMateriasPrimas(manufactura);
                    break;
                case 5:
                    printf("Salida al Menú Princiap\n\n");
                    break;
                default:
                    printf("Opcion no valida\n\n");
                    break;
                }

                break;

            case 2:
                
                break;

            case 3:
                
                break;

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

