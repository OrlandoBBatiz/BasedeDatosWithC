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

int opcionesMenuPrincipal()
{
    int opcion;
    fflush(stdin);
    printf("1. Materia Prima\n\n");
    printf("2. Productos\n\n");
    printf("3. Maquinas\n\n");
    printf("4. Salir\n\n");
    printf("Seleccione una opcion(1-4): ");
    scanf("%d",&opcion);
    while(opcion<0&&opcion>4)
    {
        printf("\n\nHas ingresado una opcion no valida!\n\n");
        printf("1. Materia Prima\n\n");
    	printf("2. Productos\n\n");
    	printf("3. Maquinas\n\n");
        printf("Opcion (1 / 2 / 3  ): ");
        scanf("%d",&opcion);
    }
    return opcion;
}

//Men� principal

int main()
{
int opcion;
    do{

    system(CLEAR);
        printf("MANUFACTURA\n\n");
        opcion=opcionesMenuPrincipal();
        switch(opcion)
        {
        case 1:
            menuMateriaPrima();
            break;

        case 2:
            menuProductos();
            break;

        case 3:
            menuMaquinas();
            break;

        case 4:
            printf("Gracias por utilizar el programa\n\n");
	        break;
        default:
            printf("Opcion no valida\n\n");
            break;
	    }
    }
	while(opcion!=4);
	return 0;
}

//---

int opcionesMateriaPrima()
{
    fflush(stdin);
    int opcion;
    printf("1. Agregar Materia prima\n");
    printf("2. Modificar Materia prima\n");
    printf("3. Eliminar Materia prima\n");
    printf("4. Listar Materias primas\n");
    printf("5. Regresar\n");
    printf("Seleccione una opcion (1-5): ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>5)
    {
        fflush(stdin);
        printf("\n\nHas ingresado una opcion invalida!\n\n");
        printf("1. Agregar Materia prima\n\n");
    	printf("2. Modificar Materia prima\n\n");
    	printf("3. Eliminar Materia prima\n\n");
        printf("4. Listar Materias primas");
        printf("Opcion (1 - 5): ");
    }
    system(CLEAR);
    return opcion;
}

void menuMateriaPrima()
{
    int opcion;
    do
    {
        system(CLEAR);
        printf("MENU MATERIA PRIMA\n\n");
        opcion=opcionesMateriaPrima();
        switch(opcion)
        {
        case 1:
            agregarMateriaPrima();
            break;

        case 2:
            modificarMateriaPrima();
            break;

        case 3:
            eliminarMateriaPrima();
            break;

        case 4:
            listarMateriasPrimas();
            break;

        case 5:
            break;
        }

        system(CLEAR);
    }
    while(opcion!=5);

}

//---

int opcionesProductos()
{
    fflush(stdin);
    int opcion;
    printf("1. Agregar Producto\n");
    printf("2. Seleccionar Producto\n");
    printf("3. Listar Producto\n");
    printf("4. Eliminar Producto\n");
    printf("5. Regresar\n");
    printf("Seleccione una opcion (1-5): ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>5)
    {
        fflush(stdin);
        printf("\n\nHas ingresado una opcion invalida\n\n");
        printf("1. Agregar Producto\n\n");
    	printf("2. Seleccionar Producto\n\n");
    	printf("3. Listar Producto\n\n");
        printf("4. Eliminar Producto");
        printf("Opcion (1 - 4): ");
    }
    system(CLEAR);
    return opcion;
}

void menuProductos()
{
    int opcion;
    do
    {
        system(CLEAR);
        printf("MENU PRODUCTOS\n\n");
        opcion=opcionesProductos();
        switch(opcion)
        {
        case 1:
            agregarProducto();
            break;

        case 2:
            seleccionarProducto();
            break;

        case 3:
            listarProductos();
            break;

        case 4:
            eliminarProducto();
            break;

        case 5:
            break;
        }

        system(CLEAR);
    }
    while(opcion!=5);

}

//---

int opcionesMaquinas()
{
    fflush(stdin);
    int opcion;
    printf("1. Agregar Maquina\n");
    printf("2. Seleccionar Maquina\n");
    printf("3. Listar Maquina\n");
    printf("4. Eliminar Maquina\n");
    printf("5. Regresar\n");
    printf("Seleccione una opcion (1-5): ");
    scanf("%d",&opcion);
    while(opcion<0||opcion>5)
    {
        fflush(stdin);
        printf("\n\nHas ingresado una opcion invalida\n\n");
        printf("1. Agregar Maquina\n\n");
    	printf("2. Seleccionar Maquina\n\n");
    	printf("3. Listar Maquina\n\n");
        printf("4. Eliminar Maquina");
        printf("Opcion (1 - 4): ");
    }
    system(CLEAR);
    return opcion;
}

void menuMaquinas()
{
    int opcion;
    do
    {
        system(CLEAR);
        printf("MENU MAQUINAS\n\n");
        opcion=opcionesMaquinas();
        switch(opcion)
        {
        case 1:
            agregarMaquina();
            break;

        case 2:
            seleccionarMaquina();
            break;

        case 3:
            listarMaquinas();
            break;

        case 4:
            eliminarMaquina();
            break;

        case 5:
            break;
        }

        system(CLEAR);
    }
    while(opcion!=5);

}
