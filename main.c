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
    FILE *pfA1,*pfA2,*pfA3,*pfA4,*pfA5,*pfC1,*pfNombres;
    int E1,E2,ND,Contador,rep=0,V1;
    char nombre[30],nombre1[30],nombre2[30],nombre3[30],nombre4[30],RD,Opcion[100],respuesta2[]="Guardar nueva funcion",respuesta3[]="Calcular imagen",respuesta4[]="Manual",respuesta5[]="Volver",respuesta6[]="Salir",Nueva[50];

    // Abrimos fichero para escritura
    while(rep!=1)
    {
        V1=0;
        rep=0;
        Contador=0;
        printf("Introduzca el numero correspondiente a la opcion que elija:\n");
        printf("1-Crear Proyecto\n2-Mis Proyectos\n3-Manual (Recomendable si es su primera vez con el software)\n4-Salir\n\n");
        scanf(" %i",&E1);
        switch(E1)
        {
            case 1:
                printf("Crear Proyecto:\n\n Nombre del Proyecto: ");
                scanf(" %30[^\n]",nombre);
                strcat(nombre,".txt");
                printf("Numero de decimales:\n\n ");
                scanf("%i",&ND);
                printf("En el caso de que quieras usar angulos,trabajaras con Radianes(R) o Grados(G)?:\n\n*Grados\n*Radianes\n\n ");
                scanf(" %c",&RD);
                pfNombres = fopen("Nombre.txt","a");
                fprintf(pfNombres,"%s,",nombre);
                fclose(pfNombres);

                pfC1 = fopen(nombre,"w");
                fprintf(pfC1, "%s,%c,%i\n",nombre,RD,ND);
                fclose(pfC1);
                break;
            case 2:
                printf("Que archivo qieres abrir?\n\n");
                pfNombres = fopen("Nombre.txt","r");
                fscanf(pfNombres,"%[^,],%[^,],%[^,],%[^,],",nombre1,nombre2,nombre3,nombre4);
                printf("1-%s\n2-%s\n3-%s\n4-%s\n",nombre1,nombre2,nombre3,nombre4);
                fclose(pfNombres);

        scanf("%i",&E2);
        switch(E2)
        {
            case 1:
                pfA1=fopen(nombre1,"a");
                V1=1;
                break;
            case 2:
                pfA2=fopen(nombre2,"a");
                V1=2;
                break;
            case 3:
                pfA3=fopen(nombre3,"a");
                V1=3;
                break;
            case 4:
                pfA1=fopen(nombre1,"a");
                V1=4;
                break;
            case 3:
                printf("Manual:\n\n");
                printf("... Mucho texto ...\n");
                break;
            case 4:
                printf("Ha cerrado el programa, \n\nHasta la proxima!\n\n");
    }
    printf("\n\nMenu de opciones:\n- Guardar nueva funcion:\n- Calcular imagen:\n- Manual:\n- Volver:\n- Salir:\n\n");

    while(Contador!=1)
    {
        scanf(" %29[^\n]",Opcion);
        printf("%s\n\n",Opcion);

        if(strcmp(Opcion, respuesta2) == 0)
        {
            rep=1;
            Contador=1;
            switch(V1)
            {
                case 1:
                    scanf("%50s",Nueva);
                    fprintf(pfA1,"\n%s",Nueva);
                    fclose(pfA1);
                    break;
                case 2:
                    scanf("%50s",Nueva);
                    fprintf(pfA2,"\n%s",Nueva);
                    fclose(pfA2);
                    break;
                case 3:
                    scanf("%50s",Nueva);
                    fprintf(pfA3,"\n%s",Nueva);
                    fclose(pfA3);
                    break;
                case 4:
                    scanf("%50s",Nueva);
                    fprintf(pfA4,"\n%s",Nueva);
                    fclose(pfA4);
                    break;
            }
        }

        if(strcmp(Opcion, respuesta3) == 0)
        {
            rep=1;
            Contador=1;
            printf("Solucion");
        }

        if(strcmp(Opcion, respuesta4) == 0)
        {
            rep=1;
            Contador=1;
            printf("Manual:\n\n");
            printf("... Mucho texto ...\n");
        }
        if(strcmp(Opcion, respuesta5) == 0)
        {
            Contador=1;
        }

        if(strcmp(Opcion, respuesta6) == 0)
        {
            rep=1;
            Contador=1;

            printf("Hasta la proxima!");
        }
    }


    return 0;
}
