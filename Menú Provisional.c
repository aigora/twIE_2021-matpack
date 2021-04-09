#include <stdio.h>

int main()
{
    char Operacion;
    printf("Escribe que Operacion quieres, pulsa Q para acabar. \n");

    while(Operacion!='Q')
    {
        scanf("%c",&Operacion);
        switch(Operacion)
        {
        case 'D':
            printf("Dominio\n");
            break;
        case 'd':
            printf("Derivada\n");
            break;
        case 'R':
            printf("Recorrido\n");
            break;
        case 'F':
            printf("Funcion InversaHola\n");
            break;
        case 'P':
            printf("Puntos de corte con los ejes\n");
            break;
        case 'S':
            printf("Signo\n");
            break;
        case 'E':
            printf("Extremos\n");
            break;
        case 'p':
            printf("Puntos de Inflexion\n");
            break;
        case 'G':
            printf("Gráfica\n");
            break;
      }
   }
   return 0;
}

