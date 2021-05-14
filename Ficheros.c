#include "ficheros.h"

//Esta función crea un fichero con extensión csv dado un nombre el cual guarda en el fichero Nombres.csv.
//Si el proceso se completa satisfactoriamente devuelve 1, en caso contrario devuelve 0.
int crear_proyecto(char nombre[])
{
    FILE *fich,*nombres;

    strcat(nombre,".csv");

    fich=fopen(nombre,"w");

    if(fich==NULL)
    {
        printf("Error al crear proyecto.");
        return 0;
    }
    fclose(fich);

    nombres=fopen("Nombres.csv","w");

    if(nombres==NULL)
    {
        printf("Error al crear proyecto. Por favor, elimine el fichero generado.");
        return 0;
    }
    fprintf(nombres,"%s\n",nombre);
    fclose(nombres);

    return 1;
}
