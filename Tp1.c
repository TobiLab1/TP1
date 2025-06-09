/*Una Empresa Registra mensualmente la siguiente información:
Sucursal - entera (1 a 3 ) Articulo - entero (1 a 60) Cantidad - entero Descripción del Artículo - Cadena de caracteres.

Usar un menú para:

A. Cargar las fichas (no se saben cuantas son) teniendo en cuenta cargar las descripciones una sola vez, mostrando en pantalla la misma si ya fue ingresada.

B. Al finalizar el punto 1 emitir un listado ordenado por totales de artiíulo de la siguiente forma:

Ej.

 Articulo       Sucursal 1      Sucursal 2     Sucursal 3     Total
 Martillo          xxx             xxx            xxx          xxx
 Pala              xxx             xxx            xxx          xxx
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2
#define TOTAL 4

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3]; // sucursal 1 2 3    
    int total;
}articulos_t;

int main(int argc, char const *argv[])
{
    Printf("Bienvenido al final de Info 1\n\n");
    return 0;
};
