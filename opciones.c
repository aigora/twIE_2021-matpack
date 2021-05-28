#include <stdio.h>
#include "opciones.h"
#include "calculadora.h"
#include "analisis.h"

void limpiar_pan()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif // _WIN32
}
//Esta función crea un fichero con extensión csv dado un nombre el cual guarda en el fichero Nombres.csv.
//Si el proceso se completa satisfactoriamente devuelve 1, en caso contrario devuelve 0.
int crear_proyecto(char nombre[])
{
    FILE *fich,*nombres;
    char fnom[35];

    strcpy(fnom,nombre);
    strcat(fnom,".txt");

    fich=fopen(fnom,"w");

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
//Si el proceso se completa satisfactoriamente devuelve 1, en caso contrario devuelve 0.
int agreg_info(char nombre[],char contenido[])
{
    FILE *fich;
    char nombre_ext[35];
    strcpy(nombre_ext,nombre);
    strcat(nombre_ext,".txt");

    fich=fopen(nombre_ext,"a");

    if(fich==NULL)
    {
        printf("Error al agregar información.\n");
        return 0;
    }
    fprintf(fich,"%s",contenido);
    fclose(fich);

    return 1;
}

//Esta función crea una cadena con los n primeros elementos del otra y posteriormente la compara con una tercera cadena.
int cogycomp(char cadena[],char comp[])
{
    char resultado[31];
    int i,n=strlen(comp);

    for(i=0;i<n;++i)
    {
        resultado[i]=cadena[i];
    }
    resultado[i]='\0';

    if(strcmp(resultado,comp)==0)
        return 1;
    else
        return 0;
}
int identificar(i_funcion funciones[],int longitud,char nombre[])
{
    int i;

    for(i=0;i<longitud;++i)
    {
        if(strcmp(funciones[i].nombre,nombre)==0)
        {
            return i;
        }
    }
    return -1;
}
//Esta función envia al usuario al primer menú.
void primer_menu()
{
    FILE *config,*nombres,*nombres2;
    int E1,E2,ND,Contador=1,primero=1,n_proyecto,espera,cont=1,indice_p=0;
    char RD,caracter,nombre[31],proyecto[31];

    limpiar_pan();

    printf("Introduzca el numero correspondiente a la opcion que elija:\n");
    printf("1. Crear Proyecto\n2. Mis Proyectos\n3. Manual del programa (Recomendable si es su primera vez con el software)\n4. Salir\n");

    while(1)
    {
        printf("> ");
        scanf(" %i",&E1);
        switch(E1)
        {
            case 1:
                limpiar_pan();
                printf("Introduzca el nombre del proyecto: ");
                scanf(" %30[^\n]",nombre);

                if(crear_proyecto(nombre))
                {
                    segundo_menu(nombre);
                }
                else
                    scanf("%i",&espera);
                break;
            case 2:
                limpiar_pan();
                printf("Elija el archivo que desee abrir:\n");
                nombres = fopen("Nombres.txt","r");

                if(config==NULL)
                    {
                        printf("Error al abrir el archivo Nombres.txt.\n");
                        scanf("%i",&espera);
                        primer_menu();
                    }
                else
                {
                    while(fscanf(nombres,"%c",&caracter)!=EOF)
                    {
                        if(primero)
                        {
                            printf("%i. %c",Contador,caracter);
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
                    printf("(Introduzca 0 para volver al menú principal)\n");

                    scanf("%i",&n_proyecto);

                    if(n_proyecto==0)
                        primer_menu();

                    nombres=fopen("Nombres.txt","r");
                    while(fscanf(nombres,"%c",&caracter)!=EOF)
                    {
                        if(cont==n_proyecto)
                        {
                            if(caracter=='\n')
                            {
                                fclose(nombres);
                                proyecto[indice_p]='\0';
                                segundo_menu(proyecto);
                            }
                            else
                                proyecto[indice_p]=caracter;
                                ++indice_p;
                        }
                        else if(caracter=='\n')
                        {
                            ++cont;
                        }
                    }
                    printf("El proyecto elegido no existe.");
                    fclose(nombres);
                    break;
                }
            case 3:
                limpiar_pan();
                printf("¡¡¡Bienvenido!!!\nPara comenzar con la explicación del código es importante explicar primero que se organiza mediante proyectos constituidos por funciones suministradas por el usuario. Al ingresar se le mostrarán, dentro del menú principal, las opciones relacionadas con el acceso y creación de los proyectos. Una vez haya escogido o creado un proyecto será redirigido al menú secundario, en el cual, se le proveerán un conjunto de herramientas que le permitiran a analizar varios aspectos de la función.\nInformación relevante para el correcto uso del software:\n- No cree dos proyectos con el mismo nombre.\n- No cree dos funciones con el mismo nombre.\n- El número pi se indicará como p.\n- El número pi y el número e no se pegan a las constantes o a la x para indicar el producto. Por ejemplo, para escribir la fórmula del perímetro del círculo no se escribe 2px, ni 2p*x, ni 2*px, sino 2*p*x.\n");
                printf("(Introduzca 0 para volver al menú principal)\n");
                scanf("%i",espera);
                primer_menu();
                break;
            case 4:
                exit(-1);
        }
    }
}

//Esta función envia al usuario al segundo menú.
void segundo_menu(char nombre[])
{
    FILE *proyecto;
    int i,j=0,fila=0,igualdad=0,prop=1,prop2=1,longitud_x,longitud_y=0,existencia=0,c_funciones=0,nom=1,prim1=1,prim2=1,eleccion;
    float num,maximo,intervalo,valores_x[100],valores_y[100],valores_y2[100];
    char caracter,funcion[51],funcion_graf[51],Opcion[101],nombre_fun[31],nombre_ext[35],agregar[2],resultado[51],traducida_o[151],traducida_r[51];
    i_funcion funciones[50];

    strcpy(nombre_ext,nombre);
    strcat(nombre_ext,".txt");

    proyecto=fopen(nombre_ext,"r");

    while(fscanf(proyecto,"%c",&caracter)!=EOF)
    {
        agregar[0]=caracter;
        agregar[1]='\0';
        if(nom)
        {
            if(caracter=='=')
            {
                nom=0;
            }
            else
            {
                if(prim1)
                {
                    strcpy(funciones[c_funciones].nombre,agregar);
                    prim1=0;
                }
                else
                    strcat(funciones[c_funciones].nombre,agregar);
            }
        }
        else
        {
            if(caracter=='\n')
            {
                nom=1;
                ++c_funciones;
            }
            else
            {
                if(prim2==1)
                {
                    strcpy(funciones[c_funciones].forma,agregar);
                    prim2=0;
                }
                else
                    strcat(funciones[c_funciones].forma,agregar);
            }
        }
    }
    fclose(proyecto);

    limpiar_pan();

    printf("(Para mostrar el menú de opciones escriba 'opciones')\n");
    while(1)
    {
        printf("> ");
        scanf(" %100[^\n]",Opcion);

        if(strcmp(Opcion,"opciones")==0)
        {
            printf("- Guardar nueva función: guardar\n- Calcular imagen que asocia una función a un determinado valor: imagen\n- Puntos de corte: corte\n- Función inversa: inversa\n- Gráfica: grafica\n- Mostrar las funciones guardadas en el proyecto: funciones\n- Manual del programa: manual\n- Volver al menú principal: volver\n- Salir del programa: salir\n");
        }
        else if(cogycomp(Opcion,"inversa"))
        {
            printf("Introduzca el nombre o expresión de la función que desee invertir: ");
            scanf("%30s",funcion);

            if(identificar(funciones,c_funciones,funcion)!=-1)
            {
                strcpy(funcion_graf,funciones[identificar(funciones,c_funciones,funcion)].forma);
            }
            else
            {
                strcpy(traducida_r,"");
                traducir_r(funcion,traducida_r);
                strcpy(funcion_graf,traducida_r);
            }

            strcpy(resultado,"");
            strcpy(traducida_o,"");

            invertir(funcion,resultado);
            traducir_o(resultado,traducida_o);

            for(i=0;traducida_o[i]!='\0';++i)
            {
                printf("%c",traducida_o[i]);
            }
            printf("\n¿Desea guardar la funcion? (si:1/no:0)");
            scanf("%i",&eleccion);
            if(eleccion)
            {
                printf("Introduzca el nombre de la función: ");
                scanf("%31s",funciones[c_funciones].nombre);

                strcpy(funciones[c_funciones].forma,resultado);
                strcpy(nombre_fun,funciones[c_funciones].nombre);
                strcat(nombre_fun,"=");
                strcat(resultado,"\n");
                agreg_info(nombre,nombre_fun);
                agreg_info(nombre,resultado);
                ++c_funciones;
            }
        }
        else if(cogycomp(Opcion,"guardar"))
        {
            printf("Introduzca el nombre de la función: ");
            scanf("%30s",funciones[c_funciones].nombre);
            printf("Introduzca su expresión: ");
            scanf("%50s",funcion);

            traducir_r(funcion,funciones[c_funciones].forma);

            strcpy(nombre_fun,funciones[c_funciones].nombre);
            strcpy(funcion,funciones[c_funciones].forma);

            strcat(nombre_fun,"=");
            strcat(funcion,"\n");
            agreg_info(nombre,nombre_fun);
            agreg_info(nombre,funcion);
            ++c_funciones;
        }
        else if(cogycomp(Opcion,"imagen"))
        {
            printf("Introduzca el nombre o expresión de la función: ");
            scanf("%30s",nombre_fun);
            printf("Introduzca el valor cuya imagen desea calcular: ");
            scanf("%f",&num);

            if(identificar(funciones,c_funciones,nombre_fun)!=-1)
            {
                printf("%f\n",calc_imagen(funciones[identificar(funciones,c_funciones,nombre_fun)].forma,num));
            }
            else
            {
                strcpy(traducida_r,"");
                traducir_r(nombre_fun,traducida_r);
                printf(" %f\n",calc_imagen(traducida_r,num));
            }
        }
        else if(cogycomp(Opcion,"grafica"))
        {
            printf("Introduzca el nombre o expresión de la función que desee graficar: ");
            scanf("%50s",funcion);
            printf("Introduzca la cantidad de valores de x que se van a graficar: ");
            scanf(" %i",&longitud_x);
            printf("Introduzca el primer valor que tomará x en la gráfica: ");
            scanf("%f",&num);
            printf("Introduzca la distancia entre dos valores consecutivos de x: ");
            scanf("%f",&intervalo);

            if(identificar(funciones,c_funciones,funcion)!=-1)
            {
                strcpy(funcion_graf,funciones[identificar(funciones,c_funciones,funcion)].forma);
            }
            else
            {
                strcpy(traducida_r,"");
                traducir_r(funcion,traducida_r);
                strcpy(funcion_graf,traducida_r);
            }

            valores_x[0]=num;

            for(i=0;i<longitud_x;++i)
            {
                if(i!=0)
                    valores_x[i]=valores_x[i-1]+intervalo;
                valores_y[i]=calc_imagen(funcion_graf,valores_x[i]);
                for(j=0;j<i;++j)
                {
                    if(valores_y[i]==valores_y[j])
                    {
                        existencia=1;
                    }
                }
                if(!existencia)
                    ++longitud_y;
                existencia=0;
            }
            for(i=0;i<longitud_x;++i)
            {
                valores_y2[i]=valores_y[i];
            }
            for(i=0;i<longitud_y;++i)
            {
                maximo=mayor(valores_y2,longitud_x);
                for(j=0;j<longitud_x;++j)
                {
                    if(valores_y[j]==maximo)
                        printf("*");
                    else
                    printf(" ");
                }
                printf("\n");
            }
            j=0;
            longitud_y=0;
        }
        else if(cogycomp(Opcion,"funciones"))
        {
            for(i=0;i<c_funciones;++i)
            {
                strcpy(traducida_o,"");
                traducir_o(funciones[i].forma,traducida_o);
                printf("%s=%s\n",funciones[i].nombre,traducida_o);
            }
        }
        else if(cogycomp(Opcion,"manual"))
        {
            printf("¡¡¡Bienvenido!!!\nPara comenzar con la explicación del código es importante explicar primero que se organiza mediante proyectos constituidos por funciones suministradas por el usuario. Al ingresar se le mostrarán, dentro del menú principal, las opciones relacionadas con el acceso y creación de los proyectos. Una vez haya escogido o creado un proyecto será redirigido al menú secundario, en el cual, se le proveerán un conjunto de herramientas que le permitiran a analizar varios aspectos de la función.\nInformación relevante para el correcto uso del software:\n- No cree dos proyectos con el mismo nombre.\n- No cree dos funciones con el mismo nombre.\n- El número pi se indicará como p.\n- El número pi y el número e no se pegan a las constantes o a la x para indicar el producto. Por ejemplo, para escribir la fórmula del perímetro del círculo no se escribe 2px, ni 2p*x, ni 2*px, sino 2*p*x.\n");
        }
        else if(cogycomp(Opcion,"volver"))
        {
            primer_menu();
        }
        else if(cogycomp(Opcion,"salir"))
        {
            exit(-1);
        }
    }
}

