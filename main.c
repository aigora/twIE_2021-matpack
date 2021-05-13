#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

//Esta estructura define una condición del tipo <=, <, >=, > o =.
typedef struct
{
    int condic;
    float num;
}condicion;

//Esta estructura almacena información sobre una función.
typedef struct
{
    char forma[51];
    condicion dominio[10];
    condicion recorrido[10];
}funcion;

int main()
{
    return 0;
}
