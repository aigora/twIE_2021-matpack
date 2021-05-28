#include <stdio.h>
#include <string.h>
#include <math.h>
#include "opciones.h"

//Esta estructura define una condición del tipo <=, <, >=, > o =.
typedef struct
{
    int condic;
    float num;
}condicion;

int main()
{
    primer_menu();
    return 0;
}
