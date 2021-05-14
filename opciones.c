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
        printf("Error al crear proyecto.\n");
        return 0;
    }
    fclose(fich);

    nombres=fopen("Nombres.txt","a");

    if(nombres==NULL)
    {
        printf("Error al crear proyecto. Por favor, elimine el fichero generado.\n");
        return 0;
    }
    fprintf(nombres,"%s\n",nombre);
    fclose(nombres);

    return 1;
}

//Esta función agrega información a un fichero.
int agreg_info(char nombre[],char contenido)
{
    FILE *fich;

    strcat(nombre,".csv");

    fich=fopen(nombre,"a");

    if(fich==NULL)
    {
        printf("Error al agregar información.\n");
        return 0;
    }
    fprintf(fich,"%s",contenido);
    fclose(fich);

    return 1;
}

//Esta función envia al usuario al primer menú.
void primer_menu()
{
    FILE *config,*nombres;
    int E1,E2,ND,Contador=1,V1,primero=1;
    char RD,caracter,nombre[31];

    printf("Introduzca el numero correspondiente a la opcion que elija:\n");
    printf("1- Crear Proyecto\n2- Mis Proyectos\n3- Manual (Recomendable si es su primera vez con el software)\n4- Salir\n");

    while(1)
    {
        printf("> ");
        scanf(" %i",&E1);
        switch(E1)
        {
            case 1:
                printf("\nIntroduzca el nombre del proyecto: ");
                scanf(" %30[^\n]",nombre);
                printf("Elija el número de decimales a los que se redondeará o se truncará: ");
                scanf("%i",&ND);
                printf("Elija con que unidades unidades de ángulos con las que desea trabajar (radianes(R) o grados(G)): ");
                scanf(" %c",&RD);

                if(crear_proyecto(nombre))
                {
                    config=fopen("Config.csv","a");

                    if(config==NULL)
                    {
                        printf("Error al crear proyecto. Por favor, elimine el fichero generado.\n");
                    }
                    else
                    {
                        fprintf(config, "%s,%c,%i\n",nombre,RD,ND);
                        fclose(config);
                    }
                    segundo_menu(nombre);
                }
                break;
            case 2:
                printf("\nElija el archivo que desee abrir:\n");
                nombres = fopen("Nombres.csv","r");

                if(config==NULL)
                    {
                        printf("Error al abrir el proyecto.\n");
                    }
                else
                {
                    while(fscanf(nombres,"%c",&caracter)!=EOF)
                    {
                        if(primero)
                        {
                            printf("%i- %c",Contador,caracter);
                            primero=0;
                        }
                        else
                        {
                            if(caracter=='\n')
                            {
                                primero=1;
                                ++Contador;
                            }
                            printf("%c",caracter);
                        }
                    }
                    fclose(nombres);
                    segundo_menu(nombre);
                }
            case 4:
                exit(-1);
        }
    }
}

//Esta función envia al usuario al segundo menú.
void segundo_menu(char nombre[])
{
    int i,j=0,fila=0,igualdad=0,prop=1,prop2=1;
    float num;
    char funcion[51],funciones[25][51],nom_fs[25][31],nom_f[31],Opcion[20],respuesta2[]="Guardar nueva funcion",respuesta3[]="Calcular imagen",respuesta4[]="Manual",respuesta5[]="Volver",respuesta6[]="Salir";

    printf("Introduzca el nombre de la opción que elija:\n");
    printf("- Guardar nueva funcion\n- Calcular imagen\n- Manual:\n- Volver\n- Salir\n");
    while(1)
    {
        printf("> ");
        scanf(" %19[^\n]",Opcion);

        if(strcmp(Opcion, respuesta2) == 0)
        {
            printf("Introduzca la expresión de la nueva función: ");
            scanf("%c",funcion);
            printf("Introduzca la expresión de la nueva función: ");
            scanf("%c",funcion);
            strcat(funcion,"\n");
            agreg_info(nombre,funcion);

            for(i=0;funcion[i]!='\0';++i)
            {
                funciones[fila][i]=funcion[i];
            }
            funciones[fila][i]='\0';

            for(i=0;nom_f[i]!='\0';++i)
            {
                nom_fs[fila][i]=nom_f[i];
            }
            nom_fs[fila][i]='\0';
            ++fila;
        }

        else if(strcmp(Opcion, respuesta3) == 0)
        {
            printf("Introduzca la expresión o el nombre de la función: ");
            scanf("%51[^n]",funcion);
            printf("Introduzca el valor del que desea calcular su imagen: ");
            scanf("%f",num);

            i=0;

            while(prop2)
            {
                while(prop)
                {
                    if(nom_fs[i][j]!=funcion[j])
                        prop=0;
                    else if(nom_fs[i][j]=='\0' && nom_fs[i][j]=='\0')
                    {
                        prop=0;
                        igualdad=1;
                    }
                    else if(nom_fs[i][j]=='\0' ||  nom_fs[i][j]=='\0')
                        prop=0;
                    else
                        ++j;
                }
                if(igualdad || i+1==fila)
                    prop2=0;
                else
                    ++i;
            }

            if(igualdad==0)
            {
               printf("%f",calc_imagen(funcion,num));
            }
        }
        else if(strcmp(Opcion, respuesta5) == 0)
        {
            primer_menu();
        }

        else if(strcmp(Opcion, respuesta6) == 0)
        {
            exit(-1);
        }
    }
}
