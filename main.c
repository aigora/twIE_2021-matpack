#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

//Esta estructura define una condici�n del tipo <=, <, >=, > o =.
typedef struct
{
    int condic;
    float num;
}condicion;

//Esta estructura almacena informaci�n sobre una funci�n.
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
