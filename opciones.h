typedef struct
{
    char nombre[31];
    char forma[51];
}i_funcion;
int crear_proyecto(char nombre[]);
int agreg_info(char nombre[],char contenido[]);
int cogycomp(char cadena[],char comp[]);
int identificar(i_funcion funciones[],int longitud,char nombre[]);
void primer_menu();
void segundo_menu(char nombre[]);
