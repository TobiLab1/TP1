#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    articulos_t articulos[CANT_ARTICULOS];
    int cantidad_articulos = 0;
    int opcion = 1;
    char descripcion[90];
    int index, sucursal;

    inicializar_articulos(articulos, CANT_ARTICULOS);

    printf("Bienvenido al Final de Informatica I (Refaccionado)\n");

    while (opcion == 1) {
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", descripcion);

        index = buscar_o_agregar_articulo(articulos, &cantidad_articulos, descripcion);
        printf("Articulo: %s - Indice: %d\n", descripcion, index);

        printf("Para que sucursal? (1-3): ");
        scanf("%d", &sucursal);

        if (sucursal >= 1 && sucursal <= 3) {
            cargar_cantidad(articulos, index, sucursal);
        } else {
            printf("Sucursal invalida\n");
        }

        printf("Desea ingresar otro articulo? (1-Si, 2-No): ");
        scanf("%d", &opcion);
    }

    calcular_total(articulos, cantidad_articulos);

    printf("\n### Datos Ingresados ###\n");
    imprimir_tabla(articulos, cantidad_articulos);

    ordenar_por_total(articulos, cantidad_articulos);

    printf("\n### Ordenado por Totales Descendentes ###\n");
    imprimir_tabla(articulos, cantidad_articulos);

    return 0;
}
