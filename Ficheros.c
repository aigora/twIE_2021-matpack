#include <stdio.h>

int main(){
  FILE *pfA1,*pfA2,*pfA3,*pfA4,*pfA5,*pfC1;
  char texto[31];
  char respuesta;
  char Op;

  // Abrimos fichero para escritura
  printf("\t\t\t\t\t \t \t\t Menu \n");
  printf("Elije la opcion: \n*Crear Proyectos \n*Abrir Proyectos \n");
  scanf("%c",&respuesta);

  if(respuesta=='A')
  {
       printf("En que Proyecto te quieres meter? (1-5)\n");
    scanf("%i",&Op);
    if(Op==1)
    {
pfA1 = fopen("c:Menu/Abrir Proyectos/A1/ProyectoA1.txt", "w");
    fprintf(pfA1, "Meow");
    fclose(pfA1); // Cerramos fichero

  }
    if(Op==2)
    {
 pfA2 = fopen("c:Menu/Abrir Proyectos/A2/ProyectoA2.txt", "w");
    fprintf(pfA2, "Meow");
    fclose(pfA2); // Cerramos fichero
    }
     if(Op==3)
    {
pfA3 = fopen("c:Menu/Abrir Proyectos/A3/ProyectoA3.txt", "w");
    fprintf(pfA3, "Meow");
    fclose(pfA3); // Cerramos fichero
    }
     if(Op==4)
    {
pfA4 = fopen("c:Menu/Abrir Proyectos/A4/ProyectoA4.txt", "w");
    fprintf(pfA4, "Meow");
    fclose(pfA4); // Cerramos fichero
    }
     if(Op==5)
    {
pfA5 = fopen("c:Menu/Abrir Proyectos/A5/ProyectoA5.txt", "w");
    fprintf(pfA5, "Meow");
    fclose(pfA5); // Cerramos fichero
    }

    }
else
{
    pfC1 = fopen("c:Menu/Abrir Proyectos/ProyectoA1.txt", "w");
    fprintf(pfC1, "Meow");
    fclose(pfC1); // Cerramos fichero
}
return 0;
  }
