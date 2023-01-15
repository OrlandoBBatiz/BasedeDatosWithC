#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#define CLEAR "cls"


int opcionesMenuPrincipal();

CelulaManufactura *manufactura;
//manufactura.producto = NULL;
//manufactura.materiaprima = NULL;
//manufactura.maquina = NULL;

//Men� principal

int main(){

    int opcionMP;
    int opcionMateriaPrima;
    manufactura->materiaPrima = NULL;
    manufactura->producto = NULL;
    manufactura->maquina = NULL;
        do{
        system(CLEAR);
            printf("=============MANUFACTURA=============\n\n");
            printf("Menu Principal\n");
            printf("1. Materia Prima\n");
            printf("2. Productos\n");
            printf("3. Maquinas\n");
            printf("4. Salir\n");
            print("Seleccione una opcion (1-4): ");
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
                    manufactura->materiaPrima = agregarMateriaPrima(manufactura);
                    break;
                case 2:
                    manufactura->materiaPrima = modificarMateriaPrima(manufactura);
                    break;
                case 3:
                    manufactura->materiaPrima = eliminarMateriaPrima(manufactura);
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

