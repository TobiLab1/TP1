#include <stdio.h>
#include <string.h>
#include "funciones.h"

void inicializar_articulos(articulos_t articulos[], int n) {
    for (int i = 0; i < n; i++) {
        articulos[i].descripcion[0] = '\0';
        for (int j = 0; j < 3; j++) {
            articulos[i].cantidad_sucursal[j] = 0;
        }
        articulos[i].total = 0;
    }
}


int buscar_o_agregar_articulo(articulos_t articulos[], int* cantidad_actual, char descripcion[]) {
    for (int i = 0; i < *cantidad_actual; i++) {
        if (strcmp(articulos[i].descripcion, descripcion) == 0) {
            return i;
        }
    }

    strcpy(articulos[*cantidad_actual].descripcion, descripcion);
    return (*cantidad_actual)++;
}

void cargar_cantidad(articulos_t articulos[], int index, int sucursal) {
    int cantidad;
    printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
    scanf("%d", &cantidad);
    articulos[index].cantidad_sucursal[sucursal - 1] += cantidad;
}

void calcular_total(articulos_t articulos[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        articulos[i].total = 0;
        for (int j = 0; j < 3; j++) {
            articulos[i].total += articulos[i].cantidad_sucursal[j];
        }
    }
}

void imprimir_tabla(articulos_t articulos[], int cantidad) {
    printf("Articulo\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[0],
               articulos[i].cantidad_sucursal[1],
               articulos[i].cantidad_sucursal[2],
               articulos[i].total);
    }
}

void ordenar_por_total(articulos_t articulos[], int cantidad) {
    articulos_t temp;
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (articulos[j].total < articulos[j + 1].total) {
                temp = articulos[j];
                articulos[j] = articulos[j + 1];
                articulos[j + 1] = temp;
            }
        }
    }
}
