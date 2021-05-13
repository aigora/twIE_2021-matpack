#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calculadora.h"

//Esta estructura define una condición del tipo <=, <, >=, > o =.
typedef struct
{
    int con;
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
    char funcion[51];
    float x;

    scanf("%50s",funcion);
    scanf("%f",&x);

    //calc_imagen(funcion,x);
    printf("%f",calc_imagen(funcion,x));
    return 0;
}
